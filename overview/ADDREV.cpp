#include <iostream>

using namespace std;

int revert_int(int n)
{
    int ans = 0;
    while (n != 0)
    {
        ans = ans * 10 + (n % 10);
        n = n / 10;
    }
    return ans;
}
int main()
{
    int T;
    int a, b, sum;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> a >> b;
        sum = revert_int(a) + revert_int(b);
        cout << revert_int(sum) << endl;
    }
    return 0;
}