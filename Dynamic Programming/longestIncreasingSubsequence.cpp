#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define fastIO                  ios::sync_with_stdio(0);cin.tie(0);
#define fRead(x)                freopen(x,"r",stdin)
#define fWrite(x)               freopen(x,"w",stdout)
#define endl                    "\n"
#define pb                      push_back
#define mp                      make_pair
#define mt                      make_tuple
#define all(x)                  x.begin(),x.end()
#define rep(i,l,r)              for(ll i=l;i<r;i++)
#define min3(a,b,c)             min(a,min(b,c))
#define min4(a,b,c,d)           min(a,min(b,min(c,d)))
#define max3(a,b,c)             max(a,max(b,c))
#define max4(a,b,c,d)           max(a,max(b,max(c,d)))
#define print(v)                for(auto x:v) cout<<x<<" ";cout<<endl;
#define ff                      first
#define ss                      second
#define PQ                      priority_queue
typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef vector<ll>              vll;
typedef vector<vll>             vvll;
typedef vector<string>          vs;
typedef pair<int,int>           pii;
typedef pair<ll,ll>             pll;
//typedef tuple<int,int,int>      tiii;
//typedef tuple<ll,ll,ll>         tlll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


const ll mod=1e9+7;
const ll inf=1e18;
vll a,dp;

ll LIS(ll n) // O(nlogn)
{
    vll temp; // this vector is not the LIS vector, but its size will give the length of LIS
    temp.pb(a[0]);
    for(int i=1;i<n;i++)
    {
        ll x=lower_bound(all(temp),a[i])-temp.begin();
        if(x<temp.size()) temp[x]=a[i];
        else temp.pb(a[i]);
    }
    return temp.size();
}

void solve()
{
    ll n; cin>>n;
    a.resize(n+2);
    //dp.resize(n+2,1);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<LIS(n)<<endl;
}


int main()
{
    #ifndef ONLINE_JUDGE
    //fRead("input.txt");
    //fWrite("output.txt");
    #endif
    
    fastIO;
    int t=1; //cin>>t;
    for(int i=1;i<=t;i++)
    {
        //printf("Case %d: ", i);
        solve();
    }
}


/*
ll LIS(ll n) // bottom up, O(n^2)
{
    ll ans=-inf;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<k;i++)
        {
            if(a[i]<a[k]) dp[k]=max(dp[k],dp[i]+1);
        }
        ans=max(ans,dp[k]);
    }
    return ans;
}
*/


/*
int lis(int i,int prev) // top down, O(n^2)
{
    if(i==N) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int no=lis(i+1,prev);
    int yes=0;
    if(prev==-1 || v[i]>v[prev]) yes=1+lis(i+1,i);
    return dp[i][prev+1]=max(no,yes);
}
*/
