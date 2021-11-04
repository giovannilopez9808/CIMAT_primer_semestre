data = read.csv("output.csv")
diff = data$time_shell-data$time_quick
n = nrow(data)
alpha = 1-0.95
z=-qnorm(alpha/2)
mu = mean(diff)
sigma = sd(diff)
li = mu-z*sigma/sqrt(n)
lf = mu+z*sigma/sqrt(n)
print(c("Promedio",round(mu,6)))
print(c("Sigma",round(sigma**2,6)))
print(c("IC",round(li,6),round(lf,6)))
