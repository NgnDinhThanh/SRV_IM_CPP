#include <iostream>

using namespace std;

int main()
{
    int T;
    int N;
    int x, y;
    int mod = 1000007;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cin >> N;
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            x = N / j;
            y = (x * j) % mod;
            sum = (sum + y) % mod;
        }
        cout << sum << endl;
    }
    return 0;
}