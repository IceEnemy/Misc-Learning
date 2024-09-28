# Missing Value -> Value that does not EXIST, symbol is 'NA' (not applicable, not available, no answer)

names <- c("Andi", "Budi", NA, NA, "Budi")
is.na(names)

names[is.na(names)] <- "-" #replacing NA values with other symbols

scores <- c(100, 90, 85, NA, 90)

dataframe <- data.frame(name = names, score = scores)

duplicated(dataframe)
# remove duplicated data
dataframe <- dataframe[!duplicated(dataframe),]
# remove NA data -> only shows complete data
dataframe <- na.omit(dataframe)

data <- read.csv("datasets_19_420_iris_NA.csv", fileEncoding = "UTF-8-BOM", na.strings = c(""))

data <- na.omit(data)

# aggregate function -> counting our data and summarize it into a single value
# >> finding the minimum, maximum, average, median, standard deviation, etc

data.virginica <- subset(data, data$Species == "Iris-virginica", select = c("SepalWidthCm", "Species"))

data.virginica.mean <- mean(data.virginica$SepalWidthCm)
data.virginica.median <- median(data.virginica$SepalWidthCm)
data.virginica.sd <- sd(data.virginica$SepalWidthCm)
data.virginica.min <- min(data.virginica$SepalWidthCm)
data.virginica.max <- max(data.virginica$SepalWidthCm)
data.virginica.sum <- sum(data.virginica$SepalWidthCm)
data.virginica.length <- length(data.virginica$SepalWidthCm)
# length = counting how many values there are

summary(data)
# if the data is a number -> min, mean, etc
# if it is character, it will return the length, what type of class