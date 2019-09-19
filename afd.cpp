#include <iostream>
#include <cstring>

#define q0 0
#define q1 1
#define q2 2
#define q3 3
#define d0 4
#define d1 5
#define d3 6


using namespace std;

int main(int argc, char const *argv[])
{
	// definição das variaveis
	char cadeia[5];
	int currentState= q0;
	int finalState = q3;



	cout<<"insira a cadeia"<<endl;
	cin>> cadeia;
	// cout<<"->"<<currentState;
	for (int i= 0; i<strlen(cadeia);i++){
		// cout<<cadeia[i]<<endl;
		switch(currentState){
			case q0:
				if(cadeia[i]=='0'){
					currentState= d0;
				}else if(cadeia[i]=='1'){
					currentState= q1;
				}
			break;
			case q1:

				if(cadeia[i]=='0'){
					currentState= q2;
				}else if(cadeia[i]=='1'){
					currentState= d1;
				}
			break;
			case q2:

				if(cadeia[i]=='0'){
					currentState= q3;
				}else if(cadeia[i]=='1'){
					currentState= q2;
				}
			break;
			case q3:

				currentState= d3;
				
			break;
			case d0:

				currentState= d0;
			break;
			case d1:

				currentState= d1;
			break;
			case d3:

				currentState= d3;
			break;
		}
		// cout<<"->"<<currentState;
	}
	if (currentState==finalState)
	{
		cout<<"\ncadeia aceita"<<endl;
	}else{
		cout<<"\ncadeira recusada"<<endl;
	}

	return 0;
}