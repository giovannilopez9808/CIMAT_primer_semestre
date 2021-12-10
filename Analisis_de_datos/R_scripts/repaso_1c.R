library(ggplot2)
library(MASS)
data<-geyser
n<-length(data$waiting)
# Reescritura de las columnas
colnames(data)<-c("i","d")
# Llenado de la columna i+1
data$i1<-c(data$i[-1],0)
data$i2<-c(data$i1[-1],0)
# Eliminacion de la ultima fila
data<-data[-c(n,n-1),colnames(data)]
n<-n-2
reg<-lm(i2~i1,data)
summary(reg)
plot(reg)
# Grafica con los intervalos de confianza
ggplot(data.frame(y=data$i1,x1=data$i),
aes(x1,y))+
geom_point()+
stat_smooth(method="lm",
col="red")
