#include <cstdio>
#include <algorithm>

using namespace std;

int a[1000];
int gis[1000];

int main()
{
    int n, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)  scanf("%d", &a[i]);

    for(int i = 0; i < n; i++)
    {
        gis[i] = a[i];

        for(int j = 0; j < i; j++)
            if(a[i] > a[j])
                gis[i] = max(gis[i], a[i] + gis[j]);
    }

    ans = *max_element(gis, gis + n);
    printf("%d", ans);
    return 0;
}
