import matplotlib.pyplot as plt
import numpy as np


def f(x: list):
    return (x*np.cos(x)*np.sin(x))/(x-np.sin(x))


parameters = {
    "path graphics": "../Graphics/",
    "graphics name": "limit.eps",
}
x1 = np.linspace(0.01, 1, 100)
x2 = np.linspace(-1, -0.01, 100)
y1 = f(x1)
y2 = f(x2)
plt.xlim(-1, 1)
plt.ylim(-100, 100)
plt.plot(x1, y1,
         color="#480ca8",
         lw=3)
plt.plot(x2, y2,
         color="#480ca8",
         lw=3)
plt.grid(ls="--",
         color="#000000")
plt.tight_layout()
plt.savefig("{}{}".format(parameters["path graphics"],
                          parameters["graphics name"]))
