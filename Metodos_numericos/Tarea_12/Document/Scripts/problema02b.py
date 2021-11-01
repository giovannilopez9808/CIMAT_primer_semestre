import matplotlib.pyplot as plt
import numpy as np


def f(x: float, parameters: list):
    a, b, c, d, e = parameters
    if (-1 <= x <= 0):
        return a*x**3+b*x**2+c*(x-1)
    if (0 < x <= 1):
        return d*(x-1)**2+e*x
    return


def plot(parameters: list):
    x = np.linspace(-1, 1, 100)
    y = [f(i, parameters) for i in x]
    plt.plot(x, y,
             lw=3,
             color="#780000")
    plt.xlim(-1, 1)
    plt.ylim(-4, 0)
    plt.grid(ls="--",
             color="#000000",
             alpha=0.5)


parameters = [1, -1, 1, -1, -1]
plt.subplots(figsize=(8, 4))
plot(parameters)
plt.tight_layout()
plt.savefig("../Graphics/problema02b.png")
