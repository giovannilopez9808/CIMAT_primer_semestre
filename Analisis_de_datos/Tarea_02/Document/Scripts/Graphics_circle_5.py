import matplotlib.pyplot as plt
import numpy as np


def circle_function(r: float, x: float):
    return np.sqrt(r**2-x**2)


def make_circle(r: float, color="#5e60ce"):
    x = np.linspace(0, r, 1000)
    y = circle_function(r, x)
    plt.axis("off")
    plt.plot(x, y,
             color=color)
    plt.plot(x, -y,
             color=color)
    plt.plot(-x, y,
             color=color)
    plt.plot(-x, -y,
             color=color)


def draw_lines(r: float, x: list):
    x = np.array(x)
    y = circle_function(r, x)
    for i in range(2):
        if np.random.random() > 0.5:
            y[i] = -y[i]
    len = obtain_line_lenght(x, y)
    color = obtain_color(len)
    plt.plot(x, y,
             color=color)


def obtain_color(len: float):
    colors = {"y": "#d00000",
              "n": "#52b69a"}
    if abs(len) < np.sqrt(3):
        return colors["y"]
    else:
        return colors["n"]


def obtain_line_lenght(x: list, y: list):
    x_len = (x[0]-x[1])**2
    y_len = (y[0]-y[1])**2
    return np.sqrt(x_len+y_len)


parameters = {"path graphics": "../Graphics/",
              "graphics name": "circle_4.eps",
              "radius": 1,
              "lines": 100
              }
plt.subplots(figsize=(6, 6))
make_circle(parameters["radius"])
x = np.linspace(-0.9, 1, parameters["lines"])
print(x)
for xi in x:
    x_list = [-1]
    x_list.append(xi)
    draw_lines(parameters["radius"],
               x_list)
plt.savefig("{}{}".format(parameters["path graphics"],
                          parameters["graphics name"]))
