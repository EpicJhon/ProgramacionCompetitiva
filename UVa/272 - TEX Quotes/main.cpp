#include <iostream>
using namespace std;


/*
 * 272 - TEX Quotes
 */

int main() {
    
    string text;
    bool flag = true;
    long pos = 0;
    
    while(getline(cin, text), !text.empty()) {
        
        while(true) {
            pos = text.find('"', pos);
            
            if(pos == string::npos) {
                pos = 0;
                break;
            }
            
            text.replace(pos, 1, 2, flag ? '`' : '\'');
            
            flag = !flag;
        }
        
        cout << text << endl;
        text = "";
    }

	return 0;
}
