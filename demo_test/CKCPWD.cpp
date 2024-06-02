#include <iostream>

using namespace std;

char keyboard[4][3];
char pass_correct[8];
char pass_incorrect[8];

void set_keyboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            keyboard[i][j] = '0';
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            keyboard[i][j] = '0' + i * 3 + j + 1;
        }
    }

    keyboard[3][0] = '*';
    keyboard[3][1] = '0';
    keyboard[3][2] = '#';
}

bool checkPass(char x, char y)
{
    int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (keyboard[i][j] == x)
            {
                i1 = i;
                j1 = j;
            }
            if (keyboard[i][j] == y)
            {
                i2 = i;
                j2 = j;
            }
        }
    }

    if ((abs(i1 - i2) == 1 && abs(j1 - j2) == 0) || (abs(j1 - j2) == 1 && abs(i1 - i2) == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int tc, t, n;

int main()
{
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> pass_correct[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> pass_incorrect[i];
        }

        set_keyboard();

        int count = 0;
        int error = -1;

        for (int i = 0; i < n; i++)
        {
            if (pass_correct[i] != pass_incorrect[i])
            {
                if (checkPass(pass_correct[i], pass_incorrect[i]))
                {
                    count++;
                    if (count > 1)
                    {
                        break;
                    }
                    error = i + 1;
                }
                else
                {
                    count = -1;
                    break;
                }
            }
        }
        if (count == -1 || count > 1)
        {
            cout << "#" << tc << " " << -1 << endl;
        }
        else if (count == 0)
        {
            cout << "#" << tc << " " << 0 << endl;
        }
        else
        {
            cout << "#" << tc << " " << error << endl;
        }
    }
    return 0;
}