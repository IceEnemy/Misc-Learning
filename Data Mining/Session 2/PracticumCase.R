participant <- read.csv("Participant.csv", sep = ",", fileEncoding = "UTF-8-BOM")
question <- read.csv("Question.csv", sep = ",", fileEncoding = "UTF-8-BOM")
result <- read.csv("Result.csv", sep = ",", fileEncoding = "UTF-8-BOM")

result <- na.omit(result)

result.merged <- merge(x = result, y = participant, by.x = "Participant.Number", by.y = "Participant.Number")

test <- table(result.merged$Question.1, result.merged$Question.2)

q1.frequency <- t(table(result.merged$Question.1, result.merged$Gender == "Male")) #transposed

labels.q1 = c("Strongly Disagree", "Disagree", "Neutral", "Agree", "Strongly Agree")

q1.title <- subset(question$Question, question$Question.Number == 1)

q1.title <- paste("Result Percentage of Question 1: ", q1.title, sep = "\n")

barplot(q1.frequency, col = rainbow(length(result.merged)), names.arg = labels.q1, main = q1.title)

labels.gender = c("Female", "Male")
legend("topleft", legend=labels.gender, fill = rainbow(length(result.merged)))

#q4

boxplot(result.merged$Question.1 ~ result.merged$Gender, col = rainbow(length(result.merged)))