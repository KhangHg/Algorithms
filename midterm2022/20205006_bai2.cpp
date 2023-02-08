#include <bits/stdc++.h>

using namespace std;

int n;
int a[100001];
char c[20];
int k = 0;
queue<int> Q1;
priority_queue<int> Q;
void in()
{
    // for (int i = 0; i < Q1.size(); i++)
    // {
    //     int top = Q1.top();
    //     Q1.pop();
    //     cout << top << "\n";
    // }

    while (!Q1.empty())
    {
        int top = Q1.front();
        Q1.pop();
        cout << top << "\n";
    }
}
void nhap_day()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        Q.push(num);
    }
}

void slove()
{
    while (1)
    {
        string key;
        int num;
        cin >> key;
        if (key == "*")
            break;
        if (key == "insert")
        {
            cin >> num;
            Q.push(num);
        }
        else if (key == "delete-max")
        {
            int top = Q.top();
            Q.pop();
            // top = Q.top();
            Q1.push(top);
            // in();
        }
    }
}
int main()
{
    nhap_day();
    slove();
    in();
    return 0;
}