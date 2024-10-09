install.packages("readxl")
library(readxl)

install.packages("dplyr")
library(dplyr)

retail.1 <- read_xlsx("Online Retail.xlsx")
retail.2 <- read_xlsx("online_retail_II.xlsx")
retail.2.pt2 <- read_xlsx("online_retail_II.xlsx", sheet = 2)

retail.1 <- retail.1 %>%
  rename(
    Invoice = InvoiceNo,
    Price = UnitPrice,
    `Customer ID` = CustomerID
  )

combined_retail <- rbind(retail.1, retail.2, retail.2.pt2)
combined_retail <- combined_retail[!duplicated(combined_retail), ]

# Step 1: Check the number of NA values in each column
na_count <- colSums(is.na(combined_retail))

# View the result
print(na_count)

combined_retail <- na.omit(combined_retail)

combined_retail<- combined_retail %>%
  filter(across(where(is.numeric), ~ . > 0))

combined_retail <- combined_retail %>%
  filter(grepl("[0-9]", StockCode))

install.packages("writexl")
library(writexl)

write_xlsx(combined_retail, "cleaned_combined_retail.xlsx")

