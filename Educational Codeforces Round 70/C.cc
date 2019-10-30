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

int T;
string s;

void solve_q();

void read_input(){
    cin >> T;
    for(int i=0;i<T;i++) solve_q();
}

pair<int, bool> process_string(char plus, char minus){
    
    int maxi=0, mini=0, cnt=0, first_max=0, last_max=0, first_min=0, last_min=0;
    
    for(int i=0;i<s.size();i++){
        
        if(s[i] == plus) cnt++;
        else
        if(s[i] == minus) cnt--;
        
        if(cnt > maxi){
            maxi = cnt;
            first_max = i;
            last_max = i;
        }else
        if(cnt == maxi){
            last_max = i;
        }

        if(cnt < mini){
            mini = cnt;
            first_min = i;
            last_min = i;
        }else
        if(cnt == mini){
            last_min = i;
        }
    }

    int l = maxi - mini + 1;
    bool can_decrease = false;
    if(l > 2 && (last_max < first_min || last_min < first_max))
        can_decrease = true;

    return {l, can_decrease};
}

void solve_q(){

    cin >> s;

    int height, width;
    bool can_decrease_height, can_decrease_width;
    
    tie(height, can_decrease_height) = process_string('W', 'S');
    tie(width, can_decrease_width) = process_string('D', 'A');

    LL sol = (LL)height * (LL)width;

    if(can_decrease_height)
        sol = min(sol, (LL)(height-1) * (LL)width);

    if(can_decrease_width)
        sol = min(sol, (LL)height * (LL)(width - 1));

    cout << sol << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    // solve();
    return 0;
}
