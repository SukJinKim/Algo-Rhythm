#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000];
int lis[1000];

int main()
{
    int n, ans;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)  scanf("%d", &a[i]);

    for(int k = 0; k < n; k++)
    {
        lis[k] = 1;
        for(int j = 0; j < k; j++)
            if(a[k] < a[j])
                lis[k] = max(lis[k], lis[j] + 1);
    }

    ans = *max_element(lis, lis + n);
    printf("%d", ans);
    return 0;
}