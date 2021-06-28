#include <cstdio>

int main()
{
    int n, a = 1, ans = 0;
    scanf("%d", &n);

    while(a <= n)
    {
        ans += n - a + 1;
        a *= 10; 
    }

    printf("%d", ans);
    return 0;
}