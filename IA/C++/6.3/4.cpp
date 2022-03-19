#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int x;
    std::cin >> x;
    int a,b;

    std::vector<int> v,_a,_b;
    v.reserve(x);
    _a.reserve(x);
    _b.reserve(x);
    for (int i = 0; i < x; i++) {
        std::cin >> a >> b;
        v.push_back(a+b);
        _a.push_back(a);
        _b.push_back(b);
    }

    std::sort(v.begin(),v.end(),[](int a, int b){
        return a>b;
    });

    for (int i=0; i<3; i++) {
        for (int j=0; j<x; j++) {
            if (_a[j]+_b[j]==v[i])
            {
                std::cout << '(' << _a[j] << ',' << _b[j] << ")\n";
                break;
            }
        }
    }
} 
