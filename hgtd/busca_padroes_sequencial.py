# Algoritimo de busca de padroes sequencial. 
# Aula LFC 

# imports
import random

#tamanho do padrao a ser buscado
tam_padrao = 5

#contador

#leitura do arquivo a ser buscado
arquivo = open('Species1.fasta','r')
texto = []
while True:
	aux = arquivo.read(1)
	if aux == '':
		break
	if aux== '\n':
		pass
	else:
		texto.append(aux)

arquivo.close()	

# print texto

# print len(texto)

padrao = []


aux2 = random.randint(11, len(texto) )
	
for i in xrange(aux2,aux2+tam_padrao):
	padrao.append(texto[i])

print padrao

i = 0
while i<len(texto):
	if texto[i] == padrao[0]:
		for x in xrange(1,tam_padrao):
			if texto[i+x] !=padrao[x]:
				break

	else:
		i+=1

	

