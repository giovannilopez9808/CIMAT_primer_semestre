import matplotlib.pyplot as plt
import numpy as np


def circle_function(r: float, x: float):
    return np.sqrt(r**2-x**2)


def make_circle(r: float, r2: float, color="#5e60ce"):
    x = np.linspace(0, r, 1000)
    y = circle_function(r, x)
    plt.subplots(figsize=(6, 6))
    plt.axis("off")
    plt.plot(x, y,
             color=color)
    plt.plot(x, -y,
             color=color)
    plt.plot(-x, y,
             color=color)
    plt.plot(-x, -y,
             color=color)
    fill_circle(r, r2)
    plot_axis(r)


def fill_circle(r: float, r2: float, color="#64dfdf"):
    x = np.linspace(0, r2, 1000)
    y = circle_function(r, x)
    plt.fill_between(x, y,
                     color=color)
    plt.fill_between(x, -y,
                     color=color)
    plt.fill_between(-x, y,
                     color=color)
    plt.fill_between(-x, -y,
                     color=color)


def plot_axis(r: float, color="#5e60ce"):
    plt.plot([0, 0], [-r, r],
             color=color,
             lw=2)
    plt.plot([-r, r], [0, 0],
             color=color,
             lw=2)


parameters = {"path graphics": "../Graphics/",
              "graphics name": "circle_1.eps",
              "radius": 1,
              "radius 2": 1/2}
make_circle(parameters["radius"],
            parameters["radius 2"])
plt.tight_layout()
plt.savefig("{}{}".format(parameters["path graphics"],
                          parameters["graphics name"]))
