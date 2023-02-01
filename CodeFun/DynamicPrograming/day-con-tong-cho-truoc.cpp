// đếm số dãy con có tổng cho trước
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int n, a[MAX], S;

int F(int s, int k)
{
    if (k == 0)
        return (s == 0) ? 1 : 0;
    return (s < a[k]) ? F(s, k - 1) : F(s, k - 1) + F(s - a[k], k - 1);
}

int main()
{
    cout << "N = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "S = ";
    cin >> S;
    cout << "So day con : " << F(S, n);
}