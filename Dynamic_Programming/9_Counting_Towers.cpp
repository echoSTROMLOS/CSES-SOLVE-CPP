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

//const ll MAXN = 1e6+3;
//vector<vl> dp(MAXN, vl(2, 0));

inline void solve()
{
    ll n; cin>>n;
    // dp[n][0] = dp[n][1] = 1;
    // for (ll i=n-1; i>-1; i--) {
    //     dp[i][0] = (dp[i+1][1] + 2*dp[i+1][0]) % MOD;
    //     dp[i][1] = (dp[i+1][0] + 4*dp[i+1][1]) % MOD;
    // }
    // cout<<((dp[1][0]+dp[1][1])%MOD) <<endl;
    // This is too much of a waste of space!!! I think I can do better!
    
    ll dp0 = 1, dp1 = 1;
    for (ll i=n-1; i>0; i--) {
        ll new_dp0 = (dp1 + 2*dp0) % MOD;
        ll new_dp1 = (dp0 + 4*dp1) % MOD;
        dp0 = new_dp0;
        dp1 = new_dp1;
    }
    cout<<((dp0+dp1)%MOD) <<endl;
}


int main()
{
    fastIO_
    //readINFile();
    ll tc; cin>>tc;
    while(tc--) solve();
}
 
inline void readINFile() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}