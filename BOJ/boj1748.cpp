#include <cstdio>
#include <cmath>

typedef long long ll;

int main()
{
    int n, tmp, a = 0;
    ll ans = 0;
    scanf("%d", &n);

    tmp = n;
    while(tmp)
    {
        a++;
        tmp/=10;
    }

   for(int i = 1; i <= a - 1; i++)
       ans += i * (9 * (ll)pow(10.0, i - 1));
    ans += a * (n - (ll)pow(10.0, a - 1) + 1);

    printf("%lld", ans);
    return 0;
}