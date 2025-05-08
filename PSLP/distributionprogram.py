from numpy import random
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
sns.distplot(random.binomial(n=10,p=0.5,size = 1000),hist=True,kde=False)
plt.show()

sns.distplot(random.poisson(lam=2,size = 100),kde = False)
plt.show()

sns.distplot(np.random.normal(size = 1000),hist = False)
plt.show()

