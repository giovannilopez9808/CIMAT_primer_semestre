import matplotlib.pyplot as plt
import numpy as np


def pn(x, n):
    if n == 0:
        return 1
    if n == 1:
        return x
    return ((2*n-1)*x*pn(x, n-1)-(n-1)*pn(x, n-2))/n


x = np.linspace(-1, 1, 1000)
for i in range(2, 6):
    roots = np.loadtxt("Output/{}.csv".format(i),
                       usecols=2,
                       skiprows=1,
                       delimiter=",")
    y = [pn(xi, i) for xi in x]
    plt.plot(x, y,
             label="$P_{}(x)$".format(i))
    for root in roots:
        plt.scatter(root, 0, c="#000000")
plt.legend(frameon=False,
           ncol=2)
plt.savefig("../../Document/Graphics/problema2.png",
            dpi=400)
