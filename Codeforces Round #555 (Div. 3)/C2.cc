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
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VS> VVS;

int n;
VI a;
map<PII, int> memo;

void read_input(){
    cin >> n; // 1 <= n <= 2*10^5
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

VC helper(int l, int r, int largest){
    VC sol;
    while(l <= r && (a[l] > largest || a[r] > largest)){
        if(a[l] == a[r] && a[l] > largest){
            VC sol_left = helper(l+1, r, a[l]);
            VC sol_right = helper(l, r-1, a[r]);

            if(sol_left.size() > sol_right.size()){
                sol.push_back('L');
                sol.insert(sol.end(), sol_left.begin(), sol_left.end());
            }else{
                sol.push_back('R');
                sol.insert(sol.end(), sol_right.begin(), sol_right.end());
            }
            return sol;
        }

        if(a[l] > largest && a[r] > largest){
            if(a[l] < a[r]){
                largest = a[l];
                l++;
                sol.push_back('L');
            }else{
                largest = a[r];
                r--;
                sol.push_back('R');
            }
        }else
        if(a[l] > largest){
            largest = a[l];
            l++;
            sol.push_back('L');
        }else{
            largest = a[r];
            r--;
            sol.push_back('R');
        }
    }
    return sol;
}

void solve(){
    
    VC sol = helper(0, n-1, 0);
    cout << sol.size() << "\n";
    cout << string(sol.begin(), sol.end()) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
