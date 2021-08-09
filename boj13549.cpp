#include <queue>
#include <array>
#include <cstdio>
#include <limits>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

class Greater
{
    public:
        bool operator() (const pii &lhs, const pii &rhs)
        {
            return lhs.second > rhs.second;
        }
};

const int MIN = 0;
const int MAX = (int)1e5;
const int INF = numeric_limits<int>::max();

priority_queue<pii, vector<pii>, Greater> pq;
array<int, MAX + 1> _time;
array<bool, MAX + 1> visited;

int main()
{
    int src, dest;
    int curr_pos, curr_t, backward_pos, forward_pos, teleport_pos;
    scanf("%d %d", &src, &dest);

    fill(_time.begin(), _time.end(), INF);

    _time[src] = 0;
    pq.push(make_pair(src, 0));

    while(!pq.empty())
    {
        curr_pos = pq.top().first;

        if(curr_pos == dest)
            break;

        if(!visited[curr_pos])
        {
            visited[curr_pos] = true;
            
            backward_pos = curr_pos - 1;
            forward_pos = curr_pos + 1;
            teleport_pos = curr_pos * 2;

            if(MIN <= backward_pos && backward_pos <= MAX && _time[curr_pos] + 1 < _time[backward_pos])
            {
                _time[backward_pos] = _time[curr_pos] + 1;
                pq.push(make_pair(backward_pos, _time[backward_pos]));
            }
            if(MIN <= forward_pos && forward_pos <= MAX && _time[curr_pos] + 1 < _time[forward_pos])
            {
                _time[forward_pos] = _time[curr_pos] + 1;
                pq.push(make_pair(forward_pos, _time[forward_pos]));
            }
            if(MIN <= teleport_pos && teleport_pos <= MAX && _time[curr_pos] < _time[teleport_pos])
            {
                _time[teleport_pos] = _time[curr_pos];
                pq.push(make_pair(teleport_pos, _time[teleport_pos]));
            }
        }

        pq.pop();
    }

    printf("%d\n", _time[dest]);
    return 0;
}
