#include <iostream>

using namespace std;

int length(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

bool check(char s[])
{
    for (int i = 0; i < length(s) / 2; i++)
    {
        if (s[i] != s[length(s) - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t, tc;
    char s[255], st[255];
    cin >> t;
    for (tc = 1; tc <= t; tc++)
    {
        cin >> s;
        int count = 0;
        for (int i = 0; i < length(s); i++)
        {
            for (int j = i; j < length(s); j++)
            {
                int index = 0;
                for (int k = i; k <= j; k++)
                {
                    st[index] = s[k];
                    index++;
                }
                st[index++] = '\0';
                if (check(st))
                {
                    count += 1;
                }
            }
        }
        cout << "#" << tc << " " << count << endl;
    }
    return 0;
}