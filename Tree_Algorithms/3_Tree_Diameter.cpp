#include <bits/stdc++.h>
using namespace std;

/* echoSTROMLOS */

#define el '\n'
#define x first
#define y second
#define ll long long
#define pb push_back
typedef vector<ll> vl;
#define eb emplace_back
inline void readINFile();
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;
//#define max(a, b) a>b ? a:b
//#define min(a, b) a<b ? a:b
typedef pair<ll,ll> pair_ll;
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

inline pair_ll bfsVisit(vector<vl> adj, ll start, ll n) 
{   
    v_bool visited(n+1, false);
    queue<pair_ll> q; 
    q.push(make_pair(start, 0));
    pair_ll node;
    while (!q.empty()) {
        node = q.front();
        visited[node.x] = true;
        q.pop();
        for  (ll v: adj[node.x]) {
            if (!visited[v]) {
                q.push(make_pair(v, node.y+1));
            }
        }
    }
    return node;

}
inline void solve()
{
    ll n; cin>>n;

    vector<vl> adj(n+1);
    
    for (ll e=0; e<n-1; e++) {
        ll a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll try1x = bfsVisit(adj, 1, n).first;
    cout<< bfsVisit(adj, try1x, n).second <<el;
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