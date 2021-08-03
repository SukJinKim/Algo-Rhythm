#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = (int)1e9 + 1;
const int SIZE = (int)1e6;

int l_min[SIZE], r_min[SIZE];

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    
    l_min[0] = MAX;
    for(int i = 1; i < n; i++)  
        l_min[i] = min(l_min[i - 1], a[i - 1]);
    
    r_min[n - 1] = MAX;
    for(int i = n - 2; i >= 0; i--)
        r_min[i] = min(r_min[i + 1], a[i + 1]);
    
    for(int i = 0; i < n; i++)
        if(!(l_min[i] < a[i] && a[i] > r_min[i]))   answer++;
        
    return answer;
}