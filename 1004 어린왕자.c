// [1004]어린 왕자 SILV3 - SUCC

#include <stdio.h>

int isin(int x, int y, int xc, int yc, int r)
{
    x -= xc;
    y -= yc;
    if (x*x + y*y < r*r)
        return 1;
    else
        return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    int n;
    int x1, y1, x2, y2;
    int xc;
    int yc;
    int r;
    int sum;
    for (int t=0; t<T; t++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        sum = 0;
        for (int i=0; i<n; i++){
            scanf("%d %d %d", &xc, &yc, &r);
            if (isin(x1, y1, xc, yc, r) != isin(x2, y2, xc, yc, r))
                sum++;
        }
        printf("%d\n", sum);
    }
    return 0;
}
