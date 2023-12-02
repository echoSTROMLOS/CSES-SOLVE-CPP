#include <bits/stdc++.h>
using namespace std;
 
/* echoSTROMLOS */
 
#define el '\n'
#define fi first
#define se second
#define ll long long
#define pb push_back
typedef vector<ll> vl;
#define eb emplace_back
inline void readINFile();
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
//#define max(a, b) a>b ? a:b
//#define min(a, b) a<b ? a:b
typedef vector<bool> v_bool;
typedef unsigned long long ull;
typedef vector<pair<ll,ll>> vpl;
#define all(v) v.begin(), v.end()
#define maxHeap priority_queue<ll>
typedef unordered_map<ll, ll> uml2l;
typedef unordered_map<char, ll> umc2l;
#define mx3(a, b, c)  max(a, max(b, c))
#define mn3(a, b, c)  min(a, min(b, c))
#define minHeap priority_queue<ll, vl, greater<ll>>
#define fastIO_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
inline void printV(vl &a) { for (auto o: a) cout<<o<<" "; cout<<"\n"; }
#define fp fixed << setprecision(12)

const ll MAXN = 5005;
vector<vl> dp(MAXN, vl(MAXN, INF));

inline void solve()
{
    string x, y; cin>>x>>y;
    ll n = x.size(), m=y.size();
    for (ll i=0; i<=n; i++)
        dp[i][0] = i;
    iota(all(dp[0]), 0);
    for (ll i=1; i<=n; i++) {
        for (ll j=1; j<=m; j++) {
            dp[i][j] = x[i-1] != y[j-1] ? dp[i-1][j-1] + 1 : dp[i-1][j-1];
            dp[i][j] = min({dp[i][j], dp[i-1][j]+1, dp[i][j-1]+1});
        }
    }
    cout<<dp[n][m]<<el;
}


int main()
{
    fastIO_
    //readINFile();
    ll tc=1; //cin>>tc;
    while(tc--) solve();
}
 
inline void readINFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}