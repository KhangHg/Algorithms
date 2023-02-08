#include <bits/stdc++.h>

using namespace std;

const int MAX = 8;
int n = 7, M; // 7 la so chu cai
int x[MAX], a[MAX];
int res = 0;
long long sum = 0;

void input()
{
    a[1] = 1000;  // H
    a[2] = 100;   // U
    a[3] = 2;     // T
    a[4] = 10010; // S
    a[5] = 1000;  // O
    a[6] = 100;   // I
    a[7] = 10;    // C
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
        if (x[1] == 0 || x[4] == 0) // check trường hợp 2 số đầu bằng 0
        {
            return false;
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
    for (int i = 0; i <= 9; i++)
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
    int num;
    cin >> num;
    int N[50];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &N[i]);
    }

    for (int i = 0; i < num; i++)
    {
        res = 0;
        sum = 0;
        M = N[i];
        Try(1);
        cout << res << "\n";
    }

    return 0;
}