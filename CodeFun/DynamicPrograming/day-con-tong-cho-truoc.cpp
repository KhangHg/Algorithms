// đếm số dãy con có tổng cho trước
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int n, a[MAX], S;
int c[MAX][1000];
// top down
int F(int s, int k)
{
    if (k == 0)
        return (s == 0) ? 1 : 0;
    return (s < a[k]) ? F(s, k - 1) : F(s, k - 1) + F(s - a[k], k - 1);
}

// bottom up
void B(int s, int n)
{
    c[0][0] = 1;
    for (int j = 1; j <= s; j++)
    {
        c[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            c[i][j] = c[i - 1][j];
            if (j >= a[i])
            {
                c[i][j] += c[i - 1][j - a[i]];
            }
        }
    }
}

int main()
{
    cout << "N = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "S = ";
    cin >> S;
    cout << "So day con (top down) : " << F(S, n) << endl;
    B(S, n);
    cout << "So day con ( bottom up) : " << c[n][S];
}