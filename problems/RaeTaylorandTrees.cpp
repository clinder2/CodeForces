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
using vs=vector<string>;
using mii=map<int,int>;
using mci=map<char,int>;

using vivi=vector<vector<int> >;

template<typename T> using pq_mi=priority_queue<T, vector<T>, greater<T> >;
template<typename T> using pq_ma=priority_queue<T>;

#define nline "\n";
#define fo(i,s,n) for(i=s; i<n; i++)
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
    int n, i, curr; cin>>n;
    int ma=0, prev=0;
    vs v; vi v1;
    cin>>curr; ma=curr;
    fo(i,1,n) {
        cin>>curr;
        if (!prev && curr>ma) {
            v.pb(to_string(ma)+" "+to_string(curr));
        } else {
            if (!prev) {
                prev=ma;
            } else if (curr>prev) {
                v.pb(to_string(prev)+" "+to_string(curr));
                prev=0;
            }
            ma=min(ma,curr);
            while (v1.size() && v1.back()<curr) {
                v.pb(to_string(v1.back())+" "+to_string(curr));
                v1.pop_back();
            }
            if (prev) {
                v1.pb(curr);
            }
        }
    }
    if (v.size()!=n-1) {
        cout<<"No"<<nline;
    } else {
        cout<<"Yes"<<nline;
        for (auto s : v) {
            cout<<s<<nline;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}