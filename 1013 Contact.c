// [1013]Contact GOLD5 - SUCC

#include <stdio.h>

int search(char str[], int idx)
{
    int z;
    int o;
    if (str[idx] == '1'){
        idx++;
        // counting 0 after 1;
        z = 0;
        while (str[idx] == '0'){
            z++;
            idx++;
        }
        if (z < 2)
            return 0;
        // the string must end with 1
        // there are no 11 start pattern
        // counting 1 after zeros
        o = 0;
        while (str[idx] == '1'){
            idx++;
            o++;
        }
        if (o == 0)
            return 0;
        else if (o == 1){
            // if string ends with 10...01
            if (str[idx] == '\0')
                return 1;
            return search(str, idx);
        }
        // see how recurse 10...01..1-0 or 10...01...1-10
        else
            return (search(str, idx) || search(str, idx-1));
    }
    else if (str[idx] == '0'){
        // 01 pattern
        if (str[idx+1] == '1'){
            if (str[idx+2] == '\0')
                return 1;
            return search(str, idx + 2);
        }
        return 0;
    }
    // occasion of str[idx] is null character
    return 1;
}

int main() {
    int T;
    scanf("%d\n", &T);
    char str[301];
    int rst;
    for (int i=0; i<T; i++){
        scanf("%s\n", str);
        rst = search(str, 0);
        if (rst)
            printf("YES");
        else
            printf("NO");
        if (i<T-1)
            printf("\n");
    }
    return 0;
}
