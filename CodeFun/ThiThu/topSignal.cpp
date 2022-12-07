#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;
int n, a[MAX];
int num = 0;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        /* code */
    }
}
void cal(int i)
{
    if (i == n)
        return;
    if (a[i] > a[i - 1] && a[i] > a[i + 1])
    {
        num++;
        cal(i + 2);
    }
    else
    {
        cal(i++);
    }
}

int main()
{
    input();

    for (int i = 2; i <= n - 1; i++)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            num++;
        }
    }
    // cal(2);

    cout << num;
}