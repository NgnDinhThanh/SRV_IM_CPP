#include <iostream>

using namespace std;

int T, tc;
int m, n;
char a[505][505];

int main()
{
    cin >> T;
    for (tc = 1; tc <= T; tc++)
    {
        cin >> m >> n;
        for (int i = 0; i < 5 * m + 1; i++)
        {
            cin >> a[i];
        }
        int type[5] = {0, 0, 0, 0, 0};

        for (int i = 1; i < 5 * m + 1; i += 5)
        {
            for (int j = 1; j < 5 * n + 1; j += 5)
            {
                int count = 0;
                for (int k = i; k < i + 4; k++)
                {
                    if (a[k][j] == '*')
                    {
                        count++;
                    }
                }
                type[count]++;
            }
        }
        cout << "#" << tc << " ";
        for (int i = 0; i < 5; i++)
        {
            cout << type[i] << " ";
        }
        cout << endl;
    }
    return 0;
}