#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int w[10][10];
int route[10];
int mn = INT_MAX;

int main()
{
    int n, tmp, src, dest;
    bool possible, necessary;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++)  for(int j = 0; j < n; j++)  scanf("%d", &w[i][j]);
    for(int i = 0; i < n; i++)  route[i] = i;

    do
    {
        tmp = 0;
        possible = true;
        necessary = true;

        for(int i = 1; i <= n; i++)
        {
            src = route[i - 1 % n];
            dest = route[i % n];
            
            if(!w[src][dest])
            {
                possible = false;
                break;
            }

            tmp += w[src][dest];

            if(tmp > mn)
            {
                necessary = false;
                break;
            }
        }
        if(!possible || !necessary)   continue;

        mn = min(mn, tmp);
    } while (next_permutation(route, route + n));

    printf("%d\n", mn);
    return 0;
}