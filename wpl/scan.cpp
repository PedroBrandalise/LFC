#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string linha[1000];
string palavras[1000];
string caracteres[1000];
int maxi = 0;
int aux = 0;

void arquivoSaida(string arquivo, string valor, string token){
    ofstream inFile;
    inFile.open(arquivo, ios::app);
    inFile << "<" << valor << ", " << token << ">" << endl;
    inFile.close();
}

void pegaLinhas(){
    int i = 0;
    string line;
    ifstream myfile ("/home/pedro/Documentos/LFC/wpl/entrada_scan.txt");
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            linha[i] = line;
            i++;
        }
        maxi = i;
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
}

bool enumero(char c){
    if(c == '0'||c == '1'||c == '2'||c == '3'||c == '4'||c == '5'||c == '6'||c == '7'||c == '8'||c == '9'){
        //cout<<c<<endl;
        return true;
    }
    else{
        return false;
    }
}

bool eoperador(char c){
    if(c == '+'|| c == '-' || c == '/' || c == '*' || c == '<'|| c == '>'){
        return true;
    }
    else if(c == '=' || c == '=='|| c == ')' || c == '('){
        return true;
    }
    else if(c == ';'){
        return true;
    }
    else{
        return false;
    }

}

bool ecomentario(char c){
    if(c == '/'){
        return true;
    }
    else{
        return false;
    }

}

bool espace(char c){
    if(c == 0x20 || c == 0x09){
        return true;
    }
    else{
        return false;
    }
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
    bool ret = comparaString(a);
    if(ret == true){
        token = "String";
        return token;
    }
    ret = comparaKeyword(a);
    if(ret == true){
        token = "KeyWord";
        return token;
    }
    ret = comparaOperador(a);
    if(ret == true){
        token = "Operador";
        return token;
    }

    ret = comparaNumero(a);
    if(ret == true){
        token = "Numero";
        return token;
    }

    token = "Ident";
    return token;
}


void pegaCaracteres(){
    int i = 0;
    unsigned a = 0;
    int b = 0;
    char c;
    int flag = 0;
    while(i < maxi){
        a = 0;
        while(a<linha[i].length()){
            c =  linha[i].at(a);
            //cout<<c;
            bool n = enumero(c);
            bool o = eoperador(c);
            bool s = espace(c);
            bool coment = ecomentario(c);
            if(flag == 0){
                if(s == false){
                    if(coment == true){
                        c =  linha[i].at(a+1);
                        coment = ecomentario(c);
                        if(coment == true){
                            flag = 1;
                        }
                        else{
                          c =  linha[i].at(a);
                        }
                    }
                    if(flag != 1){
                        if(n == true || o == true){
                            b++;
                            palavras[b] = c;
                        }
                        else{
                            if(a > 0){
                                c =  linha[i].at(a-1);
                            }
                            n = enumero(c);
                            o = eoperador(c);
                            s = espace(c);
                            if(o == true || s == true || n == true){
                                b++;
                            }
                            c =  linha[i].at(a);
                            palavras[b] = palavras[b] + c;

                        }
                    }
                    else if(flag == 1){
                       flag = 0;
                       break;
                    }
                }
                a++;
            }

        }
        i++;
    }
    aux = b;

}

int main () {
    int i = 0;
    string token;
    pegaLinhas();
    pegaCaracteres();
    while(i < aux){
        token = compara(palavras[i]);
        arquivoSaida("/home/pedro/Documentos/LFC/wpl/saida_scan.txt", palavras[i], token);
        i++;
    }


    return 0;
}
