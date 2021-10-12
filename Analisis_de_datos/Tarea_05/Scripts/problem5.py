import matplotlib.pyplot as plt
import numpy as np


def normal_distribution(x, mu, sigma):
    up = np.exp(-(x-mu)**2/(2*sigma**2))
    down = sigma*np.sqrt(2*np.pi)
    return up/down


def solve(mu1, mu2, sigma1, sigma2):
    a = sigma1**2-sigma2**2
    b = 2*(mu1*sigma2**2-mu2*sigma1**2)
    c = sigma1**2*mu2**2-sigma2**2*mu1**2-2 * \
        sigma1**2*sigma2**2*np.log(sigma1/sigma2)
    ans = np.sqrt(b**2-4*a*c)
    print((ans-b)/(2*a))
    x = (-ans-b)/(2*a)
    print(x)
    return x


sigma1 = 1
sigma2 = np.sqrt(2)
mu1 = 2
mu2 = 4
x_inter = solve(mu1, mu2, sigma1, sigma2)
x_inter = np.linspace(0, x_inter, 1000)
y_inter = normal_distribution(x_inter, mu2, sigma2)
x1 = np.linspace(0, 6, 1000)
x2 = np.linspace(0, 8, 1000)
y1 = normal_distribution(x1, mu1, sigma1)
y2 = normal_distribution(x2, mu2, sigma2)
plt.fill_between(x_inter, y_inter,
                 color="#480ca8")
plt.plot(x1, y1, color="#b5179e",
         label="$\mu = {}$ $\sigma^2 = {} $".format(mu1, sigma1**2))
plt.plot(x2, y2, color="#4361ee",
         label="$\mu = {}$ $\sigma^2 = {:.0f} $".format(mu2, sigma2**2))
plt.yticks(np.arange(0, 0.55, 0.05))
plt.xticks(np.arange(0, 8.5, 0.5))
plt.ylim(0, 0.5)
plt.xlim(0, 8)
plt.grid(ls="--",
         color="#000000",
         alpha=0.5)
plt.legend(frameon=False,
           fontsize=14)
plt.tight_layout()
plt.savefig("../Document/Graphics/problem5.png")
