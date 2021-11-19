suppressPackageStartupMessages({
    library(ggplot2)
    library(Rlab)
})
alpha <- 0.05
nboot <- 1000
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
    c(alpha / 2, 1 - alpha / 2)
)
ci <- mu - c(
    quantiles[1],
    quantiles[2]
)

theme_set(theme_classic())
ggplot(
    data.frame(x = counts),
    aes(x = counts)
) +
    geom_density(
        colour = "#560bad",
        fill = "#3f37c9",
        alpha = 0.5,
    ) +
    ylab("Densidad") +
    xlab("Número de cambios")
ggsave("problema05.png",
    height = 750,
    width = 1200,
    limitsize = FALSE,
    units = "px"
)
print(c(mu, ci))

sigma <- sqrt(var(counts))
p_value <- pt((abs(42 - mu) / (sigma / sqrt(n))), n - 1)
print(p_value)