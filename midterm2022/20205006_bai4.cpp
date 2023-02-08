#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
int n;
int a[MAX];
int c[MAX][3];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int sum(int i, int j)
{
    if (i == n + 1)
    {
        return 0;
    }

    if (c[i][j] != 0)
    {
        return c[i][j];
    }

    c[i][j] = sum(i + 1, 0);

    if (j == 0)
    {
        c[i][j] = max(c[i][j], sum(i + 1, 1) + a[i]);
    }
    return c[i][j];
}

int main()
{
    input();
    int res = sum(1, 0);
    cout << res;
    return 0;
}