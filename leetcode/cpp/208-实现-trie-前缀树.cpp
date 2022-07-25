/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

#include "include/headers.h"

// @lc code=start
class Trie {
 public:
  Trie() {
    this->children = vector<Trie*>(26, nullptr);
    this->end = false;
  }

  void insert(string word) {
    Trie* node = this;
    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';
      if (node->children[idx] == nullptr) node->children[idx] = new Trie;
      node = node->children[idx];
    }
    node->end = true;
  }

  bool search(string word) {
    Trie* node = this;
    for (int i = 0; i < word.size(); i++) {
      int idx = word[i] - 'a';
      if (node->children[idx] == nullptr) return false;
      node = node->children[idx];
    }
    return node->end;
  }

  bool startsWith(string prefix) {
    Trie* node = this;
    for (int i = 0; i < prefix.size(); i++) {
      int idx = prefix[i] - 'a';
      if (node->children[idx] == nullptr) return false;
      node = node->children[idx];
    }
    return true;
  }

 private:
  vector<Trie*> children;
  bool end;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
