import matplotlib.pyplot as plt
import numpy as np


def function_1(x: list):
    return x-2**(-x)


def function_2(x: list):
    return 2*np.cos(2*x)-(x+1)**2


def function_3(x: list):
    return (2-np.exp(x)+2*x)/3


def function_4(x: list):
    return (4*x-3)/(x**2-2*x)


def select_dataset(dataset: str):
    datasets = {"function 1": {"function": function_1,
                               "title": "$f(x)=x-2^{x}$",
                               "graphics name": "function_1.eps",
                               "x limit": [-4, 4],
                               "x ticks": 1},
                "function 2": {"function": function_2,
                               "title": "$f(x)=2xcos(2x)-(x+1)^2$",
                               "graphics name": "function_2.eps",
                               "x limit": [-4, 4],
                               "x ticks": 1},
                "function 2b": {"function": function_2,
                                "title": "$f(x)=2xcos(2x)-(x+1)^2$",
                                "graphics name": "function_2b.eps",
                                "x limit": [-1, 1],
                                "x ticks": 0.2},
                "function 3": {"function": function_3,
                               "title": "$f(x)=\\frac{2-e^x+2x}{3}$",
                               "graphics name": "function_3.eps",
                               "x limit": [0, 1],
                               "x ticks": 0.1},
                "function 4": {"function": function_4,
                               "title": "$f(x)=\\frac{4x-3}{x^2-2x}$",
                               "graphics name": "function_4.eps",
                               "x limit": [0.5, 1.5],
                               "x ticks": 0.1},
                }
    return datasets[dataset]


def define_xticks(dataset: dict):
    return np.arange(dataset["x limit"][0],
                     dataset["x limit"][1]+dataset["x ticks"],
                     dataset["x ticks"])


parameters = {"path graphics": "Graphics/",
              "dataset": "function 2b"
              }
dataset = select_dataset(parameters["dataset"])
x = np.linspace(dataset["x limit"][0],
                dataset["x limit"][1],
                1000)
y = dataset["function"](x)
plt.xlim(dataset["x limit"])
plt.plot(dataset["x limit"],
         [0, 0],
         color="#001d3d",
         lw=3)
plt.plot(x, y,
         label=dataset["title"],
         color="#00afb9",
         lw=3)
plt.xticks(define_xticks(dataset))
plt.legend(frameon=False,
           fontsize=14)
plt.savefig("{}{}".format(parameters["path graphics"],
                          dataset["graphics name"]),
            dpi=400)
plt.show()
