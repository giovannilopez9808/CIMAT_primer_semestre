import matplotlib.pyplot as plt
from pylab import *
import numpy as np


def pn(x, n):
    if n == 0:
        return 1
    if n == 1:
        return x
    return ((2*n-1)*x*pn(x, n-1)-(n-1)*pn(x, n-2))/n


x = np.linspace(-1, 1, 1000)
plt.subplots(figsize=(8, 3))
colors = ["#7400b8",
          "#5390d9",
          "#6a040f",
          "#e85d04",
          "#ffba08",
          "#40916c",
          "#72efdd",
          "#f15bb5"]
for i in range(2, 8):
    roots = np.loadtxt("Output/{}.csv".format(i),
                       usecols=2,
                       skiprows=1,
                       delimiter=",")
    y = [pn(xi, i) for xi in x]
    plt.plot(x, y,
             label="$P_{}(x)$".format(i),
             color=colors[i-2])
    for root in roots:
        plt.scatter(root, 0, c=colors[i-2])
plt.plot([-1, 1], [0, 0],
         color="#000000",
         ls="--")
plt.ylim(-1, 1)
plt.xlim(-1, 1)
plt.tight_layout()
plt.legend(frameon=False,
           ncol=3)
plt.savefig("../../Document/Graphics/problema2.png",
            dpi=400)
