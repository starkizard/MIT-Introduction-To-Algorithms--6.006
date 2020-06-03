// auth: starkizard
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define f(i, a, b) for (long long i = a; i < b; i++)
#define rep(i, a, b) for (long long i = a; i <= b; i++)
#define fm(i, a, b) for (long long i = a; i > b; i--)
#define repm(i, a, b) for (long long i = a; i >= b; i--)
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define pqmaxi priority_queue<int>
#define pqmaxl priority_queue<ll>
#define pqmini priority_queue<int, vi, greater<int>>
#define pqminl priority_queue<ll, vl, greater<ll>>
#define all(x) x.begin(), x.end()
#define test     \
    ll test;     \
    cin >> test; \
    while (test--)
#define pb(i) push_back(i)
#define mp(i, j) make_pair(i, j)
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)


int main()
{
    fast;
    ll n,m; cin >> n >> m;
    vector< vector<ll> > vec(n,vector<ll>(m));
    f(i,0,n){
        f(j,0,m){
            cin >> vec[i][j];
        }
    }
    ll low=0,high=n-1,peaki,peakj,peakvalue;
    while(low<=high){
        ll mid= (low+high)/2;

        ll ind,maxv=-10e9; //coloumn max index and value
        f(i,0,n){
            if(vec[i][mid]>maxv){
                maxv=vec[i][mid];
                ind=i;
            }
        }

        // single column left to check (base case for recursion)
        if(low==high){
            peaki=ind;
            peakj=low;
            peakvalue=maxv;
            break;
        }
        if(vec[ind][mid-1]>maxv) high=mid-1;
        else if(vec[ind][mid+1]>maxv) low=mid+1;
        else{
            peaki=ind;
            peakj=low;
            peakvalue=maxv;
            break;
        }  
        
    }
    cout << "\n\n(" << peaki << "," << peakj << ") value:\t" << peakvalue << "\n";
    return 0;
}