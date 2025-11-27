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

template<typename T> using pq_mi=priority_queue<T, vector<T>, greater<T> >;
template<typename T> using pq_ma=priority_queue<T>;

#define fo(i,n) for(i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define sortall(v) sort(all(v))
#define pb(x) push_back(x)
#define F first
#define S second
#define mp make_pair

#define getst(s) getline(cin, s);

#define db(x) cout<<"x="<<x<<"\n"
#define dbpair(p) cout<<"first="<<p.first<<", second="<<p.second<<"\n"

//basic solve
void solve() {
    int n;
    cin >> n;
    mii m;
    int i;
    int x;
    fo(i, n) {
        cin >> x;
        m[x]++;
    }
    int ans=0;
    for (auto p : m) {
        if (p.F>p.S) {
            ans+=p.S;
        } else if (p.F<p.S) {
            ans+=p.S-p.F;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    string s;
    getst(s);
    while (t--) solve(); //solve each testcase
}