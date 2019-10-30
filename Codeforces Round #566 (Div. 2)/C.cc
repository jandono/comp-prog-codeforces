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
unordered_map<int, unordered_map<char, vector<string>>> m;
unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

string x;

VS second;
unordered_map<int, vector<string>> first;

void read_input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        char last = 'z';
        int cnt = 0;
        for(int j=0;j<x.size();j++){
            if(vowels.count(x[j])){
                cnt++;
                last = x[j];
            }
        }

        m[cnt][last].push_back(x);
    }
}

void solve(){
    
    for(auto iter_im : m){

        for(auto iter_cvs : iter_im.second){
            int sz = iter_cvs.second.size();
            if(sz % 2){
                first[iter_im.first].push_back(iter_cvs.second.back());
                iter_cvs.second.pop_back();
                sz--;
            }

            for(auto s : iter_cvs.second){
                second.push_back(s);
            }
        }
    }

    if(second.size() < 2){
        cout << 0 << "\n";
        return;
    }

    int j = 0;
    int cnt = 0;
    stringstream ss;
    for(auto kv : first){
        
        for(int i=0;i+1<kv.second.size();i+=2, j+=2){
            
            if(j + 1 >= second.size()) break;
            cnt++;
            ss << kv.second[i] << " " << second[j] << "\n";
            ss << kv.second[i+1] << " " << second[j+1] << "\n";
        }
    }

    for(;j+3<second.size();j+=4){
        cnt++;
        ss << second[j] << " " << second[j+2] << "\n";
        ss << second[j+1] << " " << second[j+3] << "\n";
    }

    cout << cnt << "\n";
    cout << ss.str();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
