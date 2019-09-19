import re

def exercicio1a():
	txt = ["wp","wzp","wzzzp"]

	for i in range(0,len(txt)):
		
		x = re.fullmatch("^wz*p$", txt[i])

		if (x):
		  print("YES! We have a match!")
		else:
		  print("No match")

def exercicio1b():
	txt = ["aabbcc","cba","cab"]

	for i in range(0,len(txt)):

		x = re.fullmatch("c*b*a*", txt[i])
		print (txt[i])
		if (x):
			print("YES! We have a match!")
		else:
			print("No match")


def exercicio1c():
	txt = ["bbccaa","ba","cab"]

	for i in range(0,len(txt)):

		x = re.fullmatch("c*b*c*a*c*", txt[i])
		print (txt[i])
		if (x):
			print("YES! We have a match!")
		else:
			print("No match")

def exercicio1d():
	txt = ["bbccaa","ba","abababab"]

	for i in range(0,len(txt)):

		x = re.fullmatch("((ab)*|(ba))*|(a|b)", txt[i])
		print (txt[i])
		if (x):
			print("YES! We have a match!")
		else:
			print("No match")


exercicio1d()

