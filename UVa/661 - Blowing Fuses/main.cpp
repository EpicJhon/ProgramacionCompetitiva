#include <iostream>
#include <sstream>
#include <vector>
#include <utility>

using namespace std;


/*
 * 661 - Blowing Fuses
 */

int main() {
    
    int n, m, c, tmp;
    int max = 0, sum = 0, sequence = 1;
    vector<pair<int, bool>> devices;
    
    while (cin >> n >> m >> c, n != 0) {
        
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            devices.push_back({tmp, false});
        }
        
        for (int i = 0; i < m; i++) {
            cin >> tmp;
            
            if (devices[tmp - 1].second) {
                devices[tmp - 1].second = false;
                sum -= devices[tmp - 1].first;
            } else {
                devices[tmp - 1].second = true;
                sum += devices[tmp - 1].first;
            }
            
            max = (sum > max) ? sum : max;
        }
        
        std::cout << "Sequence " << sequence << std::endl;
        
        if (max > c)
            std::cout << "Fuse was blown." << std::endl;
        else 
            std::cout << "Fuse was not blown." << std::endl << "Maximal power consumption was " << max << " amperes." << std::endl;
        
        std::cout << std::endl;
        
        sum = max = 0;
        devices.clear();
        sequence++;
    }
    
	return 0;
}
