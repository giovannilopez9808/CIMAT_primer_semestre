library(ggplot2)
library(Rlab)
nboot <- 100
n <- 100
counts <- matrix(0, n)
for (i in 1:n) {
    data <- rbern(n, prob = 0.5)
    changes <- sum(abs(diff(data)))
    counts[i] <- changes
}
mu <- mean(counts)
data_tmp <- sample(
    counts,
    n * nboot,
    replace = TRUE
)
data_bootstrap <- matrix(
    data_tmp,
    nrow = n,
    ncol = nboot
)
delta <- colMeans(data_bootstrap) - mu
quantiles <- quantile(
    delta,
    c(0.1, 0.9)
)
ci <- mu - c(
    quantiles[2],
    quantiles[1]
)
theme_set(theme_classic())
ggplot(
    data.frame(x = delta),
    aes(x = counts)
) +
    geom_density() +
    ylab("Densidad") +
    xlab("Número de cambios")
ggsave("problema05.png",
    height = 1000,
    width = 1200,
    limitsize = FALSE,
    units = "px"
)
print(c(mu, ci))