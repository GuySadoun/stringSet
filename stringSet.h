//
// Created by guy-pc on 6/7/19.
//

#ifndef CONFIGURE_STRINGSET_H
#define CONFIGURE_STRINGSET_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "linkedList.h"

using std::unordered_map;

using std::string;

using std::endl;

int Prime_num(int n);

class stringSet {

    unordered_map<int, linkedList<string>> set;

    unordered_map<char, int> char_to_prime_table;

public:
    stringSet() {  // constructor
        set = *new unordered_map<int, linkedList<string>>(); // set gets empty map string->list of anagrams
        char_to_prime_table = *new unordered_map<char, int>;  // initialize the char to prime table
        std::cout << "char to prime table:" << endl;
        for (int i = 0; i < 26; i++) {
            char_to_prime_table[(char) ('a' + i)] = Prime_num(i + 1);
            std::cout << (char) ('a' + i) << " = " << char_to_prime_table[(char) ('a' + i)] << endl;
        }
    }

    void insert(string string);

    linkedList<string>& anagrams(string string);

private:

    int getPrimesKey(string String);

};

linkedList<string>& stringSet::anagrams(string str) {

    if (set.find(getPrimesKey(str)) != set.end()) {
        return set[getPrimesKey(str)];
    } else {
        throw linkedList<string>::NotFound();
    }

}

void stringSet::insert(string str) {
    int prime_key = getPrimesKey(str);
    if ( set.find(prime_key) == set.end()) {
        set[prime_key] = *new linkedList<string>(str);
        return;
    }
    set[prime_key].insert(str);

}

int stringSet::getPrimesKey(string str) {
    int key = 1;
    for (char &c : str) {
        if (char_to_prime_table.find(c) == char_to_prime_table.end()) {
            std::cout << "string must contain only chars from [a..z]" << endl;
            return 0;
        } else {
            key = key * char_to_prime_table[c];
        }
    }
    return key;
}


/************************************helpers*********************************/

int Prime_num(int n) {
    assert( n > 0);
    int last_prime = 3, num = 3 , i, divided = 0, count = 1;

    if (n==1) return 2;

    while( count < n ) {
        for (i = 2; i < num; i++) {
            if (num % i == 0) {
                divided = 1;
                break;
            }
        }
        if(!divided && num!= 1) {
            count++;
            last_prime = num;
        }
        divided = 0 ;
        num++;
    }

    return last_prime;
}


#endif //CONFIGURE_STRINGSET_H
