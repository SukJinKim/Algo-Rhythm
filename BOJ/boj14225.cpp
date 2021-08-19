#include <cstdio>

using namespace std;

const int SEQ_SIZE = 20;
const int CACHE_SIZE = 20 * (int)1e5 + 1;

int seq[SEQ_SIZE];
bool cache[CACHE_SIZE];

void find_psum(int psum, int idx, int &n)
{
    if(idx == n)
    {
        cache[psum] = true;
        return;
    }

    find_psum(psum + seq[idx], idx + 1, n);
    find_psum(psum, idx + 1, n);
}

int main()
{
    int n, ans = 1;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &seq[i]);
    
    find_psum(0, 0, n);
    
    while(cache[ans]) { ans++; }

    printf("%d\n", ans);
    return 0;
}
