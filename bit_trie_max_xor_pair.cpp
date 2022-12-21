#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define ll long long
#define ld long double
#define el '\n'
#define sp ' '
#define S second
#define F first
#define vi vector<int>
#define vl vector <long long int>
#define vop vector<pair<ll,ll>>
#define vov vector<vector<ll>>
#define dbg(x)      cout << #x << " is " << x << endl;

struct node {
    node* child[2];
    node(){
        child[0] = child[1] =NULL;
    }
};

struct bit_trie{
    node* root;
    bit_trie(){
        root = new node;
    }
    insert(int x, ll pad)
    {
        node* cur = root;
        for(int i = pad-1; i>=0; i--)
        {
            int bit = (x&(1<<i)) ? 1 : 0;
            if(!cur->child[bit])                
            {
                cur->child[bit] = new node;
            }
            cur = cur->child[bit];
        }
    }
};

ll find_best(ll x, node* cur, ll pad)
{
    ll ans = 0;
    for(int i = pad-1; i>= 0; i--)
    {
        int bit = (x & (1 << i)) ? 0 : 1;
        if(cur->child[bit])
        {
            cur = cur->child[bit];
            if(bit) ans = (ans | 1 << i);
        }
        else
        {
            cur = cur->child[!bit];     
            if(!bit) ans = (ans | 1 << i);
        }
    }

    return ans;
}
 
 
mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
 
void test_case(){
    vl a = {13, 9, 12, 7, 5, 1};
    bit_trie* x = new bit_trie; 
    x->insert(a[0], 4);
    ll mx = INT_MIN;
    for(int i = 1; i < a.size(); i++)
    {
        mx = max(find_best(a[i], x->root, 4)^a[i], mx);
        x->insert(a[i], 4);
    }
    cout << mx << el;
}
 
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0); 
int t=1;
// cin>>t;
while(t--) test_case();
return 0;
}
