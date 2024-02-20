#include "function.h"
void Save(string name, int n, int luot, int tg) {
    vector<int> n1, n2, n4; vector<string> n3;
    int k = 0, MIN, MIN2;
    fstream output("kiluc.txt", ios::in);
    for (int i = 2; i < 10; i++) {
        int a = 0, b = 0, c = 0; string s;
        output >> a >> b >> c;
        getline(output, s);
        if (s[0] == ' ') s.erase(s.begin());
        n1.push_back(a); n2.push_back(b); n3.push_back(s); n4.push_back(c);
        if (i == n) {
            k = a; MIN = b; MIN2 = c;
        }
    }
    if (k == 0 || (MIN2>tg && MIN >= luot)) {
        n1[n - 2] = n; n2[n - 2] = luot; n3[n - 2] = name; n4[n - 2] = tg;
    }
    output.close();
    fstream kiluc("kiluc.txt", ios::out);
    for (int i = 2; i < 10; i++) {
        kiluc << n1[i - 2] << " " << n2[i - 2] << " " << n4[i - 2] << " " << n3[i - 2] << "\n";
    }
    kiluc.close();
}