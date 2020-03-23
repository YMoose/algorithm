#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "fib.h"
// typedef __int64 long;
Fib::Fib(int n){
    f = 1;
    g = 0;
    while(0 < n--){
        g += f;
        f = g - f;
    }
}

__int64 Fib::get(){
    return g;
}

__int64 Fib::next(){
    return g+f;
}

__int64 Fib::prev(){
    return f;
}

__int64 fib1(int n){    // binary recursion
    return (n < 2) ? (__int64) n: fib1( n - 1 ) + fib1( n - 2 );
}

__int64 fib2(int n, __int64& prev){     // linear recursion
    if( 0 == n){
        prev = 1;
        return 0;
    }
    __int64 prevPrev;
    prev = fib2( n - 1, prevPrev);
    return prevPrev + prev;
}

__int64 fib3(int n){    // iteration
    __int64 f = 1, g = 0;
    while(0 < n--){
        g += f;
        f = g - f;
    }
    return g;
}

int main(int argc, char** argv){
    int method;
    time_t start,end;
    printf("what kind of fibonacci function you want to test?\n1) binary recursion\n2) linear recursion\n3) iteration\n");
    scanf("%d",&method);
    start = time(NULL);
    __int64 ret = 0;
    switch((method)%3){
        case 1:
            ret = fib1(45);
            break;
        case 2:
            __int64 prev;
            ret = fib2(45, prev);
            break;
        case 0:
            ret = fib3(45);
            break;
    }
    end = time(NULL);
    printf("fibonacci 45 is %lld, method %d spend %lf s\n", ret, method, difftime(end, start));
    printf("test Fib API\n");
    Fib test = Fib(45);
    printf("Fib 44 is %lld ,Fib 45 is %lld, Fib 46 is %lld",test.prev(), test.get(), test.next());
    return 0;
}