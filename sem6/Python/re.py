import re

with open('sample.txt', 'r') as file:
    content = file.read()

emails = re.findall(r'\b[\w.-]+@[\w.-]+\.\w+\b', content)
print("Emails found: ", emails)

# 2. Find all instances of phone numbers
# Pattern matches: 3 digits - 3 digits - 4 digits (e.g., 123-456-7890)
phones = re.findall(r'\d{3}-\d{3}-\d{4}', content)
print("Phone numbers found: ", phones)

# 3. Find all instances of dates
# Pattern matches: 2 digits / 2 digits / 4 digits (e.g., 01/01/2024)
dates = re.findall(r'\d{2}/\d{2}/\d{4}', content)
print("Dates found: ", dates)
