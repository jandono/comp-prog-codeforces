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

VI a(4);
bool solved = false;
vector<int> solution;

void read_input(){
    for(int i=0;i<4;i++) cin >> a[i];
}

bool check_invalid(int x, int y){
    
    if(x > y + 1) return true;
    return false;
}

void solve_r(int i, vector<int> &seq){

    // debug(i);
    // debug(a);
    // debug(seq);
    // cout << "######################\n";
    if(i == 3){
        if(!a[i] || (a[i] == 1 && (!seq.size() || (i - *seq.rbegin()  == 1)))){
            if(a[i]) seq.push_back(i);
            solved = true;
            solution = seq;
        }
        return;
    }

    if(!a[i]){
        solve_r(i+1, seq);
        return;
    }

    if(check_invalid(a[i], a[i+1])) return;

    if(a[i+1] > a[i]){

        // OPTION 1
        if(!seq.size() || (i+1 - *seq.rbegin() == 1)){
            seq.push_back(i+1);
            for(int j=0;j<a[i];j++){
                seq.push_back(i);
                seq.push_back(i+1);
            }

            int prev1 = a[i];
            int prev2 = a[i+1];
            
            a[i+1] = a[i+1] - a[i] - 1;
            a[i] = 0;
            
            solve_r(i+1, seq);
            if(solved) return;

            a[i] = prev1;
            a[i+1] = prev2;
            for(int j=0;j<a[i];j++){
                seq.pop_back();
                seq.pop_back();
            }
            seq.pop_back();
        }

        // OPTION 2
        if(!seq.size() || (i - *seq.rbegin() == 1)){
            for(int j=0;j<a[i];j++){
                seq.push_back(i);
                seq.push_back(i+1);
            }
            
            int prev1 = a[i];
            int prev2 = a[i+1];
            
            a[i+1] = a[i+1] - a[i];
            a[i] = 0;
            
            solve_r(i+1, seq);
            if(solved) return;

            a[i] = prev1;
            a[i+1] = prev2;
            for(int j=0;j<a[i];j++){
                seq.pop_back();
                seq.pop_back();
            }
        }
    }

    if(a[i+1] == a[i]){ 
        
        // OPTION 1
        if(!seq.size() || (i - *seq.rbegin() == 1)){
            for(int j=0;j<a[i];j++){
                seq.push_back(i);
                seq.push_back(i+1);
            }

            int prev1 = a[i];
            a[i] = 0;
            int prev2 = a[i+1];
            a[i+1] = a[i+1] - prev1;

            solve_r(i+1, seq);
            if(solved) return;

            a[i] = prev1;
            a[i+1] = prev2;

            for(int j=0;j<a[i];j++){
                seq.pop_back();
                seq.pop_back();
            }
        }

        // OPTION 2
        if(!seq.size() || (i + 1 - *seq.rbegin() == 1)){
            for(int j=0;j<a[i];j++){
                seq.push_back(i+1);
                seq.push_back(i);
            }

            int prev1 = a[i];
            a[i] = 0;
            int prev2 = a[i+1];
            a[i+1] = a[i+1] - prev1;

            solve_r(i+1, seq);
            if(solved) return;

            a[i] = prev1;
            a[i+1] = prev2;

            for(int j=0;j<a[i];j++){
                seq.pop_back();
                seq.pop_back();
            }
        }
    }

    if(a[i+1] == a[i] - 1){
        
        if(seq.size() && (i - *seq.rbegin() != 1)) return;
        
        for(int j=0;j<a[i+1];j++){
            seq.push_back(i);
            seq.push_back(i+1);
        }
        seq.push_back(i);

        int prev1 = a[i];
        a[i] = 0;
        int prev2 = a[i+1];
        a[i+1] = 0;

        solve_r(i+1, seq);
        if(solved) return;

        a[i] = prev1;
        a[i+1] = prev2;

        for(int j=0;j<a[i+1];j++){
            seq.pop_back();
            seq.pop_back();
        }
        seq.pop_back();
    }
}

void solve(){

    VI seq;
    solve_r(0, seq);

    if(solved){
        cout << "YES\n";
        for(int i=0;i<solution.size();i++){
            cout << solution[i] << " ";
        }
        cout << "\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
