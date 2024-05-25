#include <iostream>

using namespace std;

int n;
int main()
{
    // freopen("input.txt", "rt", stdin);
    cin >> n;
    while (n != 42)
    {
        cout << n << endl;
        cin >> n;
    }
    return 0;
}