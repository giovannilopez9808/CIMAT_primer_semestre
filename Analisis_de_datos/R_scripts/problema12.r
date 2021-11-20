library(ggplot2)
data <- read.csv("Data/data_1.csv")
print(cor(data))
regresion <- lm(volumen ~ gastos,data)
ggplot(
       data,
       aes(x=gastos,y=volumen)
)+
geom_point()
print(regresion)
