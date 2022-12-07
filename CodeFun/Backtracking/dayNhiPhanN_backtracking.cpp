#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;

int a[MAX], n;

void inday()
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;
}

void sinh(int k)
{
    // neu k > n thi in day
    if (k > n)
    {
        inday();
    }
    else
    {
        a[k] = 0;
        sinh(k + 1);
        a[k] = 1;
        sinh(k + 1);
    }
}

int main()
{
    cout << "Nhap n = ";
    cin >> n;
    sinh(1);
}