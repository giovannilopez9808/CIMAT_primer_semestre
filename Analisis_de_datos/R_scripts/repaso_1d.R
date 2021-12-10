library(ggplot2)
library(dplyr)
library(MASS)
data<-geyser
n<-length(data$waiting)
# Reescritura de las columnas
colnames(data)<-c("i","d")
# Llenado de la columna i+1
data$i1<-c(data$i[-1],0)
data$i2<-c(data$i1[-1],0)
estimacion11<-rep(5,0)
estimacion12<-rep(5,0)
estimacion21<-rep(5,0)
estimacion22<-rep(5,0)
# Eliminacion de la ultima fila
data<-data[-c(n,n-1),colnames(data)]
n<-n-2
for(i in 1:100) {
    data_sample<-sample_n(data, 59)
    reg1<-lm(i1~i,data_sample)
    reg2<-lm(i2~i1+i-1,data_sample)
    estimacion11[i]<-reg1$coefficients[1]
    estimacion12[i]<-reg1$coefficients[2]
    estimacion21[i]<-reg2$coefficients[1]
    estimacion22[i]<-reg2$coefficients[2]
}
plot(data$i,data$i1,col="red")
abline(a=estimacion11[1],b=estimacion12[1],color="red")
# abline(a=estimacion21[1],b=estimacion22[1])
for (i in 2:100)
{
    abline(a=estimacion11[i],b=estimacion12[i])
  #  abline(a=estimacion21[i],b=estimacion22[i])
}
