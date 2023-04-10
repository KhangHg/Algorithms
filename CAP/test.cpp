#include <bits/stdc++.h>

using namespace std;
int t, m, n;
int a[9999], b[9999];

void input()
{
    ifstream cin("input.txt");
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // scanf("%d", &a[i]);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        // scanf("%d", &b[i]);
        cin >> b[i];
    }
}

int num = 0;
void slove(int k)
{
    if (k == n)
        return;
    for (int i = 0; i < m; i++)
    {
        if (a[k] == b[i])
            num++;
    }
    slove(k + 1);
}

int main()
{
    input();
    slove(0);
    cout << num;
    return 0;
}