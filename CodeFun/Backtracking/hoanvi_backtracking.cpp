#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
bool b[MAX];

int a[MAX], n;

void print()
{
    for (int i = 1; i <= n; i++)
    {
        /* code */
        cout << " " << a[i];
    }
    cout << endl;
}

void get(int k)
{
    if (k > n)
    {
        print();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        /* code */
        if (b[i])
        {
            a[k] = i;
            b[i] = false;
            get(k + 1);
            b[i] = true;
        }
    }
}

int main()
{
    // cout << "N = ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        b[i] = true;
    }

    get(1);
}