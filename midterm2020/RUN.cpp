#include <bits/stdc++.h>

const int MAX = 100005;
using namespace std;

int n;
int a[MAX];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int num = 0;
int cal()
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            num++;
        }
    }

    return num;
}

int main()
{
    input();
    cout << cal();
}