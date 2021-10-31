sigma= 1 
mu = 0
n = 50
m=100
plot(c(-1,1),
     c(m,m),
     ylim=c(-1,1),
     xlim=c(0,m))
for (i in 1:100)
{
data=rnorm(n,mu,sigma)
alpha=0.1
z=qnorm(alpha/2,mu,sigma)
error = z*sigma/sqrt(n)
min = mean(data) - error 
max = mean(data) + error
lines(c(i,i),c(min,max))
}
