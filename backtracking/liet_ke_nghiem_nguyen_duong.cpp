#include <iostream>

using namespace std;

#define MAX 200

int X[MAX];
int N, M, T;

int check(int v, int k)
{
    if (k < N)
        return 1;
    return T + v == M;
}

void solution()
{
    for (int i = 1; i <= N; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
}

void Try(int k)
{
    for (int v = 1; v <= M - T - (N - k); v++)
    {
        if (check(v, k))
        {
            X[k] = v;
            T = T + X[k];
            if (k == N)
            {
                solution();
            }
            else
            {
                Try(k + 1);
            }
            T = T - X[k];
        }
    }
}

int main()
{
    N = 3;
    M = 5;
    T = 0;
    Try(1);
    return 0;
}
