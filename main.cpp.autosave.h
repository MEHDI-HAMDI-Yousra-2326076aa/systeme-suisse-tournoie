#include <cmath>
#include <iostream>
#include <vector>
#include<functional>
#include <algorithm>

using namespace std;

struct joueur{
    string prenom;
    string nom;
    unsigned int equipe;
    int score;
};

struct equipe{
    vector<joueur> j;
    int points;
};

void pierreFeuilleC(equipe & e1,equipe & e2)
{
    int score = 0,scorebis=0;
    for(size_t i=0;i< e1.j.size();++i){
        int j1,j2,p1=0,p2=0;
        cout << "rentrez 1 pour pierre,2 pour feuille,3 pour ciseau \n";
        cin >> j1;
        cin >> j2;
        if((j1==1 && j2 == 2 )|| (j1== 2 && j2 == 3)||(j1==3 && j2 ==1))
        {
            p2 += 1;
            cout << "point pour le joueur 2"<<endl;
        }
        else if((j1 == 1 && j2 == 3)||(j1==3 && j2==2)||(j1==2 && j2==1))
        {
            p1 += 1;
            cout << "point pour le joueur 1"<<endl;
        }
        if(p2<p1)
        {
            cout<<"le joueur 1 a gagné" << endl;
            e1.j[i].score+=1;
            score+=1;
        }
        else if(p1<p2)
        {
            cout <<"le joueur 2 a gagné" << endl;
            e2.j[i].score+=1;
            scorebis+=1;
        }
        else if(j1 == j2)
        {
            cout << "égalité"<<endl;
            e1.j[i].score+=0.5;
            e2.j[i].score+=0.5;
        }
    }
    if(score > scorebis){
        e1.points+=1;
    }else if(score == scorebis){
        e1.points+=0.5;
        e2.points+=0.5;
    }else{
        e2.points+=1;
    }
}

void batonet(equipe & j1,equipe & j2){
    cout << "C'est parti !" << endl;
    int pte1=0;
    int pte2=0;
    int batonet=21;
    int enlever=0;
    unsigned int compteur=0;
    for(size_t i=0;i < j1.j.size() ;++i){
        sort(begin(j1.j),end(j1.j),greater<joueur>());
        while(true){
            if(compteur%2 != 0){
                cout <<j1.j[i].prenom <<" combien de batons souhaite tu enlever?" << endl;
                cin >> enlever;
            }else{
                cout <<j2.j[i].prenom <<" combien de batons souhaite tu enlever?" << endl;
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
            if (compteur%2 != 0){
                j1.j[i].score+=1;
                pte1=pte1+1;
            }else{
                j2.j[i].score+=1;
                pte2=pte2+1;
            }
        }
    }
    if(pte1 > pte2){
        j1.points+=1;
        j2.points+=0;
    }
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


//Tournoie suisse


equipe tournoie(vector<equipe> lesequipes){
equipe gagnant;
unsigned int cpt=1;
unsigned int nbderondes;
cin >> nbderondes;
//la premiere ronde on trie le tableau de la meilleur equipe a la plus nul
for(size_t i=0;i< lesequipes.size()-1;i=i+2){
//    ici on trie le tableau de joueur ,du meilleur score au moin bon, pour que les joueur de même niveau s'affronte
    sort(begin(lesequipes[i].j),end(lesequipes[i].j),greater<joueur>());
    sort(begin(lesequipes[i+1].j),end(lesequipes[i+1].j),greater<joueur>());
    batonet(lesequipes[i],lesequipes[i+1]);
    pierreFeuilleC(lesequipes[i],lesequipes[i+1]);
}
//On passe aux autres rondes
//Ici aussi on trie le tableau des equipes : de l'equipe qui a le plus de point à celle qui a le moin
//On lance le compteur des rondes et on commence le tournoie entre les plus bon et les moins bons
sort (begin(lesequipes), end(lesequipes), greater<equipe>());
while(cpt != nbderondes){
    //Pour toute les equipes ils jouent les jeux, forcement comme ils sont ordonné leur voisin est du même niveau sauf pour certains cas
    //A chaque fois qu'on fait appel au fonction des jeu on rempli le tableau lesequipes,dans chaque case on aura apporter
//    les modification concernant les ponit des equipes et les score des joueurs
    for(size_t i=0;i< lesequipes.size()-1;i=i+2){
     batonet(lesequipes[i],lesequipes[i+1]);
     pierreFeuilleC(lesequipes[i],lesequipes[i+1]);
    }
    cpt=cpt+1;
    sort (begin(lesequipes), end(lesequipes), greater<equipe>());
}
//Comme nous trions le tableau d'equipe du meilleur score au moin bon a la fin de la boucle le 1er element correspond a  l'equipe gagnante
gagnant=lesequipes[0];
return gagnant;

}

//Fonction principale

int main()
{
vector<equipe> lesequipes (2) ;
vector<joueur> lesjoueurs (4);
joueur j;
for (size_t i (0); i < 4; ++i){
    string nom (litUneString());
    string prenom  (litUneString());
    int equipe (litUnEntier());
    j.nom=nom;
    j.prenom=prenom;
    j.equipe=equipe;
    cout << j.nom << endl << j.prenom << endl << equipe << endl;
    lesjoueurs[i]=j;
    lesequipes[equipe-1].j.push_back(lesjoueurs[i]);
}
equipe winner=tournoie(lesequipes);
cout << "l'equipe gagnante est " << winner.j[0].equipe << endl ;
return 0;
}
