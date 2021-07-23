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

    for(int i = 0; i < n; i++)
    {
        lis[i] = 1;

        for(int j = 0; j < i; j++)
            if(a[i] > a[j])
                lis[i] = max(lis[i], lis[j] + 1);
    }

    ans = *max_element(lis, lis + n);
    printf("%d", ans);
    return 0;
}
