// [1016]제곱ㄴㄴ수 GOLD1 - SUCC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

signed char *table;
unsigned char *erat;

void seterat(int idx)
{
    erat[idx/8] &= ~(1 << (idx%8));
}

int readerat(int idx)
{
    return (erat[idx/8] >> (idx%8)) & 1;
}

unsigned long long int nsqr(unsigned long long int n)
{
    unsigned long long int sum = 0;
    unsigned long long int rt = 2;
    while (rt*rt <= n){
        sum += (n/(rt*rt)) * table[rt];
        rt++;
    }
    return (n + sum);
}

int main() {
    // making möbius function table
    // with sieve of Eratosthenes
    table = (signed char *)malloc(1000002);
    // making the sieve with the least size : one number per a bit
    erat = (unsigned char *)(malloc(125001));
    int p = 2;
    int q;
    memset((void *)table, 1, 1000002);
    while (p*p <= 1000001) {
        q = 1;
        while (p*p*q <= 1000001){
            table[p*p*q] = 0;
            q++;
        }
        p++;
    }
    table[0] = 0;
    int k;
    memset((void *)erat, -1, 125001);
    for (int i=2; i<1000000; i++){
        if (readerat(i)){
            k = 1;
            while (i*k < 1000000){
                seterat(i*k);
                table[i*k] *= -1;
                k++;
            }
        }
    }
    unsigned long long int min, max;
    scanf("%llu %llu", &min, &max);
    printf("%llu", nsqr(max) - nsqr(min - 1));
    return 0;
}
