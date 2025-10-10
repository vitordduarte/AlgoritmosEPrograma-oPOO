#include "Data.h" // inclui cabeçalho da classe

Data::Data(){
    dia = 10;
    mes = 3;
    ano = 2020;

    cout << "data recebida" << endl;
}

Data::~Data(){
    cout << "deixou de existir!" << endl;
}

void Data::imprimirData(){
    cout << dia << "/" << mes << "/" << ano << endl;
}

void Data::imprimirDataPorExtenso(string cidade){
    cout << cidade << "," << dia << "de" << mes << "de" << ano << endl;
}