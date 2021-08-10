#include <array>
#include <queue>
#include <stack>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MIN = 0;
const int MAX = (int)1e5;
const int UNKNOWN = -1;

queue<int> que;
stack<int> route;
array<int, MAX + 1> Time;
array<int, MAX + 1> parents;

bool inRange(int pos)
{
    return (MIN <= pos && pos <= MAX);
}

void insertPos(int pos, int _time, int parent)
{
    que.push(pos);
    Time[pos] = _time;
    parents[pos] = parent;
}

int main()
{
    int src, dest;
    int currPos, backwardPos, forwardPos, teleportPos;
    scanf("%d %d", &src, &dest);

    fill(Time.begin(), Time.end(), UNKNOWN);

    insertPos(src, 0, src);
    while(!que.empty())
    {
        currPos = que.front();
        que.pop();

        if(currPos == dest)
            break;

        backwardPos = currPos - 1;
        if(inRange(backwardPos) && Time[backwardPos] == UNKNOWN)
            insertPos(backwardPos, Time[currPos] + 1, currPos);

        forwardPos = currPos + 1;
        if(inRange(forwardPos) && Time[forwardPos] == UNKNOWN)
            insertPos(forwardPos, Time[currPos] + 1, currPos);

        teleportPos = currPos * 2;
        if(inRange(teleportPos) && Time[teleportPos] == UNKNOWN)
            insertPos(teleportPos, Time[currPos] + 1, currPos);
    }

    currPos = dest;
    while(currPos != src)
    {
        route.push(currPos);
        currPos = parents[currPos];
    }
    route.push(src);

    printf("%d\n", Time[dest]);
    while(!route.empty())
    {
        printf("%d ", route.top());
        route.pop();
    }
    return 0;
}
