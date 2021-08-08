#include <cstdio>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

enum vertex_stat 
{
    NONE,
    GRAPH1,
    GRAPH2
};

unordered_map<int, vector<int> > graph;
vertex_stat vertex_stats[20001];        // default : NONE
bool visited[20001];                    // default : false

bool _isBipartiteGraph(int parent)
{
    vector<int> children = graph[parent];
    for(int child : children)
    {
        vertex_stat &parent_stat = vertex_stats[parent];
        vertex_stat &child_stat = vertex_stats[child];

        if(visited[child])
        {
            if(parent_stat == child_stat)
                return false;
        }
        else
        {
            if(parent_stat == GRAPH1)   child_stat = GRAPH2;
            if(parent_stat == GRAPH2)   child_stat = GRAPH1;

            visited[child] = true;
            if(!_isBipartiteGraph(child))
                return false;
        }
    }
    
    return true;
}

bool isBipartiteGraph()
{
    for(auto &x : graph)
    {
        int root = x.first;
        if(!visited[root])
        {
            vertex_stats[root] = GRAPH1;

            visited[root] = true;   
            if(!_isBipartiteGraph(root))
                return false;
        }
    }

    return true;
}

int main()
{
    int k, v, e, v1, v2;
    scanf("%d", &k);

    for(int i = 0; i < k; i++)
    {
        scanf("%d %d", &v, &e);

        for(int j = 0; j < e; j++)
        {
            scanf("%d %d", &v1, &v2);
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        printf("%s\n", isBipartiteGraph() ? "YES" : "NO");

        memset(vertex_stats, NONE, sizeof(vertex_stats));
        memset(visited, false, sizeof(visited));
        graph.clear();
    }
    
    return 0;
}
