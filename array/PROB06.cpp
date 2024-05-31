#include <iostream>

using namespace std;

int T, tc, m, n;
char a[101][101];

void solve(int i, int j, int k)
{
    int ii = i + 1;
    while (ii <= i + k)
    {
        if (ii > m)
        {
            break;
        }
        if (a[ii][j] == 'H')
        {
            a[ii][j] = 'D';
        }
        ii++;
    }

    ii = i - 1;
    while (ii >= i - k)
    {
        if (ii < 0)
        {
            break;
        }
        if (a[ii][j] == 'H')
        {
            a[ii][j] = 'D';
        }
        ii--;
    }

    int jj = j + 1;
    while (jj <= j + k)
    {
        if (jj > n)
        {
            break;
        }
        if (a[i][jj] == 'H')
        {
            a[i][jj] = 'D';
        }
        jj++;
    }

    jj = j - 1;
    while (jj >= j - k)
    {
        if (jj < 0)
        {
            break;
        }
        if (a[i][jj] == 'H')
        {
            a[i][jj] = 'D';
        }
        jj--;
    }
}

int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> m >> n;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 'A')
                {
                    solve(i, j, 1);
                }
                else if (a[i][j] == 'B')
                {
                    solve(i, j, 2);
                }
                else if (a[i][j] == 'C')
                {
                    solve(i, j, 3);
                }
            }
        }

        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 'H')
                {
                    count++;
                }
            }
        }
        cout << "#" << tc << " " << count << endl;
    }
    return 0;
}