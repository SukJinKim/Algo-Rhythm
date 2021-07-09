#include <cstdio>
#include <vector>

using namespace std;

vector<int> p;
int s[12];
bool visited[50];

int k;

void solve(int n, int size)
{
    if(size == 6)
    {
        for(int _p : p) printf("%d ", _p);
        printf("\n");
        return;
    }

    for(int i = n; i < k; i++)
    {
        int next_n = s[i];
        if(!visited[next_n])
        {
            visited[next_n] = true;
            p.push_back(next_n);
            solve(i, size + 1);
            p.pop_back();
            visited[next_n] = false;
        }
    }
}

int main()
{
    while(true)
    {
        scanf("%d", &k);
        if(!k)  break;

        for(int i = 0; i < k; i++)  scanf("%d", &s[i]);

        solve(0, 0);
        printf("\n");
    }
    return 0;
}