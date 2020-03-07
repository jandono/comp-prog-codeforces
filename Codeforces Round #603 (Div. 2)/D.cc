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

int n;
string s;

vector<int> components(26, -1);
vector<int> depths(26, 1);
vector<int> sizes(26, 0);
unordered_set<char> chars;

int root(int x){
    
    while(components[x] != -1)
        x = components[x];

    return x;
}

void merge(int x, int y){

    int root_x = root(x);
    int root_y = root(y);
    if(root_x == root_y) return;

    if(depths[root_x] > depths[root_y]){
        components[root_y] = root_x;
        sizes[root_x] += sizes[root_y];
    }else
    if(depths[root_x] < depths[root_y]){
        components[root_x] = root_y;
        sizes[root_y] += sizes[root_x];
    }else{
        components[root_x] = root_y;
        sizes[root_y] += sizes[root_x];
        depths[root_y]++;
    }
}

void read_input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        chars.insert(s[0]);

        for(int j=1;j<s.size();j++){
            chars.insert(s[j]);
            merge(s[0] - 'a', s[j] - 'a');
        }
    }
}

void solve(){

    int sol = 0;
    for(int i=0;i<26;i++){
        if(components[i] == -1 && chars.count('a' + i)) sol++;
    }

    cout << sol << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
