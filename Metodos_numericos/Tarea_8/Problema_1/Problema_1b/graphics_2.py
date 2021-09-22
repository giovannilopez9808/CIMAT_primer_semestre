import matplotlib.pyplot as plt
import pandas as pd
parameters = {"file results": "results_2.csv",
              "file graphics": "heat_results_2.png"}
data = pd.read_csv(parameters["file results"])
plt.ylabel("Solución")
plt.xlabel("Número de elementos")
plt.plot(data["N"]+2, data["Value"],
         ls="--",
         color="#7209b7")
plt.scatter(data["N"], data["Value"],
            c="#34a0a4",
            s=30)
plt.xlim(10, 210)
plt.ylim(15, 15.2)
plt.xticks([i for i in range(10, 230, 20)])
plt.yticks([i/100 for i in range(1500, 1522, 2)])
plt.grid(ls="--",
         color="#000000",
         alpha=0.5)
plt.tight_layout()
plt.savefig(parameters["file graphics"],
            dpi=400)
plt.show()
