function_r=function(x){
    return (exp(-x*x/4)/sqrt(4*pi))
}
integrate=function(a,b){
    n=100
    x = runif(n)*2
    y = function_r(x)
    r=2*sum(y)/n
    return (r)
}
print(integrate(0.0,2.0))
