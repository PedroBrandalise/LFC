
#include <iostream>
#include <cstring>


using namespace std;
int main(int argc, char const *argv[])
{
	// definição das variaveis
	char cadeia[5];
	int currentState= 2
;
	int finalState = 1;

	cout<<"insira a cadeia"<<endl;
	cin>> cadeia;

for (int i= 0; i<strlen(cadeia);i++){
	switch(currentState){

	case 0:
		if(cadeia[i] == '0' ){
 			currentState= 0;
		}
		if(cadeia[i] == '1' ){
 			currentState= 0;
		}
	break;
	case 1:
		if(cadeia[i] == '0' ){
 			currentState= 0;
		}
		if(cadeia[i] == '1' ){
 			currentState= 0;
		}
	break;
	case 2:
		if(cadeia[i] == '0' ){
 			currentState= 0;
		}
		if(cadeia[i] == '1' ){
 			currentState= 1;
		}
	break;

	}
}
if (currentState==finalState)
	{
		cout<<"\ncadeia aceita"<<endl;
	}else{
		cout<<"\ncadeira recusada"<<endl;
	}

	return 0;
}
