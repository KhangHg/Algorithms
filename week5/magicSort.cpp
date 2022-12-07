#include <bits/stdc++.h>

using namespace std;
/*
1 ham tinh tong cac chu so

*/

int sum(int a)
{
    int sum = 0;
    while (a != 0)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

typedef struct magicSort
{
    int val;
    int sum;
} magicSort;

int main()
{
    int N;
    cin >> N;
    magicSort arr[100];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].val;
        arr[i].sum = sum(arr[i].val);
        cout << arr[i].val << " ";
    }

    return 0;
}