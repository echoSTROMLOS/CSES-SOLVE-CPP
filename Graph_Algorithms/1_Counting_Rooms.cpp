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
typedef vector<bool> v_bool;
#define mx(a, b) a > b ? a : b
#define mn(a, b) a < b ? a : b
typedef unsigned long long ull;
typedef vector<pair<ll,ll>> vpl;
#define all(v) v.begin(), v.end()
typedef unordered_map<ll, ll> uml2l;
typedef unordered_map<char, ll> umc2l;
typedef vector<vector<bool>> vv_bool;
#define mx3(a, b, c)  max(a, max(b, c))
#define mn3(a, b, c)  min(a, min(b, c))
#define fastIO_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
 
void dfs(vector<string>&edges, ll i, ll j, ll n, ll m, vv_bool &visited){
    visited[i][j] = true;
    for (int xy=0; xy<4; xy++) {
        int tempX = i + fx[xy];
        int tempY = j + fy[xy];
        if (tempX >= 0 && tempX < n && tempY >= 0 && tempY < m && !visited[tempX][tempY] && edges[tempX][tempY]=='.') {
            dfs(edges, tempX, tempY, n, m, visited);
        }
    }
 
}
void solve() {
    ll n, m; cin>>n>>m;
    vector <string> edges;
    for (int i=0; i<n; i++) {
        string st; cin>>st;
        edges.push_back(st);
    }
    vv_bool visited(n+3, v_bool(m+3, false));
    ll cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!visited[i][j] && edges[i][j] == '.') {
                dfs(edges, i, j, n, m, visited);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
 
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
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}