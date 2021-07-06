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
 
int dx[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
 
const int Mxn = 2e5+1 ;
const int LOG = 18 ;
int n, q ;
vector<vector<int>> up(Mxn,vector<int>(LOG)) ;
vector<int> level(Mxn) ;
vector<int> edge[Mxn] ;
 
void dfs( int u = 1, int p = 0, int depth = 0 ){
    if( p == 0 ) up[u][0] = 1 ;
    else up[u][0] = p ; 
	level[u] = depth ;
	for( int v : edge[u] ){
		if( v != p ){
			dfs(v,u,depth+1) ;
		}
	}
}
 
void binaryLifting(){
	for( int i = 1 ; i < LOG ; i++){
		for( int j = 1 ; j <= n ; j++ ){
			up[j][i] = up[up[j][i-1]][i-1] ;
		}
	}
}
 
int getKthAncestor(int node, int k) {
	if( level[node] < k )
		return -1 ;
	for( int i = LOG ; i >= 0 ; i-- ){
		int x = (1ll<<i) ; 
		if( x&k ){
			node = up[node][i] ; 
		}
	}
	return node ;
}
 
int LCA( int x, int y ){
	if( level[x] > level[y] ) swap(x,y) ;
	y = getKthAncestor(y,level[y]-level[x]) ; 
    if( x == y ){
		return x ; 
	}
	for( int i = LOG-1 ; i >= 0 ; i-- ){
		if( up[x][i] != up[y][i] ){
			x = up[x][i] ; 
			y = up[y][i] ;
		}	
	}
	return up[x][0] ;
}
 
void solve(){
    cin >> n >> q ; 
    for( int i = 2 ; i <= n ; i++ ){
        int a; scanf("%d",&a) ;
        edge[a].pb(i) ; 
        edge[i].pb(a) ; 
    }
    dfs() ;
    binaryLifting() ;
    while(q--){
        int a, b ; scanf("%d%d",&a,&b) ; 
        int x = LCA(a,b) ; 
        cout << x << endl ;
    }
}
 
 
int main(){
	int t = 1 ;
 
	//clock_t start , finish ;
	//start = clock() ;
	while(t--){
		solve() ;
	}
	//finish = clock() ;
	//cout << fixed << setprecision(3) << (float)(finish - start)/CLOCKS_PER_SEC ;
	
}
 