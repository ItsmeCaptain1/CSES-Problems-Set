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
 
int n ; 
unordered_map<int,vector<int>> edge ;
 
int dp1[Mxn], dp2[Mxn] ; 
 
// dp2 -> we do not include the node -> sum of max(dp1[v],dp2[v]) 
// dp1 -> we include the node -> - - - - dp2[v] - - - 
 
void dfs( int u, int p){
    vector<pair<int,int>> mx ; 
    for( int v : edge[u] ){
        if( v == p ) continue ; 
        dfs(v,u) ; 
        int x = max(dp1[v],dp2[v]) ; 
        dp2[u] += x ; 
        mx.pb({x,v}) ;
 
    }
 
    vector<int> suf(mx.size()+1), pre(mx.size()+1) ; 
    for( int i = 0 ; i < (int)mx.size() ; i++ ){
        if( i == 0 ){
            pre[i] = mx[i].ff ; 
        }else{
            pre[i] = pre[i-1] + mx[i].ff ; 
        }
    }
    for( int i = (int)mx.size()-1 ; i >= 0 ; i-- ){
        if( i == (int)mx.size()-1){
            suf[i] = mx[i].ff ; 
        }else{
            suf[i] = suf[i+1] + mx[i].ff ; 
        }
    }
    
    for( int i = 0 ; i < (int)mx.size() ; i++){
        if( i == 0 ){
            dp1[u] = dp2[mx[i].ss] + suf[i+1] + 1 ;
        }else if( i == mx.size()-1 ){
            dp1[u] = max(dp1[u], dp2[mx[i].ss] + pre[i-1] + 1) ;
        }else{
            dp1[u] = max(dp1[u], dp2[mx[i].ss] + pre[i-1] + suf[i+1] + 1 ) ;
        }
    }
 
}
 
void solve(){ 
    cin >> n ; 
    for( int i = 0 ; i < n-1 ; i++ ){
        int a, b ; cin >> a >> b ; 
        edge[a].pb(b) ; 
        edge[b].pb(a) ;
    }
    dfs(1,0) ;
    cout << max(dp1[1], dp2[1] ) ;
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