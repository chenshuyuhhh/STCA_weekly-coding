#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    if (s.size() == 0) return 0;
    int size = 0;
    int i;
    for (i = s.size() - 1; i >= 0; --i) {
        //cout<<i<< " ";
        if (s[i] == ' ') s = s.substr(0, i);
        else break;
    }
    for (; i >= 0; --i) {
        if (s[i] == ' ') return size;
        else ++size;
    }
    return size;
}