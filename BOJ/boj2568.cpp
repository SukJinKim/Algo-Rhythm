#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> connections;
vector<int> lis;
stack<pii> lis_records;                     // (idx of lis, poleA_pos)
stack<int> remove_poleA_pos;

bool compare_connection (pii a, pii b) { return (a.first < b.first); }

int main()
{
    int n, ans;
    int poleA, poleB, poleA_pos, poleB_pos;
    int last_idx, lis_idx, find_idx;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &poleA, &poleB);
        connections.push_back(make_pair(poleA, poleB));
    }

    sort(connections.begin(), connections.end(), compare_connection);

    poleA_pos = connections[0].first;
    poleB_pos = connections[0].second;

    lis.push_back(poleB_pos);
    lis_records.push(make_pair(0, poleA_pos));
    for(int i = 1; i < n; i++)
    {
        last_idx = lis.size() - 1;
        poleA_pos = connections[i].first;
        poleB_pos = connections[i].second;

        if(poleB_pos > lis[last_idx])
        {
            lis.push_back(poleB_pos);
            lis_records.push(make_pair(last_idx + 1, poleA_pos));
        }
        else
        {
            int pos = lower_bound(lis.begin(), lis.end(), poleB_pos) - lis.begin();
            lis[pos] = poleB_pos;
            lis_records.push(make_pair(pos, poleA_pos));
        }
    }

    ans = n - lis.size();
    printf("%d\n", ans);

    find_idx = lis.size() - 1;
    while(!lis_records.empty())
    {
        lis_idx = lis_records.top().first;
        poleA_pos = lis_records.top().second;

        if(lis_idx == find_idx) 
            find_idx--;
        else                    
            remove_poleA_pos.push(poleA_pos);

        lis_records.pop();
    }

    while(!remove_poleA_pos.empty())
    {
        poleA_pos = remove_poleA_pos.top();
        printf("%d\n", poleA_pos);
        remove_poleA_pos.pop();
    }

    return 0;
}
