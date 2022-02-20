#include <iostream>
using namespace std;

int main(){
    char rszam[7];
    bool ok = false;
    do{
        cout <<"Adjon meg egy magyar rendszámot!"<<endl;
        cin >> rszam;
        int vizsgal = 0;

        for(int i=0;i<=2; i++){
            if (rszam[i] >= 65 && rszam[i] <= 90)
                vizsgal++;            
        }

        for(int j=4;j<=6; j++){
            if (rszam[j] >= 48 && rszam[j] <= 57)
                vizsgal++;            
        }

        if (rszam[3] == 45)
            {vizsgal++;}

        
        if (vizsgal == 7)
            {
                ok =true;
                cout << "A megadott rendszám helyes!"<<endl;
            }
        else
            {cout <<"A megadott rendszám nem helyes!"<<endl;
            vizsgal = 0;ok =false;}


    } while (ok==false);


    return 0;
    
}