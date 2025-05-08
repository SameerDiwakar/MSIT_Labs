import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm

mean,std =5,2
data = np.random.normal(mean,std,1000)
normal_fit = norm(mean,std)
x = np.linspace(norm.ppf(0.001,mean,std),norm.ppf(0.99,mean,std),100)

plt.hist(data,bins = 30, density = True,alpha = 0.6,color ='g')
plt.plot(x,normal_fit.pdf(x))
plt.legend()
plt.show()