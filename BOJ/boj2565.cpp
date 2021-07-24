#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> connections;
vector<int> lis;

bool compare_connection (pii a, pii b) { return (a.first < b.first); }

int main()
{
    int n, poleA, poleB, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &poleA, &poleB);
        connections.push_back(make_pair(poleA, poleB));
    }

    sort(connections.begin(), connections.end(), compare_connection);

    lis.push_back(connections[0].second);
    for(int i = 1; i < n; i++)
    {
        int last_idx = lis.size() - 1;
        int poleB_pos = connections[i].second;

        if(poleB_pos > lis[last_idx])
            lis.push_back(poleB_pos);
        else
        {
            int pos = lower_bound(lis.begin(), lis.end(), poleB_pos) - lis.begin();
            lis[pos] = poleB_pos;
        }
    }

    ans = n - lis.size();
    printf("%d", ans);
    return 0;
}