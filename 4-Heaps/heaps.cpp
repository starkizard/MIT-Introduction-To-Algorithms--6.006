// auth: starkizard
#include <bits/stdc++.h>
#include<unistd.h>
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

void max_heapify(vl &A,ll index){
    // Fixes one index
    ll left=index*2 +1;
    ll right=index*2 + 2;
    ll size=A.size();
    ll largest=index;
    if(left<size && A[left]>A[index]){
        largest=left;
    }
    if(right<size && A[right]>A[largest]){
        largest=right;
    }
    if(largest!=index){
        ll temp=A[index];
        A[index]=A[largest];
        A[largest]=temp;
        max_heapify(A,largest);
    }

}

void build_max_heap(vl &A){
    fm(i,(A.size()-2)/2,-1){
        max_heapify(A,i);
    }
}

ll extract_max(vl &A){
    ll max=A[0];
    A[0]=A[A.size()-1];
    A.pop_back();
    max_heapify(A,0);
    return max;

}

void max_heapify_bottomUp(vl &A,ll index){
    if(index==0){
        return;
    }
    ll parent=(index-1)/2;
    if(A[parent]<A[index]){
        ll temp=A[parent];
        A[parent]=A[index];
        A[index]=temp;
        max_heapify_bottomUp(A,parent);
    }
}

void insert(vl &A, ll value){
    A.push_back(value);
    max_heapify_bottomUp(A,A.size()-1);
}

void print_vector(vl &A){
    f(i,0,A.size()){
        cout << A[i] << " ";
    }
    cout << "\n";
}
void heap_sort(vl A){
    cout << "Heap sorting using a copy of the vector so that it isn't destroyed Descending order\n";
    ll size=A.size();
    while(size>0){
        cout << extract_max(A) << " ";
        size-=1;
    }
    cout << "\n";
}
int main()
{
    ll n; cin >> n;
    vl A(n);
    f(i,0,n){
        cin >> A[i];
    }
    cout << "Building Heap:";
    build_max_heap(A);
    print_vector(A);
    cout << "Extracting Max:";
    ll max=extract_max(A);
    cout << "Extracted Element : " << max << "\n";
    print_vector(A);
    cout << "insert any element: ";
    ll value; cin >> value;
    cout<< "Heap now: " ;
    insert(A,value);
    print_vector(A);
    heap_sort(A);
    return 0;
}