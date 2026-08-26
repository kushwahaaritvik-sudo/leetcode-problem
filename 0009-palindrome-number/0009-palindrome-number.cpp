class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (except 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        // Build the reversed second half until it's >= the remaining first half
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even length: x == reversedHalf
        // For odd length: middle digit is in reversedHalf, so remove it by /10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};