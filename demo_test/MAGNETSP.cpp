#include <iostream>

// #define _CRT_SECURE_NO_WARNINGS
// #pragma warning(disable: 6031)
// #pragma warning(disable: 4996)

using namespace std;

int n, m, k;
int t, tc;
int board[101][101];
int magnet[11];
int mark[101][101];

int x, y;

int main()
{
    /*freopen("input.txt", "r", stdin);*/
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++)
            cin >> magnet[i];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == 2)
                {
                    x = i;
                    y = j;
                }
            }
        }
        /*cout << x << " " << y << endl;*/

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mark[i][j] = 0;
            }
        }

        mark[x][y] = 1;

        for (int i = 0; i < k; i++)
        {
            if (magnet[i] == 1)
            {
                while (x - 1 >= 0)
                {
                    x--;
                    if (board[x][y] != 1)
                    {
                        mark[x][y] = 1;
                    }
                    else
                    {
                        x++;
                        break;
                    }
                }
            }
            else if (magnet[i] == 2)
            {
                while (y + 1 < m)
                {
                    y++;
                    if (board[x][y] != 1)
                    {
                        mark[x][y] = 1;
                    }
                    else
                    {
                        y--;
                        break;
                    }
                }
            }
            else if (magnet[i] == 3)
            {
                while (x + 1 < n)
                {
                    x++;
                    if (board[x][y] != 1)
                    {
                        mark[x][y] = 1;
                    }
                    else
                    {
                        x--;
                        break;
                    }
                }
            }
            else if (magnet[i] == 4)
            {
                while (y - 1 >= 0)
                {
                    y--;
                    if (board[x][y] != 1)
                    {
                        mark[x][y] = 1;
                    }
                    else
                    {
                        y++;
                        break;
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                /*cout << mark[i][j] << " ";*/
                if (mark[i][j] == 1)
                {
                    count++;
                }
            }
            /*cout << endl;*/
        }
        cout << "#" << tc << " " << count << endl;
    }
    return 0;
}
