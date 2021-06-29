#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> seq;

void solve(int l, int prev)
{
    if(l == m)
    {
        for(int i = 0; i < seq.size(); i++) printf("%d ", seq[i]);
        printf("\n");
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(prev <= i)
        {
            seq.push_back(i);
            solve(l + 1, i);
            seq.pop_back();
        }
    }       
}

int main()
{
    scanf("%d %d", &n, &m);
    solve(0, 0);
    return 0;
}