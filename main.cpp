#include <cmath>
#include <iostream>
#include <vector>
#include<functional>
#include <algorithm>
#include <iomanip>
using namespace std;
//base
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

void affichetab(vector<equipe> tab){
    for(size_t i=0;i<tab.size();++i){
        cout << tab[i].j[0].equipe << " ";
    }
}

//Puissance 4
constexpr int h = 7;
constexpr int l = 7;

bool testHorizontal(const vector<vector<int>> & tab, const int & joueur){
    for(size_t j =0; j<7; j=j+1){
        if(tab.at(3).at(j)==joueur && tab.at(4).at(j)==joueur && tab.at(5).at(j)==joueur && tab.at(6).at(j)==joueur) return true;
        if(tab.at(3).at(j)==joueur && tab.at(2).at(j)==joueur && tab.at(1).at(j)==joueur && tab.at(0).at(j)==joueur) return true;
        if(tab.at(4).at(j)==joueur && tab.at(3).at(j)==joueur && tab.at(2).at(j)==joueur && tab.at(1).at(j)==joueur) return true;
        if(tab.at(2).at(j)==joueur && tab.at(3).at(j)==joueur && tab.at(4).at(j)==joueur && tab.at(5).at(j)==joueur) return true;
    }
    return false;
}

bool testVertical(const vector<vector<int>> & tab, const int & joueur){
    for(size_t i =0; i<7; i=i+1){
        if(tab.at(i).at(3)==joueur && tab.at(i).at(4)==joueur && tab.at(i).at(5)==joueur && tab.at(i).at(6)==joueur) return true;
        if(tab.at(i).at(3)==joueur && tab.at(i).at(2)==joueur && tab.at(i).at(1)==joueur && tab.at(i).at(0)==joueur) return true;
        if(tab.at(i).at(2)==joueur && tab.at(i).at(3)==joueur && tab.at(i).at(4)==joueur && tab.at(i).at(5)==joueur) return true;
        if(tab.at(i).at(4)==joueur && tab.at(i).at(3)==joueur && tab.at(i).at(2)==joueur && tab.at(i).at(1)==joueur) return true;
    }
    return false;
}

bool testDiagonale(const vector<vector<int>> & tab, const int & joueur){
    //Diagonale 1 (haut gauche)
    for(size_t i =3; i<7; i=i+1){
        for(size_t j=0 ; j<4 ; j=j+1){
            if(tab.at(i).at(j)==joueur && tab.at(i-1).at(j+1)==joueur && tab.at(i-2).at(j+2)==joueur && tab.at(i-3).at(j+3)==joueur) return true; }}
    //Diagonale 2 (haut droite)
    for(size_t i =0; i<4; i=i+1){
        for(size_t j=0 ; j<4 ; j=j+1){
            if(tab.at(i).at(j)==joueur && tab.at(i+1).at(j+1)==joueur && tab.at(i+2).at(j+2)==joueur && tab.at(i+3).at(j+3)==joueur) return true; }}
    //Diagonale 3 (bas droite)
    for(size_t i =0; i<4; i=i+1){
        for(size_t j=3; j<7 ; j=j+1){
            if(tab.at(i).at(j)==joueur && tab.at(i+1).at(j-1)==joueur && tab.at(i+2).at(j-2)==joueur && tab.at(i+3).at(j-3)==joueur) return true; }}
    //Diagonale 4 (bas gauche)
    for(size_t i =3; i<7; i=i+1){
        for(size_t j=3; j<7 ; j=j+1){
            if(tab.at(i).at(j)==joueur && tab.at(i-1).at(j-1)==joueur && tab.at(i-2).at(j-2)==joueur && tab.at(i-3).at(j-3)==joueur) return true; }}
    return false;
}



