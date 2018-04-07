#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

inline int nextInt() { int _; scanf("%d", &_); return _; }
inline string nextStr() { string s; cin >> s; return s; }

const int MAXN = 200;

// #define DEBUG

#define bprint(_) cout << #_": "; _.print();

struct Block
{
    vector<string> val;
    int w, h;
    Block(int _w, int _h): w(_w), h(_h)
    {
        val.assign(h, "");
    }
    void input()
    {
        for (int i = 0; i < h; i++)
            val[i] = nextStr();
    }
    void print()
    {
        printf("#[%d x %d]: \n", w, h);
        for (int i = 0; i < h; i++)
            puts(val[i].c_str());
        puts("---\n");
    }
    void transpose()
    {
        vector<string> tmp(h, "");
        for (int i = 0; i < h; i++)
        {
            tmp[i] = string(val[h - 1 - i].rbegin(), val[h - 1 - i].rend());
        }
        for (int i = 0; i < h; i++)
            val[i] = tmp[i];
    }
};

void print_block(int k, int x, const Block &l, const Block &c, const Block &r)
{
    for (int i = 0; i < x; i++)
    {
        printf("%s", l.val[i].c_str());
        for (int j = 1; j + 1 < k; j++)
            printf("%s", c.val[i].c_str());
        printf("%s", r.val[i].c_str());
        puts("");
    }
}

void solve()
{
    int n = nextInt();
    int m = nextInt();
    int k = m / n, x = 0, y = 0;
    for (int kk = k; kk * n <= MAXN; kk++)
    {
        y = kk * n - m;
#ifdef DEBUG
        cout << "kk= " << kk << ", x= " << x << ", y= " << y << endl;
#endif
        if (y < 0) continue;
        if (y % 2 == 0)
        {
            x = n - y / 2;
            k = kk;
            if (x == n) { k += 2; x = 0; }
            break;
        }
    }
#ifdef DEBUG
    cout << " k= " << k << ", x= " << x << ", y= " << y << endl;
#endif
    Block zero(n, n); zero.input();
    Block hogeA(x, x), hogeB(x, x);
    Block piyo(n, x);
    Block fugaA(x, n), fugaB(x, n);
    for (int i = 0; i < x; i++)
    {
        hogeA.val[i] = zero.val[n - x + i].substr(n - x);
        hogeB.val[i] = zero.val[n - x + i].substr(0, x);
        piyo.val[i] = zero.val[n - x + i];
    }
    for (int i = 0; i < n; i++)
    {
        fugaA.val[i] = zero.val[i].substr(n - x);
        fugaB.val[i] = zero.val[i].substr(n - x);
    }
    fugaB.transpose();
#ifdef DEBUG
    bprint(zero);
    bprint(hogeA);
    bprint(hogeB);
    bprint(piyo);
    piyo.transpose();
    bprint(piyo);
    piyo.transpose();
    bprint(fugaA);
    bprint(fugaB);
#endif
    for (int i = 0; i < k; i++)
    {
        if (i == 0)
        {
            print_block(k, x, hogeA, piyo, hogeB);
            hogeA.transpose();
            hogeB.transpose();
            piyo.transpose();
        }
        else if (i + 1 == k)
            print_block(k, x, hogeB, piyo, hogeA);
        else
            print_block(k, n, fugaA, zero, fugaB);
    }
    puts("");
}

int main()
{
    int t = nextInt();
    while (t--) solve();
    return 0;
}
/** samples
4
3 5
1x1
x0x
1x1

3 7
1x1
x0x
1x1

5 7
13s31
LKcKL
Sc2cS
LKcKL
13S31

5 13
12321
23432
34543
23432
12321
==>
11x11
11x11
xx0xx
11x11
11x11

0xx0xx0
x11x11x
x11x11x
0xx0xx0
x11x11x
x11x11x
0xx0xx0

113S311
113s311
LLKcKLL
SSc2cSS
LLKcKLL
113S311
113S311

3432234322343
4543345433454
3432234322343
2321123211232
2321123211232
3432234322343
4543345433454
3432234322343
2321123211232
2321123211232
3432234322343
4543345433454
3432234322343

*/