lst = [[-4,-1,0,2,5],[1245,33,5,9, 1335]]

def interpolate(y,target,lst,divdiff,seconddivdiff):
    ans = y + (target-lower_bound)*divdiff[lower_bound] + (target-lower_bound)*(target - upper_bound)*seconddivdiff(lower_bound)
    
divdiff = []
seconddivdiff = [] 
for i in range(len(lst[0])):
    divdiff[i] = lst[i+1]-lst[i]
