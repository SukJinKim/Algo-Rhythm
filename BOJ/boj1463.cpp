#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 1;

int mem[MAX];

int main()
{
    int x, f1, f2, f3;
    scanf("%d", &x);

    mem[1] = 0;
    for(int i = 2; i <= x; i++)
    {
        f1 = (i % 3 == 0) ? mem[i / 3] + 1 : MAX;
        f2 = (i % 2 == 0) ? mem[i / 2] + 1 : MAX;
        f3 = mem[i - 1] + 1;
        mem[i] = min(min(f1, f2), f3);
    }

    printf("%d", mem[x]);
    return 0;
}