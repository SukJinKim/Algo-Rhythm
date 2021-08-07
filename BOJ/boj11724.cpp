#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, vector<int> > graph;
bool visited[1000];

int ans;

void findConnectedComponent(int vertex)
{
    vector<int> conn_vertices = graph[vertex];
    for(int conn_v : conn_vertices)
    {
        if(!visited[conn_v])
        {
            visited[conn_v] = true;
            findConnectedComponent(conn_v);
            ans--;
        }
    }
}

int main()
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ans = n;

    for(auto &x : graph)
    {
        int vertex = x.first;
        if(!visited[vertex])
        {
            visited[vertex] = true;
            findConnectedComponent(vertex);
        }
    }

    printf("%d", ans);
    return 0;
}
