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
    int n, m, i=0, temp;
    cin >> n, cin >> m;
    int ans=m;
    string s;
    //getst(s);
    cin >> s;
    vector<vector<ll> > v;
    int l=1;
    fo(i,m) {
        cin>>temp;
        if (temp>l) {
            vector<ll> t;
            t.pb(l);
            t.pb(temp-1);
            v.push_back(t);
            //cout<<t[0]<<", "<<t[1]<<nline;
        }
        l=temp+1;
    }
    vector<ll> t;
    t.pb(l);
    t.pb(1000000000);
    v.push_back(t);
    char prev='A';
    int index=0;
    int curr=1;
    set<int> ret;
    //cout<<"N: "<<n<<"M: "<<m<<"S: "<<s<<nline;
    for (auto c : s) {
        //cout<<index<<" index\n";
        if (prev=='B') {
            curr=v[index][0];
            if (c=='A') {
                curr++;
                ret.insert(curr);
                v[index][0]+=2;
                if (v[index][0]>v[index][1]) {
                    index++;
                }
            } else {
                if (v[index][0]<v[index][1]) {
                    curr++;
                    ret.insert(curr);
                    v[index][0]+=2;
                    if (v[index][0]>v[index][1]) {
                        index++;
                    }
                } else {
                    index++;
                    curr=v[index][0];
                    ret.insert(curr);
                    v[index][0]++;
                    if (v[index][0]>v[index][1]) {
                        index++;
                    }
                }
            }
        } else {
            if (c=='A') {
                curr++;
                ret.insert(curr);
                if (v[index][0]==curr) {
                    v[index][0]++;
                    if (v[index][0]>v[index][1]) {
                        index++;
                    }
                }
            } else {
                curr=v[index][0];
                ret.insert(curr);
                v[index][0]++;
                if (v[index][0]>v[index][1]) {
                    index++;
                }
            }
        }
        prev=c;
    }

    cout<<ret.size()<<nline;
    for (auto value : ret) {
        cout<<value<<" ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}