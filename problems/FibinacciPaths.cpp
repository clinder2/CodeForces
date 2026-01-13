#include "../bits-stdc++.h"
//#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using d=double;
using pii=pair<int,int>;
using vi=vector<int>;
using vd=vector<d>;
using vll=vector<ll>;
using vpii=vector<pii>;
using mii=map<int,int>;
using mci=map<char,int>;

using vivi=vector<vector<int> >;

template<typename T> using pq_mi=priority_queue<T, vector<T>, greater<T> >;
template<typename T> using pq_ma=priority_queue<T>;

#define nline "\n";
#define fo(i,n) for(i=0; i<n; i++)
#define fob(i,n) for(i=n; i>=0; i--)
#define all(v) v.begin(), v.end()
#define sortall(v) sort(all(v))
#define pb(x) push_back(x)
#define F first
#define S second

#define getst(s) scanf("%s", &s)

#define db(x) cout<<"x="<<x<<"\n"
#define dbpair(p) cout<<"first="<<p.first<<", second="<<p.second<<"\n"

vll T; vi v; vivi adj; vi seen;
vi edgeend; vi edgest;
vpii vp;
ll MOD=998244353;
ll dfs(int vertex, int curr) {
    for (auto n : adj[vertex]) {
        if (n==curr) {
            if (seen[n] && seen[vertex]) {
                T[vertex]+=T[n]; T[vertex]%=MOD;
            } else {
                T[vertex]+=dfs(n, v[n]+v[vertex]); T[vertex]%=MOD;
            }
        }
    }
}

//basic solve
void solve() {
    int n, m, i=0;
    ll temp;
    cin>>n; cin>>m;
    T=*(new vll(m, 1)); v=*(new vi(n,0));
    adj = *(new vivi(n)); seen=*(new vi(n,0));
    edgeend=*(new vi(m, 0)); edgest=*(new vi(m, 0));
    fo(i,n) {
        cin>>temp; pii t=make_pair(temp, i);
        v[i]=temp; vp.pb(t);
    }
    sortall(vp);
    i=0;
    ll a,b;
    fo(i,m) {
        cin>>a; cin>>b;
        adj[a-1].push_back(b-1);
        //edgeend[i]=b-1; edgest[i]=a-1;
    }
    ll ans=0;
    fo(i,n) {
        int curr=vp[i].S;
        if (!seen[curr]) {
            seen[curr]=1;
            for (auto p : adj[curr]) {
                temp=v[curr]+v[p];
            }
        }
        ans=(ans+T[i])%MOD;
    }
    //ll ans=0;
    // fo(i,m) {
    //     ans=(ans+T[i])%MOD;
    // }
    cout<<ans<<nline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}