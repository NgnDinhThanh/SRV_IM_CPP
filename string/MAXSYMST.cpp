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
    char s[1000], st[1000];
    cin >> t;
    for (tc = 1; tc <= t; tc++)
    {
        cin >> s;
        int max_length = 0;
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
                    if (length(st) > max_length)
                        max_length = length(st);
                }
            }
        }
        cout << "#" << tc << " " << max_length << endl;
    }
    return 0;
}