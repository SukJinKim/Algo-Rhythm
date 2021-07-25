#include <string>
#include <vector>

using namespace std;

int n_zero = 0, n_one = 0;

bool all_equal(vector<vector<int>> &arr, int x_pos, int y_pos, int n)
{
    bool all_eq = true;
    int tmp = arr[x_pos][y_pos];
    
    for(int x = x_pos; x < x_pos + n; x++)
        for(int y = y_pos; y < y_pos + n; y++)
            if(tmp != arr[x][y])
            {
                all_eq = false;
                break;
            }
    
    return all_eq;
}

void quad_comp(vector<vector<int>> &arr, int x_pos, int y_pos, int n)
{   
    if(n == 1)
    {
        if(arr[x_pos][y_pos] == 1)  n_one++;
        else                        n_zero++;
        return;
    }
    
    if(all_equal(arr, x_pos, y_pos, n))
    {
        if(arr[x_pos][y_pos] == 1)  n_one++;
        else                        n_zero++;
    }
    else
    {
        int x_offset = x_pos, y_offset = y_pos;
        
        for(int x = 0; x < n; x += n / 2)
            for(int y = 0; y < n; y += n / 2)
                quad_comp(arr, x + x_offset, y + y_offset, n / 2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    int n = arr.size();
    
    quad_comp(arr, 0, 0, n);
    
    answer.push_back(n_zero);
    answer.push_back(n_one);
    return answer;
}
