import matplotlib.pyplot as plt
import numpy as np


def obtain_relative_difference(data1: np.array, data2: np.array):
    n, m = np.shape(data1)
    diff = 0
    l = 0
    for i in range(n):
        for j in range(m):
            i1 = data1[i, j]
            i2 = data2[i, j]
            diff += np.abs((i1-i2)/max(i2, 1))
            l += 1
    return 100*diff/l


def same_plot(ax: plt.axes, xlim: float):
    ax.set_ylabel("Tiempo")
    ax.set_xlabel("Posición")
    ax.view_init(26, 37)
    ax.set_xlim(0, xlim)
    ax.set_ylim(0, 1)
    ax.set_zlim(0, 1)
    ax.xaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
    ax.yaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))
    ax.zaxis.set_pane_color((1.0, 1.0, 1.0, 0.0))


def obtain_xy(data: np.array, xlim: float):
    x = np.linspace(0, xlim, np.shape(data)[0])
    y = np.linspace(0, 1, np.shape(data)[1])
    return x, y


def f3(x: np.array, y: np.array):
    z = np.exp(-np.pi**2*y)*np.sin(np.pi*x) + x*(1 - x) * np.sin(10*y)
    return z


def f2(x: np.array, y: np.array):
    z = np.exp(-y)*np.sin(np.pi*x)
    return z


def f1(x: np.array, y: np.array):
    z = np.exp(-np.pi**2*y)*np.sin(np.pi*x)
    return z


def f4(x: np.array, y: np.array):
    z = (np.exp(y)-np.exp(-4*y))*np.sin(x)/5
    return z


parameters = {"path data": "../Output/",
              "path graphics": "Output/",
              "datasets": {
                  "1": {"function": f1,
                        "xlim": 1,
                        "file data": "output_1.txt",
                        "file graphics": "surface_1.png"},
                  "2": {"function": f2,
                        "xlim": 1,
                        "file data": "output_2.txt",
                        "file graphics": "surface_2.png"},
                  "3": {"function": f3,
                        "xlim": 1,
                        "file data": "output_3.txt",
                        "file graphics": "surface_3.png"},
                  "4": {"function": f4,
                        "xlim": np.pi,
                        "file data": "output_4.txt",
                        "file graphics": "surface_4.png"}
              }}

dataset = parameters["datasets"]["4"]
f = dataset["function"]
data = np.loadtxt("{}{}".format(parameters["path data"],
                                dataset["file data"]))
x, y = obtain_xy(data, dataset["xlim"])
x, y = np.meshgrid(x, y)
z = f(x, y)
fig, (ax1, ax2) = plt.subplots(1, 2,
                               figsize=(10, 4),
                               subplot_kw={"projection": "3d"})
surf = ax1.plot_surface(x, y, z,
                        cmap="inferno")
ax2.plot_surface(x, y, data,
                 cmap="inferno")
ax1.set_title("Solución análitica")
ax2.set_title("Solución numérica")
same_plot(ax1, dataset["xlim"])
same_plot(ax2, dataset["xlim"])
fig.colorbar(surf,
             ax=ax2,
             shrink=0.5,
             aspect=13)
fig.tight_layout()
plt.savefig("{}{}".format(parameters["path graphics"],
                          dataset["file graphics"]),
            dpi=300)
print("La diferencia relativa en el dataset es:")
print(obtain_relative_difference(data, z))
