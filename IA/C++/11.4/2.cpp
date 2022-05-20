#include "iostream"
#include "vector"
#include "algorithm"

int main(){
    std::vector<double> nr;
    double x;
    while (std::cin >> x) nr.push_back(x);


    sort(nr.begin(), nr.end(),[](double a, double b) {
             return a < b;
        });

    for (auto el : nr) {
        std::cout << el << ";";
    }

    std::cout << "\n";

    sort(nr.begin(), nr.end(),[](double a, double b) {
        return a > b;
    });

    for (auto el : nr) {
        std::cout << el << ";";
    }

    std::cout << "\n";

    sort(nr.begin(), nr.end(),[](double a, double b) {
        return (int)a%10 < (int)b%10;
    });

    for (auto el : nr) {
        std::cout << el << ";";
    }

    std::cout << "\n";

    sort(nr.begin(), nr.end(),[](double a, double b) {
//        std::cout << a << " " << b << "\n";
        a-=(int)a;
        b-=(int)b;
//        std::cout << (int)(a*1000) << " " << (int)(b*1000) << "\n\n\n\n\n";
        return (int)(a*1000) <= (int)(b*1000);
    });

    for (auto el : nr) {
        std::cout << el << ";";
    }

    std::cout << "\n";

}
