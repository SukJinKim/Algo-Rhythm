#include <cstdio>
#include <algorithm>

using namespace std;

int p[10000];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)  scanf("%d", &p[i]);

    int a = n - 2;
    while(a >= 0 && p[a] <= p[a + 1])    a--;

    if(a >= 0)
    {
        int b = n - 1;
        while(p[a] < p[b]) b--;
        swap(p[a], p[b]);
        
        int c = a + 1;
        int d = n - 1;
        while(c < d)
        {
            swap(p[c], p[d]);
            c++, d--;
        }

        for(int i = 0; i < n; i++)  printf("%d ", p[i]);
    }
    else
        printf("-1\n");

    return 0;
}