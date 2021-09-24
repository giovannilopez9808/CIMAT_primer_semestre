import matplotlib.pyplot as plt
import numpy as np


def point(x, y):
    plt.scatter(x, y, s=30, color="blue")


def line(x, y, color="#000000"):
    plt.plot(x, y, lw=2, color=color)


def text(x, y, text):
    plt.text(x, y, text, fontsize=20)


line([6.25, 10],
     [0, 0],
     color="#b5179e")
line([0, 0],
     [0, 5])
line([0, 6.25],
     [0, 0],
     color="#2d6a4f")
line([0, 6.25],
     [5, 0],
     color="#1a759f")
point(0, 0)
text(0.25, -0.5, "A")
text(-0.5, 5, "L")
text(6, -0.5, "C")
text(10, -0.5, "B")
text(3, -0.5, "x")
text(3, 3, "y=$\sqrt{x^2+25}$")
text(8, -0.5, "10-x")
point(0, 5)
point(6.25, 0)
point(10, 0)
plt.axis("off")
plt.savefig("../Graphics/problem1_graph.eps", dpi=400)
