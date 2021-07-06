#include<bits/stdc++.h>
using namespace std ;
 
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define ar array
#define endl '\n'
const int mod = 1e9+7 ;
const int Mxn = 2e5+2 ;
 
int n; 
unordered_map<int,vector<int>> edge ;
vector<ll> sz(Mxn), sm(Mxn), res(Mxn) ;
 
void caldp(int u,int p){
    sz[u] = 1 ; 
    sm[u] = 0 ; 
    for( int v : edge[u] ){
        if( p == v ) continue ; 
        caldp(v,u); 
        sz[u] += sz[v] ; 
        sm[u] += sm[v] ;
    }
    sm[u] += (sz[u]-1); 
    
}
 
void dfs(int u, int p){
    res[u] = sm[u] ; 
    for( int v : edge[u] ){
        if( v == p ) continue ; 
        sz[u] -= sz[v] ; 
        sm[u] -= (sz[v]+sm[v]) ; 
        sm[v] += sz[u]+sm[u] ; 
        sz[v] += sz[u] ; 
        dfs(v,u) ; 
        sz[v] -= sz[u] ; 
        sm[v] -= (sz[u]+sm[u]) ; 
        sm[u] += (sz[v]+sm[v]) ; 
        sz[u] += sz[v] ; 
    } 
}
 
void solve(){
    cin >> n ; 
    for( int i = 0 ; i < n-1 ; i++ ){
        int a,b ; cin >> a >> b ; 
        edge[a].pb(b) ;
        edge[b].pb(a) ;
    }
    caldp(1,0) ;
    dfs(1,0) ; 
    for( int i = 1 ; i <= n ; i++ ) cout << res[i] << " " ;  
    
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t = 1 ;
    
	//clock_t start , finish ;
	//start = clock() ;
	while(t--){
		solve() ;
	}
	//finish = clock() ;
	//cout << fixed << setprecision(3) << (float)(finish - start)/CLOCKS_PER_SEC ;
	
}