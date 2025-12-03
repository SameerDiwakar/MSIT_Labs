Linear_search(A,key):
	for (i<-0 to length(A) - 1
		if A[i] = key
			return i
		return -1


Complexity: Best : O1
W : O(n)
av space O 1

Binary_Search(A,key)
	low<-0
	high<-lenght(A)-1
	while(low<=high)
		mid<- (low+high)/2
		if A[mid] = key
			return mid
		else if A[mid] < key
			return low<-mid+1
		else
			high<-mid-1
	return -1


		 
