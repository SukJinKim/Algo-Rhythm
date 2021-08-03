#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> pos(500000, vector<int>());
bool visited[500000];

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    
    if(n < 4)
        return 0;
    
    for(int i = 0; i < n; i++)  
        pos[a[i]].push_back(i);
    
    for(int i = 0; i < n; i++)
    {
        int size = pos[i].size();
        
        if(size < 2)
            continue;
        
        vector<int> star_seq;
        
        for(int j = 0; j < size; j++)
        {
            int prev = (j > 0) ? pos[i][j - 1] : -1;
            int curr = pos[i][j];
            int next = (j < size - 1) ? pos[i][j + 1] : n;
            
            for(int idx = prev + 1; idx < next; idx++)
            {
                if(idx == curr)
                    continue;
                
                if(!visited[idx])
                {
                    star_seq.push_back(a[idx]);
                    star_seq.push_back(a[curr]);
                    visited[idx] = true;
                    break;
                }
            }
        }
        memset(visited, false, sizeof(visited));
        
        if(star_seq.size() > answer)
            answer = star_seq.size();
    }

    return answer;
}