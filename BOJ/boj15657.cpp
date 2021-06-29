#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int nums[8];
vector<int> seq;

void solve(int l, int prev)
{
    if(l == m)
    {
        for(int i = 0; i < seq.size(); i++) printf("%d ", seq[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(prev <= nums[i])
        {
            seq.push_back(nums[i]);
            solve(l + 1, nums[i]);
            seq.pop_back();
        }
    }       
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)  scanf("%d", &nums[i]);
    sort(nums, nums + n);
    solve(0, 0);
    return 0;
}