int testVictoire(const vector<vector<int>> & tab, const size_t & joueur){
    if(testHorizontal(tab, joueur)==true || testVertical(tab, joueur)==true || testDiagonale(tab, joueur) == true) return true;
    return false;
}
size_t test (vector<vector<int>> & tab, const int & i) {
    int j = 6;

    while(true) {
        if (j < 0){
            break;
        }

        if (tab.at(j).at(i) == 0) {return j;}

        j=j-1;

    }
    return 0;
}
void aff(vector<vector<int>> & tab) {
    srand(time(nullptr));
    for (auto &item : tab) {
        for (auto &j : item) {
            cout << setw(2) << j;
        }
        cout << endl;
    }
    cout <<endl;
}
void puissance4(equipe& e1,equipe& e2 )
{
    int i;
    unsigned int score = 0,scorebis = 0;
    string err = "ERR: vous ne pouvez pas positionner votre pion ici !";
    size_t cpt = 0;
    bool j1 = true;
    bool j2 = false;
    //On verifie que le tableau de joueur sois de la même taille et redimensionner selon l'équipe qui a le moin de joueur
    if(e1.j.size() != e2.j.size() || e2.j.size() > e1.j.size() ){
        e2.j.resize(e1.j.size());
    }else if(e1.j.size() != e2.j.size() || e1.j.size() > e2.j.size()){
        e1.j.resize(e2.j.size());
    }
    for(size_t j=0;j<e2.j.size();++j){
        //CREER LE JEUX AVEC QUE DES 0
        vector<vector<int> > tab(l, vector<int> (h, 0));
        srand(time(nullptr));
        for (auto &item : tab) {
            for (auto &i : item) {
                i = 0;
            }
        }
        //JEUX + REMPLISSAGE DU JEUX
        //    aff(tab);

        while (true) {
            if(cpt == 49) {
                //            cout << "EGALITE"<<endl;
                break;
            }


            if (j1==true) {
                //          cout << "Choisis ta colonne J1 :"<< endl;
                i=litUnEntier();

                if (i-1 <= 6) {
                    if(tab.at(0).at(i-1) != 0) {
                        //                    cout<<err<<endl;
                        //                      aff(tab);

                    } else {
                        cpt= cpt+1;
                        tab.at(test(tab,i-1)).at(i-1)= 1;
                        j1 = false;
                        j2 = true;
                        //                system("clear");
                        //                  aff(tab);
                        if(testVictoire(tab, 1) == true) {
                            e1.j[j].score+=1;
                            //                        cout << "gagnant 1 "<<endl;
                            score+=1;
                            break;
                        }
                    }} else {
                    cout << err << endl;
                }



            }
            if (j2==true) {
                //          cout << "Choisis ta colonne J2 :"<< endl;
                i=litUnEntier();
                if (i-1 <= 6) {
                    if(tab.at(0).at(i-1) != 0) {
                        //                    cout<<err<<endl;
                    }
                    else {
                        cpt= cpt+1;
                        tab.at(test(tab,i-1)).at(i-1)= 2;
                        j2 = false;
                        j1 = true;
                        //                system("clear");
                        //               aff(tab);
                        if(testVictoire(tab, 2) == true) {
                            e2.j[j].score+=1;
                            //                        cout << "gagnant 2" << endl;
                            scorebis+=1;
                            break;
                        }
                    } }else {
                    cout << err << endl;
                }

            }


        }
    }
    if(score > scorebis){
        e1.points+=2;
    }else if(score == scorebis){
        e1.points+=1;
        e2.points+=1;
    }else{
        e2.points+=2;
    }



}




//Jeu du pile ou face

void pileouface(equipe& e1,equipe &e2){
    int score1 = 0,score2=0;
    int choix;
    //si on a pas le même nombre de joueur
    if(e1.j.size() != e2.j.size() || e2.j.size() > e1.j.size() ){
        e2.j.resize(e1.j.size());
    }else if(e1.j.size() != e2.j.size() || e1.j.size() > e2.j.size()){
        e1.j.resize(e2.j.size());
    }
    for(size_t i=0;i< e2.j.size();++i){
        choix=litUnEntier();
        if(choix == 1){
            e1.j[i].score+=1;
            score1+=1;
        }else{
            e2.j[i].score+=1;
            score2+=1;
        }
    }
    if(score1 > score2){
        e1.points+=2;
    }else if(score1 == score2){
        e1.points+=1;
        e2.points+=1;
    }else{
        e2.points+=2;
    }
}
//le jeu du morpion
unsigned int testLigne( vector<vector<char>> & tab)
{
    unsigned int pj2=0,pj1=0;
    for(unsigned int i=0;i<3;++i)
    {

        for(unsigned int j=0;j<2;++j)
        {
            if(tab[i][j] == tab[i][j+1])
            {
                if (tab[i][j] == 'o')
                {
                    pj1 += 1;
                }
                else if(tab[i][j] == 'x')
                {
                    pj2 += 1;
                }
            }
        }
        if (pj1 == 2)
        {
            return 1;
        }
        else if (pj2 == 2)
        {
            return 2;
        }
        pj1 =0;
        pj2 =0;
    }
    return 0;

}


