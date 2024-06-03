#include <iostream>

using namespace std;

#define N 20

int x[N];
int n;
bool visited[N];

bool check(int v, int k)
{
    return visited[v] == false;
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void Try(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (check(v, k))
        {
            x[k] = v;
            visited[v] = true;
            if (k == n)
            {
                solution();
            }
            else
            {
                Try(k + 1);
            }
            visited[v] = false;
        }
    }
}

int main()
{
    n = 3;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    Try(1);
    return 0;
}