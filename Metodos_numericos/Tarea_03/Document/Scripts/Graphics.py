import matplotlib.pyplot as plt
import numpy as np


def f(x: list):
    return (x*np.cos(x)-np.sin(x))/(x-np.sin(x))


parameters = {
    "path graphics": "../Graphics/",
    "graphics name": "limit.eps",
}
x = np.linspace(-1, 1, 100)
y = f(x)
plt.xlim(-1, 1)
plt.ylim(-2.1, -1.9)
plt.plot(x, y,
         color="#480ca8",
         lw=3)
plt.grid(ls="--",
         color="#000000")
plt.tight_layout()
plt.savefig("{}{}".format(parameters["path graphics"],
                          parameters["graphics name"]))
