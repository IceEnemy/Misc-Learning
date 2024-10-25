install.packages(c("readxl", "dplyr", "lubridate", "ggplot2", "factoextra", "cluster", "writexl", "GGally"))
library(readxl)
library(dplyr)
library(lubridate)
library(ggplot2)
library(factoextra)
library(cluster)
library(writexl)
library(GGally)


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

set.seed(123)
fviz_nbclust(rfm_scaled, kmeans, method = "wss") +
  labs(title = "Elbow Method for Optimal Clusters")

k <- 4

set.seed(123)
kmeans_result <- kmeans(rfm_scaled, centers = k, nstart = 25)

rfm_clustered <- rfm_data_transformed %>%
  mutate(Cluster = as.factor(kmeans_result$cluster))

fviz_cluster(kmeans_result, data = rfm_scaled,
             palette = "jco",
             geom = "point",
             ellipse.type = "convex",
             ggtheme = theme_minimal()) +
  labs(title = "Customer Segments Visualization using PCA")

ggplot(rfm_clustered, aes(x = Recency, y = Frequency, color = Cluster)) +
  geom_point(alpha = 0.6) +
  theme_minimal() +
  labs(title = "Recency vs. Frequency by Cluster",
       x = "Recency (days since last purchase)",
       y = "Frequency (number of transactions)") +
  scale_color_brewer(palette = "Set1")

ggplot(rfm_clustered, aes(x = Frequency, y = Monetary, color = Cluster)) +
  geom_point(alpha = 0.6) +
  theme_minimal() +
  labs(title = "Frequency vs. Monetary by Cluster",
       x = "Frequency (number of transactions)",
       y = "Monetary (total spend)") +
  scale_color_brewer(palette = "Set1")

ggplot(rfm_clustered, aes(x = Recency, y = Monetary, color = Cluster)) +
  geom_point(alpha = 0.6) +
  theme_minimal() +
  labs(title = "Recency vs. Monetary by Cluster",
       x = "Recency (days since last purchase)",
       y = "Monetary (total spend)") +
  scale_color_brewer(palette = "Set1")

ggpairs(
  data = rfm_clustered,
  columns = c("Recency", "Frequency", "Monetary"),
  mapping = aes(color = Cluster),
  title = "Pairwise Plot of Original RFM Variables by Cluster"
)

cluster_summary <- rfm_clustered %>%
  group_by(Cluster) %>%
  summarise(
    Count = n(),
    Avg_Recency = mean(Recency),
    Avg_Frequency = mean(Frequency),
    Avg_Monetary = mean(Monetary)
  )

print(cluster_summary)

ggplot(rfm_clustered, aes(x = Cluster, y = Recency, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Recency by Cluster",
       x = "Cluster",
       y = "Recency (days since last purchase)") +
  scale_fill_brewer(palette = "Set1")

ggplot(rfm_clustered, aes(x = Cluster, y = Frequency, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Frequency by Cluster",
       x = "Cluster",
       y = "Frequency (number of transactions)") +
  scale_fill_brewer(palette = "Set1")

ggplot(rfm_clustered, aes(x = Cluster, y = Monetary, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Monetary Value by Cluster",
       x = "Cluster",
       y = "Monetary (total spend)") +
  scale_fill_brewer(palette = "Set1")

# Step 10: Save the Clustered Data
write_xlsx(rfm_clustered, "customer_segmentation_clusters.xlsx")
