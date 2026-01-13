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
    int n, k, i=0, temp=0;
    cin >> n, cin >> k;
    vi q, r;
    fo(i,n) {
        cin >> temp;
        q.pb(temp);
    }
    i=0;
    fo(i,n) {
        cin >> temp;
        r.pb(temp);
    }
    sortall(q), sortall(r);
    int l=0, ri=n-1, ans=0;
    int ans1=0;
    while (l<=ri) {
        int m=(l+ri)/2;
        int qp=0, rp=n-1;
        ans=0;
        while (qp<n && rp>=0 && ans<m) {
            if (ll(1+r[rp])*(ll)q[qp]<=(ll)k-r[rp]) {
                ans++;
            }
            qp++;
            rp--;
        }
        if (ans>=m) {
            ans1=max(ans1,ans);
            l=m+1;
        } else {
            ri=m-1;
        }
    }
    cout<<ans1<<nline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}