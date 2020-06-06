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

void merge(vl &arr,ll l, ll m , ll r){
    vl L,R;
    f(i,l,r+1){
        if(i<m+1){
            L.pb(arr[i]);
        }
        else{
            R.pb(arr[i]);
        }
    }
    ll k=l,i=0,j=0;
    while(i<L.size() and j<R.size()){
        if(L[i]<R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<L.size()){
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<R.size()){
        arr[k]=R[j];
        k++;
        j++;
    }
}

void mergeSort(vl &arr,ll l, ll r){
    if(l<r){
    ll m=(l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
    }
}

int main()
{
    fast;
    ll n; cin >> n;
    vl vec(n);
    f(i,0,n){
        cin >> vec[i];
    }
    mergeSort(vec,0,n-1);
    f(i,0,n) cout << vec[i] << " ";
    cout << "\n";
    return 0;
}