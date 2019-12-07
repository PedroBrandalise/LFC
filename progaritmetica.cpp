#include <iostream>

using namespace std;

void pa(int init, int q, int n){
	int i = 0;
	while (i < n){
		cout<<init<<endl;
		init = init + q;
		i=i+1;
	}

}

int main(){
	int init, q, n;
	cin>>init;
	cin>>q;
	cin>>n;


	pa(init, q, n);
	return 0;
}