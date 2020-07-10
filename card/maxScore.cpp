#include <vector>

using namespace std;

int maxScore(vector<int> &cardPoints, int k) {
    if (k > cardPoints.size()) return 0;

    int passScore[k + 1];
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += cardPoints[i];
        passScore[i] = sum;
    }

    int score = 0;
    sum = 0;
    for (int i = k - 1, j = cardPoints.size() - 1; i >= 0; --i, --j) {
        score = max(score, passScore[i] + sum);
        sum += cardPoints[j];
    }
    score = max(score, sum);
    return score;
}