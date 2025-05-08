import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import expon

lambda_values  = [0.5,1.0,1.5]

#data points for each lambda
x = np.linspace(0,5,1000)

for lam in lambda_values:
	y = expon.pdf(x,scale = 1/lam)
	plt.plot(x,y,label = f'Lambda= {lam}')

plt.title("Exponential distribution")
plt.xlabel('x')
plt.ylabel('Probability density function')
plt.legend()

plt.show()
