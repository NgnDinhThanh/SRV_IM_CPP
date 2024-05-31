#include <iostream>

using namespace std;

int t, tc, n, m, k;
int a[105][105];

int main()
{
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        int min = 100000001;
        int min_sum = 100000001;
        int i_min = -1;
        int j_min = -1;

        for (int i = 0; i < n - m + 1; i++)
        {
            for (int j = 0; j < n - m + 1; j++)
            {
                int sum = 0;

                for (int k = i; k < i + m; k++)
                {
                    for (int l = j; l < j + m; l++)
                    {
                        sum += a[k][l];
                    }
                }

                int res = abs(sum - k);
                // if (res < 0)
                // {
                //     res = -res;
                // }
                if (min > res)
                {
                    min = res;
                    i_min = i;
                    j_min = j;
                }
                else if (min == res)
                {
                    if (min_sum > sum)
                    {
                        i_min = i;
                        j_min = j;
                    }
                    else if (min_sum == sum)
                    {
                        if (i_min > i)
                        {
                            i_min = i;
                            j_min = j;
                        }
                        else if (i_min == i)
                        {
                            if (j_min > j)
                            {
                                // i_min = i;
                                j_min = j;
                            }
                        }
                    }
                }
            }
        }
        cout << "#" << tc << " " << i_min << " " << j_min << endl;
    }
    return 0;
}