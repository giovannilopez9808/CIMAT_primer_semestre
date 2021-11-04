import matplotlib.pyplot as plt
from scipy.stats import norm
import pandas as pd
import numpy as np


def plot_lines(bins: list, ylim: list):
    for bin in bins:
        plt.plot([bin, bin], [ylim[0], ylim[-1]],
                 color="white")


def plot_confidence_bands(confidence_bands: list, ylim: list):
    if(len(confidence_bands) != 0):
        for band in confidence_bands:
            plt.plot([band, band],
                     [ylim[0], ylim[-1]],
                     lw=2,
                     color="#581845",
                     ls="--")


def plot(parameter: dict):
    confidence_bands = parameter["confidence bands"]
    n, bins, patches = plt.hist(parameter["data"],
                                bins=parameter["bins"],
                                color=parameter["color"])
    plot_lines(bins,
               parameter["ylim"])
    plot_confidence_bands(parameter["confidence bands"],
                          parameter["ylim"])
    plt.xlabel("Tiempo (s)")
    plt.ylabel("Frecuencia")
    plt.xlim(parameter["xlim"][0],
             parameter["xlim"][-1])
    plt.ylim(parameter["ylim"][0],
             parameter["ylim"][-1])
    plt.tight_layout()
    plt.savefig(parameter["graphics name"],
                dpi=300)
    plt.close()


data = pd.read_csv("output.csv")
parameters = {"Quick sort": {"data": data["time_quick"],
                             "graphics name": "quick_sort.png",
                             "bins": 100,
                             "xlim": [1.5, 1.8],
                             "ylim": [0, 20],
                             "color": "#b5179e",
                             "confidence bands": []},
              "Shell sort": {"data": data["time_shell"],
                             "graphics name": "shell_sort.png",
                             "bins": 100,
                             "xlim": [4.2, 6],
                             "ylim": [0, 25],
                             "color": "#3a0ca3",
                             "confidence bands": []},
              "Diff": {"data": data["time_shell"]-data["time_quick"],
                       "graphics name": "diff.png",
                       "bins": 100,
                       "xlim": [2.8, 3.6],
                       "ylim": [0, 25],
                       "color": "#b7094c",
                       "confidence bands": [2.927563, 2.997897]}
              }


plot(parameters["Quick sort"])
plot(parameters["Shell sort"])
plt.subplots(figsize=(10, 4))
plot(parameters["Diff"])
