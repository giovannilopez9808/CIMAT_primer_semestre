import matplotlib.pyplot as plt
import numpy as np


def r(t):
    return np.exp(np.cos(t)-2*np.cos(4*t)+(np.sin(t/12))**5)


def xt(t):
    return r(t)*np.sin(t)


def yt(t):
    return r(t)*np.cos(t)


def create_points(t):
    x = xt(t)
    y = yt(t)
    return x, y


x, y = np.loadtxt("Output/output.txt",
                  unpack=True)
t_function = np.linspace(0, 2*np.pi, 1000)
x_function, y_function = create_points(t_function)
t_input = np.array([np.pi*i/12 for i in range(25)])
x_input, y_input = create_points(t_input)
plt.subplots(figsize=(8, 5))
plt.xlim(-12, 12)
plt.ylim(-4, 12)
plt.plot(x_input, y_input,
         label="Input points",
         color="#007200",
         ls="",
         marker=".")
plt.plot(x, y,
         color="#c1121f",
         label="Spline cubic",
         ls="--",
         marker=".")
plt.plot(x_function, y_function,
         color="#2196f3",
         label="$f\;(t)=(x(t),y(t))$",
         alpha=0.5)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(frameon=False,
           fontsize=14)
plt.tight_layout()
# plt.savefig("../../../Document/Graphics/problema04b.png",
#            dpi=300)
plt.show()
