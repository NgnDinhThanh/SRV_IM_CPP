#include <iostream>

using namespace std;

const int N = 1e4 + 1;

int a[N], b[N];
int n, m;
int F[N][N];
char trace[N][N];
int ans;

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
}

void solve()
{
    for (int i = 0; i <= n; i++)
        F[i][0] = 0;
    for (int j = 0; j <= m; j++)
        F[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                F[i][j] = F[i - 1][j - 1] + 1;
                trace[i][j] = 'D';
            }
            else
            {
                if (F[i - 1][j] > F[i][j - 1])
                {
                    F[i][j] = F[i - 1][j];
                    trace[i][j] = 'U';
                }
                else
                {
                    F[i][j] = F[i][j - 1];
                    trace[i][j] = 'L';
                }
            }
        }
    }
    ans = F[n][m];
}

void traceSolution()
{
    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (trace[i][j] == 'D')
        {
            cout << a[i] << " ";
            i -= 1;
            j -= 1;
        }
        else if (trace[i][j] == 'U')
        {
            i -= 1;
        }
        else
        {
            j -= 1;
        }
    }
}

int main()
{
    input();
    solve();
    cout << ans << endl;
    traceSolution();
    cout << endl;
    return 0;
}