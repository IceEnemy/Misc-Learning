data <- read.csv("data.csv", sep = ",", fileEncoding = "UTF-8-BOM")

#split([what you want to group], [what will it be grouped by])

transactions <- split(data$Items,data$TransactionID)

install.packages('arules')
library(arules)

#turn this into a transaction object so that we can use apriori function
transaction_list <- as(transactions, 'transactions')
inspect(transaction_list)

frequent_itemsets <- apriori(transaction_list, parameter = list(target = 'frequent itemsets',  support = 0.22))
inspect(frequent_itemsets)

rules <- ruleInduction(frequent_itemsets, confidence = 0.8)
inspect(rules)

# if lift == 1, that means that they are independent of each other
# lift > 1 , they have positive correlation
# lift < 1, they have negative correlation

rules_apriori <- apriori(transaction_list, parameter = list(target = 'rules',  support = 0.22, confidence = 0.8))
inspect(rules_apriori)

write(transaction_list, file = 'dataFP.csv', sep = ',')

# we are opening cmd to run a system command
system('cmd', input = 'fpgrowth -ts -s22 -k, dataFP.csv fpResult.csv')

system('cmd', input = 'fpgrowth -tr -s22 -c80 -k, dataFP.csv fpResult2.csv')
