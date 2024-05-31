#include <iostream>

using namespace std;

int n, m, nq, nk, np;
int tc;

int board[1001][1001];
int mq[1000001][2];
int mk[1000001][2];

int qx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int qy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int kx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ky[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool check(int i, int j)
{
    return i > 0 && j > 0 && i <= m && j <= n;
}

int check_safe()
{
    for (int i = 0; i < nq; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int xx = mq[i][0] + qx[j];
            int yy = mq[i][1] + qy[j];

            while (check(xx, yy) && (board[xx][yy] == 0 || board[xx][yy] == -1))
            {
                board[xx][yy] = -1;
                xx += qx[j];
                yy += qy[j];
            }
        }
    }

    for (int i = 0; i < nk; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int xx = mk[i][0] + kx[j];
            int yy = mk[i][1] + ky[j];

            if (check(xx, yy) && board[xx][yy] == 0)
            {
                board[xx][yy] = -1;
            }
        }
    }

    int count_safe = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i][j] == 0)
            {
                count_safe++;
            }
        }
    }

    return count_safe;
}

int main()
{
    cin >> m >> n;
    tc = 1;
    while (m != 0)
    {

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                board[i][j] = 0;
            }
        }
        // Quân hậu
        cin >> nq;
        for (int i = 0; i < nq; i++)
        {
            int x, y;
            cin >> x >> y;
            mq[i][0] = x;
            mq[i][1] = y;
            board[x][y] = 1;
        }

        // Quân mã
        cin >> nk;
        for (int i = 0; i < nk; i++)
        {
            int x, y;
            cin >> x >> y;
            mk[i][0] = x;
            mk[i][1] = y;
            board[x][y] = 2;
        }

        // Quân tốt
        cin >> np;
        for (int i = 0; i < np; i++)
        {
            int x, y;
            cin >> x >> y;
            board[x][y] = 3;
        }

        cout << "Board " << tc << " has " << check_safe() << " safe squares." << endl;
        tc++;
        cin >> m >> n;
    }
    return 0;
}