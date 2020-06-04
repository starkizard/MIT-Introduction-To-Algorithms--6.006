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

pair<unordered_map<string,ll>,int> mapping(const char* s){
    ifstream fin;
    fin.open(s);
    ll count=0;
    unordered_map <string,ll> m;
    string x;
    while(getline(fin,x)){
        string word="";
        for(auto i:x){
            if((i>='a' && i<='z') || (i>='A' && i<='Z')){
                word+=i;
            }
            else{
                if(word==""){
                    continue;
                }
                if(m.find(word)==m.end()){
                    m[word]=1;
                }
                else{
                    m[word]+=1;
                }
                count++;
                word="";
            }
        }
    }
    fin.close();
    return {m,count};
}

void printmap(unordered_map<string,ll> m){
    cout << "\n\nMap: \n";
    for(auto i:m){
        cout << i.first << " , " << i.second << "\n";
    }

}

ll inner_product(unordered_map<string,ll> m1, unordered_map<string,ll> m2){
    ll sum=0;
    for(auto i:m1){
        if( m2.find(i.first) != m2.end() ) {
            sum+=m2[i.first]*i.second;
        }
    }
    return sum;
}

double vector_angle(unordered_map<string,ll> d1,unordered_map<string,ll> d2, ll s1,ll s2){
    ll numerator=inner_product(d1,d2);
    double denominator=sqrt( inner_product(d1,d1) * inner_product(d2,d2) );
    cout << "numerator is: " << numerator << " and the denominator is " << denominator << "\n";
    return acos(double(numerator/denominator));
}

int main()
{
    fast;
    pair<unordered_map<string,ll>,ll> d1,d2;
    d1=mapping("Document1.txt");
    d2=mapping("Document2.txt");
    printmap(d1.first);
    printmap(d2.first);
    cout << "\n\nDistance between the two files in radians is: ";
    cout << vector_angle(d1.first,d2.first,d1.second,d2.second) << '\n';
    return 0;
}