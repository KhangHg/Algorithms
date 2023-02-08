#include <bits/stdc++.h>

using namespace std;

int k, n;

int C(int k, int n)
{
    if (n == 0)
        return 0;
    if (k == n || k == 0)
        return 1;
    return C(k, n - 1) + C(k - 1, n - 1);
}

int a[999][999];
int boo[999][999];

void B(int i, int j)
{
    if (boo[i][j] == 1)
    {
        B(i + 1, j);
        boo[i + 1][j] = 1;
    }
    a[i][j] = a[i][j - 1] + a[i - 1][j - 1];
    if (i == k && j == n)
    {
        return;
    }
}

int main()
{
    cin >> k;
    cin >> n;
    // cout << C(k, n);

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            boo[i][j] = 0;
        }
    }

    a[0][0] = a[1][0] = 1;
    B(1, 1);
    cout << a[k][n];
}