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

void read_input(){

}

void solve(){
    unordered_map<int, PII> prod_to_nums;

    VI nums = {4, 8, 15, 16, 23, 42};
    for(int i=0;i<6;i++){
        for(int j=i;j<6;j++){
            prod_to_nums[nums[i] * nums[j]] = {nums[i], nums[j]};
        }
    }

    VI sol(6);
    int prod;
    for(int t=0;t<2;t++){
        cout << "? " << t+1 << " " << t+1 << "\n";
        cout << flush;
        cin >> prod;
        sol[t] = prod_to_nums[prod].first;
    }

    prod_to_nums[64] = {4, 16};
    
    cout << "? 3 4\n";
    cout << flush;
    cin >> prod;
    sol[2] = prod_to_nums[prod].first;
    sol[3] = prod_to_nums[prod].second;

    cout << "? 4 5\n";
    cout << flush;
    cin >> prod;
    int tmp3 = prod_to_nums[prod].first;
    sol[4] = prod_to_nums[prod].second;
    if(sol[3] != tmp3){
        if(sol[2] == sol[4]){
            swap(sol[2], sol[3]);
            swap(tmp3, sol[4]);
        }else
        if(sol[3] == sol[4]){
            swap(tmp3, sol[4]);
        }else
        if(sol[2] == tmp3){
            swap(sol[2], sol[3]);
        }
    }

    unordered_set<int> s;
    for(int i=0;i<5;i++){
        s.insert(sol[i]);
    }

    for(int i=0;i<6;i++){
        if(!s.count(nums[i])){
            sol[5] = nums[i];
            break;
        }
    }

    cout << "!";
    for(auto el : sol){
        cout << " " << el;
    }
    cout << "\n";
    cout << flush;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
