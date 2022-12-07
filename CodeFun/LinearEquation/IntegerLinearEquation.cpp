#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
int n, M;
int X[MAX], a[MAX];
int res = 0;
long long sum = 0;
int s[MAX];
void input()
{
    // freopen("text.inpt", "r", stdin);
    scanf("%d %d", &n, &M);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        /* code */
    }

    for (int i = n; i >= 1; i--)
    {
        s[i] = s[i + 1] + a[i];
        /* code */
    }
}

void Try(int index)
{
    if (index > n)
    {
        // long long sum = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //     sum = sum + a[i] * X[i];
        // }
        if (sum == M)
            res++;

        return;
    }
    int limit = (M - sum - s[index + 1]) / a[index];
    for (int i = 1; i <= limit; i++)
    {
        X[index] = i;
        long long pre_sum = sum;
        sum = sum + a[index] * X[index];
        Try(index + 1);

        // reset
        sum = pre_sum;
        X[index] = 0;
    }
}
int main()
{

    input();
    Try(1);

    cout << res;
    return 0;
}