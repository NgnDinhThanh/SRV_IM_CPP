#include <iostream>

using namespace std;

int n, m1, m2;
int a[100];
int T, tc;

int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n >> m1 >> m2;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[j] > a[i])
                {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }

        int k = 1;
        int s1 = 0, s2 = 0;
        int i = k;
        while (k <= n)
        {
            if (k > m1)
            {
                for (int j = k; j <= m2; j++)
                {
                    s2 += a[i] * j;
                    i += 1;
                }
                break;
            }
            else if (k > m2)
            {
                for (int j = k; j <= m1; j++)
                {
                    s1 += a[i] * j;
                    i += 1;
                }
                break;
            }
            s1 += a[i] * k;
            i += 1;
            s2 += a[i] * k;
            i += 1;
            k += 1;
        }

        cout << "#" << tc << " " << s1 + s2 << endl;
    }
    return 0;
}