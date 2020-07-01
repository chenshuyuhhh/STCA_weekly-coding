#include <vector>
#include <iostream>
#include <set>

using namespace std;


string addStrs(string s1, string s2) {
    int size1 = s1.size() - 1;
    int size2 = s2.size() - 1;
    string result = "";
    int more = 0;
    while (size1 >= 0 && size2 >= 0) {
        int n1 = s1[size1] - '0';
        int n2 = s2[size2] - '0';
        int n_temp = n1 + n2 + more;
        char n = n_temp % 10 + '0';
        result = n + result;
        more = n_temp / 10;
        --size1;
        --size2;
    }
    while (size1 >= 0) {
        int n1 = s1[size1] - '0';
        int n_temp = n1 + more;
        char n = n_temp % 10 + '0';
        result = n + result;
        more = n_temp / 10;
        --size1;
    }
    while (size2 >= 0) {
        int n2 = s2[size2] - '0';
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

vector<int> splitIntoFibonacci(string S) {
    if (S.size() < 3) return {};

    int size = S.size();

    string num1 = ""; // first number

    for (int i = 0; i * 2 + 3 <= size; ++i) {
        char digit1 = S[i];
        if (num1 == "0" && i > 0) break;
        num1 = num1 + digit1; // 第一次相加，由于前面的判断，不存在首字符为0的情况

        string num2 = "";  // second number
        for (int j = i + 1; j * 2 - i < size; ++j) {
            char digit2 = S[j];

            if (num2 == "0" && j > i + 1) break; // 不满足leader条件

            num2 = num2 + digit2;
            int k = j + 1;

            string num1_temp = num1;
            string num2_temp = num2;
            vector<int> result;
            if(num1_temp.size()>32 || stol(num1_temp)>INT32_MAX) break;
            if(num2_temp.size()>32 || stol(num2_temp)>INT32_MAX) break;
            result.push_back(stoi(num1_temp));
            result.push_back(stoi(num2_temp));
            while (k < size) {
                string num3 = addStrs(num1_temp, num2_temp); // 第三个数应当为num3
                if(num3.size()>32 || stol(num3)>INT32_MAX) break;

                // 检验是否满足加法条件
                if (k + num3.size() > size) break; // 首先第三个数长度要够
                int cnt = 0;
                for (char c:num3) { // 每个数位得一样
                    if (S[k] != c) break;
                    ++k;
                    ++cnt;
                }

                if (cnt < num3.size()) break; // 不满足 add 条件

                result.push_back(stoi(num3));
                num1_temp = num2_temp;
                num2_temp = num3;
            }
            if (k == size) return result;
        }
    }
    return {};
}

void printIntVec(vector<int> v) {
    for (int n:v) cout << n << endl;
}

//int main() {
//    printIntVec(splitIntoFibonacci("214748364721474836422147483641"));
//}