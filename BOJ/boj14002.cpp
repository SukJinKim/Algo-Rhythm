#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int SIZE = (int)1e7;

int a[SIZE];
vector<int> lis;
stack<pii> tracking;    // (idx, val)
stack<int> tracking_lis;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)  scanf("%d", &a[i]);

    lis.push_back(a[0]);
    tracking.push(make_pair(0, a[0]));
    for(int i = 1; i < n; i++)
    {
        int last_idx = lis.size() - 1;
        if(lis[last_idx] < a[i])
        {
            lis.push_back(a[i]);
            tracking.push(make_pair(last_idx + 1, a[i]));
        }
        else
        {
            int pos = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[pos] = a[i];
            tracking.push(make_pair(pos, a[i]));
        }
    }

    printf("%d\n", lis.size());
    int find_idx = lis.size() - 1;
    while(!tracking.empty() && find_idx >= 0)
    {
        if(find_idx == tracking.top().first)
        {
            tracking_lis.push(tracking.top().second);
            find_idx--;
        }
        
        tracking.pop();
    }

    while(!tracking_lis.empty())
    {
        printf("%d ", tracking_lis.top());
        tracking_lis.pop();
    }
    return 0;
}