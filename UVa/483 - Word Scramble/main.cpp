#include <iostream>
#include <sstream>
#include <stack>

using namespace std;


/*
 * 483 - Word Scramble
 */

int main() {
    
    stack<string> stk;
    string text, word;
    
    while(getline(cin, text)) {
        
        if (text.empty()) {
            cout << endl;
            continue;
        }
        
        string rev = string(text.rbegin(), text.rend());
        
        stringstream ss(rev);
        
        while (ss >> word)
            stk.push(word);
        
        while (!stk.empty())
        {
            cout << stk.top() << ((stk.size() > 1) ? " " : "");
            stk.pop();
        }
        
        cout << endl;
    }

	return 0;
}
