#include <iostream>

using namespace std;

int A[32][32];
int N;
int T;

int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> A[i][j];
            }
        }
        bool ok = true;
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (A[i][j] != A[N - 1 - i][j] || A[j][i] != A[j][N - 1 - i])
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
        {
            cout << "#" << tc << " " << "YES" << endl;
        }
        else
        {
            cout << "#" << tc << " " << "NO" << endl;
        }
    }
    return 0;
}