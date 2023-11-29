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
inline void printVec(vl &a) { for (auto o: a) cout<<o<<" "; cout<<"\n"; }
#define fp fixed << setprecision(12)

#define WHITE 0
#define RED 1
#define BLUE 2

const ll MAX_N = 2e5 + 5;
//ll cycleStart, cycleEnd, p[MAX_N];
ll color[MAX_N];
vector <vl> adj(MAX_N);

inline bool isBipartiteBFS(ll src) {
    queue<ll> q; 
    q.push(src);
    color[src] = RED;
    while (!q.empty()) {
        ll node = q.front();
        q.pop();
        for (auto x: adj[node]) {
            if (color[x]==WHITE) {
                if (color[node]==RED) {
                    color[x] = BLUE;
                }
                else {
                    color[x] = RED;
                }
                q.push(x);
            }
            if (color[x] == color[node]) {
                return false;
            }
        }
    }
    return true;

}
 
inline void solve()
{
   ll n, m; 
   cin>>n>>m;
   for (int i=0; i<m; i++) {
    ll a, b; cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
   }
   memset(color, WHITE, sizeof(color));
   for (ll i=1; i<=n; i++) {
    if (color[i]==WHITE && !isBipartiteBFS(i)){
        cout<<"IMPOSSIBLE\n";
        return;
    } 
   }
    for (ll i=1; i<=n; i++) {
        cout<<color[i]<<" ";
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