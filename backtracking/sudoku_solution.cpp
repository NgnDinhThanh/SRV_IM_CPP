#include <iostream>

using namespace std;

int x[9][9];
bool markR[9][10];
bool markC[9][10];
bool markS[3][3][10];

void solution()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
}

bool check(int r, int c, int v)
{
    if (markR[r][v])
        return false;
    if (markC[c][v])
        return false;
    if (markS[r / 3][c / 3][v])
        return false;
    return true;
}

void Try(int r, int c)
{
    for (int v = 1; v <= 9; v++)
    {
        if (check(r, c, v))
        {
            x[r][c] = v;
            markR[r][v] = true;
            markC[c][v] = true;
            markS[r / 3][c / 3][v] = true;
            if (r == 8 && c == 8)
            {
                solution();
            }
            else
            {
                if (c == 8)
                {
                    Try(r + 1, 0);
                }
                else
                {
                    Try(r, c + 1);
                }
            }
            markR[r][v] = false;
            markC[c][v] = false;
            markS[r / 3][c / 3][v] = false;
        }
    }
}

int main()
{
    for (int i = 0; i <= 9; i++)
    {
        for (int r = 0; r < 9; r++)
            markR[r][i] = false;
        for (int c = 0; c < 9; c++)
            markC[c][i] = false;
        for (int I = 0; I < 3; I++)
        {
            for (int J = 0; J < 3; J++)
            {
                markS[I][J][i] = false;
            }
        }
    }
    Try(0, 0);
    return 0;
}