unsigned int testColonne(vector<vector<char>> & tab)
{
    unsigned int pj2=0,pj1=0;
    for(unsigned int j=0;j<3;++j)
    {
        for(unsigned int i=0;i<2;++i)
        {
            if(tab[i][j] == tab[i+1][j])
            {
                if (tab[i][j] == 'o')
                {
                    pj1 += 1;
                }
                else if(tab[i][j] == 'x')
                {
                    pj2 += 1;
                }
            }
        }
        if(pj1 == 2)
        {
            return 1;
        }
        else if (pj2 == 2)
        {
            return 2;
        }
        pj1 =0;
        pj2 = 0;
    }
    return 0;
}

unsigned int testDiago(vector<vector<char>> &tab)
{
    if (tab[0][0] == tab[1][1] && tab[0][0] == tab[2][2])
    {
        if (tab[0][0] == 'o')
        {
            return 1;
        }
        else if (tab[0][0] == 'x')
        {
            return 2;
        }
    }
    else if(tab[0][2] == tab[1][1] && tab[0][2] == tab[2][0])
    {
        if (tab[0][2] == 'o')
        {
            return 1;
        }
        else if (tab[0][2] == 'x')
        {
            return 2;
        }
    }
    return 0;
}
unsigned int gagne(vector<vector<char>> tab)
{
    unsigned int a = 0 ;
    if((testLigne(tab) == 0 && testColonne(tab) == 0) && testDiago(tab)==0)
    {
        a=0;
    }
    else if((testLigne(tab) == 1 || testColonne(tab) == 1) || testDiago(tab)==1)
    {
        a=1;
    }
    else if((testLigne(tab) == 2 || testColonne(tab) == 2) || testDiago(tab)==2 )
    {
        a=2;
    }
    return a;
}



//void affiche(vector<vector<char>> tableau){
//    for(unsigned int i=0 ; i < 3 ;i=i+1 ){
//        cout << endl ;
//        for(unsigned int j=0 ; j < 3 ;++j ){
//            cout <<tableau[i][j] << ".___|" ;
//        }

//    }

//}


