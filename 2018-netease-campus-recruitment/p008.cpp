#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
inline int nextInt() { int x; scanf("%d", &x); return x; }

const int MAXN = 100;
int n;
vector<int> x, y;

void solve()
{
    if (n <= 2) { printf("%d\n", n); return; }
    int ans = 1, cnt = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        if (i == j) continue;
        int dx1 = x[j] - x[i], dy1 = y[j] - y[i];
        for (int k = 0; k < n; k++)
        {
            if (k == i || k == j) continue;
            cnt = 0;
            for (int l = 0; l < n; l++)
            {
                if ((x[k] - x[l]) * dx1 == (y[l] - y[k]) * dy1)
                    cnt++;
                else if ((x[l] - x[i]) * dy1 == (y[l] - y[i]) * dx1)
                    cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    printf("%d\n", ans);
}


int main()
{
    n = nextInt();
    for (int i = 0; i < n; i++) x.push_back(nextInt());
    for (int i = 0; i < n; i++) y.push_back(nextInt());
    solve();
    return 0;
}