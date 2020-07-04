#include <string>
#include <cstring>
#include <iostream>

using namespace std;

string validIPAddress(string IP) {
    string num = "";
    const string err = "Neither";
    string isfour = IP.find('.') != std::string::npos ? "IPv4" : "IPv6";

    if (isfour == "IPv4") {
        int cnt = 0;
        for (char ip : IP) {
            if (ip == '.') { // split
                if (num.size() > 3 || num.empty()) return err;
                num = "";
                ++cnt;
                continue;
            } else if ('0' <= ip && ip <= '9') { // number
                if (num == "0") // leader is not right
                    return err;
                // exceed 255
                if (num.empty() && ip > '2') return err;
                if (num == "2" && ip > '5') return err;
                if (num == "25" && ip > '5') return err;
                num += ip;
            } else return err; // illegal number
        }
        if (num.size() > 3 || num.empty() || cnt != 3) return err;
    } else {
        int cnt = 0;
        for (char ip : IP) {
            if (ip == ':') {
                if (num.size() > 4 || num.empty()) return err;
                num = "";
                ++cnt;
                continue;
            } else if (('a' <= ip && ip <= 'f') || ('A' <= ip && ip <= 'F') || ('0' <= ip && ip <= '9')) {
            } else return err;
        }
        if (num.size() > 4 || num.empty() || cnt != 7) return err;
    }
    return isfour;
}

//int main() {
//    cout << validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334");
//}