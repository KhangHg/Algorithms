#include <bits/stdc++.h>

using namespace std;
#define N 10000001
int n;
int a[N];

void input()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        /* code */
    }
}

int maxLeft(int L, int R)
{
    int sum = 0;
    int ans = -9999999;
    for (int i = R; i >= L; i--)
    {
        sum += a[i];
        /* code */
        if (ans < sum)
        {
            ans = sum;
        }
    }

    return ans;
}

int maxRight(int L, int R)
{
    int sum = 0;
    int ans = -99999999;
    for (int i = L; i <= R; i++)
    {
        sum += a[i];
        /* code */
        if (ans < sum)
        {
            ans = sum;
        }
    }

    return ans;
}

int maxSubSeq(int L, int R)
{
    if (L == R)
        return a[L];
    int m = (L + R) / 2;
    int wL = maxSubSeq(L, m);
    int wR = maxSubSeq(m + 1, R);
    int wLR = maxLeft(L, m) + maxRight(m + 1, R);
    return max(wL, max(wR, wLR));
}

int main()
{
    input();
    cout << maxSubSeq(1, n);

    return 0;
}
