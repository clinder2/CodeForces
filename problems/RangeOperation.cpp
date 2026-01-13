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
    int n, i=0;
    cin >> n;
    vi v;
    vll pref;
    ll total=0;
    fo(i,n) {
        int temp;
        cin >> temp;
        v.pb(temp);
        total+=temp;
        pref.pb(total);
    }
    ll ans=total;
    int l=0, r=0;
    ll best=0;
    while (r<n) {
        int curr=r+l+2;
        ll temp=curr*(r-l+1);
        ll diff=temp-(pref[r]-(l>0 ? pref[l-1] : 0));
        if (r==l) {
            diff=temp-v[r];
        }
        best=max(best,diff);
        //cout<<best<<" best"<<nline;
        //cout<<best<<", t "<<temp<<", d "<<diff<<nline;
        while (l<r && ((r+l+3)*(r-l)-(pref[r]-pref[l]))>best) {
            best=max(best, (ll)((r+l+3)*(r-l)-(pref[r]-pref[l])));
            l++;
        }
        r++;
    }
    r--;
    while (l<=r) {
        ll temp=(ll)(r+l+2)*(r-l+1);
        //cout<<temp<<", "<<(pref[r]-pref[l-1])<<", "<<l<<", "<<r<<nline;
        best=max(best,(ll)(temp-(pref[r]-(l==0 ? 0 : pref[l-1]))));
        l++;
    }
    ans+=best;
    cout<<ans<<nline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}