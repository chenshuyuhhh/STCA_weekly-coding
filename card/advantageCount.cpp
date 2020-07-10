#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

struct node {
    int val;
    int p;

    node(int val, int p) : val(val), p(p) {};
};

bool cmp(node *n1, node *n2) {
    return n1->val > n2->val;
}


vector<int> advantageCount(vector<int> A, vector<int> B) {
    node *Barray[B.size()];
    //node *Aarray[A.size()];
    int result[B.size()];
    for (int i = 0; i < B.size(); ++i) {
        Barray[i] = new node(B[i], i);
        // Aarray[i] = new node(A[i], i);
    }

    sort(Barray, Barray + B.size(), cmp);
    sort(A.begin(), A.end());
    // sort(Aarray, Aarray + sizeof(Aarray), cmp);

    for (int i = 0; i < B.size(); ++i) {
        int num = Barray[i]->val;
        if (A.back() <= num) {
            result[Barray[i]->p] = A.front();
            A.erase(A.begin());
        } else {
            result[Barray[i]->p] = A.back();
            A.pop_back();
        }
    }
    return vector<int>(result,result+ sizeof(result));
}

//int main() {
//    advantageCount({12, 24, 8, 32}, {13, 25, 32, 11});
//}