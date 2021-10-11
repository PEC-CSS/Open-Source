import string
import random

s = input()
s = '!'+s+'!'
alplist = list(string.ascii_lowercase)
finalstr = ''
for i in range(0,len(s)):
	if s[i] == "?":
		z = random.choice(alplist)
		while z==s[i-1] or z==s[i+1]:
			z = random(alplist)
		finalstr+=z
	else:
		finalstr+=s[i]

finalstr = finalstr[1:len(finalstr)-1]
print(finalstr)