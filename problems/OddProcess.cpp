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
    int n, i=0;
    cin>>n;
    vi odd; vi even;
    fo(i,n) {
        int temp;
        cin>>temp;
        if (temp%2) {
            odd.pb(temp);
        } else {
            even.pb(temp);
        }
    }
    sortall(odd); sortall(even);
    if (!odd.size()) {
        for (i=1; i<=n; i++) {
            cout<<0<<" ";
        }
        cout<<nline;
    } else if (!even.size()) {
        for (i=1; i<=n; i++) {
            if (i%2) {
                cout<<odd.back()<<" ";
            } else {
                cout<<0<<" ";
            }
        }
        cout<<nline;
    } else {
        ll sum=odd.back(); int e=even.size()-1;
        int temp=even.size()+1;
        cout<<sum<<" ";
        for (i=2; i<n; i++) {
            if (e>=0) {
                sum+=even[e--];
                cout<<sum<<" ";
            } else {
                if ((i-even.size()-1)%2) {
                    cout<<(sum-even[0])<<" ";
                } else {
                    cout<<sum<<" ";
                }
            }
        }
        if ((odd.size()-1)%2) {
            cout<<0<<" ";
        } else {
            if (e==0) {
                sum+=even[e];
            }
            cout<<sum<<" ";
        }
        cout<<nline;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}