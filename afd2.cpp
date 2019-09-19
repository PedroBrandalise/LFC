#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

#define q0 0
#define d0 1

bool acceptanceFunction(string c);


int main(int argc, char const *argv[]){

	ifstream myfile;
	myfile.open("entrada1.txt");
	string line;
	getline (myfile,line);
	cout<<line<<endl;
	string cadeia[10];


	// transferindo a linha para um vetor
	string buffer;
	buffer.clear();
	
	// j é o tamanho da cadeia - 1
	int j =0;

	for (int i = 0 ; i < line.length() ; ++i){
		if(line[i]!= ',') {
			buffer+=(line[i]);
		}
		if(line[i]==','){
			cadeia[j] =buffer;
			j++;
			// cout<<buffer<<endl;
			buffer.clear() ;
		}
	}
	cadeia[j] =buffer;


	
	int currentState = q0;
	int finalState = q0;

	// cout<<"dsadsa \n";

	cout<<"->"<<currentState;
	for(int i=0;i<j+1;i++){
		// cout<<cadeia[i]<<endl;
		switch(currentState){
			case q0:
				if (acceptanceFunction(cadeia[i])){
					currentState = q0;
				}
				else{
					currentState = d0;

				}		
			break;
			case d0:

			break;
		}
		cout<<"->"<<currentState;
	}

	if (currentState==finalState)
	{
		cout<<"\ncadeia aceita"<<endl;
	}else{
		cout<<"\ncadeira recusada"<<endl;
	}


	// cout<< 
	acceptanceFunction("1");
	// <<endl<<endl;
	return 0;
}


//basicamente a função verifica se existe algum caracter na
// string que nao seja numeral ou ponto
// ¬¬' deve ter alguma função que ve isso ja   >:o 
bool acceptanceFunction(string c){
	for (int i = 0; i < c.length(); ++i)
	{
			

		if (
			c[i] != '0' &&
			c[i] != '1' &&
			c[i] != '2' &&
			c[i] != '3' &&
			c[i] != '4' &&
			c[i] != '5' &&
			c[i] != '6' &&
			c[i] != '7' &&
			c[i] != '8' &&
			c[i] != '9' &&
			c[i] != '0' &&
			c[i] != '.' 
			)
		{
			return false;
		}
	}
	return true;

}