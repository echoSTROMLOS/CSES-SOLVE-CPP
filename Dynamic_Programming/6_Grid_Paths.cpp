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
#define fp fixed << setprecision(10)

inline void solve()
{
    ll n; cin>>n;
    vector<string>grid(n);
    for (int i=0; i<n; i++) {
        cin>>grid[i];
    } 
    vl optim_dp(n); // space optimed dp!
    optim_dp[n-1] = (grid[n-1][n-1] == '*') ? 0 : 1;
    for (int col=n-2; col>-1; col--) {
        optim_dp[col] =  (grid[n-1][col] == '.') ? optim_dp[col+1] : 0;
    }
    for (int row=n-2; row>-1; row--) {
        vl trackCurr(n);
        for (int col=n-1; col>-1; col--) {
            if (grid[row][col] == '*') {
                trackCurr[col] = 0;
            }
            else {
                ll atob = optim_dp[col];
                ll btoc = col < n-1 ? trackCurr[col+1] : 0;
                trackCurr[col] = (atob + btoc) % MOD;
             }
        }
        optim_dp = trackCurr;
    }
    cout<<optim_dp[0]<<endl;
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