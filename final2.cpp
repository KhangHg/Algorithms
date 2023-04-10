#include <bits/stdc++.h>
using namespace std;

#define se second
#define mp make_pair
#define pb push_back
#define EL putchar('\n');
#define mod 1000000007
#define oo 100006

#define pii pair<int, int>

#define MIN(x, y) \
    if (x > (y))  \
    x = (y)
#define MAX(x, y) \
    if (x < (y))  \
    x = (y)
#define fi first

#define INF 0x3f3f3f3f
#define ppi pair<ll, pii>

#define F(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define FD(i, a, b) for (int i = (int)a; i >= (int)b; i--)
ll base = 1e9 + 7;
int n, m, k;
vector<pii> a[oo];
int ok[oo];
long long L[oo][32];
#define reset(x, y) memset(x, y, sizeof(x))

void ghi(int x)
{
    if (x > 9)
        ghi(x / 10);
    putchar(x % 10 + '0');
}

int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
main()
{
    ifstream cin("input.txt");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sotest = 1;
    // cin>>sotest;
    while (1)
    {
        cin >> n >> m;
        F(i, 1, n)
        {
            a[i].clear();
            ok[i] = 0;
        }
        F(i, 1, m)
        {
            int x, y, c;
            cin >> x >> y >> c;
            a[x].pb(mp(y, c));
            a[y].pb(mp(x, c));
        }
        cin >> k;
        F(i, 1, k)
        {
            int x;
            cin >> x;
            ok[x] = i;
        }
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        F(i, 1, n)
        {
            F(j, 0, 31)
            L[i][j] = 1e15;
            if (ok[i])
            {
                pq.push(mp(0, mp(i, 1 << (ok[i] - 1))));
                L[i][1 << (ok[i] - 1)] = 0;
            }
        }
        int tt = (1 << k) - 1;
        while (!pq.empty())
        {
            int i = pq.top().se.fi;
            int mask = pq.top().se.se;
            ll c = pq.top().fi;
            pq.pop();
            if (L[i][mask] != c)
                continue;
            if (mask == tt)
            {
                cout << L[i][tt] << '\n';
                break;
            }
            for (int z = 0; z < a[i].size(); z++)
            {
                int v = a[i][z].fi;
                c = a[i][z].se;
                int nmask = mask;
                if (ok[v])
                    nmask |= (1 << (ok[v] - 1));
                if (L[v][nmask] <= L[i][mask] + c)
                    continue;
                L[v][nmask] = L[i][mask] + c;
                pq.push(mp(L[v][nmask], mp(v, nmask)));
            }
            for (int z = 0; z <= 31; z++)
            {
                if (L[i][z | mask] > L[i][z] + L[i][mask])
                {
                    L[i][z | mask] = L[i][z] + L[i][mask];
                    pq.push(mp(L[i][z | mask], mp(i, z | mask)));
                }
            }
        }
        break;
    }
}