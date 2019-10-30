#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <sstream>
#include <climits>
#include <fstream>
#include <cmath>

using namespace std;

/// ********* debug template by Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const unordered_set< T > &v ) {
    os << "[";
    typename unordered_set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << ": " << it -> second ;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const unordered_map< F, S > &v ) {
    os << "[";
    typename unordered_map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << ": " << it -> second ;
    } 
    return os << "]";
}

#define debug(x) cerr << #x << " = " << x << endl;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VB> VVB;
typedef vector<VI> VVI;
typedef vector<VC> VVC;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;

// TEMPLATE DEFINITIONS END

int n, x;
VI a;

void read_input(){
    cin >> n >> x;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

bool f(int l, int r){
    int prev = -1;
    for(int i=0;i<n;i++){
        if(a[i] >= l && a[i] <=r) continue;

        if(prev == -1){
            prev = a[i];
            continue;
        }

        if(prev > a[i]) return false;
        prev = a[i];
    }
    return true;
}

void solve(){

    int lb=x, ub=1;

    int l = 1, r = x + 1;
    while(l < r){
        int m = l + (r-l)/2;
        if(f(m, x)){
            lb = m;
            l = m + 1;
        }else{
            r = m;
        }
    }

    l = 0, r = x;
    while(l < r){
        int m = l + (r-l)/2;
        if(f(1, m)){
            ub = m;
            r = m - 1;
        }else{
            l = m;
        }
    }

    set<PII> sol;

    for(int i=ub;i<=x;i++){
        sol.insert({1, i});
    }

    for(int i=lb;i>=1;i--){
        sol.insert({i, x});
    }

    if(lb <= ub)
    for(int i=1;i<=lb;i++){
        for(int j=ub;j<=x;j++){
            if(f(i, j))
            sol.insert({i, j});
        }
    }

    int res = sol.size();
    // debug(x);
    // debug(lb);
    // debug(ub);
    // debug(sol);
    // debug(res);

    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
