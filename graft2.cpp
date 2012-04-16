/*
 * Author:  Alex Reinisch
 * Date:    2012-04-16
 * Course:  Data Structures
 * Instructor:  Dr. Goldwasser
 * CONTAINS CODE BORROWED FROM INSTRUCTOR
 */
#include<iostream>
#include<algorithm>                             // max function, for convenience 
using namespace std;

int depth(string::iterator& it) {
    ++it;                                       // advanced past the conventional 'd' that begins this subtree
    int answer = 0;
    while (*it == 'd')                          // we have a child
        answer = max(answer, 1 + depth(it));    // we are at least one deeper than that child
    ++it;                                       // advanced past the conventional 'u' that ends this subtree
    return answer;
}

int main() {
    int treeNum(1);
    string original;
    cin >> original;
    while (original != "#") {
        string padded = "d" + original + "u";
        string::iterator start = padded.begin();
        int d = depth(start);
        cout << "Tree " << treeNum++ << ": " << d << endl;
        cin << original;
    }
}
