from pandas.core.frame import DataFrame
from scipy.integrate import quad
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


def f1(x: float) -> float:
    return x*np.cos(x)


def f2(x: float) -> float:
    return x*np.exp(-x)


def plot(data: DataFrame, label: str, limits: str, result: float, dataset: dict, path: str, name: str) -> None:
    plt.subplots(figsize=(8, 3))
    plt.plot([data.index[0]-1,
              data.index[-1]+1],
             [result, result],
             lw=2,
             label="Valor exacto",
             ls="--")
    plt.plot(data.index, data[label],
             marker="o",
             label=dataset["label"],
             color=dataset["color"])
    plt.ylim(dataset[limits][0],
             dataset[limits][1])
    plt.xlim(data.index[0]-1,
             data.index[-1]+1)
    plt.xticks(data.index)
    plt.legend(frameon=False,
               fontsize=13)
    plt.tight_layout()
    plt.grid(ls="--",
             color="#000000",
             alpha=0.5)
    plt.savefig("{}{}".format(path,
                              dataset[name]))
    plt.clf()
    plt.close()


parameters = {"path data": "Output/",
              "path graphics": "../../Document/Graphics/",
              "datasets": {"1": {"file data": "f1.csv",
                                 "x limits": [0, np.pi],
                                 "y limits fun": [-2.3, -1.9],
                                 "y limits diff": [-0.1, 0.25],
                                 "color": "#6a040f",
                                 "label": "$xcos(x)$",
                                 "file graphics fun": "problema03_fun_f1.png",
                                 "file graphics diff": "problema03_diff_f1.png",
                                 "function": f1},
                           "2": {"file data": "f2.csv",
                                 "x limits": [-1, 0],
                                 "y limits fun": [-1.02, -0.98],
                                 "y limits diff": [-0.01, 0.015],
                                 "color": "#6930c3",
                                 "label": "$xe^{-x}$",
                                 "file graphics fun": "problema03_fun_f2.png",
                                 "file graphics diff": "problema03_diff_f2.png",
                                 "function": f2}}}

for function in parameters["datasets"]:
    dataset = parameters["datasets"][function]
    data = pd.read_csv("{}{}".format(parameters["path data"],
                                     dataset["file data"]),
                       index_col=0)
    result = quad(dataset["function"],
                  dataset["x limits"][0],
                  dataset["x limits"][1])[0]
    data["diff"] = data["result"]-result
    data["diff"] = data["diff"].abs()
    print(data)
    plot(data,
         "result",
         "y limits fun",
         result,
         dataset,
         parameters["path graphics"],
         "file graphics fun")
    result = 0
    plot(data,
         "diff",
         "y limits diff",
         result,
         dataset,
         parameters["path graphics"],
         "file graphics diff")
