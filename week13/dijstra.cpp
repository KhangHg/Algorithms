#include <bits/stdc++.h>

using namespace std;

#define N 100001
#define pii queue<>;

struct Arc
{
    int nod;
    int w;
    Arc(int _nod, int _w)
    {
        nod = _nod;
        w = _w;
    }
};
int m, n;
vector<Arc> A[N];
int d[N], p[N];
int s, t;
void input()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        A[N].push_back(Arc(v, w));
    }

    scanf("%d%d", &s, &t);
}

int selectMin(set<int> &NonFixed)
{
    int minD = INFINITY;
    int sel_v = -1;
    for (set<int>::iterator it = NonFixed.begin(); it != NonFixed.end(); it++)
    {
        int v = *it;
        if (d[v] < minD)
        {
            minD = d[v];
            sel_v = v;
        }
    }
}
// void dijksrta()
// {
// }

// void dijkstraPriorityQueue()
// {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;

//     pq.push(make_pair(2, 20));
//     pq.push(make_pair(5, 50));
//     pq.push(make_pair(10, 100));
//     pq.push(make_pair(3, 30));

//     while (!pq.empty())
//     {
//         pii e = pq.top();
//         pq.pop();
//         cout << e.first << "," << e.second << endl;
//     }
// }

int main()
{

    // dijkstraPriorityQueue();
}