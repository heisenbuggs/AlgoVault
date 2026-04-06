/*
* Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths.
* Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
* Keep the following conditions in mind:

* A word can only consist of lowercase characters.
* Only one letter can be changed in each transformation.
* Each transformed word must exist in the wordList including the targetWord.
* startWord may or may not be part of the wordList.
* Return an empty list if there is no such transformation sequence.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;

    void dfs(string word, vector<string> &seq) {
        if(word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word];
        int sz = word.size();
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch; 
                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push({beginWord});
        mpp[beginWord] = 1;
        int sz = beginWord.size();
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if(word == endWord) break;

            for (int i = 0; i < sz; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};