// Author: Nguyen Duy Khanh
#include<bits/stdc++.h>
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define DEBUG(x) { printf << #x << " = " << x << endl; }
#define DEBUGARR(a,n) {cout << #a << " = " ; FOR(_,1,n) cout << a[_] << ' '; cout <<endl;}
#define CHECK printf("OK\n");
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define Nmax 35000
using namespace std;

int n;
long long m, k, res, mul, a[200200], l[200200], r[200200];

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) l[i] = l[i-1] | a[i];
    DOW(i,n,1) r[i] = r[i+1] | a[i];
    res = 0;
    mul = 1;
    FOR(i,1,m) mul *= k;
    FOR(i,1,n) res = max(res, l[i-1] | r[i+1] | (a[i] * mul));
    cout << res;
    return 0;
}
