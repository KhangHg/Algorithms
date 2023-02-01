// Binary sequences generation without consecutive 11
#include <bits/stdc++.h>
using namespace std;

int n;
int s[20];

void print()
{
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 1 && s[i + 1] == 1)
            return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 1 && s[i + 1] == 1)
            return;
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
    cal(k + 1);

    s[k] = 1;
    cal(k + 1);
}

int main()
{
    // input
    cin >> n;
    cal(1);

    return 0;
}
