from pandas.core.frame import DataFrame
from scipy.integrate import quad
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


def f1(x: float) -> float:
    return np.exp(x)


def f2(x: float) -> float:
    return 1/(x*x+1)


def print_text(data: DataFrame) -> None:
    for index in data.index:
        value = data["diff"][index]
        plt.text(index*1.05, value, "{:.7f}".format(value))


parameters = {"path data": "Output/",
              "path graphics": "../../Document/Graphics/",
              "datasets": {"1": {"file data": "f1.csv",
                                 "y limits": [2.350, 2.356],
                                 "color": "#6a040f",
                                 "label": "$e^x$",
                                 "file graphics": "problema01_f1.png",
                                 "function": f1},
                           "2": {"file data": "f2.csv",
                                 "y limits": [1.565, 1.605],
                                 "color": "#6930c3",
                                 "label": "$\\frac{1}{x^2+1}$",
                                 "file graphics": "problema01_f2.png",
                                 "function": f2}}}

for function in parameters["datasets"]:
    dataset = parameters["datasets"][function]
    data = pd.read_csv("{}{}".format(parameters["path data"],
                                     dataset["file data"]),
                       index_col=0)
    result = quad(dataset["function"], -1, 1)[0]
    plt.subplots(figsize=(8, 3))
    plt.plot([data.index[0]-1,
              data.index[-1]+1],
             [result, result],
             lw=2,
             label="Valor exacto",
             ls="--")
    plt.plot(data.index, data["result"],
             marker="o",
             label=dataset["label"],
             color=dataset["color"])
    plt.ylim(dataset["y limits"][0],
             dataset["y limits"][1])
    plt.xlim(data.index[0]-1,
             data.index[-1]+1)
    plt.grid(ls="--",
             color="#000000",
             alpha=0.7)
    plt.legend(frameon=False,
               fontsize=13)
    plt.tight_layout()
    plt.savefig("{}{}".format(parameters["path graphics"],
                              dataset["file graphics"]))
    plt.clf()
