#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string len_to_bin_str(int len)
{
    string s_bin = "";
    
    while(len)
    {
        s_bin += to_string(len % 2);
        len /= 2;
    }
    reverse(s_bin.begin(), s_bin.end());
    
    return s_bin;
}

vector<int> solution(string s) {
    vector<int> answer;
    int n_transform = 0, n_zero = 0;
    
    while(s != "1")
    {
        n_zero += count(s.begin(), s.end(), '0');
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        s = len_to_bin_str(s.size());
        
        n_transform++;
    }
    
    answer.push_back(n_transform);
    answer.push_back(n_zero);
    return answer;
}
