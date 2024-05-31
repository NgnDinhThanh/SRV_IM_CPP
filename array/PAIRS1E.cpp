#include <iostream>

using namespace std;

int T, n, k;
int a[999999];

int main()
{
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dif = a[j] - a[i];
                if (dif == k || dif == -k)
                {
                    count++;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}