import matplotlib.pyplot as plt
n = 4
n_test = 100
xi = [0.1, 0.2, 0.3, 0.4]
fi = [1.45, 1.8, 1.7, 2.0]
a = [0 for i in range(n-1)]
b = [0 for i in range(n-1)]
for i in range(n-1):
    a[i] = (fi[i+1]-fi[i])/(xi[i+1]-xi[i])
    b[i] = fi[i]-a[i]*xi[i]

x_test = [xi[0]+i*(xi[-1]-xi[0])/n_test for i in range(n_test)]
y_test = [0 for i in range(n_test)]

for i in range(n_test):
    for j in range(n-1):
        if(x_test[i] >= xi[j] and x_test[i] <= xi[j+1]):
            y_test[i] = a[j]*x_test[i]+b[j]
plt.subplots(figsize=(8, 4))
plt.xlim(xi[0], xi[-1])
plt.plot(x_test, y_test, color="#4895ef")
plt.scatter(xi, fi, c="#560bad")
plt.tight_layout()
plt.savefig("../../Document/Graphics/problema3.png")
