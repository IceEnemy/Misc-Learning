# Pie Chart

data.icecream <- c(20,50,10,40)
labels.icecream <- c("Vanilla","Chocolate","Mint","Berries")

pie.percentage <- round(data.icecream/sum(data.icecream) * 100)

pie(data.icecream,labels = labels.icecream, col = rainbow(length(data.icecream)), clockwise = TRUE, main = "Ice Cream Sales", radius = 1)

pie(data.icecream, label = pie.percentage, col = rainbow(length(data.icecream)), clockwise = TRUE, main = "Ice Cream Sales", radius = 1)
legend("topright", legend = labels.icecream, fill = rainbow(length(data.icecream)))


# Bar Chart

barplot(data.icecream, names.arg = labels.icecream, col = rainbow(length(data.icecream)), main = "Favourite Flavours", xlab = "Flavour", ylab = "Frequency")

matrix.icecream <- matrix(c(6,7,7,25,13,12,3,2,5,20,12,18), nrow = 3, byrow = FALSE)

labels.age <- c("<18", "18-25",">25")

barplot(matrix.icecream, names.arg = labels.icecream, col = rainbow(length(data.icecream)), main = "Favourite Flavours", xlab = "Flavour", ylab = "Frequency")

legend("topleft",legend = labels.age, fill = rainbow(length(data.icecream)))

# Box Plot
data.employee <- data.frame(
  id = c(1:8),
  name = c("Nathan","Christo","Valdo", "David", "Kevin", "Budi", "Dimas", "Oliver"),
  salary = c(625,515,610,730,840,570,630,720),
  dept = c("IT","Operations","IT","HR","Finance","IT","Operations","Finance")
)

boxplot(data.employee$salary ~ data.employee$dept, data.employee, col = rainbow(length(data.employee)), xlab = "Department", ylab = "Salary")

# Boxplot with Notches

boxplot(data.employee$salary ~ data.employee$dept, data.employee, col = rainbow(length(data.employee)), xlab = "Department", ylab = "Salary", notch = TRUE)

data.boxplot <- list(
  group1 = rnorm(100),
  group2 = rnorm(50),
  group3 = rnorm(20)
)

boxplot(data.boxplot$group1, notch = TRUE)

# Boxplot with Variable Widths

boxplot(data.boxplot, varwidth = TRUE)

# Histogram

data.histogram <- c(1,3,3,3,5,6,6,6,6,6,4,2,7)

hist(data.histogram, main = "histogram", ylab = "Frequency", col = "green", border = "blue", xlim = c(0,10), ylim = c(0,10))

hist(data.employee$salary, breaks = c(400,500,600,700,800,900,1000))
  
#line graph
salary1 <- c(200,230,260,300,350,400)
salary2 <- c(220,250,270,300,320,350)
year <- c(2012:2017)

plot(x = year, y = salary1, type = "l", col = "red")
plot(x = year, y = salary1, type = "o", col = "red")
lines(x = year, y=salary2, type="o", col = "blue")
labels.salary <- c("company1","company2")
legend("topleft", legend = labels.salary, fill = c("red","blue"))

# Scatter Plot

#how to add a new column:

data.employee$age <- c(20,24,25,30,22,31,23,35)

png("scatterplot.png",width = 800, height = 600)
plot(x = data.employee$age, y = data.employee$salary, main = "Employee Salary", xlab = "Age", ylab = "Salary", col = rainbow(length(data.employee)), pch = 19)

dev.off() # so it saves properly
