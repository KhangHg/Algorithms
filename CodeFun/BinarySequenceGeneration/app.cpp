#include <bits/stdc++.h>
using namespace std;

int n;
int s[20];

void print()
{
    for (int i = 1; i <= n; i++)
    {
        cout << s[i];
    }
    cout << "\n";
}

void cal(int k)
{

    if (k > n)
    {
        print();
        return;
    }
    s[k] = 0;
    cal(++k);
    s[k] = 1;
    cal(++k);
}

int main()
{
    // input
    cin >> n;
    cal(1);

    return 0;
}
