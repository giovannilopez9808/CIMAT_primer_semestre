data = read.csv("output.csv")
alpha = 1-0.9
mu = mean(data$time)
sigma = sd(data$time)
n = nrow(data)
z=-qnorm(alpha/2)
li = mu-z*sigma/sqrt(n)
lf = mu+z*sigma/sqrt(n)
print(c(li,lf))
hist(data$time,
     breaks=100,
     xlim=c(4,8),
     ylim=c(0,30),
     main="")
