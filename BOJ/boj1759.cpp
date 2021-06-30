#include <iostream>
#include <algorithm>

#define MAX 15

using namespace std;

int l, c;
char cipher[MAX + 1];
char alphabets[MAX + 1];

void solve(int depth, int idx, int n_consonants, int n_vowel)
{
    if(depth == l)
    {
        if(n_consonants >= 2 && n_vowel >= 1)
            cout << cipher << endl;
        return;
    }
    for(int i = idx + 1; i < c; i++)
    {
        cipher[depth] = alphabets[i];

        if(alphabets[i] == 'a' || alphabets[i] == 'e' || alphabets[i] == 'i' ||
           alphabets[i] == 'o' || alphabets[i] == 'u')
           solve(depth + 1, i, n_consonants, n_vowel + 1);
        else
           solve(depth + 1, i, n_consonants + 1, n_vowel);
    }
}

int main()
{
    cin >> l >> c;
    for(int i = 0; i < c; i++)  cin >> alphabets[i];
    sort(alphabets, alphabets + c);
    cipher[l + 1] = 0x0;
    solve(0, -1, 0, 0);
    return 0;
}