#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define fast_input() ios::sync_with_stdio(false); cin.tie(nullptr);

#define int long long
#define fr(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define frr(i, a, b) for (int i = (a); i > (int)(b); --i)
#define in(n)    \
    long long n; cin >> n;
#define ina(x, n)               \
    for (int i = 0; i < n; ++i) \
        cin >> x[i];
#define input_set(set, n)       \
    for(int i=0;i<n;i++){int x;cin>>x;set.insert(x);}
#define double long double
#define pb push_back
#define vi vector<int>
#define mii map<int, int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define si set<int>

#define ff first
#define ss second
#define MOD 1000000007
#define endl "\n"
#define oyes cout << "YES" << endl;
#define ono cout << "NO" << endl;
#define oyess cout << "Yes" << endl;
#define onoo cout << "No" << endl;
#define ve1 cout << "-1" << endl;

#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define rall(x) reverse((x).begin(), (x).end())
#define sz(x) (int)(x).size()

#define nline <<'\n'

const int INF = LLONG_MAX >> 1;

//?-----------------------------------------------------------------------------------------------------------

void solve(){
    in(n);


    // final implementation, just measure two numbers
    // if abs(count(number1) - count(number2)) == 0||1 { oyes; }
    
    vi nums(n);
    ina(nums, n);


    int a = -1, b = -1;
    int ac = 0, bc = 0;
    bool flag = false;
    fr(i,0,n){
        if (a != -1 && b == -1 && a!=nums[i]){
            b = nums[i];
        }
        else if(a == -1){
            a = nums[i];
        }
        

        if (nums[i] == a){
            ac+=1;
        }
        else if (nums[i] == b){
            bc+=1;
        }
        else{
            flag = true;
        }
    }

    // cout << ac << " " << bc nline;

    if (flag){
        onoo;
    }
    else if( ac-bc == 0 || abs(ac - bc) == 1 || bc == 0){
        oyess;
    }
    else{
        onoo;
    }
    
    // char with freq 1 is edgecase, only 'good' is if nothing exists or another char with freq 2
    //

    // 3 5
    // a a b b b c c c c c 
    // c c c c c
    // parity needs to remain same?
    // odd with odd

    // edgecase of even with odd working is 2 with 3
    // 1 with 0
    // 1 with 2
    // 2 with even
    // ababa

    // its not parity, its just a very few sub conditions that work out
    // both same
    // 


    // final
    // both same, all same freq

    // 1 with 0, 1 with 2

    // 3 with 2
    // 4 with 3
    

    // algo - if freq, then freq-1 OR freq should also be present
    // smart question


    // implementation, multiset measuring count, count stored in vector, sorted
    
    // 2 3 4
    // aabbbcccc
    //cbcbcbc
    // if multiple counts then all should be same?
    // 2 2 2
    // cbc

    // looks like multiple counts wont work
    // final implementation, just measure two numbers
    // if abs(count(number1) - count(number2)) == 0||1 { oyes; }



    
}

signed main(){
    fast_input();

    int t=1;
    cin >> t;
    for (int i = 1; i <= t; i++){
        // cout << "Case " << i << ":" << endl;
        solve();
    }

    return 0;
}