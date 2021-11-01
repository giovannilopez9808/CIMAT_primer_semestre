import matplotlib.pyplot as plt
import numpy as np


def f(x):
    return x/(1+x**2)


def create_points():
    x = np.array([(i-8)/2 for i in range(17)])
    y = f(x)
    return x, y


x, y = np.loadtxt("Output/output.txt",
                  unpack=True)
x_function = np.linspace(-4, 4, 1000)
y_function = f(x_function)
x_input, y_input = create_points()
plt.subplots(figsize=(8, 5))
plt.xlim(-4, 4)
plt.ylim(-0.6, 0.6)
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
         label="$f\;(x)=\\dfrac{x}{1+x^2}$",
         alpha=0.5)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(frameon=False,
           fontsize=14)
plt.tight_layout()
plt.savefig("../../../Document/Graphics/problema04a.png",
            dpi=600)
