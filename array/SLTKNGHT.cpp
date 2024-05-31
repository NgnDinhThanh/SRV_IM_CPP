#include <iostream>

using namespace std;

int N, T;
int tc;
int m, k, d;
int kx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ky[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int board[1001][1001];
int nm[1001][1001], nk[2][999999], nd[1001][1001];

int main()
{
    cin >> T;
    for (int tc = 1; tc < N; tc++)
    {
        cin >> N >> k >> m >> d;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                board[i][j] = 0;
            }
        }

        // Quân mã
        for (int i = 0; i < k; i++)
        {
            cin >> nk[0][i] >> nk[1][i];
            board[nk[0][i]][nk[1][i]] = 1;
        }

        // Quân được ăn
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            board[x][y] = 2;
        }

        // Quân không được ăn
        for (int i = 0; i < d; i++)
        {
            int x, y;
            cin >> x >> y;
            board[x][y] = 3;
        }
        int k_choice = 0;
        int u, v;
        int max_count = 0;
        for (int i = 0; i < k; i++)
        {
            int count = 0;
            for (int j = 0; j < 8; j++)
            {
                u = nk[0][i] + kx[j];
                v = nk[1][i] + ky[j];
                if (u < 0 || u > N - 1 || v < 0 || v > N - 1)
                    continue;
                if (board[u][v] == 1 || board[u][v] == 2)
                {
                    count++;
                }
            }
            if (count > max_count)
            {
                max_count = count;
                k_choice = i;
            }
        }
        cout << "#" << tc << " " << nk[0][k_choice] << " " << nk[1][k_choice] << " " << max_count << endl;
    }
    return 0;
}