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

int t;
string s;

void solve_q();

void read_input(){
    cin >> t;
    for(int i=0;i<t;i++) solve_q();
}

void solve_q(){

    unordered_map<char, unordered_map<char, char>> m;
    
    m['a']['?'] = 'b';
    m['a']['a'] = 'b';
    m['a']['b'] = 'c';
    m['a']['c'] = 'b';

    m['b']['?'] = 'c';
    m['b']['a'] = 'c';
    m['b']['b'] = 'c';
    m['b']['c'] = 'a';

    m['c']['?'] = 'a';
    m['c']['a'] = 'b';
    m['c']['b'] = 'a';
    m['c']['c'] = 'a';

    m['?']['?'] = 'a';
    m['?']['a'] = 'b';
    m['?']['b'] = 'c';
    m['?']['c'] = 'a';

    cin >> s;
    int n = s.size();
    s.insert(0, "?");
    s.insert(n+1, "?");
    // cout << s << "\n";

    for(int i=1;i<=n;i++){
        if(s[i] == '?') s[i] = m[s[i-1]][s[i+1]];
        if(s[i] == s[i-1]){
            cout << -1 << "\n";
            return;
        }
    }

    cout << s.substr(1, n) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    // solve();
    return 0;
}
