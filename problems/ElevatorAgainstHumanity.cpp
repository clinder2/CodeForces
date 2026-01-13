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

//basic solve
void solve() {
    int n, i, s1, e1; cin>>n;
    vi s; vi e;
    fo(i,n) {
        cin>>s1; cin>>e1;
        s.pb(s1); e.pb(e1);
    }
    sortall(s); sortall(e);
    ll ans=0;
    int l=0, r=n-1, prev=0;
    while (l<r) {
        ans+=2*(s[r--]-s[l])+(s[l]-prev);
        prev=s[l++];
    }
    if (l==r) {
        ans+=s[l]-prev;
    } else {
        l--;
    }
    if (e.back()-s[l]>s[l]-e[0]) {
        ans+=e.back()-s[l]+e.back()-e[0];
        l=0; r=e.size()-2;
        while (l<r) {
            ans+=e[r]-e[l]+e[r]-e[l+1]; l++; r--;
        }
    } else {
        ans+=s[l]-e[0]+e.back()-e[0];
        l=1; r=e.size()-1;
        while (l<r) {
            ans+=e[r]-e[l]+e[r-1]-e[l]; l++; r--;
        }
    }
    cout<<ans-1<<nline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}