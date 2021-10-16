library("mixtools")
n=100
mean=c(2,3)
sigma=matrix(c(200,33,60,36),2,2)
n2=rmvnorm(n,mean,sigma)
mean_sample=c(mean(n2[,1]),mean(n2[,2]))
cov_sample=cov(n2)
print(mean_sample)
plot(n2)
print(cov_sample)
ellipse(mean_sample,
        cov_sample,
        alpha = .05,
        npoints = 250,
        newplot = FALSE, 
        draw = TRUE)
