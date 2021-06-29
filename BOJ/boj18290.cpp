#include <cstdio>
#include <algorithm>

#define MAX 10

using namespace std;

int n, m, k, mx = -10000 * 100;
int g[MAX][MAX];
int v[MAX][MAX];  // v = 0 : not visited, v > 0 : visited

void solve(int l, int acc)
{
    if(l == k)
    {
        mx = max(mx, acc);
        return;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!v[i][j])
            {
                // exclude adjacent cells and itself
                if(i - 1 > -1)  v[i - 1][j]++;
                if(i + 1 < n)   v[i + 1][j]++;
                if(j - 1 > -1)  v[i][j - 1]++;
                if(j + 1 < m)   v[i][j + 1]++;
                v[i][j]++;

                solve(l + 1, acc + g[i][j]);

                // include adjacent cell and itself
                if(i - 1 > -1)  v[i - 1][j]--;
                if(i + 1 < n)   v[i + 1][j]--;
                if(j - 1 > -1)  v[i][j - 1]--;
                if(j + 1 < m)   v[i][j + 1]--;
                v[i][j]--;
            }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < m; j++)  
            scanf("%d", &g[i][j]);

    solve(0, 0);

    printf("%d", mx);    
    return 0;
}