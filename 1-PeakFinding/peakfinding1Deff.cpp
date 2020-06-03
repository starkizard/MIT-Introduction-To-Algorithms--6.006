// auth: starkizard
include <bits/stdc++.h>
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
    //input n
    ll n; cin >> n;
    vl v(n);
    // input n integers
    f(i,0,n){
        cin >> v[i];
    }
    ll low=0,high=n-1;
    ll peak,peakvalue;
    // check that low should stay less than or equal to high, when it's equal, means we're checking for a single element, if we reach this stage anytime, we know it's a peak
    // proven in class
    while(low<=high){
        ll mid=(low+high)/2;
        if(low==high){
            peak=mid;
            peakvalue=v[mid];
            break;
        }
        if(v[mid]<v[mid-1]) high=mid-1;
        else if(v[mid]<v[mid+1]) low=mid+1;
        else{
            peak=mid;
            peakvalue=v[mid];
            break;
        }
    }
    cout << peakvalue << " , " << peak << "\n";
    return 0;
}