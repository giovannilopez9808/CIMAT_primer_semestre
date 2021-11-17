obtain_ci <- function(alpha) {
    ci <- t.test(
        x = data$difference,
        conf.level = 1 - alpha
    )$conf.int
    return(ci)
}

library(ggplot2)
library(tidyr)
data <- read.csv("../Data/data.csv")
data$difference <- data$outer.lane - data$inner.lane
mu <- mean(data$difference)
print(obtain_ci(0.1))
print(obtain_ci(0.05))
print(obtain_ci(0.01))
data_long <- data %>% gather(
    lane,
    value,
    outer.lane:inner.lane
)
theme_set(theme_classic())
plot <- ggplot(
    data = data_long,
    aes(
        x = lane,
        y = value,
        fill = lane,
    )
) +
    geom_boxplot() +
    scale_x_discrete(labels = c(
        "Carril interior",
        "Carril exterior"
    )) +
    scale_fill_manual(values = c(
        "#1a759f",
        "#76c893"
    )) +
    ylab("Tiempo (s)") +
    xlab("Carriles") +
    theme(legend.position = "none")
ggsave("problema07_boxplot.png",
    height = 1000,
    width = 1200,
    limitsize = FALSE,
    units = "px"
)
n <- length(data$inner.lane)
sigmax <- var(data$inner.lane) * n / (n - 1)
sigmay <- var(data$outer.lane) * n / (n - 1)
sigma <- sqrt((sigmax + sigmay) / n)
meanx <- mean(data$inner.lane)
meany <- mean(data$outer.lane)
t_d <- (meanx - meany) / sigma
print(c(t_d, pnorm(t_d, lower.tail = FALSE)))
plot <- ggplot(
    data,
    aes(difference)
) +
    geom_histogram(
        bins = 15,
        aes(y = ..count..),
        colour = "black",
        fill = "#ce2626",
        alpha = 0.5
    ) +
    xlab("Diferencia (s)") +
    ylab("Frecuencia") +
    geom_vline(aes(xintercept = mu),
        color = "red",
        linetype = "dashed",
        size = 0.9
    ) +
    annotate("text",
        x = 0.75,
        y = 3,
        label = paste(
            "mean =",
            round(mu, 4)
        )
    )
ggsave("problema07_histogram.png",
    height = 1000,
    width = 1200,
    limitsize = FALSE,
    units = "px"
)