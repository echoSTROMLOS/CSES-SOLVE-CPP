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
#define max(a, b) a>b ? a:b
#define min(a, b) a<b ? a:b
typedef vector<bool> v_bool;
typedef vector<char> v_char;
typedef pair <ll, ll> pair_ll;
typedef unsigned long long ull;
typedef vector<pair<ll,ll>> vpl;
#define all(v) v.begin(), v.end()
#define maxHeap priority_queue<ll>
typedef unordered_map<ll, ll> uml2l;
typedef unordered_map<char, ll> umc2l;
typedef vector<vector<bool>> vv_bool;
#define mx3(a, b, c)  max(a, max(b, c))
#define mn3(a, b, c)  min(a, min(b, c))
#define minHeap priority_queue<ll, vl, greater<ll>>
#define fastIO_ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
inline void printV(vl &a) { for (auto o: a) cout<<o<<" "; cout<<"\n"; }
#define fp fixed << setprecision(12)

ll fx[] = {1, -1, 0, 0};
ll fy[] = {0, 0, 1, -1};
char sym[] = {'D', 'U', 'R', 'L'};

inline bool is_valid(ll x, ll y, vector<string>& grid, ll n, ll m, vector<vl> &dist) {
    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#' && dist[x][y] == LLONG_MAX) {
        return true;
    }
    return false;
}

inline void visit_bfs(pair_ll &start, vector<string> &grid, ll n, ll m, vector<vl> &dist, vector<v_char> &travel) {
    queue <pair_ll> q;
    q.push(start);
    dist[start.x][start.y] = 0;
    while(!q.empty()) {
        pair_ll node = q.front();
        q.pop();
        for (ll dir=0; dir<4; dir++) {
            ll tx = node.x + fx[dir];
            ll ty = node.y + fy[dir];
            if (is_valid(tx, ty, grid, n, m, dist)) {
                q.push(make_pair(tx, ty));
                dist[tx][ty] = dist[node.x][node.y] + 1;
                travel[tx][ty] = sym[dir];
            }
        }
    }
}

void solve()
{
    ll n, m; cin>>n>>m;

    pair_ll start, end;
    vector <string> grid(n);
    vector <vl> dist(n, vl(m, LLONG_MAX));
    vector <v_char> travel(n, v_char(m, '.'));

    for (ll i=0; i<n; i++) {
        cin>>grid[i];
        for (ll j=0; j<m; j++) {
            if (grid[i][j] == 'A') {
                start = make_pair(i, j);
            }
            if (grid[i][j] == 'B') {
                end = make_pair(i, j);
            }
        }
    }

    visit_bfs(start, grid, n, m, dist, travel);

    if (dist[end.x][end.y] == LLONG_MAX) {
        cout<<"NO\n";
        return;
    }
    
    cout<<"YES\n"<<dist[end.x][end.y]<<endl;
    string shortest_path;
    while (end != start) {
        char nowDir = travel[end.x][end.y];
        shortest_path += nowDir;
        if (nowDir == 'U') {
            end.x++;
        }
        else if (nowDir == 'D') {
            end.x--;
        }
        else if (nowDir == 'L') {
            end.y++;
        }
        else if (nowDir == 'R') {
            end.y--;
        }
    }
    reverse(shortest_path.begin(), shortest_path.end());
    cout<<shortest_path<<endl;
    
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