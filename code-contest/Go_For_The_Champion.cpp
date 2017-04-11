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

int res1, res2;
vector<pair<pair<int, int>, pair<int, string> > > v;
string s[5], op;
vector<string> teams;
map<string, int> scores, goals, _count, diff;


void updateTeam(string s){
    if (find(teams.begin(), teams.end(), s) == teams.end()){
        teams.pb(s);
    }
}

void init() {
    int x, y;
    FOR(i,1,5){
        FOR(j,1,3) cin >> s[j];
        updateTeam(s[1]);
        updateTeam(s[2]);
        //FOR(k,0,teams.size()-1) cout << teams[k] << " "; cout << endl;
        x = s[3][0] - '0';
        y = s[3][2] - '0';
        if (x == y) {
            scores[s[1]]++;
            scores[s[2]]++;
        }
        else if (x > y) {
            scores[s[1]] += 3;
        }
        else {
            scores[s[2]] += 3;
        }
        diff[s[1]] += x - y;
        diff[s[2]] += y - x;
        goals[s[1]] += x;
        goals[s[2]] += y;
        _count[s[1]]++;
        _count[s[2]]++;
    }
}

bool cmp(pair<pair<int, int>, pair<int, string> > a, pair<pair<int, int>, pair<int, string> > b){
    if (a.st.st != b.st.st) return a.st.st > b.st.st;
    else if (a.st.nd != b.st.nd) return a.st.nd > b.st.nd;
    else if (a.nd.st != b.nd.st) return a.nd.st > b.nd.st;
    else return a.nd.nd < b.nd.nd;
}

bool solve(int x, int y) {
    v.clear();
    FOR(i,0,3)
        if (_count[teams[i]] == 3) v.pb(mp(mp(scores[teams[i]], diff[teams[i]]), mp(goals[teams[i]], teams[i])));
    v.pb(mp(mp(scores["VIETNAM"], diff["VIETNAM"] + x - y), mp(goals["VIETNAM"] + x, "VIETNAM")));
    v.pb(mp(mp(scores[op], diff[op] + y - x), mp(goals[op] + y, op)));
    sort(v.begin(), v.end(), cmp);
    //FOR(i,0,3) cout << v[i].st << " " << v[i].nd.st << " " << v[i].nd.nd << endl;
    if (v[0].nd.nd == "VIETNAM" || v[1].nd.nd == "VIETNAM") return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    FOR(i,0,3)
        if (_count[teams[i]] == 2 && teams[i] != "VIETNAM") op = teams[i];
    //cout << op << endl;
    scores["VIETNAM"] += 3;
    res1 = 100;
    res2 = 0;
    FOR(j,0,50)
    FOR(i,j+1,50)
        if ((i - j < res1 - res2) && solve(i, j)) {
            res1 = i;
            res2 = j;
        }
    if (res1 == 100) cout << "IMPOSSIBLE";
    else cout << res1 << ":" << res2;
    return 0;
}
