//
// Created by guy-pc on 6/10/19.
//

#ifndef CONFIGURE_STRINGSET2_H
#define CONFIGURE_STRINGSET2_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "linkedList.h"
#include "Trie.h"

using std::string;

class stringSet2 {

    Trie<string> *trie;

public:

    stringSet2();

    ~stringSet2();

    void insert(string string);

    linkedList<string>& anagrams(string string);

};

#endif //CONFIGURE_STRINGSET2_H
