# Install and load necessary libraries
install.packages(c("readxl", "dplyr", "lubridate", "ggplot2", "factoextra", "cluster", "writexl", "GGally"))
library(readxl)
library(dplyr)
library(lubridate)
library(ggplot2)
library(factoextra)
library(cluster)
library(writexl)
library(GGally)


# Step 2: Load the Cleaned Data for Analysis
data <- read_excel("cleaned_combined_retail.xlsx")

# Step 3: Calculate RFM Metrics
data$InvoiceDate <- as.Date(data$InvoiceDate)
reference_date <- max(data$InvoiceDate) + days(1)

rfm_data <- data %>%
  group_by(`Customer ID`) %>%
  summarise(
    Recency = as.numeric(difftime(reference_date, max(InvoiceDate), units = "days")),
    Frequency = n_distinct(Invoice),
    Monetary = sum(Quantity * Price)
  )

# Step 4: Preprocess the Data

# Handle skewness with log transformation
rfm_data_transformed <- rfm_data %>%
  mutate(
    Recency_log = log(Recency + 1),
    Frequency_log = log(Frequency),
    Monetary_log = log(Monetary)
  ) %>%
  filter_all(all_vars(is.finite(.)))  # Remove any infinite values

# Scale the data
rfm_scaled <- rfm_data_transformed %>%
  select(Recency_log, Frequency_log, Monetary_log) %>%
  scale()

rfm_scaled <- as.data.frame(rfm_scaled)

# Step 5: Determine the Optimal Number of Clusters

# Elbow Method
set.seed(123)
fviz_nbclust(rfm_scaled, kmeans, method = "wss") +
  labs(title = "Elbow Method for Optimal Clusters")

# Silhouette Method
fviz_nbclust(rfm_scaled, kmeans, method = "silhouette") +
  labs(title = "Silhouette Method for Optimal Clusters")

# Based on the methods, choose the optimal number of clusters
k <- 4  # Adjust this number based on your analysis

# Step 6: Perform K-Means Clustering
set.seed(123)
kmeans_result <- kmeans(rfm_scaled, centers = k, nstart = 25)

# Add Cluster labels to rfm_data_transformed
rfm_clustered <- rfm_data_transformed %>%
  mutate(Cluster = as.factor(kmeans_result$cluster))

# Step 7: Visualize the Clusters

# 7.1 Visualize clusters using PCA dimensions
fviz_cluster(kmeans_result, data = rfm_scaled,
             palette = "jco",
             geom = "point",
             ellipse.type = "convex",
             ggtheme = theme_minimal()) +
  labs(title = "Customer Segments Visualization using PCA")

# 7.2 Visualize clusters using original RFM variables

## Plot Recency vs. Frequency
ggplot(rfm_clustered, aes(x = Recency, y = Frequency, color = Cluster)) +
  geom_point(alpha = 0.6) +
  theme_minimal() +
  labs(title = "Recency vs. Frequency by Cluster",
       x = "Recency (days since last purchase)",
       y = "Frequency (number of transactions)") +
  scale_color_brewer(palette = "Set1")

## Plot Frequency vs. Monetary
ggplot(rfm_clustered, aes(x = Frequency, y = Monetary, color = Cluster)) +
  geom_point(alpha = 0.6) +
  theme_minimal() +
  labs(title = "Frequency vs. Monetary by Cluster",
       x = "Frequency (number of transactions)",
       y = "Monetary (total spend)") +
  scale_color_brewer(palette = "Set1")

## Plot Recency vs. Monetary
ggplot(rfm_clustered, aes(x = Recency, y = Monetary, color = Cluster)) +
  geom_point(alpha = 0.6) +
  theme_minimal() +
  labs(title = "Recency vs. Monetary by Cluster",
       x = "Recency (days since last purchase)",
       y = "Monetary (total spend)") +
  scale_color_brewer(palette = "Set1")

# Step 8: Create Pairwise Plot Matrix using GGally

# Using original RFM variables
ggpairs(
  data = rfm_clustered,
  columns = c("Recency", "Frequency", "Monetary"),
  mapping = aes(color = Cluster),
  title = "Pairwise Plot of Original RFM Variables by Cluster"
)

# Using log-transformed RFM variables
ggpairs(
  data = rfm_clustered,
  columns = c("Recency_log", "Frequency_log", "Monetary_log"),
  mapping = aes(color = Cluster),
  title = "Pairwise Plot of Log-Transformed RFM Variables by Cluster"
)

# Step 9: Interpret and Summarize the Clusters

# Summarize the clusters
cluster_summary <- rfm_clustered %>%
  group_by(Cluster) %>%
  summarise(
    Count = n(),
    Avg_Recency = mean(Recency),
    Avg_Frequency = mean(Frequency),
    Avg_Monetary = mean(Monetary)
  )

print(cluster_summary)

# Optionally, create box plots for each RFM variable

## Recency Box Plot
ggplot(rfm_clustered, aes(x = Cluster, y = Recency, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Recency by Cluster",
       x = "Cluster",
       y = "Recency (days since last purchase)") +
  scale_fill_brewer(palette = "Set1")

## Frequency Box Plot
ggplot(rfm_clustered, aes(x = Cluster, y = Frequency, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Frequency by Cluster",
       x = "Cluster",
       y = "Frequency (number of transactions)") +
  scale_fill_brewer(palette = "Set1")

## Monetary Box Plot
ggplot(rfm_clustered, aes(x = Cluster, y = Monetary, fill = Cluster)) +
  geom_boxplot() +
  theme_minimal() +
  labs(title = "Distribution of Monetary Value by Cluster",
       x = "Cluster",
       y = "Monetary (total spend)") +
  scale_fill_brewer(palette = "Set1")

# Step 10: Save the Clustered Data
write_xlsx(rfm_clustered, "customer_segmentation_clusters.xlsx")
