#include <cstdio>

using namespace std;

const int UNKNOWN = 0;

int sudoku[9][9];

bool check_square(int x, int y, int n)
{
    for(int r = (x / 3) * 3, a = 0; a < 3; r++, a++)
        for(int c = (y / 3) * 3, b = 0; b < 3; c++, b++)
            if(sudoku[r][c] == n)
                return false;
    return true;
}

bool check_col(int y, int n)
{
    for(int x = 0; x < 9; x++)
        if(sudoku[x][y] == n)
            return false;
    return true;
}

bool check_row(int x, int n)
{
    for(int y = 0; y < 9; y++)
        if(sudoku[x][y] == n)
            return false;
    return true;
}

bool solve(int start_x, int start_y)
{
    for(int x = start_x; x < 9; x++)
        for(int y = (x == start_x) ? start_y : 0; y < 9; y++)
        {
            if(sudoku[x][y] == UNKNOWN)
            {
                for(int n = 1; n <= 9; n++)
                {
                    if(check_row(x, n) && check_col(y, n) && check_square(x, y, n))
                    {
                        sudoku[x][y] = n;
                        if(solve(x, y))
                            return true;
                    }

                    sudoku[x][y] = 0;
                }
                
                return false;
            }
        }
        
    return true;
}

int main()
{
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            scanf("%d", &sudoku[i][j]);

    solve(0, 0);

    for(int i = 0; i < 9; i++, printf("\n"))
        for(int j = 0; j < 9; j++, printf(" "))
                printf("%d", sudoku[i][j]);

    return 0;
}
