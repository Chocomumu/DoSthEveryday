int hammingDistance(int x, int y){
    x ^= y;
    y = 0;
    for(int i = 0;i<32;i++){
        y += (x&1);
        x>>=1;
    }
    return y;
}
