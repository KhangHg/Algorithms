#include <bits/stdc++.h>

using namespace std;

int n, L1, L2;

vector<int> a;
int b[n]; // luu cac nhu cau cua cua hang ai

void input()
{
    cin >> n;
    cin >> L1;
    cin >> L2;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
}
int main()
{
    input();
}