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
inline void printVec(vl &a) { for (auto o: a) cout<<o<<" "; cout<<"\n"; }
#define fp fixed << setprecision(12)

const ll MAX_N = 2e5 + 5;
//ll cycleStart, cycleEnd, p[MAX_N];
//ll color[MAX_N];
vector <vl> adj(MAX_N);
vl dist(MAX_N, -1);

ll maxe=0;

inline ll bfsVisit(ll start, ll n) {
    queue<ll> q; 
    q.push(start);
    ll node;
    vl temp_d(n+1, -1);
    temp_d[start] = 0;
    dist[start] = max(dist[start], temp_d[start]);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (auto x: adj[node]) {
            if (temp_d[x]==-1) {
                temp_d[x] = temp_d[node] + 1;
                q.push(x);
                dist[x] = max(dist[x], temp_d[x]);
            }
        }
    }
    return node;
}
 
inline void solve()
{
   ll n; cin>>n;
   for (int i=0; i<n-1; i++) {
    ll a, b; 
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
   }
   ll dvis1 = bfsVisit(1, n);
   ll dvis2 = bfsVisit(dvis1, n);
   ll dvis2t1 = bfsVisit(dvis2, n);
   for (ll i=1; i<=n; i++) {
    cout<<dist[i]<<" ";
   }
   cout<<el;
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