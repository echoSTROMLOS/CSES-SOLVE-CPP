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
#define max(a, b) a>b ? a:b
#define min(a, b) a<b ? a:b
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
#define fp fixed << setprecision(10)

ll dfs(vector<vl>&adj, vl &sub, ll node) 
{   
  if (adj[node].empty()) return 1;
  
  for (auto k: adj[node]){
    sub[node] += dfs(adj, sub, k);
  }  
  return sub[node]+1;
}
inline void solve()
{
    ll n; cin>>n; 
    vl sub(n+1, 0);
    vector <vl> adj(n+1);
    for (int s=2; s<=n; s++) {
        ll b; cin>>b;
        adj[b].pb(s);
    }
    dfs(adj, sub, 1);
    for (ll i=1; i<=n; i++) {
        cout<<sub[i]<<" ";
    }
    cout<<"\n";
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
