#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> graph;

long long answer = 0;

bool isPossible(vector<long long> &weights)
{
    long long sum = 0;
    for(long long w: weights)
        sum += w;
    return (sum == 0);
}

void dfs(vector<long long> &weights, int parent, int child)
{
    for(int grandChild : graph[child])
        if(grandChild != parent)
            dfs(weights, child, grandChild);
    
    answer += abs(weights[child]);
    weights[parent] += weights[child];
    weights[child] = 0;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    int u, v;
    vector<long long> weights(a.size());
    
    copy(a.begin(), a.end(), weights.begin());
    
    if(!isPossible(weights))
        return -1;

    for(int i = 0; i < edges.size(); i++)
    {
        u = edges[i][0];
        v = edges[i][1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    dfs(weights, 0, 0);
    
    return answer;
}
