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

int q;
void solve_q();

void read_input(){
    cin >> q;
    for(int i=0;i<q;i++) solve_q();
}

VI a, b;
VI cnts;
int n;

void read_q(){
    cin >> n;
    a.resize(n);
    b.resize(n);
    cnts = VI(n, 0);
   
    for(int i=0;i<n;i++){
        cin >> a[i]; a[i]--;
        cnts[a[i]]++;
    }

    for(int i=0;i<n;i++){
        cin >> b[i]; b[i]--;
        cnts[b[i]]--;
    }
}

bool solve(int l, int r){

    if(l >= r)
        return true;

    int idx_a = -1, idx_b = -1;
    int maxi_a = INT_MIN, maxi_b = INT_MIN;

    for(int i=l;i<r;i++){
        if(a[i] > maxi_a){
            maxi_a = a[i];
            idx_a = i;
        }

        if(b[i] > maxi_b){
            maxi_b = b[i];
            idx_b = i;
        }
    }

    if(idx_b < idx_a) return false;

    if(idx_a < idx_b)
    for(int i=idx_a;i<idx_b;i++){
        swap(a[i], a[i+1]);
    }
    bool res = solve(l, idx_b) && solve(idx_b + 1, r);
    return res;
}

void solve_q(){
    
    read_q();

    for(int i=0;i<n;i++){
        if(cnts[i] != 0){
            cout << "NO\n";
            return;
        }
    }

    bool res = solve(0, n);
    if(res){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    // solve();
    return 0;
}
