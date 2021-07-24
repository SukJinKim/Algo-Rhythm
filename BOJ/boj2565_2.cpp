#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<pii> connections;
int lis[501];

bool connection_compare(pii a, pii b)   {return (a.first < b.first);}

int main()
{
    int n, poleA, poleB, ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &poleA, &poleB);
        connections.push_back(make_pair(poleA, poleB));
    }

    sort(connections.begin(), connections.end(), connection_compare);

    for(int k = 0; k < n; k++)
    {
        int poleB_pos_k = connections[k].second;
        lis[k] = 1;

        for(int j = 0; j < k; j++)
        {
            int poleB_pos_j = connections[j].second;
            if(poleB_pos_k > poleB_pos_j)
                lis[k] = max(lis[k], 1 + lis[j]);
        }
    }

    ans = n - *max_element(lis, lis + n);
    printf("%d", ans);
    return 0;
}