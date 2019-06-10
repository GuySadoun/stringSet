//
// Created by guy-pc on 6/10/19.
//

#ifndef CONFIGURE_TRIE_H
#define CONFIGURE_TRIE_H
#include <iostream>
#include "linkedList.h"

using namespace std;

const int alphabetSize = 26;

template <class T>
class Trie {
    struct TrieNode {
        struct TrieNode *children[alphabetSize];

        // end of a word
        bool leaf;

        linkedList<T> *extra_info;

        TrieNode() {
            leaf = false;

            for (auto & i : children)
                i = nullptr;

            extra_info = new linkedList<T>();
        }
    };

    TrieNode* root;

public:

    Trie() {
        root = new TrieNode();
    }

    class ERROR : public std::exception {
        virtual const char *what() const throw() {
            return "string must contain only chars from [a..z]";
        }
    };

    void insert(const string& key, T extra)  {
        auto dynamic_it = root;

        for (char i : key) {
            int index = i - 'a';

            if ( index > alphabetSize || index < 0 ) {
                throw ERROR();
            }
            if (!dynamic_it->children[index])
                dynamic_it->children[index] = new TrieNode();

            dynamic_it = dynamic_it->children[index];
        }

        // leaf => last node of word

        dynamic_it->extra_info->insert(extra);

        dynamic_it->leaf = true;
    }

    linkedList<T>* search(const string& key) {
        auto *dynamic_it = root;
        for (char i : key) {
            int index = i - 'a';

            if ( index > alphabetSize || index < 0 ) {
                throw ERROR();
            }
            if (!dynamic_it->children[index])
                return nullptr;

            dynamic_it = dynamic_it->children[index];
        }

        if (dynamic_it != nullptr && dynamic_it->leaf)
            return dynamic_it->extra_info;

        return nullptr;
    }
};

#endif //CONFIGURE_TRIE_H
