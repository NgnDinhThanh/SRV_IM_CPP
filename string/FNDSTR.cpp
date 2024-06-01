// #pragma warning (disable:6031)
#include <iostream>

using namespace std;

int main()
{
    // freopen_s("input.txt", "r", stdin);
    int T;
    for (int tc = 1; tc <= 10; tc++)
    {
        cin >> T;
        cin.ignore();
        char s1[10], s2[1000];
        cin.getline(s1, 10);
        cin.getline(s2, 1000);
        int len1 = 0, len2 = 0;

        while (s1[len1] != '\0')
        {
            len1++;
        }

        while (s2[len2] != '\0')
        {
            len2++;
        }

        int count = 0;
        for (int i = 0; i <= len2 - len1; i++)
        {
            if (s1[0] == s2[i])
            {
                bool flag = true;
                for (int j = 1; j < len1; j++)
                {
                    if (s1[j] != s2[i + j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    count += 1;
                }
            }
        }
        cout << "#" << tc << " " << count << endl;
    }
    return 0;
}