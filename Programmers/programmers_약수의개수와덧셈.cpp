#include <cmath>

using namespace std;

bool hasEvenDivisor(int n)
{
    int n_divisor = 0;
    
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(i * i == n)  
            n_divisor++;
        else if(n % i == 0)
            n_divisor += 2;
    }
    
    return (n_divisor % 2 == 0);
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int n = left; n <= right; n++)
    {
        if(hasEvenDivisor(n))   answer += n;
        else                    answer -= n;
    }
    
    return answer;
}