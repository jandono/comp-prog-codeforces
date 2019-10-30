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
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<VB> VVB;
typedef vector<VI> VVI;
typedef vector<VC> VVC;
typedef vector<VLL> VVLL;
typedef vector<VS> VVS;

// TEMPLATE DEFINITIONS END

int n, m;
VVI mat1, mat2;
void read_input(){
    cin >> n >> m;
    mat1.resize(n, VI(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat1[i][j];
        }
    }
    
    mat2.resize(n, VI(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat2[i][j];
        }
    }
}

void solve(){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(j < m-1 && min(mat1[i][j], mat2[i][j]) >= min(mat1[i][j+1], mat2[i][j+1])){
                cout << "Impossible\n";
                return;
            }

            if(j < m-1 && max(mat1[i][j], mat2[i][j]) >= max(mat1[i][j+1], mat2[i][j+1])){
                cout << "Impossible\n";
                return;
            }

            if(i < n-1 && min(mat1[i][j], mat2[i][j]) >= min(mat1[i+1][j], mat2[i+1][j])){
                cout << "Impossible\n";
                return;
            }
        
            if(i < n-1 && max(mat1[i][j], mat2[i][j]) >= max(mat1[i+1][j], mat2[i+1][j])){
                cout << "Impossible\n";
                return;
            }
        }
    }

    cout << "Possible\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
