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

inline void findAns(vl& prev, ll n) {
    vl ans; ll t = n;
    while(t!=1){
        ans.pb(t); t=prev[t];
    }
    ans.pb(1); reverse(all(ans));
    cout<<ans.size()<<el; printV(ans);
   
}
inline bool isPossibleBFS(vector<vl>& adj, vl& prev, ll n) 
{
    queue <ll> q;
    q.push(1);

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();
        if (cur == n) {
            return true;
        }
        for (auto v: adj[cur]) {
            if (prev[v]) continue;
            prev[v] = cur;
            q.push(v);
        }
    }
    return false;
    
} 

inline void solve()
{
    ll n, m; cin>>n>>m;
    vector<vl> adj(n+1, vl());
    for (ll i=1; i<=m; i++) {
        ll a, b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vl prev(n+1, 0);
    if (isPossibleBFS(adj, prev, n)) {
        findAns(prev, n);
    }
    else {
        cout<<"IMPOSSIBLE"<<el;
    }
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