
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

# print (len(delta))
numAlf = len(delta)/numStates
# print (numAlf,'vfdsvdf\n\n')

file.close()	
# afd = ''
afd = '''
for (int i= 0; i<strlen(cadeia);i++){
	switch(currentState){

'''

for i in range(0,numStates):
	afd +='\tcase '+delta[i*int(numAlf)][0]+''':\n'''
	for j in range(0,int(numAlf)):
		afd +='\t\tif(cadeia[i] == \''+delta[i*int(numAlf)+j][1]+ '\' ){\n \t\t\tcurrentState= '+delta[i*int(numAlf)+j][2]+';\n\t\t}\n'

	afd +='''\tbreak;\n'''	

afd +='\n\t}\n}'
# print (afd)

afdPre='''
#include <iostream>
#include <cstring>


using namespace std;
int main(int argc, char const *argv[])
{
	// definição das variaveis
	char cadeia[5];
	int currentState= '''+currentState +''';
	int finalState = '''+final[0]+''';

	cout<<"insira a cadeia"<<endl;
	cin>> cadeia;
'''

afdPos = '''
if (currentState==finalState)
	{
		cout<<"\\ncadeia aceita"<<endl;
	}else{
		cout<<"\\ncadeira recusada"<<endl;
	}

	return 0;
}
'''
afdFinal = afdPre+afd+afdPos
teste = open('afd3C.cpp','w')
teste.write(afdFinal)
teste.close