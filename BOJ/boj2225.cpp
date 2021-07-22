#include <cstdio>

int f[201][201];

void solve(int n, int k)
{
    int tmp = 0;
    for(int i = 0; i <= n; i++)
    {
        tmp += f[n - i][k - 1];
        tmp %= (int)1e9;
    } 
    f[n][k] = tmp;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
        {
            if(i == 0 || j == 1)    f[i][j] = 1;
            else                    solve(i, j);
        }

    printf("%d", f[n][k]);
    return 0;
}