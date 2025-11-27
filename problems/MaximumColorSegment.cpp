#include "../bits-stdc++.h"

using namespace std;
using ll=long long;
using d=double;
using pii=pair<int,int>;
using vi=vector<int>;
using vd=vector<d>;
using vll=vector<ll>;
using vpii=vector<pii>;

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
int solve() {
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;
    string s;
    getst(s);
    getst(s);
    vi T(k+1);
    db(n);
    db(m);
    db(k);
    db(s);
    int i;
    string curr="";
    string win="";
    int ans=0;
    fo(i,n) {
        if (s[i]=='R') {
            curr+="0";
        } else {
            curr+="1";
        }
        if (i<k) {
            win+="1";
        }
    }
    int a=stoi(curr, nullptr, 2);
    int w=stoi(win,nullptr,2);
    db(a);
    i=0;
    fo(i,k) {

    }
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