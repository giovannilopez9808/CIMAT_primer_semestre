import matplotlib.pyplot as plt
import numpy as np
parameters = {"path graphics": "Graphics/",
              "graphics name": "graphic.eps"
              }
values = np.linspace(0, 1, 11)
plt.fill_between(values,
                 values-0.1,
                 values+0.1,
                 color="#168aad")
plt.xticks(values)
plt.yticks(values)
plt.xlim(0, 1)
plt.ylim(0, 1)
plt.text(0.44,
         0.44,
         "A",
         color="#ffffff")
plt.grid(ls="--",
         color="#000000")
plt.savefig("{}{}".format(parameters["path graphics"],
                          parameters["graphics name"]),
            dpi=400)
