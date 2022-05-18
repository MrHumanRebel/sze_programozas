termek* torol(termek* horgony, string nev) {
    termek* akt = horgony;
    termek* elozo = NULL;
    while(akt!=NULL){
        termek* kov = akt->kov;
        if(akt->nev == nev){
            if(akt==horgony){
                horgony = kov;
            }
            if(elozo != NULL) {
                elozo->kov = kov;
            }
            delete akt;
        } else {
            elozo = akt;
        }
        akt = kov;
    }
    return horgony;
}
