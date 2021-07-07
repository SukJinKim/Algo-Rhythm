#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

bool visited[10];

string sign;
string mx = "0000000000";
string mn = "9999999999";
int k;

int ctoi(char c)
{
    return c - '0';
}

void solve(string n, int depth)
{
    if(depth == k + 1)
    {
        if(stoll(n) > stoll(mx))    mx = n;
        if(stoll(n) < stoll(mn))    mn = n;
        return;
    
    }
    if(sign[depth - 1] == '<')
        for(int i = ctoi(n[depth - 1]) + 1; i < 10; i++)
            if(!visited[i])
            {
                visited[i] = true;
                solve(n + to_string(i), depth + 1);
                visited[i] = false;
            }
    if(sign[depth - 1] == '>')
        for(int i = 0; i < ctoi(n[depth - 1]); i++)
            if(!visited[i])
            {
                visited[i] = true;
                solve(n + to_string(i), depth + 1);
                visited[i] = false;
            }
}

int main()
{
    cin >> k;
    for(int i = 0; i < k; i++)  cin >> sign[i];

    for(int i = 0; i < 10; i++)
    {
        visited[i] = true;
        solve(to_string(i), 1);
        visited[i] = false;
    }

    cout << mx << "\n" << mn << endl;
    return 0;
}