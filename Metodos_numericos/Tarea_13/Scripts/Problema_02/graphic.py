import matplotlib.pyplot as plt
import numpy as np


def pn(x, n):
    if n == 0:
        return 1
    if n == 1:
        return x
    return ((2*n-1)*x*pn(x, n-1)-(n-1)*pn(x, n-2))/n


x = np.linspace(-1, 1, 1000)
for i in range(5):
    y = [pn(xi, i) for xi in x]
    plt.plot(x, y)
plt.show()
