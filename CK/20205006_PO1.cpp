#include <bits/stdc++.h>

using namespace std;

int total_qty = 0;
int total_trips = 0;
string date, trip_code, customer_code, timeming, truy_van;
// string truy_van;
int qty;
// char trips[8];
map<string, int> qty_customer;
set<string> list_trips;

void input()
{
    ifstream cin("input.txt");
    total_trips = 0;
    do
    {
        /* code */
        int exit = 0;
        cin >> date;
        if (date == "*")
        {
            do
            {
                /* code */

                cin >> trip_code;
                // cout << trip_code[0] << endl;
                // trips[0] = trip_code[0];
                // trips[1] = trip_code[3];
                // trips[2] = trip_code[4];
                // trips[3] = trip_code[5];
                // trips[4] = trip_code[6];
                // trips[5] = trip_code[7];
                // trips[6] = trip_code[8];
                // trips[7] = trip_code[9];

                // cout << trips[0];
                // int num =
                // std::string str = "123";
                // int num = stoi(str);
                // std::cout << num << std::endl;
                // strncpy(trips, trip_code + 3, 8);
                // strtok();
                // cout << trips << endl;

                if (trip_code == "***")
                {
                    break;
                }
                cin >> customer_code >> date >> timeming >> qty;
                total_qty = total_qty + qty;
                list_trips.insert(trip_code);
                // total_trips = total_trips + 1;
                total_trips = list_trips.size();
                qty_customer[customer_code] += qty;
            } while (true);
        }
        if (date == "TOTAL_QTY")
        {
            cout << total_qty << endl;
        }
        else if (date == "TOTAL_TRIPS")
        {
            cout << total_trips << endl;
        }
        else if (date == "***")
        {
            break;
        }
        else if (date == "QTY_CUSTOMER")
        {
            string code;
            cin >> code;
            cout << qty_customer[code] << endl;

            /* code */
        }

    } while (true);
}

int main()
{
    input();
}