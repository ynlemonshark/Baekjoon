// [1048]유니콘 PLAT4

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int n, m, l;

vector<char> ustr;

vector<int> mindex[26];

vector<long long int> dp[50];

int abs(int a)
{
    return (a<0)?-a:a;
}

int goable(int dpt, int dst)
{
    int dx = abs((dpt % m) - (dst % m));
    int dy = abs((dpt / m) - (dst / m));
    if (dx + dy > 4 & dx > 1 & dy > 1)
        return 1;
    else
        return 0;
}

long long int rec(int depth, int idx)
{
    long long int sum = 0;
    if (dp[depth].empty())
    {
        for (int i=0; i<mindex[depth].size(); i++)
        {
            dp[depth].push_back(rec(depth + 1, i));
        }
    }
    
    for (int i=0; i<mindex[depth].size(); i++)
    {
        if (goable(mindex[depth][i], mindex[depth][idx]))
            sum += dp[depth][i];
    }
    return sum % 1000000007;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d %d %d\n", &n, &m, &l);
    
    vector<char> board;

    char c;
    scanf("%c", &c);
    while (c != '\n')
    {
        ustr.push_back(c);
        scanf("%c", &c);
    }
    int len = ustr.size() - 1;
    
    board.reserve(n*m);

    char trash;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            scanf("%c", &c);
            board.push_back(c);
            mindex[c-'A'].push_back(i*m + j);
        }
        scanf("%c", &trash);
    }

    dp[len - 1].resize(mindex[ustr.back() - 'A'].size(), 1);

    long long int sumall;
    for (int i=0; i<mindex[0].size(); i++)
    {
        sumall += rec(0, i);
    }
    sumall % 1000000007;
    printf("%lld", sumall);
    return 0;
}
