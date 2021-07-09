#include <cstdio>
#include <climits>

int w[10][10];
bool visited[10];

int n, mn = INT_MAX;

void solve(int src, int acc, int size)
{
    if(acc > mn)    return;
    if(size == n)
    {
        if(w[src][0] && acc + w[src][0] < mn)    mn = acc + w[src][0];
        return;
    }
    for(int dest = 0; dest < n; dest++)
        if(!visited[dest] && w[src][dest])
        {
            visited[dest] = true;
            solve(dest, acc + w[src][dest], size + 1);
            visited[dest] = false;
        }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)  for(int j = 0; j < n; j++)  scanf("%d", &w[i][j]);
    visited[0] = true;
    solve(0, 0, 1);
    printf("%d\n", mn);
    return 0;
}