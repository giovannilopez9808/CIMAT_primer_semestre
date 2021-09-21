import matplotlib.pyplot as plt
import pandas as pd
parameters = {"file results": "results.csv",
              "file graphics": "heat_results.png"}
data = pd.read_csv(parameters["file results"])
plt.ylabel("Heat Value")
plt.xlabel("Elements number")
plt.plot(data["N"], data["Value"],
         ls="--",
         color="#7209b7")
plt.scatter(data["N"], data["Value"],
            c="#34a0a4",
            s=30)
plt.xlim(10, 210)
plt.xticks([i for i in range(10, 230, 20)])
plt.yticks([i/10 for i in range(150, 163, 1)])
plt.grid(ls="--",
         color="#000000",
         alpha=0.5)
plt.tight_layout()
plt.savefig(parameters["file graphics"],
            dpi=400)
plt.show()
