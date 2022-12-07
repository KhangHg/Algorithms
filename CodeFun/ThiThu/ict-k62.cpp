#include <bits/stdc++.h>

using namespace std;

const int MAX = 8;
int n = 7, M;
int x[MAX], a[MAX];
int res = 0;
long long sum = 0;

void input()
{
    scanf("%d", &M);
    // M = 2000;
    M = M + 62;
    a[1] = 100;  // I
    a[2] = 10;   // C
    a[3] = 2;    // T
    a[4] = -100; // K
    a[5] = 1000; // H
    a[6] = 100;  // U
    a[7] = 10;   // S
    a[8] = 0;
}

// kiem tra xem co bi trung khong
bool test()
{
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (x[i] == x[j] && i != j)
            {
                return false;
            }
        }
    }
    return true;
}

void Try(int index)
{
    if (index > n)
    {
        if (sum == M && test() == true)
        {
            res++;
        }
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        x[index] = i;
        int pre_sum = sum;
        sum = sum + a[index] * x[index];
        Try(index + 1);

        // reset
        sum = pre_sum;
    }
}
int main()
{

    input();
    Try(1);
    cout << res;
    return 0;
}