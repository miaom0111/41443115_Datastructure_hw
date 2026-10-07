#include <iostream>
using namespace std;

char s[] = { 'a', 'b', 'c' };
const int n = 3;
bool ch[n];

void pset(int index) {
    
    if (index == n) {
        cout << "(";
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (ch[i]) { 
                if (!first) cout << ", ";
                cout << s[i];
                first = false;
            }
        }
        cout << ") ";
        return;
    }
    ch[index] = false;
    pset(index + 1);
    ch[index] = true;
    pset(index + 1);
}
int main() {
    cout << "pset(s) = {";
    pset(0);
    cout << "}" << endl;
    return 0;
}
