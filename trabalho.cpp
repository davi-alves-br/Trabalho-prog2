#include <iostream>
#include <locale.h>
using namespace std;

void menu();

void batalha_naval_s();

void batalha_naval_m();

void desenhar_tabuleiro(string tabuleiro_a[10][10], string tabuleiro_b[10][10]);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int op = 0;
    while(op != 3){
        menu();
        cin >> op;
        switch(op){
            case 1:{
                batalha_naval_s();
                break;
            }
            case 2:{
                batalha_naval_m();
                break;
            }
            case 3:{
                break;
            }
        }
    }
    return 0;
}

int letraParaNumero(char ci, char cf) {
    // Garante conversão caso receba letra maiúscula ou dentro do intervalo 'a'-'j'
    if (ci >= 'a' && ci <= 'j') {
        return ci - 'a' + 1;
    }
    else if (cf >= 'a' && cf <= 'j') {
        return cf - 'a' + 1;
    }
    return -1; // Retorno padrão para entradas fora do intervalo
}

void menu(){
    cout << "------- Batalha Naval -------\n"
    << "[1] - Jogar single-player\n"
    << "[2] - Jogar multi-player\n"
    << "[3] - Sair" << endl;
}

void desenhar_tabuleiro(string tabuleiro_a[10][10], string tabuleiro_b[10][10]){
    cout << "------- Tabuleiro -------\n\n"
    << "  A  B  C  D  E  F  G  H  I  J";
    for(int i = 0; i < 10; i++){
        cout << "\n";
        cout << (i + 1);
        for(int j = 0; j < 10; j++){
            cout << tabuleiro_a[i][j];
        }
    }
}

void batalha_naval_s(){
    int li, lf;
    char ci, cf;
    string tabuleiro_a[10][10];
    string tabuleiro_b[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro_a[i][j] = "[ ]";
            tabuleiro_b[i][j] = "[ ]";
        }
    }

    desenhar_tabuleiro(tabuleiro_a, tabuleiro_b);
    cout << "\n\nDigite onde será a posição inicial do barco porta-aviões[P]: ";
    cin >> li >> ci;
    letraParaNumero(ci, cf);
    tabuleiro_a[li-1][ci-1] = "[P]";
    cout << "Digite onde será a posição final do barco porta-aviões[P]: ";
    cin >> lf >> cf;
    letraParaNumero(ci, cf);
    if(li == lf){
        for(ci += 1; ci <= cf; ci++){
            tabuleiro_a[li-1][ci-1] = "[P]";
        }
    }
    else if(ci == cf){
        for(li += 1; li <= lf; li++){
            tabuleiro_a[li-1][ci-1] = "[P]";
        }
    }
    desenhar_tabuleiro(tabuleiro_a, tabuleiro_b);
    while(1){
        
    }
    
}

void batalha_naval_m(){

}