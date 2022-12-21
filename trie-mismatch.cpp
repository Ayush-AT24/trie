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
    node* child[26];
    vector<string> wend;
    node(){
        for(int i = 0; i < 26; i++)
            child[i]=NULL;
    }
};


struct trie {
    node* root;
    trie(){
        root = new node;
    }

    void insert(string &s)
    {
        node* cur = root;
        for(int i = 0; i < s.size(); i++)
        {
            int x = s[i] - 'a';
            if(cur->child[x] == NULL)
            {
                cur->child[x] = new node;
            }
            cur = cur->child[x];
        }
        cur->wend.PB(s);
    }
};

vector<string> get(node* cur, ll k, string s)
{
    vector<string> ans;
    function<void(node*, ll, ll)> dfs;

    dfs = [&](node* cur,ll k, ll ind)->void{

        if(ind == s.size())
        {
            for(auto &item: cur->wend)
            {
                ans.PB(item);
            }
            return;
        }

        for(int i=0; i < 26; i++)
        {
            if(cur->child[i] != NULL)
            {
                if(s[ind] - 'a' == i)
                {
                    dfs(cur->child[i], k, ind+1);
                }
                else if(k)
                {
                    dfs(cur->child[i], k-1, ind+1);
                }
            }
        }
    };

    dfs(cur, k, 0);

    return ans;
}

 
 
mt19937 rng (chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
 
void test_case(){
    vector<string> v = {"aaa", "baa", "aca", "abb"};

    trie* x= new trie;

    for(auto &i: v)
    {
        x->insert(i);
    }

    for(auto &i: get(x->root, 1, "aaa"))
    {
        cout << i << sp;
    }
}
 
int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0); 
int t=1;
// cin>>t;
while(t--) test_case();
return 0;
}
