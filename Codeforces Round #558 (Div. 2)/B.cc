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

int n;
VI ribbons;
unordered_map<int, int> cnt;
map<int, int> r_cnt;

void read_input(){
    cin >> n; // 1 <= n <= 100 000
    ribbons.resize(n);
    for(int i=0;i<n;i++){
        cin >> ribbons[i];
    }
}

bool valid(){
    
    if(r_cnt.size() == 1){
        auto it = r_cnt.begin();
        if(it->first == 1 || it->second == 1)
            return true;
        
        return false;
    }

    if(r_cnt.size() == 2){
        auto it = r_cnt.begin();
        auto it2 = r_cnt.begin();
        it2++;

        if(it->first == 1 && it->second == 1)
            return true;

        if(it2->second == 1 && (it2->first - it->first == 1))
            return true;

        return false;
    }
    
    return false;
}

void solve(){

    int res = 0;
    for(int i=0;i<n;i++){
        
        int x = ribbons[i];
        if(r_cnt.count(cnt[x])) r_cnt[cnt[x]]--;
        if(r_cnt.count(cnt[x]) && !r_cnt[cnt[x]]) r_cnt.erase(cnt[x]);

        cnt[x]++;
        r_cnt[cnt[x]]++;

        if(valid())
            res = i+1;
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
