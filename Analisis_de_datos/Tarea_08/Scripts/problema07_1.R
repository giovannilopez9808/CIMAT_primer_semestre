library(ggplot2)
library(tidyr)
data <- read.csv("../Data/data.csv")
print(summary(data))
print(var(data))
data$difference <- data$outer.lane - data$inner.lane
mu <- mean(data$difference)
ci <- t.test(
    x = data$difference,
    conf.level = 0.945
)$conf.int
print(ci)
data_long <- data %>% gather(lane, value, outer.lane:inner.lane)
theme_set(theme_classic())
ggplot(
    data_long,
    aes(value,
        fill = lane
    )
) +
    geom_density(alpha = 0.65) +
    xlab("Tiempo (s)") +
    ylab("Densidad") +
    scale_fill_manual(
        values = c(
            "#1a759f",
            "#76c893"
        ),
        name = "Carriles",
        labels = c(
            "Interior",
            "Exterior"
        )
    )
ggsave("problema07_histogram_2.png",
    height = 1000,
    width = 1200,
    limitsize = FALSE,
    units = "px"
)