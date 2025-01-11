install.packages("dbscan")
install.packages("FactoMineR")
install.packages("factoextra")

library(FactoMineR)
library(factoextra)
library(dbscan)
library(ggplot2)
library(plotly)
library(GGally)

# Used to find what the optimal epsilon value is
kNNdistplot(rfm_scaled, k = 6) # k = minPts
abline(h = 0.44, col = "red", lty = 2) # Choose h = steepest elbow

epsilon <- 0.44 # Same as h
minPts <- 6 # 2x the number of dimensions    

dbscan_result <- dbscan(rfm_scaled, eps = epsilon, minPts = minPts)

rfm_clustered <- rfm_data_transformed %>%
  mutate(Cluster = as.factor(dbscan_result$cluster))

# PCA Visualization
fviz_cluster(list(data = rfm_scaled, cluster = dbscan_result$cluster),
             palette = "jco",
             geom = "point",
             ellipse.type = "convex",
             ggtheme = theme_minimal()) +
  labs(title = "PCA Visualization using DBSCAN")

# 3D visualization
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

# Mean of clusters
cluster_summary_mean <- rfm_clustered %>%
  group_by(Cluster) %>%
  summarise(
    Count = n(),
    Avg_Recency = mean(Recency, na.rm = TRUE),
    Avg_Frequency = mean(Frequency, na.rm = TRUE),
    Avg_Monetary = mean(Monetary, na.rm = TRUE)
  )

print(cluster_summary_mean)

# Median of clusters
cluster_summary_median <- rfm_clustered %>%
  group_by(Cluster) %>%
  summarise(
    Count = n(),
    Median_Recency = median(Recency, na.rm = TRUE),
    Median_Frequency = median(Frequency, na.rm = TRUE),
    Median_Monetary = median(Monetary, na.rm = TRUE)
  )

print(cluster_summary_median)

# Boxplots
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

# Silhouette plot
silhouette_scores <- silhouette(dbscan_result$cluster, dist(rfm_scaled))
fviz_silhouette(silhouette_scores, 
                palette = "jco",
                ggtheme = theme_minimal(),
                main = "Silhouette Plot for DBSCAN Clustering",
                xlab = "Silhouette Width",
                ylab = "Clusters")

install.packages("fpc")
library(fpc)

distance_matrix = dist(rfm_scaled)
cluster_stats <- cluster.stats(as.dist(distance_matrix), dbscan_result$cluster)

print(cluster_stats)

# DBCV
dbcv_score <- function(cluster_labels, distance_matrix) {
  clusters <- unique(cluster_labels[4luster_labels != 0]) # Exclude noise cluster (label 0)
  n <- nrow(as.matrix(distance_matrix))
  
  relative_density <- sapply(clusters, function(c) {
    cluster_points <- which(cluster_labels == c)
    other_points <- which(cluster_labels != c & cluster_labels != 0)
    
    cluster_density <- sum(distance_matrix[cluster_points, cluster_points]) / (length(cluster_points)^2)
    separation_density <- sum(distance_matrix[cluster_points, other_points]) / (length(cluster_points) * length(other_points))
    
    density_ratio <- cluster_density / (cluster_density + separation_density)
    return(density_ratio)
  })
  
  cluster_sizes <- sapply(clusters, function(c) sum(cluster_labels == c))
  weighted_dbcv <- sum(relative_density * cluster_sizes) / sum(cluster_sizes)
  
  return(weighted_dbcv)
}

dbcv_result <- dbcv_score(dbscan_result$cluster, as.matrix(distance_matrix))
print(paste("DBCV Score for DBSCAN Clustering:", dbcv_result))