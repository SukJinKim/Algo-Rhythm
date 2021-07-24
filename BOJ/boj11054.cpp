#include <cstdio>
#include <algorithm>

using namespace std;

const int SIZE = (int)1e3;

int a[SIZE];
int lis[SIZE];
int lds[SIZE];

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)  scanf("%d", &a[i]);

    for(int k = 0; k < n; k++)
    {
        lis[k] = 1;

        for(int j = 0; j < k; j++)
            if(a[j] < a[k])
                lis[k] = max(lis[k], 1 + lis[j]);
    }

    for(int k = n - 1; k >= 0; k--)
    {
        lds[k] = 1;

        for(int j = n; j > k; j--)
            if(a[k] > a[j])
                lds[k] = max(lds[k], 1 + lds[j]);
    }

    for(int i = 0; i < n; i++)
        ans = max(ans, lis[i] + lds[i] - 1);

    printf("%d", ans);
    return 0;
}