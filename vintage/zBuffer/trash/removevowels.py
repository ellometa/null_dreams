import numpy as np
import matplotlib.pyplot as plt
a = np.array([[15,16,20,25,30,35,40,39,234,28,22,18],
                [14,17,21,26,31,36,38,37,33,27,21,17],
                [13,15,19,24,29,34,39,38,32,26,20,16]])
avgs = np.average(a, axis=1)
print(avgs)
plt.bar(range(1,13),a.mean(axis=0))
plt.show()
# plt.plot(a[0])
# plt.plot(a[1])
# plt.plot(a[2])
