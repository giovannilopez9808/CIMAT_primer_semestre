import matplotlib.pyplot as plt
import numpy as np


def f(x: float or list):
    return np.sin(x)


def plot_function(ax: plt.subplot, x: list):
    ax.plot(x, f(x), color="#000000")
    ax.set_xlim(0, np.pi/2)
    ax.set_ylim(0, 1)


def plot_rectangule(ax: plt.subplot, x: float, fx: float, dx: float, color: str, color_line: str, title: str):
    ax.plot([x-dx, x],
            [fx, fx],
            color=color)
    ax.plot([x-dx, x-dx],
            [0, fx],
            color=color_line,
            ls="--")
    ax.plot([x, x],
            [0, fx],
            color=color_line,
            ls="--")
    ax.fill_between([x-dx, x],
                    [fx, fx],
                    color=color)
    ax.set_title(title)


parameters = {
    "path graphics": "../Graphics/",
    "graphics name": "integration.eps",
    "x limits": [0, np.pi/2],
    "n": 10,
}
dx = (parameters["x limits"][1]-parameters["x limits"][0]) / \
    parameters["n"]
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 4))
x = np.linspace(parameters["x limits"][0],
                parameters["x limits"][1],
                1000)
plot_function(ax1, x)
plot_function(ax2, x)
title_str = "$ \int_{0}^{ \pi /2} f(x) = $"
ifxl = 0
ifxr = 0
for i in range(parameters["n"]):
    xr = parameters["x limits"][0]+(i+1)*dx
    xl = parameters["x limits"][0]+i*dx
    ifxl += f(xl)*dx
    ifxr += f(xr)*dx
    plot_rectangule(ax1,
                    xl,
                    f(xl),
                    -dx,
                    "#387b86",
                    "#67c0b1",
                    title_str+"{:.6f}".format(ifxl))
    plot_rectangule(ax2,
                    xr,
                    f(xr),
                    dx,
                    "#387b86",
                    "#67c0b1",
                    title_str+"{:.6f}".format(ifxr))
print(ifxl, ifxr)
plt.savefig("{}{}".format(parameters["path graphics"],
                          parameters["graphics name"]))
