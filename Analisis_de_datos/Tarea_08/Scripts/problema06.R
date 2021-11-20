library(ggplot2)
data <- read.csv("../Data/tazas.csv")
nboot <- 100
i <- 1
alpha <- 0.05
colors <- c(
    "#f72585",
    "#7209b7",
    "#3a0ca3",
    "#4361ee",
    "#4cc9f0"
)
for (data_person in data)
{
    n <- length(data_person)
    mu <- mean(data_person)
    data_tmp <- sample(
        data_person,
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
    name <- paste("problema06_", i, ".png",
        sep = ""
    )
    theme_set(theme_classic())
    ggplot(
        data.frame(x = data_person),
        aes(x = data_person)
    ) +
        geom_density(
            aes(y = ..count..),
            fill = colors[i],
            alpha = 0.5,
        ) +
        ylab("Densidad") +
        xlab("Número de Taza")
    ggsave(name,
        height = 750,
        width = 1200,
        limitsize = FALSE,
        units = "px"
    )
    i <- i + 1
}
