//#include "../bits-stdc++.h"
#include <bits/stdc++.h>

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
    int n, i, j; cin>>n;
    ll le, ri, left=0, right=1e9, total;
    vi l; vi r; vivi d(n); vector<vivi> door(n);
    fo(i,n) {
        int k; cin>>k; cin>>le; cin>>ri; total=0;
        l.pb(le); r.pb(ri); left=max(left, le); right=min(right, ri);
        fo(j,k) {
            cin>>le; total+=le;
            d[i].pb(le);
        }
        ll start=l.back(); total=r.back()-l.back()-total; vi t; t.pb(start); t.pb(start+total);
        door[i].pb(t);
        for (auto d1 : d[i]) {
            start+=d1; t[0]=start; t[1]+=d1; door[i].pb(t);
        }
    }
    ll ans=0;
    vivi prev=door[0]; vi t(2); vivi curr;
    fo(i,n) {
        if (i) {
            vivi next; curr=door[i]; j=0; int k=0;
            //cout<<curr.size()<<" curr "<<prev.size()<<" prev "<<nline;
            while (j<prev.size() && k<curr.size()) {
                while (j<prev.size() && prev[j][1]<curr[k][0]) {j++;}
                while (k<curr.size() && prev[j][0]>curr[k][1]) {k++;}
                if (j<prev.size() && k<curr.size()) {
                    //cout<<i<<", j "<<j<<", k "<<k<<nline;
                    if (curr[k][0]<=prev[j][1]<=curr[k][1]) {
                        t[0]=max(curr[k][0], prev[j][0]); t[1]=prev[j][1]; next.pb(t); j++;
                    } else if (curr[k][0]<=prev[j][0]<=curr[k][1]) {
                        t[0]=max(curr[k][0], prev[j][0]); t[1]=curr[k][1]; next.pb(t); k++;
                    }
                }
            }
            prev=next;
        }
    }
    if (prev.size()) {
        for (auto p : prev) {
            //db(p[0]); db(p[1]);
            ans=max(ans, (ll)p[1]-p[0]);
        }
    }
    cout<<ans<<nline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1; //num testcases
    while (t--) solve(); //solve each testcase
}