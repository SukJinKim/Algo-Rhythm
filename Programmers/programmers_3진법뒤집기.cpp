#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str_reversed_tri = "";
    
    while(n)
    {
        str_reversed_tri += to_string(n % 3);
        n/=3;
    }
    
    answer = stoi(str_reversed_tri, nullptr, 3);
    
    return answer;
}