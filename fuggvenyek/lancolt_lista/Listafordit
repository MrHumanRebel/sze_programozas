elem* fordit(elem* horgony){
    elem* eredeti = horgony;
    elem* forditott = NULL;
    elem* akt = eredeti;
    while(akt != NULL) {
        elem* eredetiKov = akt->kov;
        akt->kov = forditott;
        forditott = akt;
        akt = eredetiKov;
    }
    return forditott;
}
