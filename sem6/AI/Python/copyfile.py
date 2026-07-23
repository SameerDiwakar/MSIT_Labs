
with open("source.txt",'r') as source, open('destination.txt','w') as dest:
	for line in source:
		dest.write(line)


print("Done!")
