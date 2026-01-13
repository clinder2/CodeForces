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

template<typename T> using pq_mi=priority_queue<T, vector<T>, greater<T> >;
template<typename T> using pq_ma=priority_queue<T>;

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
    int n;
    cin >> n;
    if (n==1) {
        cout<<1<<"\n";
    } else if (n==2) {
        cout<<9<<"\n";
    } else {
        ll b = n*n;
        ll a = b-n-1;
        ll temp = b-n+b-n-2+b-(2*n)-1+a+b-1;
        ll temp2=a+(ll)(3*b)-3;
        ll ans=temp>temp2 ? temp : temp2;
        cout<<ans<<"\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}