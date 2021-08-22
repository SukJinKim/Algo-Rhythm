#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int NUM_ALPHA = 26;
const int NUM_WORDS = 50;
int n, k, ans;

bool visited[NUM_ALPHA];
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
        bool enable = true;
        string word = words[i];

        for(int j = 0; j < word.size(); j++)
        {
            if(!visited[char2Idx(word[j])])
            {
                enable = false;
                break;
            }
        }

        if(enable)
            num++;
    }

    return num;
}

void findLetters(int n_found, int ch_idx)
{
    if(n_found == k)
    {
        int n_readable_words = findNumOfReadableWords();
        ans = max(ans, n_readable_words);
        return;
    }

    for(int idx = ch_idx; idx <= NUM_ALPHA; idx++)
    {
        if(!visited[idx])
        {
            visited[idx] = true;
            findLetters(n_found + 1, idx + 1);
            visited[idx] = false;
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
        visited[char2Idx('a')] = true;
        visited[char2Idx('c')] = true;
        visited[char2Idx('i')] = true;
        visited[char2Idx('n')] = true;
        visited[char2Idx('t')] = true;

       findLetters(5, 0);
    }

    cout << ans << endl;
    return 0;
}
