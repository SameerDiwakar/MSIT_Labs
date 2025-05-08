import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import poisson

lam = 5
fit_lam = 5.037  
size = 1000

data = np.random.poisson(lam=lam, size=size)

unique_values, counts = np.unique(data, return_counts=True)
probabilities = counts / size  # Normalize to get probabilities

max_value = max(unique_values) + 1  # Extend range slightly for better visualization
x = np.arange(0, max_value + 1)
pmf = poisson.pmf(x, fit_lam)

plt.bar(unique_values, probabilities, alpha=0.7, label='Empirical Data')

plt.plot(x, pmf, 'ro', label=f'Poisson PMF (λ = {fit_lam})', markersize=8)

plt.xlabel('Number of events')
plt.ylabel('Probability')
plt.title(f'Poisson Distribution (λ = {lam}, size = {size})')
plt.legend()

plt.show()