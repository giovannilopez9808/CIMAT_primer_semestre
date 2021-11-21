import matplotlib.pyplot as plt
import numpy as np
data = np.loadtxt("u.txt")
data = np.transpose(data)
time = np.linspace(0, 1, 101)
plt.imshow(data,
           aspect="auto",
           cmap="inferno")
plt.colorbar()
plt.show()
