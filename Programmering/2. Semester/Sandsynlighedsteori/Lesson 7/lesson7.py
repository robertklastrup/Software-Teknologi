import numpy as np
import matplotlib as plt


a = 0
b = 10
n = 100

x = np.random.uniform(a,b,n)

plt.hist(x, bins=10, edgecolor="black")
