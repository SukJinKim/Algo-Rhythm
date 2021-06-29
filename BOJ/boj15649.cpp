#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> seq;
bool visited[9];

void solve(int l)
{
    if(l == m)
    {
        for(int i = 0; i < seq.size(); i++) printf("%d ", seq[i]);
        printf("\n");
        return;
    }

    for(int i = 1; i <= n; i++)
        if(!visited[i])
        {
            visited[i] = true;
            seq.push_back(i);
            solve(l + 1);
            seq.pop_back();
            visited[i] = false;
        }
}

int main()
{
    scanf("%d %d", &n, &m);
    solve(0);
    return 0;
}