#include <iostream>
#include <vector>

using namespace std;

struct joueur{
    string prenom;
    string nom;
    unsigned int equipe;
    int score;
};

struct equipe{
    joueur j [7];
    int score;
};

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


string litUneString (){
string uneChaine;
while (true){
    getline (cin, uneChaine);
    if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
}
return uneChaine;
}

int litUnEntier (){
string uneChaine;
while (true){
    getline (cin, uneChaine);
    if ((!cin) || (uneChaine.substr(0,2) != "//")) break;
}
return stoi(uneChaine);
}

int main()
{
equipe lesequipes [18] ;
unsigned int cpt;
joueur lesjoueurs [114];
joueur j;
for (size_t i (0); i < 114; ++i){
    string nom (litUneString());
    string prenom  (litUneString());
    int equipe (litUnEntier());
    j.nom=nom;
    j.prenom=prenom;
    j.equipe=equipe;
    cout << j.nom << endl << j.prenom[i] << endl << equipe << endl;
    lesjoueurs[i]=j;
}for (size_t i (0); i < 114; ++i){
    cpt=0;
    unsigned int autrecpt = 0;
    while(cpt != 18){
        if(lesjoueurs[i].equipe == cpt){
            lesequipes[cpt].j[autrecpt] = lesjoueurs[i];
            autrecpt = autrecpt +1;
            if(autrecpt == 7){
                autrecpt=0;
            }
        }
        cpt = cpt+1;
    }

}

return 0;
}
//int main()
//{
//    cout << "Hello World!" << endl;
////    int n=rand()%18+1;
//    equipe tournoie [4];
//    size_t i=1;
//    joueur j[3];
//    for(;i < 4;++i){
//    cin >> j[i].nom;
//    cin >> j[i].equipe;
//    cin >> j[i].prenom;
//    if(j[i].equipe == 1){
//        tournoie.joueur[i]=;
//    }
//    }


////    string gagnat;
////        n=hasard(n);
////        cout <<"l'equipe "<< i << " affronte l'equipe " << n << endl;
////    cout << gagnat  << endl;


//    return 0;
//}
