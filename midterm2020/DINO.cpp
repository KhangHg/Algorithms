#include <bits/stdc++.h>

using namespace std;
const int MAX = 100005;
int n, a[MAX];
char c[1000000];

int main()
{
    queue<int> Q;
    stack<int> S;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        S.push(a[i]);
    }
    cin >> c;

    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] == 67)
        {
            if (!S.empty())
            {
                int tmp = S.top();
                S.pop();
                Q.push(tmp);
            }
        }
        else if (c[i] == 72)
        {
            if (!Q.empty())
            {
                int tmp = Q.front();
                Q.pop();
                S.push(tmp);
            }
        }
    }

    // Printing content of stack
    while (!S.empty())
    {
        cout << ' ' << S.top();
        S.pop();
    }
}