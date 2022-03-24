#include <iostream>
#include <cmath>
#include <cstring>

#define MAX_SIZE 256

char* toLower(char* s) {
    for (char* p = s; *p; p++)
		*p = tolower(*p);
    return s;
}

int main()
{
    char substr[MAX_SIZE], input[MAX_SIZE];
    int n;
    std::cin >> substr >> n;
    std::cin.get();

    for (int i = 0; i != n; i++) {
        std::cin.getline(input, MAX_SIZE);
        int count = 0;
        char* p = (char*)alloca(MAX_SIZE*sizeof(char));

        for (strcpy(p, input); p; p = strstr(toLower(p) + strlen(substr), toLower(substr)))
            count++;
        if (count > 1) std::cout << input << std::endl;
    }
}