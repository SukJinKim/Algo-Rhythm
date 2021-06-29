#include <cstdio>

int n, m;
char seq[16 + 1];
bool visited[8];

void permutation(int l)
{
    if(l == m)
    {
        printf("%s\n", seq);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            seq[2 * l] = i + '1';
            permutation(l + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < 2 * m; i++)  seq[i] = ' ';   // make it printable
    seq[2 * m] = 0x0;
    permutation(0);
    return 0;
}