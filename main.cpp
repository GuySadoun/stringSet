#include <iostream>
#include <unordered_map>
#include <string>
#include "stringSet.h"

int main() {
    stringSet test = *new stringSet();
    test.insert("arcb");
    test.insert("barc");
    test.insert("abrc");
    test.insert("arbc");
    test.insert("pandora");
    test.insert("andorap");
    try {
        std::cout << test.anagrams("a231");
    } catch (std::exception& e) {
        std::cout << e.what() << endl;
    }
    try {
        std::cout << test.anagrams("barc") << endl;
        std::cout << test.anagrams("pandora") << endl;
    } catch (std::exception& e) {
        std::cout << e.what() << endl;
    }
    return 0;
}