#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string line;
    vector<string> lines;
    while (getline(cin, line)) {
        if (line[1] == '1') {
            break;
        }
        lines.push_back(line);
    }

    int num = (line.size()+1)/4;
    vector<stack<char> > crates;
    crates.resize(num);

    for (int i = lines.size()-1; i >= 0; i--) {
        for (int crate = 0; crate < num; crate++) {
            int x = 4*crate + 1;
            if (lines[i][x] != ' ') {
                crates[crate].push(lines[i][x]);
            }
        }
    }
    getline(cin, line);

    int n, from, to;
    vector<char> moves;
    while (scanf("move %d from %d to %d\n", &n, &from, &to) != EOF) {
        moves.resize(0);
        for (int i = 0; i < n; i++) {
            moves.push_back(crates[from-1].top());
            crates[from-1].pop();
            
        }
        for (int i = n-1; i >= 0; i--) {
            crates[to-1].push(moves[i]);
        }
    }

    string result;
    for (int i = 0; i < num; i++) {
        result.push_back(crates[i].top());
    }
    printf("%s\n", result.c_str());
}