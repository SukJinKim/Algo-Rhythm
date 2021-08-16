#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 10;

long long mx = 0;

int w[MAX + 1];
bool visited[MAX + 1];

void gatherEnergy(long long acc, int n, int level)
{
    int left, right;

    if(level == n - 2)
    {
        mx = max(mx, acc);
        return;
    }

    for(int i = 2; i <= n - 1; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            
            left = i - 1, right = i + 1;
            while(visited[left]) { left--; }
            while(visited[right]) { right++; }
            
            gatherEnergy(acc + 1LL * w[left] * w[right], n, level + 1);
            
            visited[i] = false;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    gatherEnergy(0, n, 0);

    printf("%lld", mx);
    return 0;
}
