// TC is O(nlogn)
// SC is O(k) + O(logn) for sorting

vector<int> KMaxCombinations(vector<int>& A,vector<int>& B, int K)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int>ans;
    int N = A.size();

    priority_queue<pair<int, pair<int, int>>> pq;

    set<pair<int, int> > my_set;

    pq.push({A[N - 1] + B[N - 1], {N-1, N-1}});

    my_set.insert({N - 1, N - 1});

    for (int count = 0; count < K; count++) {
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        ans.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        if (i - 1 >= 0) {
            int sum = A[i - 1] + B[j];
            pair<int, int> temp1 = {i - 1, j};

            if (my_set.find(temp1) == my_set.end()) {
                pq.push({sum, temp1});
                my_set.insert(temp1);
            }
        }

        if (j - 1 >= 0) {
            int sum = A[i] + B[j - 1];
            pair<int,int>temp1 = {i, j - 1};

            if (my_set.find(temp1) == my_set.end()) {
                pq.push({sum, temp1});
                my_set.insert(temp1);
            }
        }
    }
    return ans;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int>temp=KMaxCombinations(A,B,C);
    return temp;
}