import numpy as np
import matplotlib.pyplot as plt
import math

mean, var = 5, 2
n = mean * (1 - var / mean)
p = 1 - (var / mean)

n = int(round(8))
x = np.arange(0, n + 1)
pmf_values = [math.comb(n, k) * (p ** k) * ((1 - p) ** (n - k)) for k in x]

plt.bar(x, pmf_values, label='Binomial pmf')
plt.legend()
plt.show()
