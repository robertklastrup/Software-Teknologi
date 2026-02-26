import numpy as np
import matplotlib.pyplot as plt
v=np.array([[1,2],[2,2],[4,3]])
#Your code
origin=np.array([[0,0],[0,0],[0,0]])


plt.grid(True)
plt.axis('equal')
ax = plt.gca()
ax.set_aspect('equal', adjustable='box')
ax.spines['left'].set_position('zero')  # y-axis through x=0
ax.spines['bottom'].set_position('zero')  # x-axis through y=0
plt.xlim(-1, 5)
plt.ylim(-1, 4)
plt.scatter(v[:,0], v[:,1],color='red')