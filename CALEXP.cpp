#include <iostream>

using namespace std;
int T;
int a, b;
int main()
{
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> a >> b;
        int ans = 1;
        for (int i = 1; i <= b; i++)
        {
            ans = ans * a;
        }
        cout << "#" << tc + 1 << " " << ans << endl;
    }

    return 0;
}