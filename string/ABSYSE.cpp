#include <iostream>

using namespace std;

char num1[255], num2[255], num3[255], plusS, equals;

int length(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int check_number(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int converts2n(char s[])
{
    int r = 0;
    for (int i = 0; i < length(s); i++)
    {
        r = r * 10 + s[i] - '0';
    }
    return r;
}

int main()
{
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> num1 >> plusS >> num2 >> equals >> num3;
        if (!check_number(num3))
        {
            cout << num1 << " + " << num2 << " = " << converts2n(num1) + converts2n(num2) << endl;
        }
        else if (!check_number(num2))
        {
            cout << num1 << " + " << converts2n(num3) - converts2n(num1) << " = " << num3 << endl;
        }
        else if (!check_number(num1))
        {
            cout << converts2n(num3) - converts2n(num2) << " + " << num2 << " = " << num3 << endl;
        }
    }
    return 0;
}