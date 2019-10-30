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

int GCD(int a, int b){
    
    if(!a) return b;
    return GCD(b % a, a);
}

class Dropka{
public:
    int nom;
    int den;
    
    Dropka(int nom, int den){
        this->nom = nom;
        this->den = den;
    }

    void norm(){
        int gcd = GCD(this->nom, this->den);
        this->nom /= gcd;
        this->den /= gcd;
    }
};


Dropka add(const Dropka &x, const Dropka &y){
    
    int den = x.den * y.den;
    int nom = x.nom * y.den + y.nom * x.den;
    Dropka r(nom, den);
    r.norm();
    return r;
}

Dropka sub(const Dropka &x, const Dropka &y){
    
    int den = x.den * y.den;
    int nom = x.nom * y.den - y.nom * x.den;
    Dropka r(nom, den);
    r.norm();
    return r;
}

Dropka div(const Dropka &x, const Dropka &y){
    int den = x.den * y.nom;
    int nom = x.nom * y.den;
    Dropka r(nom, den);
    r.norm();
    return r;
}

int n, m, x;
VI l;
vector<Dropka> w;

void read_input(){
    cin >> n >> m;
    l.resize(n);
    for(int i=0;i<n;i++) cin >> l[i];
    for(int i=0;i<n;i++){
        cin >> x;
        w.push_back(Dropka(x, 1));
    }
}

void solve(){
    // debug(l);
    for(int i=0;i<m;i++){
        
        Dropka nc = w[0];
        for(int i=1;i<n;i++){
            nc = add(nc, w[i]);
        }

        for(int i=0;i<n;i++){
            Dropka update = div(w[i], nc);
            w[i] = (l[i]) ? add(w[i], update) : sub(w[i], update);
        }
    }

    for(auto el : w){
        // el.norm();
        cout << el.nom  << " / " << el.den << "\n";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read_input();
    solve();
    return 0;
}
