#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int a[8];

int main()
{
    int n, tmp, mx = INT_MIN;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)  scanf("%d", &a[i]);

    sort(a, a + n);
    do{
        tmp = 0;
        for(int i = 1; i < n; i++) tmp += abs(a[i - 1] - a[i]);
        mx = max(mx, tmp);
    } while(next_permutation(a, a + n));

    printf("%d", mx);
    return 0;
}