#include <iostream>

using namespace std;

int T, tc, n, x, y;
int a[101][101];
int b[1001][1001];
int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};

bool check_pos(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

int solve()
{
    bool check = true;
    int count = 0;
    while (check)
    {
        int xi, xj;
        int min_next = 10001;
        b[x][y] = 1;
        int k = 0;
        check = false;
        for (int i = 0; i < 8; i++)
        {
            int u = x + dx[i];
            int v = y + dy[i];
            if (check_pos(u, v))
            {
                if (a[u][v] > a[x][y] && a[u][v] < min_next && b[u][v] == 0)
                {
                    min_next = a[u][v];
                    xi = u;
                    xj = v;
                    k = 1;
                }
            }
        }
        if (k != 0)
        {
            x = xi;
            y = xj;
            count += 1;
            check = true;
        }
    }
    return count;
}

int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n >> x >> y;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                b[i][j] = 0;
            }
        }
        cout << "#" << tc << " " << solve() << endl;
    }
    return 0;
}