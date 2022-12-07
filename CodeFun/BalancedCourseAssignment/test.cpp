#include <bits/stdc++.h>

using namespace std;

// m giao vien
// n mon hoc
int n, m, k;
bool conflict[31][31];
bool A[11][31];
int res = 31;
int x[31];
int numOfTeacher;
vector<int> P[11]; // P[i] danh sach cac mon hoc duoc phan cong cho giao vien i

void input()
{
    cin >> m >> n;
    for (int i = 1; i < m; i++)
    {
        int k;
        while (k--)
        {
            int course;
            cin >> course;
            A[i][course] = true;
        }
    }
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        conflict[a][b] = true;
    }
}

bool check(int teacher, int course)
{
    if (A[teacher][course] == false)
        return false;
    for (int _course : P[teacher])
    {
        if (conflict[_course][course] == true)
            return false;
    }
    return true;
}

void process(int courseIndex)
{
    if (courseIndex > n)
    {
        // check dk1
        for (int i = 1; i <= m; i++)
        {
            if (P[i].size() < 1)
            {
                return;
            }
        }

        // check dk2
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int course : P[i])
        //     {
        //         if (A[i][course] == false)
        //         {
        //             return;
        //         }
        //     }
        // }

        // check dk3
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int course : P[i])
        //     {
        //         for (int _course : P[i])
        //         {
        //             if (course != _course && conflict[course][_course] == true)
        //             {
        //                 return;
        //             }
        //         }
        //     }
        // }
        // cap nhat ket qua
        int Max = -1;
        for (int i = 1; i <= m; i++)
        {
            Max = max(Max, (int)P[i].size());
        }
        res = min(res, Max);
        return;
    }

    for (int teacherIndex = 1; teacherIndex <= m; teacherIndex++)
    {
        x[courseIndex] = teacherIndex;
        P[teacherIndex].push_back(courseIndex);
        if (check(teacherIndex, courseIndex))
        {
            process(courseIndex + 1);
        }
        // reset
        x[courseIndex] = 0;
    }
}

int main()
{
    input();
    process(1);
    cout << res;
    return 0;
}
