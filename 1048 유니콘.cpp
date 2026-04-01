// [1048]유니 PLAT4

#include <iostream>
#include <vector>
#include <string>



vector<char> str;
str.reserve(51);

vector<int> index[26];

vector<long long int> dp[50];

using namespace std;

long long int rec(int depth, vector<int>& str, )
{
    
}

int main() {
    ios::sync_with_stdio(false);
    cin::tie(NULL);

    int n, m, l;
    scanf("%d %d %d\n", &n, &m, &l);
    
    vector<char> board;

    char c;
    scanf("%c", &c);
    while (c != '\n')
    {
        str.push_back(c);
        scanf("%c", &c);
    }
    str.push_back('\0');
    int len = str.size() - 1;

    char trash;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            scanf("%c", &c);
            board.push_back(c);
            index[c-'a'].push_back(i*m + j);
        }
        scanf("%c", &trash);
    }
    
    board.reserve(n*m);
    
    return 0;
}
