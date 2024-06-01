#include <iostream>

using namespace std;

int main()
{
    int NUM_COL = 0;
    while (true)
    {
        cin >> NUM_COL;
        if (NUM_COL == 0)
        {
            break;
        }

        char str[201];
        cin >> str;

        int len = 0;
        while (str[len] != '\0')
        {
            len++;
        }

        char mtr[101][101];

        int row = 0;
        int col = 0;

        int d = 1;

        for (int i = 0; i < len; i++)
        {
            mtr[row][col] = str[i];
            col += d;

            if (col >= NUM_COL)
            {
                mtr[row][col] = '\0';
                row++;
                mtr[row][col] = '\0';
                d = -1;
                col += d;
            }
            else if (col < 0)
            {
                row++;
                d = 1;
                col += d;
            }
        }
        int count = 0;
        for (int i = 0; i < NUM_COL; i++)
        {
            for (int j = 0; j < row; j++)
            {
                str[count++] = mtr[j][i];
            }
        }
        str[count++] = '\0';
        cout << str << endl;
    }
    return 0;
}