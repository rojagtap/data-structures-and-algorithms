#include<bits/stdc++.h>

using namespace std;


/**
 * TODO: Add explanation
 */
vector<int> compile_pattern(const string& pattern) {
    // lps[i] is the length of the longest proper prefix which
    // is also a proper suffix of the substring pattern[0...i]
    vector<int> lps(pattern.size(), 0);

    // we can construct the lps array in linear time

    int prefix_iter = 0, iter = 1;
    while (iter < pattern.size()) {
        if (pattern[prefix_iter] == pattern[iter]) {
            lps[iter++] = ++prefix_iter;
        } else if (prefix_iter == 0) {
            ++iter;
        } else {
            prefix_iter = lps[prefix_iter - 1];
        }
    }

    return lps;
}


/**
 * TODO: Add explanation
 */
int find_first(const string& haystack, const string& needle) {
    vector<int> lps = compile_pattern(needle);

    int haystack_iter = 0, needle_iter = 0;
    while (needle_iter < needle.size() && haystack_iter < haystack.size()) {
        if (needle[needle_iter] == haystack[haystack_iter]) {
            ++needle_iter, ++haystack_iter;
        } else if (needle_iter == 0) {
            ++haystack_iter;
        } else {
            needle_iter = lps[needle_iter - 1];
        }
    }

    if (needle_iter == needle.size()) {
        return haystack_iter - needle.size();
    }

    return -1;
}


int main() {
    string haystack = "onionionskys";
    string needle = "onions";
    cout << find_first(haystack, needle);

    return 0;
}
