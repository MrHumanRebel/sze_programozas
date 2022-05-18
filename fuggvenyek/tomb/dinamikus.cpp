//a0=kezdoeertek, d=lepeskoz, n = darabszam
int* sorozat(int a0, int d, unsigned n) {
    if(n==0){
        return NULL;
    }else {
        int *tomb = new int[n];
        int aktElem=a0;
        for(unsigned int k=0;k<n;k++){
            *(tomb+k) = aktElem;
            aktElem+=d;
        }
        return tomb;
    }
}
