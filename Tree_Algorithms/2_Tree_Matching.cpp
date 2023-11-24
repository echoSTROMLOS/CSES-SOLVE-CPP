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

/* this problem may have a potential greedy solution as well! I am trying DP anyway... */
inline void dfsVisit(vector<vl>& adj, vector<vl>& dp, ll node, ll parent)  
{   
    for (ll v: adj[node]) {
        if (v != parent) {
            dfsVisit(adj, dp, v, node);
            dp[node][0] += max(dp[v][0], dp[v][1]);
        }
    }

    for (ll v: adj[node]) {
        if (v != parent) {
            ll mxv = max(dp[v][0], dp[v][1]);
            ll tvn = dp[v][0] + dp[node][0] + 1;
            dp[node][1] = max(dp[node][1], tvn-mxv);
        }
    }

}

inline void solve()
{
    ll n; cin>>n;

    vector<vl> adj(n+1);
    vector<vl> dp(n+1, vl(2, 0));
    for (ll e=0; e<n-1; e++) {
        ll a, b; cin>>a>>b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfsVisit(adj,dp, 0, -1);

    cout<<max(dp[0][0], dp[0][1])<<endl;
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