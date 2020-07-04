#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


vector<string> removeSubfolders(vector<string> &folder) {

    sort(folder.begin(), folder.end());
    vector<string> v;
    v.push_back(folder[0]);
    string str = folder[0];
    int size = str.size();
    for (int i = 1; i < folder.size(); ++i) {
        if (str == folder[i] || (folder[i].substr(0, size) == str && folder[i][size] == '/')) {
        } else {
            v.push_back(folder[i]);
            str = folder[i];
            size = str.size();
        }

    }
    return v;
}

//int main() {
//    vector<string> v = {"/a","/a/b/c","/a/b/d", "/c/d/e", "/c/f"};
//    removeSubfolders(v);
//}