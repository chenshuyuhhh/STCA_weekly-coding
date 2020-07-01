#include <vector>
#include <iostream>
#include <set>

using namespace std;

int psize;
string plccis;

int *plccip;

void backtrack(string str,vector<string> &result) {
    if (str.size() == psize) {
        result.push_back(str);
        return;
    }

    set<char> charset;
    for (int i = 0; i < psize; ++i) {
        if (plccip[i] == 0 && charset.find(plccis[i]) == charset.end()) { // not visited
            charset.insert(plccis[i]);
            str += plccis[i];
            plccip[i] = 1;
            backtrack(str,result);
            plccip[i] = 0;
            str = str.substr(0, str.size() - 1);
        }
    }
}

vector<string> permutation(string S) {
    psize = S.size();
    if (psize == 0) return {};

    plccis = S;
    plccip = new int[psize];
    memset(plccip, 0, S.size() * sizeof(int));

    vector<string> result;
    backtrack("",result);

    return result;
}

void printStringVec(vector<string> v) {
    for (const auto & i : v) {
        cout << i << endl;
    }
}

//int main() {
//    printStringVec(permutation("aaab"));
//}