import matplotlib.pyplot as plt
import pandas as pd
parameters = {"file results": "results.csv",
              "file graphics": "heat_results.png"}
data = pd.read_csv("results.csv")
plt.ylabel("Heat Value")
plt.xlabel("Elements number")
plt.plot(data["N"], data["Value"],
         ls="--")
plt.scatter(data["N"], data["Value"])
plt.xticks([i for i in range(10, 110, 10)])
plt.yticks([i/10 for i in range(150, 164, 2)])
plt.grid(ls="--",
         color="#000000",
         alpha=0.5)
plt.tight_layout()
plt.show()
