#include <iostream>

// #define _CRT_SECURE_NO_WARNINGS
// #pragma warning(disable : 6031)
// #pragma warning(disable : 4996)

using namespace std;

#define N 1000000
int a[N];
int n;
int F[N];
int ans;
int sel_prob;
int start_index[N];
void input()
{
    // freopen("./input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void solve()
{
    F[1] = a[1];
    start_index[1] = 1;
    ans = F[1];
    sel_prob = 1;

    for (int i = 2; i <= n; i++)
    {
        if (F[i - 1] > 0)
        {
            F[i] = F[i - 1] + a[i];
            start_index[i] = start_index[i - 1];
        }
        else
        {
            F[i] = a[i];
            start_index[i] = i;
        }
        if (F[i] > ans)
        {
            ans = F[i];
            sel_prob = i;
        }
    }
    cout << "Max: " << ans << endl;
    cout << "From " << start_index[sel_prob] << " to " << sel_prob << endl;
}

int main()
{
    input();
    solve();
    return 0;
}