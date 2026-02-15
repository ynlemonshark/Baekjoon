// [1002]터렛 SILV1 - SUCC

#include <stdio.h>

int main() {
    int n;
    int x1, y1, r1, x2, y2, r2;
    int dx, dy, r;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        dx = x1 - x2;
        dy = y1 - y2;
        r = (dx*dx)+(dy*dy);
        if (dx == 0 && dy == 0 && r1 == r2)
            printf("-1\n");
        else if (r == (r1+r2)*(r1+r2) || r == (r1-r2)*(r1-r2))
            printf("1\n");
        else if (r > (r1+r2)*(r1+r2) || r < (r1-r2)*(r1-r2))
            printf("0\n");
        else
            printf("2\n");
    }
    return 0;
}
