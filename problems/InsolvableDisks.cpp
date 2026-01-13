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
    int n, i; cin>>n;
    ll ans=0; double odd_decr, odd_incre, even_decr, even_incre; int prev=0, curr;
    double lastr; int len=0; int lastc;
    fo(i,n) {
        cin>>curr;
        if (len>1) {
            if (curr>=lastc+lastr) {
                ans++; double oldr=lastr; lastr=curr-lastc-lastr;
                if (i%2) {
                    odd_decr=min(odd_decr, lastr); odd_incre=min(odd_incre, oldr);
                    even_incre=min(even_incre, lastr);
                } else {
                    even_decr=min(even_decr, lastr); even_incre=min(even_incre, oldr);
                    odd_incre=min(odd_incre, lastr);
                }
            } else {
                if (i%2) {
                    double need=(lastc+lastr)-curr;
                    double slack=min(even_decr, odd_incre);
                    if (slack>=need) {
                        even_decr-=slack; odd_incre-=slack;
                        ans++;
                    }
                }
            }
        } else if (len) {
            len++; lastr=(double)(curr-lastc)/2;
            even_decr=lastr; even_incre=lastr; odd_decr=lastr; odd_incre=lastr;
            lastc=curr; ans++;
        } else {
            lastc=curr; len++;
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