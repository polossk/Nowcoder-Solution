#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

inline int nextInt()
{
    int _;
    scanf("%d", &_);
    return _;
}

vector<pair<int, int>> players;

bool judge(int val, int x, int y)
{
    int cf = 0, mf = 0, cam = 0; // center forward, midfield, center attack midfield
    for (auto _ : players)
    {
        if (_.first >= val && _.second >= val)
            cam++;
        else if (_.first >= val)
            cf++;
        else if (_.second >= val)
            mf++;
    }
    if (cf >= x && mf >= y)
        return true;
    else if (min(x, cf) + min(y, mf) + cam >= x + y)
        return true;
    return false;
}

void solve()
{
    int n = nextInt();
    int x = nextInt();
    int y = nextInt();
    players.clear();
    for (int i = 0; i < n; i++)
    {
        int _1 = nextInt();
        int _2 = nextInt();
        players.push_back(make_pair(_1, _2));
    }
    int l = 0, r = 10000, ans = 0, mid = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (judge(mid, x, y))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d\n", ans);
}

int main()
{
    int t = nextInt();
    while (t--)
        solve();
    return 0;
}

/** samples
3
5 2 2
100 0
0 99
95 95
96 0
0 97
6 1 3
99 99
100 0
0 100
100 100
100 0
100 0
4 2 2
100 0
100 0
100 0
0 100
==>
96
99
0
*/