#include <cstdio>
#include <deque>

#define EMPTY 0
#define WALL  1

using namespace std;

typedef pair<int, int> pii;

const int MAX = 100;

deque<pii> dq;

int maze[MAX + 1][MAX + 1];
int n_broken[MAX + 1][MAX + 1];
bool visited[MAX + 1][MAX + 1];

int x[4] = {0, +1, 0, -1};
int y[4] = {-1, 0, +1, 0};

bool inRange(int x, int y, int n, int m)
{
    return (1 <= x && x <= n) &&
           (1 <= y && y <= m);
}

void insert(int x, int y, int n)
{
    visited[x][y] = true;
    n_broken[x][y] = n;

    if(maze[x][y] == WALL)  dq.push_back(make_pair(x, y));
    else                    dq.push_front(make_pair(x, y));
}

int main()
{
    int n, m;
    int curr_x, curr_y, next_x, next_y;
    scanf("%d %d", &n, &m);

    for(int j = 1; j <= m; j++)
        for(int i = 1; i <= n; i++)
            scanf("%1d", &maze[i][j]);
    
    insert(1, 1, 0);
    while(!dq.empty())
    {
        curr_x = dq.front().first;
        curr_y = dq.front().second;
        dq.pop_front();

        if(curr_x == n && curr_y == m)
            break;

        for(int i = 0; i < 4; i++)
        {
            next_x = curr_x + x[i];
            next_y = curr_y + y[i];

            if(inRange(next_x, next_y, n, m) && !visited[next_x][next_y])
            {
                if(maze[next_x][next_y] == WALL)    insert(next_x, next_y, n_broken[curr_x][curr_y] + 1);
                else                                insert(next_x, next_y, n_broken[curr_x][curr_y]);
            }
        }

    }

    printf("%d\n", n_broken[n][m]);
    return 0;
}
