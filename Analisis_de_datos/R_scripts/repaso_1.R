library(ggplot2)
library(MASS)
data<-geyser
n<-length(data$waiting)
# Reescritura de las columnas
colnames(data)<-c("i","d")
# Llenado de la columna i+1
data$i1<-c(data$i[-1],0)
# Eliminacion de la ultima fila
data<-data[-n,colnames(data)]
head(data)
n<-n-1
reg<-lm(i1~i,data)
summary(reg)
plot(reg)
predict_value<-data.frame(cbind(4.5))
names(predict_value)<-c("i")
predict_ci<-predict(reg,
predict_value,
interval="prediction",
level=0.95)
print(predict_ci)
# Grafica con los intervalos de confianza
ggplot(data.frame(y=data$d1,x1=data$i),
aes(x1,y))+
geom_point()+
stat_smooth(method="lm",
col="red")
