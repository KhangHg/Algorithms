#include <iostream>
using namespace std;
int main()
{
    int n, k, sum, A[100005];
    int cnt = 0;
    cin >> n >> k >> sum;

    int S[100005] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }
    for (int i = k; i <= n; i++)
    {
        if (S[i] - S[i - k] == sum)
            cnt++;
    }
    cout << cnt;
}