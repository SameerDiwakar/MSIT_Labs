# Insertion
1. If F = 0 & R = N, or F = (R + 1 )%SIZEthen Overflow 
2. IF F = -1 , SET F = R = 0
   else if r = n , set r = 1
   else r = r+1
3. SET Queue[R] = item

# Deletion
1. If F = -1 , underflow
2. SET ITEM = Queue[F]
3. If F=R , set F=R = -1
 Else if F = N then SET F=1
 Else F= F+1