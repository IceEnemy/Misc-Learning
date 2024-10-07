data <- read.csv("retail.csv")

data <- na.omit(data)

boxplot(Total_Cost ~ Customer_Category, data = data, main = "Total Cost by Customer Category", xlab = "Customer Category", ylab = "Total Cost", col = rainbow(length(unique(data$Customer_Category))))

payment.counts <- table(data$Payment_Method)
payment.percentages <- round(100 * payment.counts / sum(payment.counts), 2)

payment.labels <- paste(names(payment.counts), "(", payment.percentages, "%)" , sep = "")

pie(payment.counts, labels = payment.labels, col = rainbow(length(payment.counts)), main = "Distribution of Payment Methods")

store.counts <- table(data$Store_Type)
store.sorted <- sort(store.counts, decreasing = TRUE)
store.top3 <- head(store.sorted,3)

barplot(store.top3, col = rainbow(length(store.top3)), xlab = "Store Type", ylab = "Frequency", main = "Top 3 Stores by Frequency")

market <- read.csv("market_data.csv")

market.beverages <- subset(market, market$department == "beverages" & market$aisle != "soft drinks")
market.beverages <- market.beverages[!duplicated(market.beverages), ]

# install.packages("arules")
library("arules")

transaction.list <- split(market.beverages$product_name, market.beverages$order_id)
transaction.list.final <- as(transaction.list, "transactions")
inspect(transaction.list.final)

frequent.itemsets <- apriori(transaction.list.final, parameter = list(supp = 0.02, target = "frequent itemsets"))
inspect(frequent.itemsets)

rules <- apriori(transaction.list.final, parameter = list(supp = 0.02, target = "rules", conf = 0.05))
inspect(rules)
