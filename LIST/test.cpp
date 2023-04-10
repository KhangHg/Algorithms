#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[99999];
void input()
{
    ifstream cin("text.txt");
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // scanf("%d", &a[i]);
        cin >> a[i];
    }
}

int num = 1;
void slove(int k)
{
    if (k == n)
    {
        return;
    }
    int tmp = 1;
    int x = a[k];
    for (int i = k + 1; i < n; i++)
    {
        if (a[i] - x == 1)
        {
            tmp++;
            if (tmp > num)
            {
                num = tmp;
            }
            x = a[i];
        }
    }

    slove(k + 1);
}

int main()
{
    t = 1;
    while (t > 0)
    {
        input();
        slove(0);
        cout << num;
        t--;
    }
    return 0;
}