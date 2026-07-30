#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool searchHelper(string& word, int index, TrieNode* node) {
        if (index == word.length()) {
            return node->isEndOfWord;
        }

        char c = word[index];

        if (c != '.') {
            int childIndex = c - 'a';

            if (node->children[childIndex] == nullptr) {
                return false;
            }

            return searchHelper(
                word,
                index + 1,
                node->children[childIndex]
            );
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                if (searchHelper(
                        word,
                        index + 1,
                        node->children[i]
                    )) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEndOfWord = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};