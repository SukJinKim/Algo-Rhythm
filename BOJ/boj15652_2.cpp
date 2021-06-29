#include <cstdio>

int n, m;
char seq[16 + 1];

void permutation(int l, int prev)
{
    if(l == m)
    {
        printf("%s\n", seq);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(prev <= i + 1)
        {
            seq[2 * l] = i + '1';
            permutation(l + 1, i + 1);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < 2 * m; i++)  seq[i] = ' ';   // make it printable
    seq[2 * m] = 0x0;
    permutation(0, 0);
    return 0;
}