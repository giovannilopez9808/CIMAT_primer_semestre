import matplotlib.pyplot as plt
import numpy as np


def f(x: float, parameters: list):
    a, b, c, d = parameters
    if (-1 <= x <= 0):
        return a*x**3+b*x**2+c*(x-1)
    if (0 < x <= 1):
        return d*(x-1)**2+c*x
    return


def obtain_parameters(a: float):
    return [a, (3*a-7)/2, -1, 0]


def write_parameters(ax: plt.subplot, parameters: list):
    ax.set_title("a={} b={} c={} d={}".format(parameters[0],
                                              parameters[1],
                                              parameters[2],
                                              parameters[3]))


def plot(dataset: dict, parameters: list):
    x = np.linspace(-1, 1, 100)
    y = [f(i, parameters) for i in x]
    dataset["ax"].plot(x, y,
                       lw=3,
                       color=dataset["color"])
    dataset["ax"].set_xlim(-1, 1)
    dataset["ax"].set_ylim(-4, 4)
    dataset["ax"].grid(ls="--",
                       color="#000000",
                       alpha=0.5)
    write_parameters(dataset["ax"],
                     parameters)


fig, axs = plt.subplots(2, 2,
                        figsize=(10, 6),
                        sharex=True,
                        sharey=True)
axs = np.reshape(axs, 4)
datasets = {0: {"a": -5,
                "ax": axs[0],
                "color": "#a01a58"},
            1: {"a": 0,
                "ax": axs[1],
                "color": "#723c70"},
            2: {"a": 5,
                "ax": axs[2],
                "color": "#2e6f95"},
            3: {"a": 10,
                "ax": axs[3],
                "color": "#0091ad"}
            }
a_list = [-5, -0, 5, 10]
for index in datasets:
    parameters = obtain_parameters(datasets[index]["a"])
    plot(datasets[index], parameters)
plt.tight_layout()
plt.savefig("../Graphics/problema02b.png")
