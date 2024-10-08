products <- read.csv("products.csv")

par(mar = c(10,4,4,4) + 0.1)

boxplot(products$product_price ~ products$department, products, main = "Product Price for All Product Department", xlab = "", ylab = "Product Price", las=3, col = rainbow(length(unique(products$department))))

mtext("Department", side = 1, line = 8)

dept <- table(products$department)
dept <- sort(dept, decreasing = TRUE)
dept.top5 <- head(dept, 5)
dept.other <- c(Other = sum(dept[-(1:5)]))

dept.all <- c(dept.top5, dept.other)

dept.percentages <- round(100 * dept.all / sum(dept.all), 2)
dept.labels <- paste(names(dept.all), " (", dept.percentages, "%)", sep = "")

pie(dept.percentages, labels = dept.labels, main = "Top 5 Department (Based on Product Count", col = rainbow(length(dept.percentages)))

aisle <- subset(products, products$department == "frozen")
aisle.freq <- table(aisle$aisle)
aisle.freq <- sort(aisle.freq)
aisle.bottom3 <- head(aisle.freq,3)

barplot(aisle.bottom3, col = rainbow(length(aisle.bottom3)), main = "Lowest Aisle in frozen department (based on Product Count)")


orders <- read.csv("orders.csv")

products.apri <- subset(products, products$department == "alcohol" & products$aisle != "specialty wines champagnes")
products.apri <- products.apri[!duplicated(products.apri),]

full <- merge(orders, products.apri, by.x = "product_id", by.y = "product_id")

library("arules")
transaction.list <- split(full$product_name, full$order_id)
transaction.list <- as(transaction.list, "transactions")
inspect(transaction.list)

apri <- apriori(transaction.list, parameter = list(supp = 0.04, target = "frequent itemsets"))
inspect(apri)

rules <- apriori(transaction.list, parameter = list(supp=0.04, confidence = 0.5, target = "rules"))
inspect(rules)

