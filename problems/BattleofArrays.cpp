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
    int n, m, i=0, temp; cin>>n; cin>>m;
    pq_ma<int> a; pq_ma<int> b;
    fo(i,n) {
        cin>>temp; a.push(temp);
    }
    fo(i,m) {
        cin>>temp; b.push(temp);
    }
    i=0;
    int am=a.top(); int bm=b.top();
    while (a.size() && b.size()) {
        if (i%2) {
            bm=b.top();
            if (am>bm) {
                a.push(am-bm);
            }
            a.pop();
        } else {
            am=a.top();
            if (bm>am) {
                b.push(bm-am);
            }
            b.pop();
        }
        i++;
    }
    if (a.size()) {
        cout<<"Alice"<<nline;
    } else {
        cout<<"Bob"<<nline;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}