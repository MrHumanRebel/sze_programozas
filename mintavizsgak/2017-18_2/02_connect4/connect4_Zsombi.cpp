#include <iostream>
#include <algorithm>
//A defineok miatt a méret itt variálható csak, dolgozok a dinamikuson, majd frissítem  a git-en ha kész
#define row 9
#define column 15
char playingField[row][column];
char letterList[]={
    'A','B','C','D','E',
    'F','G','H','I','J',
    'K','L','M','N','O',
    'P','Q','R','S','T',
    'U','V','W','X','Y','Z'
    };

bool isItGameOver(){
    bool over=false;
    for(int i=row-1;i >= 0;i--){
        for(int k=0;k<column;k++){
            //sorcsekk
            try {
                if(((playingField[i][k] == playingField[i][k+1]) &&(playingField[i][k] == playingField[i][k+2])&&(playingField[i][k] == playingField[i][k+3]))&& playingField[i][k]!='.'){
                    over = true;
                    }
                } 
                catch(...){
                    throw;
                }
            //oszlopcsekk jobbrafel
            try {
                if(((playingField[i][k] == playingField[i-1][k+1]) &&(playingField[i][k] == playingField[i-2][k+2])&&(playingField[i][k] == playingField[i-3][k+3]))&& playingField[i][k]!='.'){
                    over = true;
                    }
                }
                catch(...){
                    throw;
                }
            //oszlopcsekk balra fel
            try {
                if(((playingField[i][k] == playingField[i-1][k-1]) &&(playingField[i][k] == playingField[i-2][k-2])&&(playingField[i][k] == playingField[i-3][k-3]))&& playingField[i][k]!='.'){
                    over = true;
                    }
                }
                catch(...){
                    throw;
                }
            //oszlopcsekk felfele
            try {
                if(((playingField[i][k] == playingField[i-1][k]) &&(playingField[i][k] == playingField[i-2][k])&&(playingField[i][k] == playingField[i-3][k]))&& playingField[i][k]!='.'){
                    over = true;
                    }
                }
                catch(...){
                    throw;
                }
        }   
    }
    return over;
}

void playerMove(char player_move, char sign){
    int n = sizeof(letterList)/sizeof(letterList[0]);
    //player_move-ot keressük a letterList-ben
    auto itr = std::find(letterList, letterList + n, player_move);
    int index = std::distance(letterList, itr);
    if(itr != std::end(letterList)){
        for(int i=row;i>=0;i--){
            if(playingField[i][index]=='.'){
                playingField[i][index] = sign;
                break;
            }
        }
    }
}

void displayField(){
    //betűk és számok kijelzése
    std::cout<<" ";
    for(int i=0;i<=row;i++){ 
        for(int k=0;k<=column+1;k++) {
            if(k==column+1){std::cout <<'\n';}
            else if(i==0 && k<=column) {std::cout << letterList[k-1];}//betűk
            else if(k==0 && i<=column) {std::cout << i;}//számok
            else std::cout << playingField[i-1][k-1];
        }
    }
}

int main(){
    bool gameOver = false, draw=false;
    int round = 0;
    bool didItFail=false;
    char first_player_move, sec_player_move;
    int n = sizeof(letterList)/sizeof(letterList[0]);
    //setting up the field
    for(int i=0;i<row;i++) for(int k=0;k<column;k++) playingField[i][k]='.';
    std::cout<<"Welcome to Connect4"<<std::endl;
    displayField();
    do{
        round++;
        std::cout <<round<<". round"<<std::endl;
        //első játékos lép
        if(round%2) {
            do {
                //lecsekkoljuk, hogy nem csúszik-e ki a tartományból a betűválasztás
                didItFail=false;
                std::cout << "First player's move: "<<std::endl;
                std::cin >> first_player_move;
                auto itr = std::find(letterList, letterList + n/*Betűlista hossza*/, first_player_move);
                int index = std::distance(letterList, itr);
                //Nem nincsen-e a választott betű a sorban ÉS Nem csúszik-e ki az index OR Betelt-e a sor(Legfelső indexvizsgálat)
                if((itr != std::end(letterList) && index >= column) || playingField[0][index]!='.'){
                    didItFail = true;
                    std::cout<<"Enter a valid letter!\n";
                }
            }while(didItFail);
            playerMove(first_player_move, 'X');
        }
        //második játékos lép
        else {
            do {
                //lecsekkoljuk, hogy nem csúszik-e ki a tartományból a betűválasztás
                didItFail=false;
                std::cout << "Second player's move: "<<std::endl;
                std::cin >> sec_player_move;
                auto itr = std::find(letterList, letterList + n/*Betűlista hossza*/, sec_player_move);
                int index = std::distance(letterList, itr);
                //Nem nincsen-e a választott betű a sorban ÉS Nem csúszik-e ki az index OR Betelt-e a sor(Legfelső indexvizsgálat)
                if((itr != std::end(letterList) && index >= column) || playingField[0][index]!='.'){
                    didItFail = true;
                    std::cout<<"Enter a valid letter!\n";
                }
            }while(didItFail);
            playerMove(sec_player_move, 'O');
        }
        displayField();
        gameOver = isItGameOver();
        //Megnézzük, nem lépjük-e át a maximális lépések számát
        if(round==row*column){
            std::cout << "Round: "<<round<<std::endl;
            gameOver = true;
            draw=true;
        }
    }while(not gameOver);
    //Eredménykiírás
    if(round%2 and not draw) std::cout << "First player wins"; else if(round%2==0 and not draw) std::cout << "Second player wins"; else std::cout << "Draw";
    return 0;
}
