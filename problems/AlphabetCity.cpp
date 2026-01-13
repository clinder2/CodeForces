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
    int n, m, i; cin>>n; cin>>m;
    string s; map<char, int> ma; vs v;
    fo(i,n) {
        cin>>s;
        for (auto c : s) {
            ma[c]++;
        }
        v.pb(s);
    }
    fo(i,n) {
        map<char,int> temp;
        for (auto c : v[i]) {
            temp[c]++;
        }
        int k=0;
        for (auto p : temp) {
            int t=ma[p.F]-p.S;
            //cout<<p.S<<", "<<t<<nline;
            if (!t) {k=-1;break;}
            k=max(k,(int)ceil((double)p.S/t));
            //cout<<"k:"<<k<<nline;
        }
        if (k<=0 || m-k<0) {
            cout<<-1<<" ";
        } else {
            cout<<m-k<<" ";
        }
    }
    cout<<nline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1; //num testcases
    while (t--) solve(); //solve each testcase
}