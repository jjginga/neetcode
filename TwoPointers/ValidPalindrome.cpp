//
// Created by Joel Jose Ginga on 05/03/2024.
//
/**
 * 125. Valid Palindrome
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.

    Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.

    Example 2:
    Input: s = "race a car"
    Output: false
    Explanation: "raceacar" is not a palindrome.

    Example 3:
    Input: s = " "
    Output: true
    Explanation: s is an empty string "" after removing non-alphanumeric characters.

    Since an empty string reads the same forward and backward, it is a palindrome.

    Constraints:
    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.
 */
class ValidPalindrome {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove_if(s.begin(), s.end(),
                               [](unsigned char c) { return std::isspace(c) || std::ispunct(c); }), s.end());
        size_t size = s.length();
        if(size<2) return true;
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c) -> unsigned char { return std::tolower(c); });

        for(int i = 0 ; i < size/2 ; i++)
            if(s[i]!=s[size-i-1])
                return false;
        return true;
    }
};
