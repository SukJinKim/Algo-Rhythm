#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int NUM_ALPHA = 26;
const int NUM_WORDS = 50;
int n, k, ans;

int visited = 0;
vector<string> words(NUM_WORDS);

int char2Idx(char ch)
{
    return ch - 'a';
}

int findNumOfReadableWords()
{
    int num = 0;

    for(int i = 0; i < n; i++)
    {
        bool isValid = true;
        string word = words[i];

        for(int j = 0; j < word.size(); j++)
        {
            if(!(visited & (0b1 << char2Idx(word[j]))))
            {
                isValid = false;
                break;
            }
        }

        if(isValid)
            num++;
    }

    return num;
}

void findLetters(int n_found, int start_idx)
{
    if(n_found == k)
    {
        ans = max(ans, findNumOfReadableWords());
        return;
    }

    for(int idx = start_idx; idx <= NUM_ALPHA; idx++)
    {
        if(!(visited & (0b1 << idx)))
        {
            visited |= (0b1 << idx);
            findLetters(n_found + 1, idx + 1);
            visited &= ~(0b1 << idx);
        }
    }
}

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> words[i];

    if(k < 5)
        ans = 0;
    else
    {
        visited |= (0b1 << char2Idx('a'));
        visited |= (0b1 << char2Idx('n'));
        visited |= (0b1 << char2Idx('t'));
        visited |= (0b1 << char2Idx('i'));
        visited |= (0b1 << char2Idx('c'));

       findLetters(5, 0);
    }

    cout << ans << endl;
    return 0;
}
