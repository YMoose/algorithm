#include <stdio.h>
#include <string>

int gcd1(int x, int y){ // Euclid's algorithm (recursion)
    return x==0? y : gcd1(y % x, x);
}

int gcd2(int x, int y){ // Euclid's algorithm (iteration)
    int r = x % y;
    while(r){
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

int gcd3(int x, int y){ // bit opeartion
    while(y^=x^=y^=x%=y);
    /*
    x1 = x % y;
    y1 = y ^ x1 = y ^ (x % y);
    x2 = x1 ^ y1 = (x % y) ^ y ^ (x % y) = y;
    y2 = y1 ^ x2 = y ^ y ^ (x % y) = x % y;
    */
    return x;
}

int gcd4(int x, int y){ // 九章算术-中华更相减损法
    int r = 0;
    while(! ( (x & 1) || (y & 1))){
        x >>= 1;
        y >>= 1;
        r ++;
    };
    while(1){
        while(! (x & 1)) x >>= 1;
        while(! (y & 1)) y >>= 1;
        (x > y)? x = x - y : y = y - x;
        if(0 == x ) return y << r;
        if(0 == y ) return x << r;
    }
}

int main(int argc, char** argv){
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    printf("Euclid's algorithm (recursion) answer is %d\n", gcd1(x,y));
    printf("Euclid's algorithm (iteration) answer is %d\n", gcd2(x,y));
    printf("bit opeartion                  answer is %d\n", gcd3(x,y));
    printf("九章算术-中华更相减损法          answer is %d\n", gcd4(x,y));
    return 0;
}