import matplotlib.pyplot as plt
import numpy as np


def f(x):
    return x/(1+x**2)


x, y = np.loadtxt("output.txt",
                  unpack=True)
y_data = f(x)
plt.xlim(-4, 4)
plt.ylim(-0.6, 0.6)
plt.plot(x, y,
         color="#370617",
         label="Spline cubic",
         ls="--",
         marker=".")
plt.plot(x, y_data,
         color="#f48c06",
         label="$f\;(x)=\\dfrac{x}{1+x^2}$",
         marker=".",
         alpha=0.5)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(frameon=False,
           fontsize=14)
plt.tight_layout()
plt.show()
