# Algoritimo de busca de padroes sequencial. 
# Aula LFC 

# imports
import random

class BuscaPadroes():
	
	#tamanho do padrao a ser buscado
	tam_padrao = 5
	#inicializacao do padrao
	padrao = []
	#inicializacao do texto
	texto = []
	#contador
	contador = 0

	def __init__(self):
				


		#leitura do arquivo a ser buscado
		arquivo = open('Species1.fasta','r')
		while True:
			aux = arquivo.read(1)
			if aux == '':
				break
			if aux== '\n':
				pass
			else:
				self.texto.append(aux)

		arquivo.close()	

		aux2 = random.randint(11, len(self.texto) )
			
		for i in xrange(aux2,aux2+self.tam_padrao):
			self.padrao.append(self.texto[i])

		# print self.padrao
	#

	def verificaIgualdade(self, i):
		for x in xrange(0, self.tam_padrao):
			if self.texto[i+x] != self.padrao[x]:
				return False
		return True
	#

	def buscaSequencial(self):
		self.contador = 0
		i = 0
		b = BuscaPadroes()
		while i<len(self.texto):
			if b.verificaIgualdade(i):
				self.contador+=1
				print "contador ", self.contador
			i+=1
	#

	def boyerMoore(self):
		i =0
		while i<len(self.texto):
			if self.texto[self.tam_padrao]!= self.padrao[self.tam_padrao]:
				if calcBC()>calcGS():
					i+=calcBC()
				else:
					i+=calcGS()
			verificaIgualdadeBM()
				
		

	def verificaIgualdadeBM():
		pass

	def calcBC():
		pass

	def calcGS():
		pass

#
############EXECUCAO##############

b1 = BuscaPadroes()
b1.buscaSequencial()
print b1.contador
# print b1.padrao