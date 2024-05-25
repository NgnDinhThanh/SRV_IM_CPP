#include <iostream>

using namespace std;

int prob(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int solve(int y)
{
    if (y < 10)
        return y;
    return solve(prob(y));
}

int main()
{
    int T;
    int n;

    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> n;
        cout << "#" << tc << " " << solve(n) << endl;
    }
    return 0;
}