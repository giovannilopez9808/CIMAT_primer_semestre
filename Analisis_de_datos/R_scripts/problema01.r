sum_x=function(x,m,s){
    return (list(sum(x[1:m]),x[1:m]))
}
n=5
m=2
x=runif(5, min=3, max=4)
c=sum_x(x,m)
print(x)
print(c)
