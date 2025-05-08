import numpy as np
from scipy.optimize import linprog

C = [-2,-3,-4]
A = [(1,2,3),(2,4,3)]
b = [30,45]
x0_bounds = (0,None)
x1_bounds = (0,None)
x2_bounds = (0,None)

res = linprog(C,A_ub = A,b_ub = b,bounds = [x0_bounds,x1_bounds,x2_bounds])

print("Optimal value" + str(res.fun))
print("Optimal Solution" + str(res.x))
