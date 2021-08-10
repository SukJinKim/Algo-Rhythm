#include <array>
#include <deque>
#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

const int MIN = 0;
const int MAX = (int)1e5;
const int INF = numeric_limits<int>::max();

array<int, MAX + 1> Time;
deque<int> dq;

bool inRange(int pos)
{
    return (MIN <= pos && pos <= MAX);
}

int main()
{
    int src, dest;
    int currPos, teleportPos, forwardPos, backwardPos;
    scanf("%d %d", &src, &dest);

    fill(Time.begin(), Time.end(), INF);

    Time[src] = 0;
    dq.push_front(src);

    while(!dq.empty())
    {
        currPos = dq.front();
        dq.pop_front();

        if(currPos == dest)
            break;
        
        backwardPos = currPos - 1;
        forwardPos = currPos + 1;
        teleportPos = currPos * 2;

        if(inRange(backwardPos) && Time[currPos] + 1 < Time[backwardPos])
        {
            dq.push_back(backwardPos);
            Time[backwardPos] = Time[currPos] + 1;
        }
        if(inRange(forwardPos) && Time[currPos] + 1 < Time[forwardPos])
        {
            dq.push_back(forwardPos);
            Time[forwardPos] = Time[currPos] + 1;
        }
        if(inRange(teleportPos) && Time[currPos] < Time[teleportPos])
        {
            dq.push_front(teleportPos);
            Time[teleportPos] = Time[currPos];
        }
    }

    printf("%d\n", Time[dest]);
    return 0;
}
