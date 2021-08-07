#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX = 2000;

unordered_map<int, vector<int> > graph;
bool visited[MAX];

bool hasABCDE(int vertex, int level)
{
    if(level == 4)
        return true;

    vector<int> vertices = graph[vertex];
    for(int v : vertices)
        if(!visited[v])
        {
            visited[v] = true;
            if(hasABCDE(v, level + 1))
                return true;
            visited[v] = false;
        }

    return false;
}

int main()
{
    int n, m, a, b;
    bool _hasABCDE;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(auto& x : graph)
    {
        int vertex = x.first;
        visited[vertex] = true;
        
        _hasABCDE = hasABCDE(vertex, 0);
        if(_hasABCDE)
            break;

        visited[vertex] = false;
    }
    
    printf("%d", _hasABCDE ? 1 : 0);
    return 0;
}
