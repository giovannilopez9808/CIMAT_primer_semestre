import matplotlib.pyplot as plt
import numpy as np


def f(x):
    return x**2-4*x+10+2*np.sin(10*x)-5*np.cos(4*x)


x_data = np.linspace(0, 5, 18)
x_fun = np.linspace(0, 5, 200)
x, y = np.loadtxt("Output/output.txt",
                  unpack=True)
plt.subplots(figsize=(8, 4))
plt.xlim(x[0], x[-1])
plt.ylim(-2, 18)
plt.xticks(np.arange(0, 5.5, 0.5))
plt.yticks(np.arange(-2, 20, 2))
plt.plot(x, y,
         color="#3f37c9",
         label="Spline line")
plt.plot(x_fun, f(x_fun),
         color="#d00000",
         label="$f(x)$")
plt.scatter(x_data,
            f(x_data),
            c="#03071e",
            label="Input")
plt.legend(frameon=False,
           ncol=3)
plt.tight_layout()
plt.show()
# plt.savefig("../../Document/Graphics/problema3.png")
