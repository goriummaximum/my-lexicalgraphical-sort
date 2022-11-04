#include <bits/stdc++.h>

using namespace std;

/**
 * @brief radix sort (each character) + bucket sort (by 26 Latin characters)
 * time: O(nk^2), space: O(nk^2)
 * n: number of strings
 * k: number of char in each string
 * 
 * @param arr 
 * @param k 
 */
void lex_sort(vector<string> &arr, int k) {
    //base case
    if (arr.size() == 0) return;

    //bucket sort with radix i
    array<vector<string>, 27> buckets;
    for (int i = 0; i < arr.size(); i++) {
        if (k >= arr[i].size()) buckets[0].push_back(arr[i]); //similar prefix and size
        else buckets[arr[i][k] - 'a' + 1].push_back(arr[i]);
    }
    
    //lex sort each bucket (except i = 0 because of exceeded size)
    for (int i = 1; i < 27; i++) {
        lex_sort(buckets[i], k + 1);
    }

    //modify original arr with the sorted strings
    int q = 0;
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[q++] = buckets[i][j];
        }
    }
}

int main() {
    vector<string> arr = {"b", "a", "aa", "abc", "c", "b", "b", "cab", "cba", "a", "cad", "abcd"};
    //lex_sort(arr, 0);
    //sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}