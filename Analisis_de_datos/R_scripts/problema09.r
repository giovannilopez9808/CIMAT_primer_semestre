M=100
N=50
mu=0
sigma=1
li=c()
ls=c()
plot(c(-1,1),c(M,M),type="n",xlim=c(-1,1),ylim=c(0,M))
abline(v=mu,lty=3,lwd=2)
for(k in 1:M)
{
datos=rnorm(N,mu,sigma)
datos
alpha=0.05
z_alpha2=-qnorm(alpha/2)
LI=mean(datos)-z_alpha2*(sigma/sqrt(N))
LS=mean(datos)+z_alpha2*(sigma/sqrt(N))
li[k]=LI
ls[k]=LS
print(c(LI,LS))
lines(c(LI,LS),c(k,k),col=k,lwd=1.5)
#Sys.sleep(1)
}
print(paste("Mu fuera=",sum(li>mu)+sum(ls<mu)))
