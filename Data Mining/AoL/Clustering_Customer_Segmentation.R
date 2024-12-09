install.packages(c("readxl", "dplyr", "lubridate", "ggplot2", "factoextra", "cluster", "writexl", "GGally", "plotly"))
library(readxl)
library(dplyr)
library(lubridate)
library(ggplot2)
library(factoextra)
library(cluster)
library(writexl)
library(GGally)
library(plotly)

data <- read_excel("cleaned_combined_retail.xlsx")

data$InvoiceDate <- as.Date(data$InvoiceDate)
reference_date <- max(data$InvoiceDate) + days(1)

rfm_data <- data %>%
  group_by(`Customer ID`) %>%
  summarise(
    Recency = as.numeric(difftime(reference_date, max(InvoiceDate), units = "days")),
    Frequency = n_distinct(Invoice),
    Monetary = sum(Quantity * Price)
  )

rfm_data_transformed <- rfm_data %>%
  mutate(
    Recency_log = log(Recency + 1),
    Frequency_log = log(Frequency),
    Monetary_log = log(Monetary)
  ) %>%
  filter_all(all_vars(is.finite(.)))

rfm_scaled <- rfm_data_transformed %>%
  select(Recency_log, Frequency_log, Monetary_log) %>%
  scale()
rfm_scaled <- as.data.frame(rfm_scaled)

# Elbow Method
set.seed(123)
fviz_nbclust(rfm_scaled, kmeans, method = "wss") +
  labs(title = "Elbow Method for Optimal Clusters")

k <- 4
set.seed(123)
kmeans_result <- kmeans(rfm_scaled, centers = k, nstart = 25)

rfm_clustered <- rfm_data_transformed %>%
  mutate(Cluster = as.factor(kmeans_result$cluster))

# 2D visualization
fviz_cluster(kmeans_result, data = rfm_scaled,
             palette = "jco",
             geom = "point",
             ellipse.type = "convex",
             ggtheme = theme_minimal()) +
  labs(title = "Customer Segments Visualization using PCA")

# 3D Visualization
plot_ly(rfm_clustered, x = ~Recency_log, y = ~Frequency_log, z = ~Monetary_log, 
        color = ~Cluster, colors = "Set1", type = "scatter3d", mode = "markers") %>%
  layout(scene = list(
    xaxis = list(title = "Log(Recency)"),
    yaxis = list(title = "Log(Frequency)"),
    zaxis = list(title = "Log(Monetary)")),
    title = "3D Visualization of Customer Segments")

# Pairwise scatterplots
ggpairs(
  data = rfm_clustered,
  columns = c("Recency", "Frequency", "Monetary"),
  mapping = aes(color = Cluster),
  title = "Pairwise Plot of Original RFM Variables by Cluster"
)

# Summarize clusters (Mean)
cluster_summary_mean <- rfm_clustered %>%
  group_by(Cluster) %>%
  summarise(
    Count = n(),
    Avg_Recency = mean(Recency),
    Avg_Frequency = mean(Frequency),
    Avg_Monetary = mean(Monetary)
  )

print(cluster_summary_mean)

# Summarize clusters (Median)
cluster_summary_median <- rfm_clustered %>%
  group_by(Cluster) %>%
  summarise(
    Count = n(),
    Median_Recency = median(Recency),
    Median_Frequency = median(Frequency),
    Median_Monetary = median(Monetary)
  )

print(cluster_summary_median)

# Recency Boxplot
ggplot(rfm_clustered, aes(x = Cluster, y = Recency, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Recency by Cluster",
       x = "Cluster",
       y = "Recency (days since last purchase)") +
  scale_fill_brewer(palette = "Set1")

# Frequency Boxplot
ggplot(rfm_clustered, aes(x = Cluster, y = Frequency, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Frequency by Cluster",
       x = "Cluster",
       y = "Frequency (number of transactions)") +
  scale_fill_brewer(palette = "Set1")

# Monetary Boxplot
ggplot(rfm_clustered, aes(x = Cluster, y = Monetary, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Monetary Value by Cluster",
       x = "Cluster",
       y = "Monetary (total spend)") +
  scale_fill_brewer(palette = "Set1")

remove_outliers <- function(x) {
  q1 <- quantile(x, 0.25, na.rm = TRUE)
  q3 <- quantile(x, 0.75, na.rm = TRUE)
  iqr <- q3 - q1
  x[x >= (q1 - 1.5 * iqr) & x <= (q3 + 1.5 * iqr)]
}

# Recency Boxplot without Outliers
ggplot(rfm_clustered %>% filter(Recency %in% remove_outliers(Recency)),
       aes(x = Cluster, y = Recency, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Recency by Cluster (Without Outliers)",
       x = "Cluster",
       y = "Recency (days since last purchase)") +
  scale_fill_brewer(palette = "Set1")

# Frequency Boxplot without Outliers
ggplot(rfm_clustered %>% filter(Frequency %in% remove_outliers(Frequency)),
       aes(x = Cluster, y = Frequency, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Frequency by Cluster (Without Outliers)",
       x = "Cluster",
       y = "Frequency (number of transactions)") +
  scale_fill_brewer(palette = "Set1")

# Monetary Boxplot without Outliers
ggplot(rfm_clustered %>% filter(Monetary %in% remove_outliers(Monetary)),
       aes(x = Cluster, y = Monetary, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Monetary Value by Cluster (Without Outliers)",
       x = "Cluster",
       y = "Monetary (total spend)") +
  scale_fill_brewer(palette = "Set1")

# Silhouette Score
silhouette_score <- silhouette(kmeans_result$cluster, dist(rfm_scaled))
avg_silhouette_score <- mean(silhouette_score[, 3]) # Extract the average silhouette score
cat("Average Silhouette Score for k =", k, "is", avg_silhouette_score, "\n")

# WCSS
wcss <- sum(kmeans_result$withinss)
cat("WCSS (Within-Cluster Sum of Squares) for k =", k, "is", wcss, "\n")

write_xlsx(rfm_clustered, "customer_segmentation_clusters.xlsx")
