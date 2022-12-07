#include <bits/stdc++.h>

using namespace std;
/*
nếu là nút hàng trên cùng  || hàng dưới cùng || hàng bên phải cùng || hàng bên trái cùng
    kết thúc

kiểm tra nút bên trên == 0 && chưa thăm
    đánh dấu nút đó thăm
    đi lên
    đánh dấu chưa thăm
*/

int m, n, r, c, A[1000][1000];
bool ok[1000][1000];
vector<string> res;

void Inp()
{
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> A[i][j];
            ok[i][j] = false;
        }
    }
}

void Try(int i, int j, string s)
{
    if (A[1][j] == 0 || A[n][j] == 0 || A[i][1] == 0 || A[i][m] == 0)
    {
        return;
    }
    if (i == n && j == m)
    {
        res.push_back(s);
    }

    // len
    if (A[i - 1][j] == 0 && i != 1 && !ok[i - 1][j])
    {
        ok[i][j] = true;
        Try(i - 1, j, s + "U");
        ok[i][j] = false;
    }
    // xuong
    if (A[i + 1][j] == 0 && i != n && !ok[i + 1][j])
    {
        ok[i][j] = true;
        Try(i + 1, j, s + "D");
        ok[i][j] = false;
    }
    // phai
    if (A[i][j + 1] == 0 && j != m && !ok[i][j + 1])
    {
        ok[i][j] = true;
        Try(i, j + 1, s + "R");
        ok[i][j] = false;
    }
    // trai
    if (A[i][j - 1] == 0 && j != 1 && !ok[i][j - 1])
    {
        ok[i][j] = true;
        Try(i, j - 1, s + "L");
        ok[i][j] = false;
    }
}

int main()
{
    Inp();
    Try(r, c, "");
    if (res.size() == 0)
        cout << -1;
    else
    {
        cout << res.size();
    }

    return 0;
}
