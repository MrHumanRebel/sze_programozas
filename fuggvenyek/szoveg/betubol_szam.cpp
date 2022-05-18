void betubolszam(const string &s){
    int hosssz = s.length();
    for(int i = 0; i < hosssz; i++){
        if(s[i] >= 'a' && s[i] <= 'i')
            cout << char(s[i] - 'a' + '1');
        else
            cout << s[i];
    }
}
