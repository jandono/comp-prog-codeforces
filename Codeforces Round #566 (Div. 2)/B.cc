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

int W, H;
VVC pic;

void read_input(){
    cin >> H >> W;
    pic.resize(H, VC(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> pic[i][j];
        }
    }
}

void update(int x, int y){
    
    pic[x][y] = '.';

    for(int i=x+1;i<H;i++){
        if(pic[i][y] == '.')
            break;
        pic[i][y] = '.';
    }

    for(int i=x-1;i>=0;i--){
        if(pic[i][y] == '.')
            break;
        pic[i][y] = '.';
    }

    for(int j=y+1;j<W;j++){
        if(pic[x][j] == '.')
            break;
        pic[x][j] = '.';
    }

    for(int j=y-1;j>=0;j--){
        if(pic[x][j] == '.')
            break;
        pic[x][j] = '.';
    }
}

void solve(){

    bool flag = false;
    for(int i=1;i<H-1;i++){
        
        for(int j=1;j<W-1;j++){
            if(pic[i][j] == '*' && pic[i-1][j] == '*' && 
            pic[i+1][j] == '*' && pic[i][j-1] == '*' && pic[i][j+1] == '*'){
                update(i, j);
                flag = true;
                break;
            }
        }

        if(flag) break;
    }

    if(!flag){
        cout << "NO\n";
        return;
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(pic[i][j] == '*'){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
