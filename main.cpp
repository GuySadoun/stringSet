#include <iostream>
#include <unordered_map>
#include <string>
#include "stringSet.h"
#include "stringSet2.h"
#include <algorithm>
#include <cstring>
#include <vector>

#define ever (;;)

void splitString(const string &str, std::vector<string> &output)
{
    string::size_type start = 0; // Where to start
    string::size_type last = str.find_first_of(" "); // Finds the first space

    // npos means that the find_first_of wasn't able to find what it was looking for
    // in this case it means it couldn't find another space so we are at the end of the
    // words in the string.
    while (last != string::npos)
    {
        // If last is greater then start we have a word ready
        if (last > start)
        {
            output.push_back(str.substr(start, last - start)); // Puts the word into a vector look into how the method substr() works
        }

        start = ++last; // Reset start to the first character of the next word
        last = str.find_first_of(" ", last); // This means find the first space and we start searching at the first character of the next word
    }

    // This will pickup the last word in the file since it won't be added to the vector inside our loop
    output.push_back(str.substr(start));
}

using std::cout;
using std::cin;
int main(int argc, char* argv[]) {

    stringSet *test = new stringSet();
    test->insert("arcb");
    test->insert("barc");
    test->insert("abrc");
    test->insert("arbc");
    test->insert("pandora");
    test->insert("andorap");
    try {
        std::cout << test->anagrams("a231");
    } catch (std::exception& e) {
        std::cout << e.what() << endl;
    }
    cout << "anagrams 'barc' : \n";
    try {
        std::cout << test->anagrams("barc") << endl;
    } catch (std::exception& e) {
        std::cout << e.what() << endl;
    }

    cout << "anagrams 'pandora' : \n";
    try {
        std::cout << test->anagrams("pandora") << endl;
    } catch (std::exception& e) {
        std::cout << e.what() << endl;
    }
    delete test;

    cout << "******************************************************************\n\n\n";
    auto* stringsSet = new stringSet();

    for ever {

        cout << "enter command\n";

        string line;

        getline(cin, line);

        if (line == "exit") break;

        std::vector<string> words;

        splitString(line, words);

        if (words[0] == "insert") {
            for (auto i = 1; i != words.size(); ++i) {
                stringsSet->insert(words[i]);
                cout << words[i] << " was inserted\n";
            }
        }
        else if ( words[0] == "anagram" ) {
            int words_num = words.size();
            if (words_num != 2) std::cout << "you can look for anagram only for one string\n";
            try {
                std::cout << stringsSet->anagrams(words[1]) << endl;
            } catch (std::exception& e) {
                std::cout << e.what() << endl;
            }
        }
        else {
            cout << "command not found, please use one of the following:\n";
            cout << "insert string1 string2...\n";
            cout << "anagram string\n";
            cout << "exit\n";
        }
    }
    delete stringsSet;

    cout << "******************************************************************\n\n\n";
    auto* stringsSet2 = new stringSet2();

    for ever {

        cout << "enter command\n";

        string line;

        getline(cin, line);

        if (line == "exit") break;

        std::vector<string> words;

        splitString(line, words);

        if (words[0] == "insert") {
            for (auto i = 1; i != words.size(); ++i) {
                stringsSet2->insert(words[i]);
                cout << words[i] << " was inserted 2\n";
            }
        }
        else if ( words[0] == "anagram" ) {
            int words_num = words.size();
            if (words_num != 2) std::cout << "you can look for anagram only for one string\n";
            try {
                std::cout << stringsSet2->anagrams(words[1]) << endl;
            } catch (std::exception& e) {
                std::cout << e.what() << endl;
            }
        }
        else {
            cout << "command not found, please use one of the following:\n";
            cout << "insert string1 string2...\n";
            cout << "anagram string\n";
            cout << "exit\n";
        }
    }
    delete stringsSet2;
    return 0;
}
