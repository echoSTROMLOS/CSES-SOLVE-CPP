#include <bits/stdc++.h>
using namespace std;
 
/* echoSTROMLOS */
 
#define el '\n'
#define fi first
#define se second
#define ll long long
#define pb push_back
#define INF 1000000000
const ll MOD = 1e9+7;
typedef vector<ll> vl;
#define eb emplace_back
inline void readINFile();
typedef vector<bool> v_bool;
#define mx(a, b) a > b ? a : b
#define mn(a, b) a < b ? a : b
typedef unsigned long long ull;
typedef vector<pair<ll,ll>> vpl;
#define all(v) v.begin(), v.end()
typedef unordered_map<ll, ll> uml2l;
typedef unordered_map<char, ll> umc2l;
#define mx3(a, b, c)  max(a, max(b, c))
#define mn3(a, b, c)  min(a, min(b, c))
#define fastIO_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
void solve() { 
    ll n, d; cin>>n>>d; vl coins(n);
    for (auto &c: coins) cin>>c;
    vl record(d+5, INT_MAX);
    record[0]=0;
    for (ll i=1; i<=d; i++) {
        for (ll j=0; j<n; j++) {
            if (i >= coins[j])
              record[i] = min(record[i], record[i-coins[j]]+1);
        }
    }
    cout<<(record[d]==INT_MAX ? -1 : record[d])<<el;
}
int main()
{
    fastIO_
    // readINFile();
    ll tc=1; //cin>>tc;
    while(tc--) solve();
}
 
inline void readINFile() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}