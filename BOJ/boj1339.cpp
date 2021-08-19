#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const int ALPHA_NUM = 26;

vector<int> alpha_weights(ALPHA_NUM);

int main()
{
    string word;
    int n, alpha_idx, weight, ans, digit; 

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> word;
        reverse(word.begin(), word.end());
        
        weight = 1;
        for(int j = 0; j < word.size(); j++)
        {
            alpha_idx = word[j] - 'A';
            alpha_weights[alpha_idx] += weight;
            weight *= 10;
        }
    }

    sort(alpha_weights.begin(), alpha_weights.end(), greater<int>());

    ans = 0, digit = 9;
    for(int i = 0; i < alpha_weights.size(); i++)
    {
        if(alpha_weights[i] == 0 || digit < 0)
            break;

        ans += alpha_weights[i] * digit;
        digit--;
    }
    
    printf("%d", ans);
    return 0;
}
