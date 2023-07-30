// TC could be O(1) idk there's no correct way to predict how many times the
// while loop will execute. SC is O(1).

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        int carry = b;

        while (carry) {
            int temp = (unsigned)(sum & carry) << 1;
            sum = sum ^ carry;
            carry = temp;
        }

        return sum;
    }
};