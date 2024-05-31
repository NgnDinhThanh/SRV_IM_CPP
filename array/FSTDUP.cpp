#include <iostream>

using namespace std;

int n, T, tc;
int a[100001], mark[100001];

int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n;
        for (int i = 0; i < 100001; i++)
        {
            mark[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            mark[a[i]] += 1;
            if (mark[a[i]] > 1)
            {
                ans = a[i];
            }
            if (ans != 0)
            {
                break;
            }
        }
        if (ans != 0)
        {
            cout << "#" << tc << " " << ans << endl;
        }
        else
        {
            cout << "#" << tc << " " << -1 << endl;
        }
    }
    return 0;
}