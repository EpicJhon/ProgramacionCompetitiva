#include <iostream>
using namespace std;


/*
 * 10812 - Beat the Spread!
 */

int main() {

    int tests;
    unsigned long long a, b, s, d;
    
    cin >> tests;
    
    
    for (int i = 0; i < tests; i++) {
        
        cin >> s >> d;
        
        if  (d > s || (s+d) % 2 != 0 || (s-d) % 2 != 0)
            goto END;
        
        std::cout << ((s+d)/2) << " " << ((s-d)/2) << std::endl;
        
        continue;
END:
        std::cout << "impossible" << std::endl;

    }

	return 0;
}
