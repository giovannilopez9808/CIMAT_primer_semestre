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


def fill_circle(r: float, color="#64dfdf"):
    x = np.linspace(0, r, 1000)
    y = circle_function(r, x)
    plt.fill_between(x, -y, y,
                     color=color)
    plt.fill_between(-x, -y, y,
                     color=color)


def draw_lines(r: float, x: list):
    x = np.array(x)
    y = circle_function(r, x)
    for i in range(2):
        if np.random.random() > 0.5:
            y[i] = -y[i]
    x_mean = np.mean(x)
    y_mean = np.mean(y)
    len = obtain_line_lenght(x, y)
    color = obtain_color(len)
    plt.plot(x, y,
             color=color)
    plt.scatter(x_mean, y_mean,
                color="#000000")
    plt.text(x_mean*0.95, y_mean*0.95,
             "{:.3f}".format(len))


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
              "graphics name": "circle_3.eps",
              "radius": 1,
              "radius 2": 1/2,
              "lines": 5
              }
plt.subplots(figsize=(6, 6))
make_circle(parameters["radius"])
make_circle(parameters["radius 2"])
fill_circle(parameters["radius 2"])
for i in range(parameters["lines"]):
    x = [-np.random.random()]
    x.append(np.random.random())
    draw_lines(parameters["radius"],
               x)
plt.tight_layout()
plt.savefig("{}{}".format(parameters["path graphics"],
                          parameters["graphics name"]))
