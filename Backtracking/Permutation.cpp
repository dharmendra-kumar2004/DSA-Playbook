#include <bits/stdc++.h>
using namespace std;

// Generate all unique permutations of the string
void permutation(string &str, int i) {
    if (i == str.size() - 1) {
        cout << str << '\n';
        return;
    }

    unordered_set<char> used;

    for (int idx = i; idx < str.size(); idx++) {
        if (used.count(str[idx])) continue; // Skip duplicate characters

        used.insert(str[idx]);
        swap(str[i], str[idx]);

        permutation(str, i + 1);

        swap(str[i], str[idx]); // Backtrack
    }
}

int main() {
    string str;
    cout << "Enter a string : ";
    cin >> str;   // Input: string
    cout << endl;
    cout << "Unique permutations of the string are -->\n";
    permutation(str, 0);

    return 0;
}