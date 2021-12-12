import matplotlib.pyplot as plt
import numpy as np
data = np.loadtxt("../Output/output.txt")
data = np.transpose(data)
x = np.linspace(0, 1, np.shape(data)[0])
y = np.linspace(0, 1, np.shape(data)[1])
x, y = np.meshgrid(y, y)
print(np.shape(x), np.shape(y))
fig, ax = plt.subplots(subplot_kw={"projection": "3d"})
ax.plot_surface(y, x, data)
plt.show()
