#include <iostream>

using namespace std;

int T;
int m, n, w, h;
int a[101][101];

int sum(int x, int y)
{

    int ans = 0;

    for (int i = y; i < w + y; i++)
    {
        if (a[x][i] % 2 == 0)
        {
            ans += a[x][i];
        }
    }

    for (int i = x + 1; i < x + h; i++)
    {
        if (a[i][y + w - 1] % 2 == 0)
        {
            ans += a[i][y + w - 1];
        }
    }

    for (int i = y; i < y + w - 1; i++)
    {
        if (a[x + h - 1][i] % 2 == 0)
        {
            ans += a[x + h - 1][i];
        }
    }

    for (int i = x + 1; i < x + h - 1; i++)
    {
        if (a[i][y] % 2 == 0)
        {
            ans += a[i][y];
        }
    }

    return ans;
}
int main()
{
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {

        cin >> h >> w >> m >> n;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        int max_sum = 0;

        for (int i = 0; i <= m - h; i++)
        {
            for (int j = 0; j <= n - w; j++)
            {
                int tmp = sum(i, j);
                if (tmp > max_sum)
                {
                    max_sum = tmp;
                }
            }
        }

        cout << "#" << tc << " " << max_sum << endl;
    }

    return 0;
}