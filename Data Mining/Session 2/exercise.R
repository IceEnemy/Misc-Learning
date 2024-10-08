participant <- read.csv("Participant.csv")
question <- read.csv("Question.csv")
result <- read.csv("Result.csv")

result <- na.omit(result)

q2.title <- subset(question$Question, question$Question.Number == 2)
q2.title <- paste("Q2:", q2.title, sep = "\n")

q2.freq <- table(result$Question.2)

satisfaction.labels = c("SD","D","N","A","SA")
tf.labels = c("TRUE","FALSE")

q2.percentages = round(100 * q2.freq / sum(q2.freq), 1)

pie(q2.freq,labels=q2.percentages, col = rainbow(length(q2.freq)), main = q2.title)
legend("topright", legend = satisfaction.labels, fill = rainbow(length(q2.freq)))

result.merged <- merge(x=result, y=participant, by.x = ("Participant.Number"), by.y = ("Participant.Number"))

result.fem <- subset(result.merged, result.merged$Gender == "Female")

result.fem.q6 <- table(result.fem$Question.6)
fem.q6.percentage <- round(100 * result.fem.q6 / sum(result.fem.q6), 1)

pie(fem.q6.percentage, labels = fem.q6.percentage, col = rainbow(length(fem.q6.percentage)))
legend("topright",legend = tf.labels, fill = rainbow(length(fem.q6.percentage)))

q1.freq <- t(table(result.merged$Question.1, result.merged$Gender))
barplot(q1.freq, col = rainbow(length(result.merged)), names.arg = satisfaction.labels)

boxplot(result.merged$Question.1 ~ result.merged$Gender, result.merged, col = rainbow(length(result.merged)))

hist(result$Question.4, xlim = c(1,5), ylim = c(0,60), breaks = 5, col = rainbow(length(unique(result$Question.4))))

q1.ans <- table(result$Question.1)
q2.ans <- table(result$Question.2)
q3.ans <- table(result$Question.3)
q4.ans <- table(result$Question.4)
q5.ans <- table(result$Question.5)

question.freq <- rbind(q1.ans, q2.ans, q3.ans, q4.ans, q5.ans)

question.freq <- t(question.freq)

barplot(question.freq)

part.date <- table(result$Date)
part.date <- c(part.date, c("7/15/2018" = 0))

formatted_dates <- sort(as.Date(names(part.date), format = "%m/%d/%Y"))

sorted_indices <- order(formatted_dates)
sorted_part.date <- part.date[sorted_indices]
formatted_dates <- formatted_dates[sorted_indices]

png("result.png", height = 600, width = 800)
plot(x = as.Date(formatted_dates), y = as.numeric(sorted_part.date), type ="o")
dev.off()

library("arules")
