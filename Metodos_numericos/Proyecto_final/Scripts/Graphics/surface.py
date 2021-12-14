import matplotlib.pyplot as plt
import numpy as np


def same_plot(ax: plt.axes):
    ax.view_init(26, 37)
    ax.set_xlim(0, 1)
    ax.set_ylim(0, 1)
    ax.set_zlim(0, 1)
    ax.xaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
    ax.yaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
    ax.zaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))


def obtain_xy(data: np.array):
    x = np.linspace(0, 1, np.shape(data)[0])
    y = np.linspace(0, 1, np.shape(data)[1])
    return x, y


def f1(x: np.array, y: np.array):
    z = np.exp(-np.pi**2*y)*np.sin(np.pi*x) + x*(1 - x) * np.sin(10*y)
    return z


parameters = {"path data": "../Output/",
              "path graphics": "Output/",
              "datasets": {"1": {
                  "function": f1,
                  "file data": "output.txt",
                  "file graphics": "surface.png"}
              }}

dataset = parameters["datasets"]["1"]
f = dataset["function"]
data = np.loadtxt("{}{}".format(parameters["path data"],
                                dataset["file data"]))
x, y = obtain_xy(data)
x, y = np.meshgrid(x, y)
z = f(x, y)
fig, (ax1, ax2) = plt.subplots(1, 2,
                               figsize=(10, 4),
                               subplot_kw={"projection": "3d"})
surf = ax1.plot_surface(x, y, z,
                        cmap="inferno")
ax2.plot_surface(x, y, data,
                 cmap="inferno")
same_plot(ax1)
same_plot(ax2)
fig.colorbar(surf,
             ax=ax2,
             shrink=0.5,
             aspect=13)
fig.tight_layout()
plt.savefig("{}{}".format(parameters["path graphics"],
                          dataset["file graphics"]),
            dpi=300)
