#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

inline int nextInt() { int _; scanf("%d", &_); return _; }

/** node map:
 * 0-1-2
 * | | |
 * 3-4-5
 * | | |
 * 6-7-8
**/

/** path map:          ->1, ->1, ->2, ->3, ->4, ->5, ->6, ->7, ->8
 * [node 1] #00...#04: ===, ->1, ===, ->3, ->4, ->5, ===, ->7, ===
 * [node 2] #05...#10: ===, ===, ->2, ->3, ->4, ->5, ->6, ===, ->8
 * [node 3] #11...#14: ===, ===, ===, ->3, ->4, ->5, ===, ->7, ===
 * [node 4] #15...#18: ===, ===, ===, ===, ->4, ===, ->6, ->7, ->8
 * [node 5] #19...#22: ===, ===, ===, ===, ===, ->5, ->6, ->7, ->8
 * [node 6] #23...#25: ===, ===, ===, ===, ===, ===, ->6, ->7, ->8
 * [node 7]       #26: ===, ===, ===, ===, ===, ===, ===, ->7, ===
 * [node 8]       #27: ===, ===, ===, ===, ===, ===, ===, ===, ->8
*/

typedef unsigned int state;

inline state _(int pos) { return (1U << pos);}
state draw(int x, int y)
{
    if (x > y) swap(x, y);
    switch (x)
    {
        case 0: switch (y)
        {
            case 1: return _(0);
            case 2: return _(0) | _(5);
            case 3: return _(1);
            case 4: return _(2);
            case 5: return _(3);
            case 6: return _(1) | _(16);
            case 7: return _(4);
            case 8: return _(2) | _(22);
        }
        case 1: switch (y)
        {
            case 2: return _(5);
            case 3: return _(6);
            case 4: return _(7);
            case 5: return _(8);
            case 6: return _(6);
            case 7: return _(7) | _(21);
            case 8: return _(10);
        }
        case 2: switch (y)
        {
            case 3: return _(11);
            case 4: return _(12);
            case 5: return _(13);
            case 6: return _(12) | _(20);
            case 7: return _(14);
            case 8: return _(13) | _(25);
        }
        case 3: switch (y)
        {
            case 4: return _(15);
            case 5: return _(15) | _(19);
            case 6: return _(16);
            case 7: return _(17);
            case 8: return _(18);
        }
        case 4: switch (y)
        {
            case 5: return _(19);
            case 6: return _(20);
            case 7: return _(21);
            case 8: return _(22);
        }
        case 5: switch (y)
        {
            case 6: return _(23);
            case 7: return _(24);
            case 8: return _(25);
        }
        case 6: switch (y)
        {
            case 7: return _(26);
            case 8: return _(26) | _(27);
        }
        case 7: switch (y)
        {
            case 8: return _(27);
        }
    }
    return 0;
}

char buf[3][3];

void solve()
{
    vector<int> tab; set<state> res;
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", buf[i]);
        for (int j = 0; j < 3; j++)
            if (buf[i][j] == '.')
                tab.push_back(i * 3 + j);
    }
    bool flag = 1;
    int sz = tab.size();
    for (state now = 0; flag; flag = next_permutation(tab.begin(), tab.end()))
    {
        now = 0;
        for (int i = sz - 1; i > 0; i--)
        {
            now |= draw(tab[i], tab[i - 1]);
            res.insert(now);
        }
        for (auto e : tab) cout << " " << e;
        printf(" => %d\n", res.size());
    }
    printf("%d\n", res.size());
}

int main()
{
    int t = nextInt();
    while (t--) solve();
    return 0;
}

/** samples
3
...
XXX
XXX
...
XXX
X.X
.X.
X.X
.X.
==>
3
22
111
*/