bool isrempli(vector<vector<char>> tab)
{
    unsigned int cpt=0;
    for(unsigned int i=0;i<3;++i)
    {
        for(unsigned int j=0;j<3;++j)
        {
            if ((tab[i][j] == 'x') || (tab[i][j] == 'o'))
            {
                cpt += 1;
            }
        }
    }
    if (cpt == 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void morpion(equipe& e1,equipe& e2)
{
    unsigned int score = 0,scorebis = 0;
    int l=0;
    int c=0;
    bool j1=true,j2=false;
    if(e1.j.size() != e2.j.size() || e2.j.size() > e1.j.size() ){
        e2.j.resize(e1.j.size());
    }else if(e1.j.size() != e2.j.size() || e1.j.size() > e2.j.size()){
        e1.j.resize(e2.j.size());
    }
    for(size_t i=0;i< e2.j.size();++i){
        vector<vector<char>> tab(3, vector<char>(3, ' '));
        while(gagne(tab) == 0 && isrempli(tab) == false)
        {
            //        cout << "entrez la colonne souhaitée" << endl;
            c =litUnEntier();
            //        cout << "entrez la ligne souhaitée" << endl;
            l=litUnEntier();
            while ( l > 2 || c > 2 || (tab[l][c] == 'x' || tab[l][c] == 'o'))
            {
//                cout<< "case non valide !" << endl;
//                cout << "entrez la colonne souhaitée" << endl;
                c=litUnEntier();
//                cout << "entrez la ligne souhaitée" << endl;
                l=litUnEntier() ;
            }
            if(j1 == true && j2 == false)
            {
                tab[l][c] = 'o';
            }
            else if(j2 == true && j1 == false)
            {
                tab[l][c] = 'x';
            }
            //        affiche(tab);
            j1 = !j1;
            j2= !j2;
        }
        if(gagne(tab) == 1 )
        {
            //        cout << "le joueur 1 a gagné !" << endl;
            e1.j[i].score+=2;
            score+=1;
        }
        else if(gagne(tab) == 2)
        {
            //        cout << "le joueur 2 a gagné ! " << endl;
            e2.j[i].score+=2;
            scorebis+=1;
        }
        else
        {
            //        cout << "égalité !" << endl;
            e1.j[i].score+=1;
            e2.j[i].score+=1;
        }
    }
    if(score> scorebis){
        e1.points+=2;
    }else if(score == scorebis){
        e1.points+=1;
        e2.points+=1;//                cout<< "case non valide !" << endl;
                //                cout << "entrez la colonne souhaitée" << endl;nts+=1;
    }else{
        e2.points+=2;
    }
}



// le jeu Pierre, feuille..
void pierreFeuilleC(equipe&  e1,equipe&  e2)
{
    int score = 0,scorebis=0;
    if(e1.j.size() != e2.j.size() || e2.j.size() > e1.j.size() ){
        e2.j.resize(e1.j.size());
    }else if(e1.j.size() != e2.j.size() || e1.j.size() > e2.j.size()){
        e1.j.resize(e2.j.size());
    }
    for(size_t i=0;i< e2.j.size();++i){
        int j1,j2,p1=0,p2=0;
        //        cout << "rentrez 1 pour pierre,2 pour feuille,3 pour ciseau \n";
        j1=litUnEntier();
        j2=litUnEntier();
        if((j1==1 && j2 == 2 )|| (j1== 2 && j2 == 3)||(j1==3 && j2 ==1))
        {
            p2 += 1;
            //            cout << "point pour le joueur 2"<<endl;
        }
        else if((j1 == 1 && j2 == 3)||(j1==3 && j2==2)||(j1==2 && j2==1))
        {
            p1 += 1;
            //            cout << "point pour le joueur 1"<<endl;
        }
        if(p2<p1)
        {
            //            cout<<"le joueur 1 a gagné" << endl;
            e1.j[i].score+=2;
            score+=1;
        }
        else if(p1<p2)
        {
            //            cout <<"le joueur 2 a gagné" << endl;
            e2.j[i].score+=2;
            scorebis+=1;
        }
        else if(j1 == j2)
        {
            //            cout << "égalite"<<endl;
            e1.j[i].score+=1;
            e2.j[i].score+=1;
        }
    }
    if(score > scorebis){
        e1.points+=2;
    }else if(score == scorebis){
        e1.points+=1;
        e2.points+=1;
    }else{
        e2.points+=2;
    }
}
//le jeu du baton
void  batonet(equipe&  j1,equipe& j2){
    int pte1=0, pte2, enlever=0;
    unsigned int compteur=0;
    if(j1.j.size() != j2.j.size() || j2.j.size() > j1.j.size() ){
        j2.j.resize(j1.j.size());
    }else if(j1.j.size() != j2.j.size() || j1.j.size() > j2.j.size()){
        j1.j.resize(j2.j.size());
    }
    for(size_t i=0;i < j2.j.size() ;++i){
        int batonet=21;
        while(true){
            if(compteur%2 != 0){
                //                cout <<j1.j[i].prenom <<" combien de batons souhaite tu enlever?" << endl;
                enlever=litUnEntier();
            }else{
                //                cout <<j2.j[i].prenom <<" combien de batons souhaite tu enlever?" << endl;
                enlever=litUnEntier();
            }
            while(true){
                if(enlever > 3){
                    //                    cout << "il n'est pas possible d'enlever plus de trois batons" << endl;
                    enlever=litUnEntier();
                }else{
                    break;
                }
            }
            batonet=batonet-enlever;
            if(batonet <= 1){
                if (compteur%2 != 0){
                    j1.j[i].score+=1;
                    pte1=pte1+1;
                }else{
                    j2.j[i].score+=1;
                    pte2=pte2+1;
                }
                break;
            }
            //            cout << "il reste " << batonet << " batons" << endl;
            compteur=compteur+1;
        }
    }
    if(pte1 > pte2){
        j1.points+= 2;
    }else if(pte1 == pte2){
        j1.points += 1;
        j2.points +=1;
    }
    else{
        j2.points+=2;
    }
}




//Tournoie suisse
bool different(vector<unsigned int> tab,vector<equipe> ep){
    bool diff=true;
    for(size_t i=0;i<tab.size()-1;i=i+2){
        for(size_t j=0;j<ep.size()-1;i=i+2)
            if(tab[i] == ep[j].j[0].equipe && tab[i+1] == ep[j+1].j[0].equipe){
                diff=false;
            }
    }
    return diff;
}
bool compadiff(const vector<unsigned int> & tab,const vector<equipe>& e,const size_t& i){
    return tab[i] != e[i].j[0].equipe && tab[i+1] != e[i+1].j[0].equipe;// il faut que les adversaire sois differents
}
bool comparaison(const equipe& equipe1, const equipe& equipe2) {
    return equipe1.points > equipe2.points; // Tri en ordre décroissant des scores
}
bool comparejoueur(const joueur& joueur1, const joueur& joueur2) {
    return joueur1.score > joueur2.score; // Tri en ordre décroissant des scores
}
equipe tournoie(vector<equipe> lesequipes){
    equipe gagnant;
    equipe changement;
    //on cree un tableau qui va stoquer le numero d'equipe qui se sont affronter : ils sont voisins
    vector<unsigned int> dejavs;
    unsigned int cpt=0;
    unsigned int nbderondes;
    cout << "saisir le nombre de round : "<< endl;
    nbderondes=litUnEntier();
    affichetab(lesequipes);
    cout<< endl;
    //On lance le compteur des rondes et on commence le tournoie entre les plus bon et les moins bons
    while(cpt != nbderondes){
        for(size_t i=0;i< lesequipes.size()-1;i+=2){
            //    ici on trie le tableau de joueur ,du moin bon score au meilleur , pour que les joueur de même niveau s'affronte
            sort(begin(lesequipes[i].j),end(lesequipes[i].j),comparejoueur);
            sort(begin(lesequipes[i+1].j),end(lesequipes[i+1].j),comparejoueur);
            //on passe aux jeux
            batonet(lesequipes[i],lesequipes[i+1]);
//            affichetab(lesequipes);
//            cout << endl;
            //        cout << lesequipes[i].points << " et les adversaires " << lesequipes[i+1].points << endl ;
            pierreFeuilleC(lesequipes[i],lesequipes[i+1]);
//                   affichetab(lesequipes);
//                    cout << endl;
            //                   cout << lesequipes[i].points << " et les adversaires " << lesequipes[i+1].points << endl;
            morpion(lesequipes[i],lesequipes[i+1]);
//                   affichetab(lesequipes);
//                    cout << endl;
            //                        cout << lesequipes[i].points << " et les adversaires " << lesequipes[i+1].points << endl;
            pileouface(lesequipes[i],lesequipes[i+1]);
//                   affichetab(lesequipes);
//                    cout << endl;
            //                         cout << lesequipes[i].points << " et les adversaires " << lesequipes[i+1].points << endl;
            puissance4(lesequipes[i],lesequipes[i+1]);

            //                       cout << lesequipes[i].points << " et les adversaires " << lesequipes[i+1].points << endl;
            //            dejavs.push_back(lesequipes[i].j[0].equipe);
            //            dejavs.push_back(lesequipes[i+1].j[0].equipe);
//            affichetab(lesequipes);
//            o=lesequipes.size();
//            cout << "taille de tab " << o << endl;
        }
        //On passe aux autres rondes
        //Ici aussi on trie le tableau des equipes : de l'equipe qui a le plus de point à celle qui a le moin
        sort (begin(lesequipes), end(lesequipes),comparaison);
//        affichetab(lesequipes);
        //Pour toute les equipes ils continuent a être dans le tournoie , forcement comme ils sont ordonné leur voisin est du même niveau sauf pour certains cas
        cpt=cpt+1;
        //On verifie que le nouveau tableau nous donne des voisins que ne se sont jamais affronter
        //desormais on verifie que les 2 tableau sont differents si ils ne le sont pas on reste dans la boucle pour changer
        //        for(size_t i=0;i<dejavs.size()-2;i=i+2){
        //            if(different(dejavs,lesequipes) == false){
        //                swap(lesequipes[i+1],lesequipes[i+2]);
        //            }
        //        }
    }
    //    sort (begin(lesequipes), end(lesequipes),comparaison);

    affichetab(lesequipes);
    cout << endl;
    //Comme nous trions le tableau d'equipe du meilleur  score au moin bon a la fin de la boucle le premiere element correspond a  l'equipe gagnante
    gagnant=lesequipes[0];
    return gagnant;

}

//Fonction principale

int main()
{
    vector<equipe> lesequipes (18) ;
    vector<joueur> lesjoueurs (114);
    joueur j;
    for (size_t i (0); i < 114; ++i){
        string nom (litUneString());
        string prenom  (litUneString());
        int equipe (litUnEntier());
        j.nom=nom;
        j.prenom=prenom;
        j.equipe=equipe;
        //        cout << j.nom << endl << j.prenom << endl << equipe << endl;
        lesjoueurs[i]=j;
        lesequipes[equipe-1].j.push_back(lesjoueurs[i]);
    }
    equipe winner=tournoie(lesequipes);
    cout << "l'equipe gagnante est " << winner.j[0].equipe << endl ;
    return 0;
}

