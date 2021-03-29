/*****************************************
Author: lizi
Email: lzy960601@gmail.com
Date: 2021-03-27
File: B.cpp
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;

#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif

#define IN freopen("B.in", "r", stdin)
#define OUT freopen("B.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;

char s[1005];
int dp[1005][2], X, Y, n, T;
// 0 for C, 1 for J


int solve()
{
    scanf("%d%d%s", &X, &Y, s + 1);
    n = strlen(s + 1);
    dp[1][0] = dp[1][1] = 1e9 + 7;
    if(s[1] != 'J') dp[1][0] = 0;
    if(s[1] != 'C') dp[1][1] = 0;
    for(int i = 2; i <= n; ++ i)
    {
        dp[i][0] = dp[i][1] = 1e9 + 7;
        if(s[i] != 'J') // C
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + Y);
        if(s[i] != 'C') // J
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + X);
    }
    return min(dp[n][0], dp[n][1]);
}

int main()
{	
    scd(T);
    for(int cas = 1; cas <= T; ++ cas)
    {
        int ans = solve();
        prcas; printf("%d\n", ans);
    }
    return 0;
}
