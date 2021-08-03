#include <vector>
#include <cmath>

using namespace std;

int n_one_before_zero (long long x)
{
    int n = 0;
    
    while(x & 0b1)
    {
        n++;
        x >>= 1;
    }
    
    return n;
}

long long f(long long x)
{
    long long res;
    
    if(x % 2)   res = x + (long long)pow(2.0, n_one_before_zero(x) - 1);
    else        res = x + 1;
    
    return res;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int n = numbers.size();
    
    for(int i = 0; i < n; i++)
        answer.push_back(f(numbers[i]));
    
    return answer;
}