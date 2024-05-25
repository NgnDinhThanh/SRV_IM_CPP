#include <iostream>

using namespace std;

int sqrt(int x)
{
    int i = 0;
    int j = 0;
    while (i * i <= x)
    {
        j = i;
        if (i * i == x)
            return i;
        i++;
    }
    return j;
}

int T;
int n;

int main()
{
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        cin >> n;
        cout << "#" << tc + 1 << " " << sqrt(n) << endl;
    }
    return 0;
}