dataset=PlantGrowth
categorie=c('ctrl','trt1','trt2')
filenames=c('ctrl.png','trt1.png','trt2.png')
for (i in 1:3){
    data = dataset[1][dataset[2]==categorie[i]]
    data = as.numeric(unlist(data))
    print(paste('Desviacion:',sqrt(var(data))))
    print(summary(data))
    png(filenames[i])
    hist(data)
}
