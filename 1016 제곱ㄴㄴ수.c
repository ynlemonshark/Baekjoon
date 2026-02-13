// [1016]제곱ㄴㄴ수 GOLD1 - FAIL

#include <stdio.h>

long long int nsqr(int num)
{
    static int cnt;
    cnt++;
    long long int rt = 1;
    long long int nsq;
    long long int sum = 0;
    while ((rt+1)*(rt+1) <= num){
        rt++;
        // nsq = 2;
        // while (nsq * nsq <= num / (rt*rt))
        //     nsq++;
        // nsq -= 2;
        // sum += (num / (rt*rt)) - nsq;
        sum += nsqr(num / (rt*rt));
        //printf("rt:%lld nsq:%lld s:%lld\n", rt, nsq, (num / (rt*rt)) - nsq);
    }
    return (num - sum);
}

int main() {
    long long int min, max;
    scanf("%lld %lld", &min, &max);
    printf("%lld", nsqr(max) - nsqr(min - 1));
}
