n_data=10000000
n=100
time_data_quick = runif(n)
time_data_shell = runif(n)
for(i in 1:n)
{
    x=runif(n_data)
    time=(system.time(x1 <- sort(x, method = "shell"), gcFirst = TRUE))[3]
    time_data_shell[i]=time
    time=(system.time(x2 <- sort(x, method = "quick"), gcFirst = TRUE))[3]
    time_data_quick[i]=time
    
}
data=data.frame(time_quick=time_data_quick,time_shell=time_data_shell)
write.csv(data,"output.csv",row.names=FALSE)
