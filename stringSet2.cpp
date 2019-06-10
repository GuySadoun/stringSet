//
// Created by guy-pc on 6/10/19.
//


#include "stringSet2.h"
#include "linkedList.h"
#include "Trie.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <algorithm>

stringSet2::stringSet2() {
    trie = new Trie<string>();
}

stringSet2::~stringSet2() {
    delete trie;
}

void stringSet2::insert(string str) {
    string str1 = str;
    sort(str1.begin(), str1.end());
    trie->insert(str1, str);
}

linkedList<string>& stringSet2::anagrams(string str) {
    sort(str.begin(), str.end());
    return *trie->search(str);
}
