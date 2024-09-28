rate <- read.csv("Exchange Rate.csv", fileEncoding = "UTF-8-BOM")

# 1. Divide the data into certain cryptocurrency
rate.btc <- subset(rate, rate$Cryptocurrency == "BTC")
rate.eth <- subset(rate, rate$Cryptocurrency == "ETH")
rate.xrp <- subset(rate, rate$Cryptocurrency == "XRP")

# 2. order the data by date and time ascendingly
rate.btc <- rate.btc[order(rate.btc$Date, rate.btc$Time),]
rate.eth <- rate.eth[order(rate.eth$Date, rate.eth$Time),]
rate.xrp <- rate.xrp[order(rate.xrp$Date, rate.xrp$Time),]

# 3. calculate open and close price for ETH on 16th august
rate.eth.16 <- subset(rate.eth, rate.eth$Date == "16-Aug-18", select = c("Time","Price"))

rate.eth.16.open <- rate.eth.16[1,2]
rate.eth.16.close <- rate.eth.16[nrow(rate.eth.16),2]

paste("Ethereum 16 August Open Price: Rp.", rate.eth.16.open)
paste("Ethereum 16 August Close Price: Rp.", rate.eth.16.close)

# 4. Calculate low and hight price of btc

rate.btc.15 <- subset(rate.btc, rate.btc$Date == "15-Aug-18", select = "Price")

rate.btc.15.high <- max(rate.btc.15$Price)
rate.btc.15.low <- min(rate.btc.15$Price)

paste("BitCoin 15th August High Price: Rp.", rate.btc.15.high)
paste("BitCoin 15th August Low Price: Rp.", rate.btc.15.low)

# 5. summarize XRP on 18th

rate.xrp.18 <- subset(rate.xrp, rate.xrp$Date == '18-Aug-18', select="Price")
is.numeric(rate.xrp.18$Price)

rate.xrp.18.price <- gsub(".","", rate.xrp.18$Price, fixed = TRUE)
rate.xrp.18.mean <- format(mean(as.numeric(rate.xrp.18.price)), big.mark = ".", decimal.mark = ",")
rate.xrp.18.median <- format(median(as.numeric(rate.xrp.18.price)), big.mark = ".", decimal.mark = ",")
rate.xrp.18.sd <- format(sd(as.numeric(rate.xrp.18.price)), big.mark = ".", decimal.mark = ",")

paste("Ripple 18 August Average Price: Rp.", rate.xrp.18.mean)
paste("Ripple 18 August Median Price: Rp.", rate.xrp.18.median)
paste("Ripple 18 August Standard Deviation: Rp.", rate.xrp.18.sd)

rate.xrp.18.all <- subset(rate.xrp, rate.xrp$Date == '18-Aug-18')
rate.xrp.18.all$Price <- as.numeric(rate.xrp.18.all$Price)
summary(rate.xrp.18.all)