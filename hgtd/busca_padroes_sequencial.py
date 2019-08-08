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
		b = BuscaPadroes()
		i =0
		while i<len(self.texto)-self.tam_padrao-1:
			# print 'oi'	
			for j in xrange(self.tam_padrao-1,-1, -1):
				# print j ,'------'
				# print self.texto[i+j]
				# print self.padrao[j]
				if(self.padrao[j]!=self.texto[i+j]):
					i+=b.calcBC(self.texto[i+j], j)
					# print 'mismatch'
					break
				elif (j==0 ): #significa que nao ocorreu incopatibilidade
					self.contador+=1
					# print 'contador --->', self.contador
					i+=1
			i+=1
			# print 'i ---> ', len(self.texto)


	#			

	#pular os caracteres ate q a incompatibilidade virar compatibilidade
	def calcBC(self, c, j):
		for i in xrange(j,0, -1):
			if c==self.padrao[i]:
				return j-i
		return j
	#

	def calcGS():
		pass
	#
#
############EXECUCAO##############

b1 = BuscaPadroes()
# b1.buscaSequencial()
b1.boyerMoore()
print b1.contador
# print b1.padrao