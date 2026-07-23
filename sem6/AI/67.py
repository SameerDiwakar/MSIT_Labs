str1 = "Hi My name is not nigga"
str2 = str1.split()
str3 = " ".join(sorted(str2))
print(str3)

#7
str4 = "The cat, which was very fluffy, sat on the mat."
for i in str4:
	if i.isalnum() or i == " ":
		print(i,end = "")
