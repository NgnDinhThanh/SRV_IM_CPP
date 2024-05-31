#include <iostream>

using namespace std;

bool square(int x)
{
    int i = 0;
    while (i * i <= x)
    {
        if (i * i == x)
            return true;
        i++;
    }
    return false;
}

int a, b;
int T;
int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int count = 0;
        cin >> a >> b;
        cout << "#" << i + 1 << " ";
        for (int j = a; j <= b; j++)
        {
            if (square(j))
            {
                cout << j << " ";
                count++;
            }
        }
        if (count == 0)
            cout << "NO NUMBER";
        cout << endl;
    }

    return 0;
}