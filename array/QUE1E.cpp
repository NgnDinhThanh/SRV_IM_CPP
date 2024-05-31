#include <iostream>

using namespace std;

int T, n;
int cc[1000], a[1000], ans[1000];

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void input()
{
    for (int i = 0; i < n; i++)
    {
        cin >> cc[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans[i] = -1;
    }
}

void sort_()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cc[i] > cc[j])
            {
                swap(cc[i], cc[j]);
                swap(a[i], a[j]);
            }
            if (cc[i] == cc[j] && a[i] > a[j])
            {
                swap(cc[i], cc[j]);
                swap(a[i], a[j]);
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        int c = a[i];
        for (int j = 0; j < n; j++)
        {
            if (c == 0 && ans[j] == -1)
            {
                ans[j] = cc[i];
                break;
            }
            if (ans[j] == -1 && c > 0)
            {
                c--;
            }
        }
    }
}

int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n;
        input();
        sort_();
        solve();
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}