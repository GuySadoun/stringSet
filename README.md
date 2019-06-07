# stringSet
set of strings with 2 main function: void insert(string s) and anagrams(string s).

anagrams func - O(stringLen(s)) avarage.
insert func - O(stringLen(s)).

using char to primes number hashing for each string.

example:
int main() {
    stringSet test = *new stringSet();
    test.insert("arcb");
    test.insert("barc");
    test.insert("abrc");
    test.insert("arbc");
    test.insert("pandora");
    test.insert("andorap");
    try {
        std::cout << test.anagrams("a231"); // will print "string must contain only chars from [a..z]"
    } catch (std::exception& e) {
        std::cout << e.what() << endl; // Not Found!
    }
    try {
        std::cout << test.anagrams("barc") << endl;
        std::cout << test.anagrams("pandora") << endl;
    } catch (std::exception& e) {
        std::cout << e.what() << endl; // shuld not enter here
    }
    return 0;
}

output:

char to prime table:
a = 2
b = 3
c = 5
d = 7
e = 11
f = 13
g = 17
h = 19
i = 23
j = 29
k = 31
l = 37
m = 41
n = 43
o = 47
p = 53
q = 59
r = 61
s = 67
t = 71
u = 73
v = 79
w = 83
x = 89
y = 97
z = 101
string must contain only chars from [a..z]
Not Found!
head-> arbc -> abrc -> barc -> arcb -> NULL
head-> andorap -> pandora -> NULL



