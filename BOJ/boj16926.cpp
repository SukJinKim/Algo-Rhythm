#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 300;

int A[MAX + 1][MAX + 1];

enum DIRECTION
{
    DOWN,
    RIGHT,
    UP,
    LEFT
};

// DOWN, RIGHT, UP, LEFT
int dx[4] = {+1, 0, -1, 0};
int dy[4] = {0, +1, 0, -1};

void moveA(int &curr_x, int &curr_y, int &tmp, int n, DIRECTION d)
{
    int next_x, next_y;

    for(int i = 0; i < n; i++)
    {
        switch(d)
        {
            case DOWN:
                next_x = curr_x + dx[0];
                next_y = curr_y + dy[0];
                break;
            case RIGHT:
                next_x = curr_x + dx[1];
                next_y = curr_y + dy[1];
                break;
            case UP:
                next_x = curr_x + dx[2];
                next_y = curr_y + dy[2];
                break;
            case LEFT:
                next_x = curr_x + dx[3];
                next_y = curr_y + dy[3];
                break;
        }

        swap(tmp, A[next_x][next_y]);

        curr_x = next_x;
        curr_y = next_y;
    }
}

void rotate(int n, int m, int r, int start_x, int start_y)
{
    if(n == 0 || m == 0)
        return;

    int curr_x, curr_y, tmp, period;

    curr_x = start_x;
    curr_y = start_y;
    tmp = A[curr_x][curr_y];

    moveA(curr_x, curr_y, tmp, n - 1, DOWN);
    moveA(curr_x, curr_y, tmp, m - 1, RIGHT);
    moveA(curr_x, curr_y, tmp, n - 1, UP);
    moveA(curr_x, curr_y, tmp, m - 1, LEFT);

    rotate(n - 2, m - 2, r, start_x + 1, start_y + 1);
}

int main()
{
    int n, m, r;
    scanf("%d %d %d", &n, &m, &r);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &A[i][j]);
    
    for(int i = 0; i < r; i++)
        rotate(n, m, r, 1, 1);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    
    return 0;
}
