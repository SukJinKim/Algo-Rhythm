#include <cstdio>

int f[1001];

int main()
{
    int n;
    scanf("%d", &n);

    f[0] = f[1] = 1;
    for(int i = 2; i <= n; i++) f[i] = (f[i - 1] + 2 * f[i - 2]) % 10007;
    
    printf("%d", f[n]);
    return 0;
}
