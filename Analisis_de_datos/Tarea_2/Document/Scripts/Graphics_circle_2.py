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
             color=color,
             lw=3)
    plt.plot(x, -y,
             color=color,
             lw=3)
    plt.plot(-x, y,
             color=color,
             lw=3)
    plt.plot(-x, -y,
             color=color,
             lw=3)
    plt.plot([0, r], [0, 0],
             color="#000000",
             ls="--",
             lw=3)
    for i, x_i in enumerate(x):
        if i % 50 == 0:
            draw_line(r, r2, x_i)


def draw_line(r: float, r2: float, x: float):
    colors = {"y": "#d00000",
              "n": "#52b69a"}
    if abs(x) > r2:
        color = colors["y"]
    else:
        color = colors["n"]
    y = circle_function(r, x)
    plt.plot([x, x], [-y, y],
             color=color,
             lw=3)


parameters = {"path graphics": "../Graphics/",
              "graphics name": "circle_2.eps",
              "radius": 1,
              "radius 2": 1/2}
make_circle(parameters["radius"],
            parameters["radius 2"])
plt.tight_layout()
plt.savefig("{}{}".format(parameters["path graphics"],
                          parameters["graphics name"]))
