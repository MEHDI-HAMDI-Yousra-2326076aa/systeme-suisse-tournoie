#include <iostream>
#include <vector>

using namespace std;
struct joueur{
    string prenom;
    string nom;
    int equipe;
    int score;
};

struct equipe{
    joueur joueur;
    int score;
};

int hasard(int n){
    int v=rand()%18+1;
    if(n == v){
        v=rand()%18+1;
    }
    return v;
}
string batonet(const string & j1,const string & j2){
cout << "C'est parti !" << endl;
string winner;
int batonet=21;
int enlever=0;
unsigned int compteur=0;
for(;;){
    if(compteur%2 != 0){
        cout <<j1 <<" combien de batons souhaite tu enlever?" << endl;
        cin >> enlever;
    }else{
        cout <<j2 <<" combien de batons souhaite tu enlever?" << endl;
        cin >> enlever;
    }
    while(true){
        if(enlever > 3){
            cout << "il n'est pas possible d'enlever plus de trois batons" << endl;
            cin >> enlever;
        }else{
            break;
        }
    }
    batonet=batonet-enlever;
    if(batonet == 1){
        cout << "bravo" << endl;
        break;
    }
    cout << "il reste " << batonet << " batons" << endl;
    compteur=compteur+1;
}
if (compteur%2 != 0){
    winner=j1;
}else{
    winner=j2;
}
return winner ;
}


int main()
{
    cout << "Hello World!" << endl;
//    int n=rand()%18+1;
    equipe tournoie [4];
    size_t i=1;
    joueur j[3];
    for(;i < 4;++i){
    cin >> j[i].nom;
    cin >> j[i].equipe;
    cin >> j[i].prenom;
    if(j[i].equipe == 1){
        tournoie.joueur[i]=;
    }
    }


//    string gagnat;
//        n=hasard(n);
//        cout <<"l'equipe "<< i << " affronte l'equipe " << n << endl;
//    cout << gagnat  << endl;


    return 0;
}
