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
    vi a;
    vi m;
    fo(i,n) {
        int temp;
        cin>>temp;
        a.pb(temp);
    }
    i=0;
    fo(i,n) {
        int temp;
        cin>>temp;
        m.pb(temp);
    }
    i=0;
    bool alast=0;
    int count=0;
    int a1=0, m1=0;
    fo(i,n) {
        if (a[i]==m[i]) {
            if (a[i]) {
                count++;
            }
        }
        else if (i%2==0) {
            a1++; alast=1;
        } else {
            m1++; alast=0;
        }
    }
    if (a1==m1) {
        cout<<"Tie"<<nline;
    } else {
        int aeven=a1%2; int meven=m1%2;
        if (count%2) {
            if (alast) {
                if (aeven && !meven) {
                    cout<<"Ajisai"<<nline;
                } else if (aeven && meven) {
                    cout<<"Tie"<<nline;
                } else if (!aeven && !meven) {
                    cout<<"Tie"<<nline;
                } else if (!aeven && meven) {
                    cout<<"Ajisai"<<nline;
                }
            } else {
                if ((aeven && meven) || (!aeven && !meven)) {
                    cout<<"Tie"<<nline;
                } else {
                    cout<<"Mai"<<nline;
                }
            }
        } else {
            if (alast) {
                if ((aeven && meven) || (!aeven && !meven)) {
                    cout<<"Tie"<<nline;
                } else {
                    cout<<"Ajisai"<<nline;
                }
            } else {
                if ((aeven && meven) || (!aeven && !meven)) {
                    cout<<"Tie"<<nline;
                } else {
                    cout<<"Mai"<<nline;
                }
            }
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