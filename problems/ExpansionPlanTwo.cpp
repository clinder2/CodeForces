#include "../bits-stdc++.h"

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

template<typename T> using pq_mi=priority_queue<T, vector<T>, greater<T> >;
template<typename T> using pq_ma=priority_queue<T>;

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
int solve() {
    int n, x, y;
    cin >> n;
    cin >> x;
    cin >> y;
    string s;
    getst(s);
    mci m;
    x=abs(x);
    y=abs(y);
    int index=0;
    int temp=1;
    int b=x+y;
    // db(b);
    // db(s);
    if (n>=b) {
        cout<<"YES";
        return 0;
    } else {
        int i;
        fo(i,n) {
            m[s[i]]++;
        }
        // db(m['8']);
        // db(x);
        // db(y);
        int ans=m['4']+2*m['8'];
        //db(ans);
        if (x>ans || y>ans) {
            cout<<"NO";
            return 0;
        } else {
            if (ans>=x+y && n>=x && n>=y) {
                cout<<"YES";
                return 0;
            } else {
                cout<<"NO";
                return 0;
            }
        }
        //cout<<"NO";
        //return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; //num testcases
    cin >> t;
    while (t--) solve(); //solve each testcase
}