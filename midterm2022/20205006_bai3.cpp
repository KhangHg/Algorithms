#include <bits/stdc++.h>
using namespace std;

int n, a[30], A, B;
int sum = 0;
void input()
{
    cin >> n >> A >> B;
    for (int i = 1; i < = n; i++)
    {
        cin >> a[i];
    }
}
int main()
{
    input();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += a[j + 1];
        }
    }

    if (sum >= A && sum <= B)
    {
        ans++;
    }
    cout << ans;
    return 0;
}
