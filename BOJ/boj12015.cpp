#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = (int)1e7;

int a[SIZE];
vector<int> lis;

int main()
{
    int n, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)  scanf("%d", &a[i]);

    lis.push_back(a[0]);
    for(int i = 1; i < n; i++)
    {
        int last_idx = lis.size() - 1;
        if(lis[last_idx] < a[i])
            lis.push_back(a[i]);
        else
        {
            int pos = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[pos] = a[i];
        }
    }

    ans = lis.size();
    printf("%d", ans);
    return 0;
}