#include <bits/stdc++.h>
using namespace std;

int count_time(string s1, string s2)
{
    // int t1 = ((s1[0] - '0')10 + s1[1] - '0')3600 + ((s1[3] - '0')10 + s1[4] - '0')60 + ((s1[6] - '0')10 + s1[7]);
    // int t2 = ((s2[0] - '0')10 + s2[1] - '0') * 3600 + ((s2[3] - '0')10 + s2[4] - '0')60 + ((s2[6] - '0')10 + s2[7]);
    // return t2 - t1;
}
int main()
{
    ifstream cin("input.txt");
    int total = 0;
    int cnt = 0;
    map<string, int> customer, time;
    while (true)
    {
        string s1;
        cin >> s1;
        if (s1 == "")
            break;
    }
    while (true)
    {
        string s1;
        cin >> s1;
        if (s1 == "")
            break;
        else
        {
            string s2, s3, s4;
            cin >> s2 >> s3 >> s4;
            int s5;
            cin >> s5;
            total += s5;
            customer[s2] += s5;
            // time[s2] += count_time()
        }
        cnt++;
    }
    while (true)
    {
        string s1;
        cin >> s1;
        if (s1 == "")
            break;
        if (s1 == "TOTAL_QTY")
        {
            cout << total << endl;
        }
        if (s1 == "QTY_CUSTOMER")
        {
            string s2;
            cin >> s2;
            cout << customer[s2] << endl;
        }
        if (s1 == "QTY_MAX_PERIOD")
        {
        }
        if (s1 == "TOTAL_TRIP")
        {
            cout << cnt << endl;
        }
        //        if (s1 == "TRAVEL_TIME_TRIP") {
        //            cout << count_time
        //        }
    }
}