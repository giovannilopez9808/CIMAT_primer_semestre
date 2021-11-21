import matplotlib.pyplot as plt
import numpy as np
data = np.loadtxt("u.txt")
plt.imshow(data,
           aspect="auto",
           cmap="inferno")
plt.colorbar()
plt.show()
