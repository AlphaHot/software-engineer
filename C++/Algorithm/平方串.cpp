
/*

���һ���ַ�������ȫ��ͬ�������ַ�����ɣ����ǳ���Ϊƽ���������硰aa��,"abab", ��
��һ���ַ����������ִ���ƽ�����ĸ���

*/
#include<bits/stdc++.h>
//#define pb push_back
//#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
//#define dbg(x) cout << #x << " at line " << __LINE__ << " is: " << x << endl
//typedef long long ll;
using namespace std;
//typedef pair<int, int> pii;
//const int maxn = 1e3 + 10;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    unordered_set<string> se;
    for (int i = 0; i < n; i++) {
        for (int j = 2; i + j - 1 < n; j += 2) {
            int left = i, right = i + j / 2, len = j / 2;
            bool f = 1;
            for (int k = 0; k < len; k++) {
                if(s[left + k] != s[right + k]) {
                    f = 0;
                    break;
                }
            }
            if(f) {
                se.insert(s.substr(i, j));
            }
        }
    }
    cout << se.size() << endl;
}
int main() {
    solve();
    return 0;
}
