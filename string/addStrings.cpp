#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    int size1 = num1.size() - 1;
    int size2 = num2.size() - 1;
    string result = "";
    int more = 0;
    while (size1 >= 0 && size2 >= 0) {
        int n1 = num1[size1] - '0';
        int n2 = num2[size2] - '0';
        int n_temp = n1 + n2 + more;
        char n = n_temp % 10 + '0';
        result = n + result;
        more = n_temp / 10;
        --size1;
        --size2;
    }
    while (size1 >= 0) {
        int n1 = num1[size1] - '0';
        int n_temp = n1 + more;
        char n = n_temp % 10 + '0';
        result = n + result;
        more = n_temp / 10;
        --size1;
    }
    while (size2 >= 0) {
        int n2 = num2[size2] - '0';
        int n_temp = n2 + more;
        char n = n_temp % 10 + '0';
        result = n + result;
        more = n_temp / 10;
        --size2;
    }
    if (more > 0) {
        char n = more + '0';
        result = n + result;
    }

    return result;
}
