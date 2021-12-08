import matplotlib.pyplot as plt
import numpy as np
data = np.loadtxt("../Output/output.txt")
data = np.transpose(data)
plt.imshow(data,
           aspect="auto",
           cmap="inferno",
           interpolation="nearest")
plt.colorbar()
plt.tight_layout()
plt.show()
