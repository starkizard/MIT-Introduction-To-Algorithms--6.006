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
    ll curri=0,currj=0;
    ll moves=0;
    ll peaki,peakj,peakvalue;
    while(moves<n*m){
        if(curri>0){
            if(vec[curri-1][currj] > vec[curri][currj]){
                curri--;
                cout << "Move:"  << moves+1 << " up to"  <<  curri << " " << currj << "\n"; 
                moves++;
                continue;
            }
        }
        if(curri<n-1){
            if(vec[curri+1][currj] > vec[curri][currj]){
                curri++;
                cout << "Move:"  << moves+1 <<  " down to " << curri << " " << currj << "\n"; 
                moves++;
                continue;
            }
        }
        if(currj>0){
            if(vec[curri][currj-1] > vec[curri][currj]){
                currj--;
                cout <<  "Move:"  <<moves +1<<  " left  to" << curri << " " << currj << "\n"; 
                moves++;
                continue;
            }
        }
        if(currj<n-1){
            if(vec[curri][currj+1] > vec[curri][currj]){
                currj++;
                cout <<  "Move:"  <<moves +1<<  " right to " << curri << " " << currj << "\n"; 
                moves++;
                continue;
            }
        }
        peaki=curri;
        peakj=currj;
        peakvalue=vec[curri][currj];
        break;
    }
    cout << "\n\n(" << peaki << "," << peakj << ") value:\t" << peakvalue << "\n";
    return 0;
}
