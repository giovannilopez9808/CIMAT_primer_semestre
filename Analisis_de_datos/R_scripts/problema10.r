data=c(25.8, 24.6, 26.1, 22.9, 25.1, 27.3, 24.0, 24.5, 23.9, 26.2, 24.3, 24.6, 23.3, 25.5, 28.1, 24.8, 23.5, 26.3, 25.4,25.5, 23.9, 27.0, 24.8, 22.9, 25.4)

# Metodo 1
n=length(data)
alpha=0.01
ci=t.test(x=data, conf.level=0.99)$conf.int
print(ci)

# Metodo 2
mu=mean(data)
sigma=sd(data)
var_1 =qt(0.005,n,lower.tail=F)
li=-var_1*sigma/sqrt(n)+mu
lf=var_1*sigma/sqrt(n)+mu
print(c(li,lf))

# Inciso B

mu_h0=24.3
t_score=abs(mu-mu_h0)/(sigma/sqrt(n))
p_value = pt(t_score,n-1,lower.tail=F)
print(c(t_score,2*p_value))


# Inciso C

alpha = qt(0.0075/2,n-1)
print(alpha)
