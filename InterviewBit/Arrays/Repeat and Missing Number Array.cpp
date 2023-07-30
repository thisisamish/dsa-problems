// Approach 1 : Brute force
// TC is O(n^2), SC is O(1)

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int repeat = -1, missing = -1;
    for (int i = 0; i < A.size(); i++) {
        int count = 0;
        for (int j = 0; j < A.size(); j++) {
            if (A[j] == i) count++;
        }
        if (count == 2) repeat = i;
        if (count == 0) missing = i;
        if (repeat != -1 && missing != -1) break;
    }
    return {repeat, missing};
}

// Approach 2 : Using hashmap
// TC is O(n), SC is O(n)

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    unordered_map<int, int> count; // num : repeatCount
    int repeat = -1, missing = -1;
    for (auto& n : A) {
        count[n]++;
        if (count[n] == 2) repeat = n;
    }
    for (int i = 1; i <= A.size(); i++) {
        if (count[i] == 0) {
            missing = i;
            break;
        }
    }
    return {repeat, missing};
}

// Approach 3 : Using maths
// TC is O(n), SC is O(1)

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long repeat = -1, missing = -1;
    long long xMinusY = 0, xSqMinusYSq = 0, xPlusY = 0;
    long long temp;
    for (int i = 0; i < A.size(); i++) {
        temp = (long long)A[i];
        xMinusY += temp;
        xSqMinusYSq += temp * temp;
        temp = (long long)(i + 1);
        xMinusY -= temp;
        xSqMinusYSq -= temp * temp;
    }
    xPlusY = xSqMinusYSq / xMinusY;
    repeat = (int)(xPlusY + xMinusY) / 2;
    missing = (int)(xPlusY - xMinusY) / 2;
    return {repeat, missing};
}

// Approach 4 : Using XOR (a bit complicated, probably avoid it)
// TC is O(n), SC is O(1)