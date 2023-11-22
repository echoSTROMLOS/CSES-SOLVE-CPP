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

#define MAX_N 2000005
ll lg[MAX_N];
const ll LOG = 25;
ll sparse_table[MAX_N][LOG];

void compute_log(ll n) {
    lg[0] = -1;
    lg[1] = 0;
    for (ll i=2; i<= n; i++) {
        lg[i] = lg[i/2] + 1;
    }
}
inline void pre_process(ll n) {
    // O(n*log(n))
    for (ll k=1; k<LOG; k++) {
        for (ll i=0; i+(1<<k)-1 < n; i++){
            sparse_table[i][k] = min(sparse_table[i][k-1], sparse_table[i+(1<<(k-1))][k-1]);
        }
    }
}
inline ll RMQ(ll L, ll R) {
    // O(1)
    ll len = R-L+1;
    ll k = lg[len];
    return min(sparse_table[L][k], sparse_table[R-(1<<k)+1][k]);
}

void solve()
{
    ll n, q; 
    cin>>n>>q; 
    compute_log(n);
    vl a(n); 
    for (ll i=0; i<n; i++) {
        cin>>a[i];
        sparse_table[i][0] = a[i];
    }
    pre_process(n);
    for (ll i=1; i<=q; i++) {
        ll L, R; cin>>L>>R;
        cout<<RMQ(L-1, R-1)<<endl;
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