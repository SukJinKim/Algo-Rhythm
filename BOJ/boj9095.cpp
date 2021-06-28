#include <cstdio>

int f[11];

int main()
{
    int t, n, tmp;
    scanf("%d", &t);
    
    for(int i = 1; i < 11; i++)
    {
        tmp = 0;
        for(int j = 1; j <= 3; j++)
        {
            if(i - j < 0)   break;
            if(i - j)       tmp += f[i - j];
            else            tmp += 1;
        }
        f[i] = tmp;
    }

    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%d\n", f[n]);
    }
    return 0;
}