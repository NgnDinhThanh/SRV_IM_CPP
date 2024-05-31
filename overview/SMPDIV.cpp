#include <iostream>

using namespace std;

int T;
int x, y, n;
int main()
{
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n >> x >> y;
        for (int i = 2; i < n; i++)
        {
            if (i % x == 0 && i % y != 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}