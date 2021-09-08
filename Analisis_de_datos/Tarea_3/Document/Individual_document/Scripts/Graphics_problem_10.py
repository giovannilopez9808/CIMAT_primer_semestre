import matplotlib.pyplot as plt


def text(x, y, text):
    plt.text(x, y, text,
             fontsize=15,
             color="#f8f9fa")


img = plt.imread("../Graphics/problema_10.png")
plt.imshow(img)
plt.fill_between([0, 543], [454, 454],
                 color="grey",
                 alpha=0.3)
text(300, 445, "A")
text(285, 385, "B")
text(365, 388, "C")
text(291, 318, "D")
text(259, 245, "F")
text(441, 266, "E")
text(91, 146, "H")
text(136, 46, "J")
text(285, 180, "I")
text(420, 223, "G")
plt.axis("off")
plt.tight_layout()
plt.savefig("../Graphics/map.png", dpi=500)
