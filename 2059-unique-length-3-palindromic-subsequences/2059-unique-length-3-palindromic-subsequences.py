class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        if len(s) < 3:
            return 0

        letter_counts: dict[str, int] = {}

        for i in s:
            if i not in letter_counts:
                letter_counts[i] = 0

            letter_counts[i] += 1

        palindrome_count = 0

        for i, count in letter_counts.items():
            if count <= 1:
                continue

            first_index = s.find(i)
            last_index = s.rfind(i)

            inbw_chars = set(s[first_index + 1 : last_index])
            palindrome_count += len(inbw_chars)

        return palindrome_count