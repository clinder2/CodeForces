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

int help(vi aj, vi ma, vi alast) {

}

//basic solve
void solve() {
    int n, i=0;
    cin >> n;
    vll a;
    vll m;
    fo(i,n) {
        ll temp;
        cin>>temp;
        a.pb(temp);
    }
    i=0;
    fo(i,n) {
        ll temp;
        cin>>temp;
        m.pb(temp);
    }
    vi aj(32, 0); vi ma(32, 0); vi alast(32, 0); i=0;
    vi total(32);
    fo(i,32) {
        aj[i]=0; ma[i]=0; alast[i]=0;
    }
    i=0;
    fo(i,n) {
        int j=0;
        fo(j,32) {
            int ab=(a[i]>>j)&1; int mb=(m[i]>>j)&1;
            //cout<<ab<<", "<<mb<<nline;
            if (ab!=mb) {
                //cout<<i<<", "<<ab<<", "<<mb<<", "<<a[i]<<", "<<m[i]<<", here "<<j<<nline;
                if (i%2) {
                    ma[j]++; alast[j]=0;
                } else {
                    aj[j]++; alast[j]=1;
                }
            } else if (ab) {
                total[j]++;
            }
        }
    }
    i=31;
    fob(i,31) {
        if (aj[i] || ma[i]) {
            //cout<<aj[i]<<", "<<ma[i]<<", "<<alast[i]<<", "<<i<<nline;
            if (alast[i]) {
                if ((aj[i]+ma[i])%2) {
                    cout<<"Ajisai"<<nline;
                    return;
                }
            } else {
                if ((aj[i]+ma[i])%2) {
                    cout<<"Mai"<<nline;
                    return;
                }
            }
        }
    }
    cout<<"Tie"<<nline;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}