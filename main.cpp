#include <iostream>
#include <vector>

using namespace std;
struct equipe{
    string nomj1;
    string nomj2;
    string nomj3;
    string nomj4;
    string nomj5;
    string nomj6;
    string nomj7;
    int score;
};


int main()
{
    cout << "Hello World!" << endl;
    equipe lesequipe[18];
    for(size_t i=1;i < 18;++i){
        cout << "equipe " << i <<"sasir le nom des joueur" << endl;
        cin >> lesequipe[i].nomj1;
        cin >> lesequipe[i].nomj2;
        cin >> lesequipe[i].nomj3;
        cin >> lesequipe[i].nomj4;
        cin >> lesequipe[i].nomj5;
        cin >> lesequipe[i].nomj6;
        cin >> lesequipe[i].nomj7;
    }
    return 0;
}
