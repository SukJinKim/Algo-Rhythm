#include <cstdio>

int n;
char p[17];
bool visited[9];

void solve(int depth)
{
    if(depth == n)
    {
        printf("%s\n", p);
        return;
    }

    for(int i = 1; i <= n / 2; i++)
        if(!visited[i])
        {
            visited[i] = true;
            p[depth] = i + '0';
            solve(depth + 2);
            visited[i] = false;
        }
}

int main()
{
    scanf("%d", &n);
    n += n;
    for(int i = 0; i < n; i++)  p[i] = ' ';
    p[n] = 0x0;
    solve(0);
    return 0;
}