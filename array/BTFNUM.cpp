#include <iostream>

using namespace std;

int t, tc, n, m, x, y;
int a[10001];

int check(int cs)
{
    int sum = 0;
    while (cs > 0)
    {
        int dv = cs % 10;
        for (int i = 0; i < n; i++)
        {
            if (dv == a[i])
            {
                sum += 1;
                break;
            }
        }
        cs /= 10;
    }
    if (sum >= m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cin >> t;
    for (tc = 1; tc <= t; tc++)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> x >> y;
        int count = 0;
        for (int i = x; i <= y; i++)
        {
            if (check(i) == 1)
            {
                count += 1;
            }
        }
        cout << "#" << tc << " " << count << endl;
    }
    return 0;
}