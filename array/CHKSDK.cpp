#include <iostream>

using namespace std;

int T, tc;
char c[11][11];
int a[11][11];
int b[11];

void load()
{
    for (int i = 0; i <= 10; i++)
    {
        b[i] = 0;
    }
}

bool check()
{
    for (int i = 0; i < 9; i++)
    {
        load();
        for (int j = 0; j < 9; j++)
        {
            b[a[i][j]] += 1;
            if (a[i][j] != 0 && b[a[i][j]] > 1)
            {
                return false;
            }
        }
    }
    for (int j = 0; j < 9; j++)
    {
        load();
        for (int i = 0; i < 9; i++)
        {
            b[a[i][j]] += 1;
            if (a[i][j] != 0 && b[a[i][j]] > 1)
            {
                return false;
            }
        }
    }
    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            load();
            for (int k = i; k <= i + 2; k++)
            {
                for (int l = j; l <= j + 2; l++)
                {
                    b[a[k][l]] += 1;
                    if (a[k][l] != 0 && b[a[k][l]] > 1)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    cin >> T;
    for (tc = 1; tc <= T; tc++)
    {
        load();
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cin >> c[i][j];
                if (c[i][j] == '.')
                {
                    a[i][j] = 0;
                }
                else
                {
                    a[i][j] = c[i][j] - '0';
                }
            }
        }
        if (check())
        {
            cout << "#" << tc << " " << 1 << endl;
        }
        else
        {
            cout << "#" << tc << " " << 0 << endl;
        }
    }
    return 0;
}