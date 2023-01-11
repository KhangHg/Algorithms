#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;

int n, c[MAX][MAX], F[MAX][MAX];
int ans = 0;

void input()
{
    cin >> n;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c[i][j];
        }
    }
}

bool contains(unsigned int S, int x)
{
    if (S & (1 << x))
    {
        return true;
    }
    else
    {
        return false;
    }
}
unsigned int removeElement(unsigned int S, int x)
{
    return S & (~(1 << x));
}

unsigned int addElement(unsigned int S, int x)
{
    return S | (1 << x);
}

int TSP(int i, unsigned int S)
{
    if (S == 0)
    {
        F[i][S] = c[i][0];
        return F[i][S];
    }
    if (F[i][S] < 0)
    {
        F[i][S] = 1e9;
        for (int j = 0; j <= n - 1; j++)
        {
            if (contains(S, j))
            {
                unsigned int Sj = removeElement(S, j);
                int Tj = TSP(j, Sj) + c[i][j];
                if (F[j][S] > Tj)
                {
                    F[i][S] = Tj;
                }
            }
        }
    }

    return F[i][S];
}

int main()
{
    input();
    for (int i = 0; i < 20; i++)
    {
        for (unsigned int S = 0; S < MAX; S++)
        {
            F[i][S] = -1;
        }
    }

    unsigned int S = (1 << n) - 1; // S = {1,2,...,n-1}
    ans = TSP(0, S);
    cout << ans;
    return 0;
}
