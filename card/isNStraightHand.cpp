#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;


bool isNStraightHand(vector<int> &hand, int W) {
    if (hand.size() % W != 0) return false;
    if (W <= 1) return true;

    map<int, int> m;
    for (int h :hand) {
        ++m[h];
    }

    while (!m.empty()) {
        int start = m.begin()->first;
        --m[start];
        if (m[start] == 0) m.erase(start);

        int end = start + W;
        for (++start; start < end; ++start) {
            if (m.find(start) == m.end()) return false;
            else --m[start];
            cout << start << " ";
            if (m[start] == 0) m.erase(start);
        }
        cout << "|";
    }
    return true;

}

//int main() {
//    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
//    int W = 3;
//    cout << isNStraightHand(hand, W);
//}