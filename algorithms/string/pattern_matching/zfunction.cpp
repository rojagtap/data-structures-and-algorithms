#include<bits/stdc++.h>

using namespace std;


/**
 * TODO: Add explanation
 */
vector<int> build_z_function(const string& text) {
    vector<int> z(text.size(), 0);

    int l = 0, r = 0;
    for (int i = 1; i < text.size(); ++i) {
        if (i > r) {
            l = r = i;
            while (r < text.size() && text[r - l] == text[r]) {
                ++r;
            }
            --r;

            z[i] = r - l + 1;
        } else {
            int k = i - l;

            if (z[k] < r - i + 1) {
                z[i] = z[k];
            } else {
                l = r = i;
                while (r < text.size() && text[r - l] == text[r]) {
                    ++r;
                }
                --r;

                z[i] = r - l + 1;
            }
        }
    }

    return z;
}

vector<int> find_all(const string& haystack, const string& needle) {
    const string text = needle + '$' + haystack;
    vector<int> z = build_z_function(text);

    int needle_size = needle.size();

    vector<int> positions;
    for (int prefix = 0; prefix < text.size(); ++prefix) {
        if (z[prefix + needle_size + 1] == needle_size) {
            positions.push_back(prefix);
        }
    }

    return positions;
}

int main() {
    string haystack = "onionionskys";
    string needle = "onion";
    vector<int> positions = find_all(haystack, needle);

    for (auto& position : positions) {
        cout << position << " ";
    }

    return 0;
}
