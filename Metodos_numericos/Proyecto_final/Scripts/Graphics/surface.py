import matplotlib.pyplot as plt
import numpy as np
data = np.loadtxt("../Output/output.txt")
# data = np.transpose(data)
x = np.linspace(0, 1, np.shape(data)[0])
y = np.linspace(0, 1, np.shape(data)[1])
x, y = np.meshgrid(y, y)
z = np.exp(-np.pi**2*y)*np.sin(np.pi*x) + x*(1 - x) * np.sin(10*y)
fig, ax = plt.subplots(subplot_kw={"projection": "3d"})
ax.plot_surface(x, y, z)
ax.plot_surface(x, y, data,
                cmap="inferno")
plt.show()
