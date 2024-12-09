# Install and load required packages
install.packages(c("readxl", "dplyr", "lubridate", "ggplot2", "factoextra", "dbscan", "writexl", "GGally", "plotly", "clusterCrit"))
library(readxl)
library(dplyr)
library(lubridate)
library(ggplot2)
library(factoextra)
library(dbscan)
library(writexl)
library(GGally)
library(plotly)

# Load data
data <- read_excel("cleaned_combined_retail.xlsx")

# Convert InvoiceDate to Date type and set the reference date
data$InvoiceDate <- as.Date(data$InvoiceDate)
reference_date <- max(data$InvoiceDate) + days(1)

# RFM calculations
rfm_data <- data %>%
  group_by(`Customer ID`) %>%
  summarise(
    Recency = as.numeric(difftime(reference_date, max(InvoiceDate), units = "days")),
    Frequency = n_distinct(Invoice),
    Monetary = sum(Quantity * Price)
  )

# Log transformation and scaling
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

# Determine optimal epsilon using k-NN distance plot
kNNdistplot(rfm_scaled, k = 4) # Set k = minPts - 1 (e.g., for minPts = 5, use k = 4)
abline(h = 0.5, col = "red", lty = 2) # Add a reference line at h = 0.5 (adjust based on your dataset)

# Analyze the elbow in the plot to select an appropriate 'eps' value

# DBSCAN clustering with selected epsilon and minPts
eps <- 0.5  # Replace with your chosen 'eps' value from the plot
minPts <- 5 # Choose the minimum points to form a cluster
dbscan_result <- dbscan(rfm_scaled, eps = eps, minPts = minPts)

# Add cluster labels to the data
rfm_clustered <- rfm_data_transformed %>%
  mutate(Cluster = as.factor(dbscan_result$cluster))

# Visualize clusters in 2D using PCA
fviz_cluster(list(data = rfm_scaled, cluster = dbscan_result$cluster),
             geom = "point",
             palette = "jco",
             ellipse.type = "convex",
             ggtheme = theme_minimal()) +
  labs(title = "Customer Segments Visualization using PCA (DBSCAN)")

# 3D Visualization of clusters
plot_ly(rfm_clustered, x = ~Recency_log, y = ~Frequency_log, z = ~Monetary_log, 
        color = ~Cluster, colors = "Set1", type = "scatter3d", mode = "markers") %>%
  layout(scene = list(
    xaxis = list(title = "Log(Recency)"),
    yaxis = list(title = "Log(Frequency)"),
    zaxis = list(title = "Log(Monetary)")),
    title = "3D Visualization of Customer Segments (DBSCAN)")

# Pairwise scatterplots
ggpairs(
  data = rfm_clustered,
  columns = c("Recency", "Frequency", "Monetary"),
  mapping = aes(color = Cluster),
  title = "Pairwise Plot of Original RFM Variables by Cluster (DBSCAN)"
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

# Boxplots for Recency, Frequency, and Monetary by Cluster
for (var in c("Recency", "Frequency", "Monetary")) {
  ggplot(rfm_clustered, aes_string(x = "Cluster", y = var, fill = "Cluster")) +
    geom_boxplot() +
    theme_minimal() +
    labs(title = paste("Distribution of", var, "by Cluster (DBSCAN)"),
         x = "Cluster",
         y = var) +
    scale_fill_brewer(palette = "Set1") +
    print()
}

# Davies-Bouldin Index for DBSCAN
library(clusterCrit) # Install and load this package if needed

# Exclude noise points (Cluster = -1)
dbscan_data <- rfm_scaled[dbscan_clusters != -1, ]
dbscan_labels <- dbscan_clusters[dbscan_clusters != -1]

# Compute DBI
dbi <- intCriteria(as.matrix(dbscan_data), as.integer(dbscan_labels), "Davies_Bouldin")
cat("Davies-Bouldin Index (DBI) for DBSCAN is", dbi[[1]], "\n")


# Save results
write_xlsx(rfm_clustered, "customer_segmentation_clusters_dbscan.xlsx")
