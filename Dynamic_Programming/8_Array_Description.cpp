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
 
inline void solve()
{
    ll n, m, res=0; cin>>n>>m;
    vl a(n); for (auto &i: a) cin>>i;
    vector<vl> dp(n+1, vl(m+1, 0)); 

    for (int i = 1; i <=m; i++) { 
        if (!a[0] || a[0] == i)
            dp[1][i] = 1;
    } 

    for (ll i=2; i<=n; i++) {
        for (ll j=1; j<=m; j++) {
            if (a[i-1] && a[i-1] != j) {
                dp[i][j] = 0;
                continue;
            }
            for (ll t = j-1; t <=  j+1; t++) {
                if (t>= 1 && t <=m) {
                    dp[i][j] = (dp[i][j] + dp[i-1][t]) % MOD;
                }
            }
        }
    }
    for (ll i=1; i<=m; i++) 
        res = (res+dp[n][i]) % MOD;
    
    cout<<res<<endl; 
}
int main()
{
    fastIO_
    //readINFile();
    ll tc=1;// cin>>tc;
    while(tc--) solve();
}
 
inline void readINFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}