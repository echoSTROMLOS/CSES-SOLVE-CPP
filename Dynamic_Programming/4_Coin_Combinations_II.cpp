#include <bits/stdc++.h>
using namespace std;
 
/* echoSTROMLOS */
 
#define el '\n'
#define fi first
#define se second
#define ll long long
#define pb push_back
const ll INF = 1e18;
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
 
bool visited[1000004][105];
ll echl[1000004];
 
void solve() { 
    ll noOfCoins, DesiredSum;
    cin>>noOfCoins>>DesiredSum;
    
    vl coinsList(noOfCoins);
    for(auto &c: coinsList) cin>>c;
    echl[0] = 1;
    // switching the order of the loops to count only ordered ways 
    for (ll i=0; i<noOfCoins; i++) {
        for (ll j=0; j<=DesiredSum; j++) {
            if (j-coinsList[i] >=0 ) {
                echl[j] += echl[j-coinsList[i]] % MOD;
            }
        }
    }
    cout<<echl[DesiredSum]%MOD<<el;
}
 
int main()
{
    fastIO_
    //readINFile();
    ll tc=1; //cin>>tc;
    while(tc--) solve();
}
 
inline void readINFile() {
#ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}