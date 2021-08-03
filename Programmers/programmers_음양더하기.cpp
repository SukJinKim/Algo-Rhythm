#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int n = absolutes.size();
    
    for(int i = 0; i < n; i++)
        answer += (signs[i]) ? absolutes[i] : -1 * absolutes[i];
    
    return answer;
}