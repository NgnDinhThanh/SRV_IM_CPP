#include <iostream>

using namespace std;

#define N 100

int n;
int c[N][N];
int x[N];
int D;
int Dmin;
int mark[N];
int x_sol[N];
int cmin;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (i != j && c[i][j] < cmin)
                cmin = c[i][j];
        }
    }
}

// void solution()
// {
//     cout << "GOT a route: ";
//     for (int i = 1; i <= n; i++)
//         cout << x[i] << " ";
//     cout << " distance = " << x[1] << D + c[x[n]][x[1]];
//     if (Dmin > D + c[x[n]][x[1]])
//     {
//         Dmin = D + c[x[n]][x[1]];
//         cout << "Update best " << Dmin << endl;
//         for (int i = 1; i <= n; i++)
//             x_sol[i] = x[i];
//     }
// }

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (mark[v] == 0)
        {
            x[k] = v;
            D = D + c[x[k - 1]][x[k]];
            mark[v] = 1;
            if (k == n)
            {
                if (Dmin > D + c[x[n]][x[1]])
                    Dmin = D + c[x[n]][x[1]];
            }
            else
            {
                int g = D + cmin * (n - k + 1);
                if (g < Dmin)
                    Try(k + 1);
            }
            D = D - c[x[k - 1]][x[k]];
            mark[v] = 0;
        }
    }
}

int main()
{
    input();
    for (int v = 1; v <= n; v++)
        mark[v] = 0;
    Dmin = 100000000;
    D = 0;
    x[1] = 1;
    mark[1] = 1;
    Try(2);
    cout << Dmin;
    return 0;
}