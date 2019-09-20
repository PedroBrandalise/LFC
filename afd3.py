
#programa que le um arquivo e implementa um AFD
import re
import numpy as np


#leitura do arquivo a ser buscado
file = open('defAfd.txt','r')
nameAFD = file.readline()
numStates = int(file.readline())
file.read(4)

currentState = file.readline()
# print(currentState)


file.read(9) # pular o 'sigma = '
strg = file.readline()
strg = strg[:-2] #corta o '}' no final 
sigma =  strg.split(',')


file.read(5) # pular o 'F = '
strg = file.readline()
strg = strg[:-3] #corta o '}' no final 
final =  strg.split(',')
# print(final)

#cortar o delta
file.readline()

# delta = None
delta = [(re.findall(r"[\w']+", file.readline()))]
# print(delta)
for linha in file:
	delta.append( re.findall(r"[\w']+", linha))

# print (delta[0])



file.close()	
