#include <bits/stdc++.h>

using namespace std;

const int MAX = 999999;
long long n, SC[MAX], SL[MAX], a[MAX];
bool BC[MAX], BL[MAX];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        scanf("%d", &a[i]);
    }
}

void tinhtoan()
{

    if (a[1] % 2 == 0)
    {
        SC[1] = a[1];
        BC[1] = true;
        BL[1] = false;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (BC[i - 1] == true && SC[i - 1] > 0)
            {
                SC[i] = SC[i - 1] + a[i];
            }
            SC[i] = a[i];
            BC[i] = true;

            if (BL[i - 1] == true)
            {
                SL[i] = SL[i - 1] + a[i];
                BL[i] = true;
            }
            else
            {
                BL[i] = false;
            }
        }
        else
        {
            if (BL[i - 1])
            {
                SC[i] = SL[i - 1] + a[i];
                BC[i] = true;
            }
            else
            {
                BC[i] = false;
            }
            if (BC[i - 1] == true && SC[i - 1] > 0)
            {
                SL[i] = SC[i - 1] + a[i];
            }
            else
            {
                SL[i] = a[i];
            }
            BL[i] = true;
        }

        /* code */
    }
}

void findMax()
{
    long long ans = 0 - 1e9;
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        if (BC[i] == true && SC[i] > ans)
        {
            ans = SC[i];
            found = true;
        }
        /* code */
    }

    if (found)
    {
        cout << ans;
    }
    else
    {
        cout << "NOT FOUND";
    }
}

int main()
{
    input();
    tinhtoan();
    findMax();
}