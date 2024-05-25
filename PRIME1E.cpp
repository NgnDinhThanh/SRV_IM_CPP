#include <iostream>

using namespace std;

bool prime(int a)
{
    if (a <= 1)
        return false;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int T;
int m, n;

int main()
{
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cin >> m >> n;
        for (int j = m; j <= n; j++)
        {
            if (prime(j))
                cout << j << endl;
        }
    }

    return 0;
}