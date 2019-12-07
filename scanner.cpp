#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void arquivoSaida(string arquivo, string valor, string token){
    ofstream inFile;
    inFile.open(arquivo, ios::app);
    inFile << "<" << valor << ", " << token << ">" << endl;
    inFile.close();
}

bool comparaKeyword(string a){
    if(a == "if"|| a == "else" || a == "read" || a == "write" || a == "int" || a == "float" || a == "void"){
        return true;
    }
    else{
        return false;
    }

}
bool comparaOperador(string a){
    if(a == "+"|| a == "-" || a == "/" || a == "*" || a == "<"|| a == ">" || a == "=" || a == "=="|| a == ")" || a == "(" || a == ";" || a == "{" || a == "}"){
        return true;
    }
    else{
        return false;
    }


}
bool comparaString(string a){
    int flag = 0;
    for (unsigned i=0; i<a.length(); ++i)
    {
        char c;
        c =  a.at(i);

        if(c == '"'){
            flag++;
        }
    }
    if(flag == 2){
        return true;
    }
    else{
        return false;
    }

}
bool comparaNumero(string a){
    int flag = 0;
    for (unsigned i=0; i<a.length(); ++i)
    {
        char c;
        c =  a.at(i);
        if(c == '0'||c == '1'||c == '2'||c == '3'||c == '4'||c == '5'||c == '6'||c == '7'||c == '8'||c == '9'){
            flag = flag + 0;
        }
        else{
            flag++;
        }
    }
    if(flag == 0){
        return true;
    }
    else{
        return false;
    }
}


string compara(string a){



    string token;
    bool ret = comparaKeyword(a);
    if(ret == true){
        token = "KeyWord";
        return token;
    }
    ret = comparaOperador(a);
    if(ret == true){
        token = "Operador";
        return token;
    }
    ret = comparaString(a);
    if(ret == true){
        token = "String";
        return token;
    }
    ret = comparaNumero(a);
    if(ret == true){
        token = "Numero";
        return token;
    }
    else{
        token = "Ident";
        return token;
    }
}

void leArquivo(string arquivo){
    fstream inFile;
    inFile.open(arquivo.c_str());
    int maxi = 0;
    string s;
    string z [100];
    int i = 0;
    while (inFile >> s){
        z[i] = s;
        i++;
        maxi = i;
    }
    i = 0;
    while(i < maxi){
        unsigned a=0;
        while(a<z[i].length())
        {
            char c;
            int flag = 0;
            c =  z[i].at(a);
            if(c == '/' || c == ';' || c == '{'){
                flag = 1;
                c =  z[i+1].at(a);
            }
            if(c == '/'){

            }
        }
        string token = compara(z[i]);
        arquivoSaida("/home/pedro/Documentos/LFC/teste2.txt", z[i], token);
        //cout << z[i] << endl;
        i++;
    }

    inFile.close();

}


int main(){
    cout<<"oi";
    leArquivo("/home/pedro/Documentos/LFC/testearq.txt");
    cout<<"bye";
    return 0;
}
