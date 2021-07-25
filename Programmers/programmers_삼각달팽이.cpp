#include <string>
#include <vector>

using namespace std;

int triangle[1000][1000];
int last_i, last_j, tri_id = 1;

void goToBottom(int src_i, int src_j, int len)
{
    int i = src_i, j = src_j;
    
    while(len--)
    {
        last_i = i, last_j = j;
        triangle[i++][j] = tri_id++;
    }
}

void goToRight(int src_i, int src_j, int len)
{
    int i = src_i, j = src_j;
    
    while(len--)
    {
        last_i = i, last_j = j;
        triangle[i][j++] = tri_id++;
    }
}

void goToTopLeftDiagonal(int src_i, int src_j, int len)
{
    int i = src_i, j = src_j;
    
    while(len--)
    {
        last_i = i, last_j = j;
        triangle[i--][j--] = tri_id++;
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    int len = n, n_go = 0;
    int src_i = 0, src_j = 0;
    
    while(len)
    {
        switch(n_go++ % 3)
        {
            case 0:
                goToBottom(src_i, src_j, len);
                src_i = last_i;
                src_j = last_j + 1;
                break;
            case 1:
                goToRight(src_i, src_j, len);
                src_i = last_i - 1;
                src_j = last_j - 1;
                break;
            case 2:
                goToTopLeftDiagonal(src_i, src_j, len);
                src_i = last_i + 1;
                src_j = last_j;
                break;
        }
        
        len--;
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            answer.push_back(triangle[i][j]);
    
    return answer;
}