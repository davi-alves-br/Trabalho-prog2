#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void menu();
void batalha_naval_s();
void batalha_naval_m();
void desenhar_tabuleiro(string tabuleiro_a[10][10], string tabuleiro_b[10][10]);
void setarTabuleiro(string tabuleiro_a[10][10], string tabuleiro_b[10][10]);

int main(){     
    setlocale(LC_ALL, "Portuguese");
    int op = 0;
    while(op != 3){
        menu();
        cin >> op;
        switch(op){
            case 1:{
                system("cls");
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
    ci = toupper(ci);
    cf = toupper(cf);
    // Garante conversão caso receba letra maiúscula ou dentro do intervalo 'a'-'j'
    if (ci >= 'A' && ci <= 'J') {
        return ci - 'A' + 1;
    }
    else if (cf >= 'A' && cf <= 'J') {
        return cf - 'A' + 1;
    }
    return -1; // Retorno padrão para entradas fora do intervalo
}

void menu(){
    cout << "------- Batalha Naval -------\n"
    << "[1] - Jogar single-player\n"
    << "[2] - Jogar multi-player\n"
    << "[3] - Sair" << endl;
}

//Desenho tabuleiro com matrizes
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

    cout << "\n\n------- Tabuleiro -------\n\n"
    << "  A  B  C  D  E  F  G  H  I  J";
    for(int i = 0; i < 10; i++){
        cout << "\n";
        cout << (i + 1);
        for(int j = 0; j < 10; j++){
            cout << tabuleiro_b[i][j];
        }
    }
}

void setarTabuleiro(string tabuleiro_a[10][10], string tabuleiro_b[10][10]){
    int li, lf, cinu, cfnu, cont = 0;
    char ci, cf;
    bool loop = true;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro_a[i][j] = "[ ]";
            tabuleiro_b[i][j] = "[ ]";
        }
    }
    while(loop){
        
        desenhar_tabuleiro(tabuleiro_a, tabuleiro_b);
        cout << "\n\nDigite onde será a posição inicial do barco porta-aviões[P]: ";
        cin >> li >> ci;
        ci = letraParaNumero(ci, cf);
        tabuleiro_a[li-1][ci-1] = "[P]";
        cout << "Digite onde será a posição final do barco porta-aviões[P]: ";
        cin >> lf >> cf;
        cf = letraParaNumero(ci, cf);
        if(((cf - ci) == 4) || ((cf - ci) ==  -4) || ((lf - li) ==  -4) || ((lf - li) ==  4)){
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
            loop = false;
        }
        else{
            tabuleiro_a[li-1][ci-1] = "[ ]";
            system("cls");
            cout << "Tamanho do barco inválido! Digite novamente!" << endl;
        }
        
    }
    loop = true;
    while(loop){
        desenhar_tabuleiro(tabuleiro_a, tabuleiro_b);
        cout << "\n\nDigite onde será a posição inicial do navio-tanque[N]: ";
        cin >> li >> ci;
        ci = letraParaNumero(ci, cf);
        tabuleiro_a[li-1][ci-1] = "[N]";
        cout << "Digite onde será a posição final do barco navio-tanque[N]: ";
        cin >> lf >> cf;
        cf = letraParaNumero(ci, cf);
        if(((cf - ci) == 3) || ((cf - ci) ==  -3) || ((lf - li) ==  -3) || ((lf - li) ==  3)){
            if(li == lf){
                for(ci += 1; ci <= cf; ci++){
                    tabuleiro_a[li-1][ci-1] = "[N]";
                }
            }
            else if(ci == cf){
                for(li += 1; li <= lf; li++){
                    tabuleiro_a[li-1][ci-1] = "[N]";
                }
            }
            loop = false;
        }
        else{
            tabuleiro_a[li-1][ci-1] = "[ ]";
            system("cls");
            cout << "Tamanho do barco inválido! Digite novamente!" << endl;
        }
    }
    loop = true;
    while(loop){
        desenhar_tabuleiro(tabuleiro_a, tabuleiro_b);
        cout << "\n\nDigite onde será a posição inicial do " << (cont + 1) << "° contratorpedeiro[C]: ";
        cin >> li >> ci;
        ci = letraParaNumero(ci, cf);
        tabuleiro_a[li-1][ci-1] = "[C]";
        cout << "Digite onde será a posição inicial do " << (cont + 1) << "° contratorpedeiro[C]: ";
        cin >> lf >> cf;
        cf = letraParaNumero(ci, cf);
        if(((cf - ci) == 2) || ((cf - ci) ==  -2) || ((lf - li) ==  -2) || ((lf - li) ==  2)){
            if(li == lf){
                for(ci += 1; ci <= cf; ci++){
                    tabuleiro_a[li-1][ci-1] = "[C]";
                    cont++;
                }
            }
            else if(ci == cf){
                for(li += 1; li <= lf; li++){
                    tabuleiro_a[li-1][ci-1] = "[C]";
                    cont++;
                }
            }
            if (cont == 2){
                loop = false;
            }   
        }
        else{
            tabuleiro_a[li-1][ci-1] = "[ ]";
            system("cls");
            cout << "Tamanho do barco inválido! Digite novamente!" << endl;
        }

    }
    loop = true;
    while(loop){
        desenhar_tabuleiro(tabuleiro_a, tabuleiro_b);
        cout << "\n\nDigite onde será a posição inicial do submarino[S]: ";
        cin >> li >> ci;
        ci = letraParaNumero(ci, cf);
        tabuleiro_a[li-1][ci-1] = "[S]";
        cout << "Digite onde será a posição final do barco submarino[S]: ";
        cin >> lf >> cf;
        cf = letraParaNumero(ci, cf);
        if(((cf - ci) == 1) || ((cf - ci) ==  -1) || ((lf - li) ==  -1) || ((lf - li) ==  1)){
            if(li == lf){
                for(ci += 1; ci <= cf; ci++){
                    tabuleiro_a[li-1][ci-1] = "[S]";
                }
            }
            else if(ci == cf){
                for(li += 1; li <= lf; li++){
                    tabuleiro_a[li-1][ci-1] = "[S]";
                }
            }
            loop = false;
        }
        else{
            tabuleiro_a[li-1][ci-1] = "[ ]";
            system("cls");
            cout << "Tamanho do barco inválido! Digite novamente!" << endl;
        }
    }
    loop = true;
    while(loop){
        srand(time(NULL));
        li = rand() % 10;
        cinu = rand() % 10;
        lf = rand() % 10;
        cfnu = rand() % 10;
        if(((cfnu - cinu) == 4) || ((cfnu - cinu) ==  -4) || ((lf - li) ==  -4) || ((lf - li) ==  4)){
            if(li == lf){
                for(cinu += 1; cinu <= cfnu; cinu++){
                    tabuleiro_b[li][cinu] = "[P]";
                }
            }
            else if(cinu == cfnu){
                for(li += 1; li <= lf; li++){
                    tabuleiro_b[li][cinu] = "[P]";
                }
            }
            loop = false;
        }
    }
    loop = true;
    while(loop){
        li = rand() % 10;
        cinu = rand() % 10;
        lf = rand() % 10;
        cfnu = rand() % 10;
        if(((cfnu - cinu) == 3) || ((cfnu - cinu) ==  -3) || ((lf - li) ==  -3) || ((lf - li) ==  3)){
            if(li == lf){
                for(cinu += 1; cinu <= cfnu; cinu++){
                    tabuleiro_b[li][cinu] = "[N]";
                }
            }
            else if(cinu == cfnu){
                for(li += 1; li <= lf; li++){
                    tabuleiro_b[li][cinu] = "[N]";
                }
            }
            loop = false;
        }

    }
    loop = true;
    while(loop){
        li = rand() % 10;
        cinu = rand() % 10;
        lf = rand() % 10;
        cfnu = rand() % 10;
        if(((cfnu - cinu) == 2) || ((cfnu - cinu) ==  -2) || ((lf - li) ==  -2) || ((lf - li) ==  2)){
            if(li == lf){
                for(cinu += 1; cinu <= cfnu; cinu++){
                    tabuleiro_b[li][cinu] = "[C]";
                    cont++;
                }
            }
            else if(cinu == cfnu){
                for(li += 1; li <= lf; li++){
                    tabuleiro_b[li][cinu] = "[C]";
                    cont++;
                }
            }
            if (cont == 2){
                loop = false;
            }   
        }
    }
    loop = true;
    while(loop){
        li = rand() % 10;
        cinu = rand() % 10;
        lf = rand() % 10;
        cfnu = rand() % 10;
        if(((cfnu - cinu) == 1) || ((cfnu - cinu) ==  -1) || ((lf - li) ==  -1) || ((lf - li) ==  1)){
            if(li == lf){
                for(cinu += 1; cinu <= cfnu; cinu++){
                    tabuleiro_b[li][cinu] = "[S]";
                }
            }
            else if(cinu == cfnu){
                for(li += 1; li <= lf; li++){
                    tabuleiro_b[li][cinu] = "[S]";
                }
            }
            loop = false;
        }
    }
    loop = true;
}

void batalha_naval_s(){
    
    //criação de dois tableiros(usuario e inimigo)
    string tabuleiro_a[10][10];
    string tabuleiro_b[10][10];
    //preenchimento com vazio
    
    setarTabuleiro(tabuleiro_a, tabuleiro_b);
    
    desenhar_tabuleiro(tabuleiro_a, tabuleiro_b);
    int x;
    cin >> x;
    
}

void batalha_naval_m(){

}
