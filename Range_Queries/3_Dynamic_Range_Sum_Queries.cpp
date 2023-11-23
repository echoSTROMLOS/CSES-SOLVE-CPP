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
#define fp fixed << setprecision(12)

inline void build(vl& seg_tree, ll n, vl& a) { 
    /* O(n) */
    for (ll i=0; i<n; i++) 
        seg_tree[n+i] = a[i];

    for (ll i=n-1; i>=1; i--) 
        seg_tree[i] = seg_tree[2*i] + seg_tree[2*i + 1];
}

inline void update_tree(vl& seg_tree, ll n, ll i, ll u) {
   /* O(log(n)) */
    seg_tree[n+i] = u;
    for (ll k = (n+i)/2; k>=1; k/=2) {
        seg_tree[k] = seg_tree[2*k] + seg_tree[2*k + 1];
    }
}

inline ll query(vl& seg_tree, ll node, ll node_lo, ll node_hi, ll q_lo, ll q_hi) {
    /* O(log(n)) */
    if (q_lo <= node_lo && node_hi <= q_hi) {
        return seg_tree[node];
    }
    if (node_hi < q_lo || q_hi < node_lo) {
        return 0;
    }
    ll lil = (node_lo+node_hi) / 2;
    return query(seg_tree, 2*node, node_lo, lil, q_lo, q_hi) 
           + 
           query(seg_tree, 2*node+1, lil+1, node_hi, q_lo, q_hi);
}

void solve()
{
    ll n, q; cin>>n>>q;
    vl a(n); for (auto &i: a) cin>>i;
    while(__builtin_popcountll(n)!=1) {
        a.pb(0); n++;
    }
    vl seg_tree(2*n);
    build(seg_tree, n, a);
    for (ll i=1; i<=q; i++) {
        ll whatTodo; cin>>whatTodo;
        if (whatTodo==1) {
            ll k, u; cin>>k>>u;
            update_tree(seg_tree, n, k-1, u);
        }
        else {
            ll lo, hi; cin>>lo>>hi;
            cout<<query(seg_tree, 1, 0, n-1, lo-1, hi-1)<<endl;            
        }
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