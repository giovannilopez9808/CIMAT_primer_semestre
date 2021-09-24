import matplotlib.pyplot as plt
import numpy as np


def function_1(x):
    return -np.sin(x)+x*x+1


def function_2(x):
    return np.sin(x)-x*x+1


x = np.linspace(-1, 1, 1000)
y1 = function_1(x)
y2 = function_2(x)
y1_min = np.min(y1)
pos = np.where(y1_min == y1)[0][0]
x1_min = x[pos]
y2_max = np.max(y2)
pos = np.where(y2_max == y2)[0][0]
x2_max = x[pos]
plt.scatter(x1_min, y1_min,
            c="#b5179e",
            s=30)
plt.scatter(x2_max, y2_max,
            c="#2d6a4f",
            s=30)
plt.plot(x, y1,
         label="$f(x)=-sin(x)+x^2+1$",
         color="#6930c3",
         lw=3)
plt.plot(x, y2,
         label="$f(x)=sin(x)-x^2+1$",
         color="#48bfe3",
         lw=3)
plt.xlim(-1, 1)
plt.ylim(-1, 3)
plt.legend(frameon=False,
           fontsize=12,
           ncol=2,
           bbox_to_anchor=(1.05, 1.125))
plt.grid(ls="--",
         color="#000000")
plt.savefig("../Graphics/problem2.eps")
