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
void affichetab(vector<equipe> tab){
    for(size_t i=0;i<tab.size();++i){
        cout << tab[i].points << " ";
    }
}

void pierreFeuilleC(equipe&  e1,equipe&  e2)
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

vector<equipe> batonet(equipe  j1,equipe j2){
    cout << "C'est parti !" << endl;
    vector<equipe> nv;
    int pte1=0;
    int pte2=0;
    unsigned int enlever=0;
    unsigned int compteur=0;
    for(size_t i=0;i < j1.j.size() ;++i){
        unsigned int batonet=21;
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
                if (compteur%2 != 0){
                    j1.j[i].score+=1;
                    pte1=pte1+1;
                }else{
                    j2.j[i].score+=1;
                    pte2=pte2+1;
                }
                cout << "bravo" << endl;
                break;
            }
            cout << "il reste " << batonet << " batons" << endl;
            compteur=compteur+1;
        }
    }
    if(pte1 > pte2){
        j1.points=j1.points + 1;
        j2.points=j2.points +0;
    }else{
        j2.points=j2.points+1;
        j1.points=j1.points+0;
    }
    nv.push_back(j1);
    nv.push_back(j2);
    return nv;
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

bool comparaison(const equipe& equipe1, const equipe& equipe2) {
    return equipe1.points > equipe2.points; // Tri en ordre décroissant des scores
}
bool comparejoueur(const joueur& joueur1, const joueur& joueur2) {
    return joueur1.score > joueur2.score; // Tri en ordre décroissant des scores
}
equipe tournoie(vector<equipe> lesequipes){
    equipe gagnant;
    unsigned int cpt=0;
    unsigned int nbderondes;
    cout << "saisir le nombre de round : "<< endl;
    cin >> nbderondes;
    affichetab(lesequipes);
    //On lance le compteur des rondes et on commence le tournoie entre les plus bon et les moins bons
    while(cpt != nbderondes){
    for(size_t i=0;i< lesequipes.size()-1;i=i+2){
        //    ici on trie le tableau de joueur ,du moin bon score au meilleur , pour que les joueur de même niveau s'affronte
        sort(begin(lesequipes[i].j),end(lesequipes[i].j),comparejoueur);
        sort(begin(lesequipes[i+1].j),end(lesequipes[i+1].j),comparejoueur);
        lesequipes=batonet(lesequipes[i],lesequipes[i+1]);
        cout << lesequipes[i].points << "et les adversaires " << lesequipes[i+1].points << endl ;
        pierreFeuilleC(lesequipes[i],lesequipes[i+1]);
        cout << lesequipes[i].points << " et les adversaires " << lesequipes[i+1].points << endl;
    }
    //On passe aux autres rondes
    //Ici aussi on trie le tableau des equipes : de l'equipe qui a le plus de point à celle qui a le moin
    sort (begin(lesequipes), end(lesequipes),comparaison);
        //Pour toute les equipes ils jouent les jeux, forcement comme ils sont ordonné leur voisin est du même niveau sauf pour certains cas
        cpt=cpt+1;
    }
    sort (begin(lesequipes), end(lesequipes),comparaison);
    affichetab(lesequipes);
    //Comme nous trions le tableau d'equipe du meilleur  score au moin bon a la fin de la boucle le premiere element correspond a  l'equipe gagnante
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

