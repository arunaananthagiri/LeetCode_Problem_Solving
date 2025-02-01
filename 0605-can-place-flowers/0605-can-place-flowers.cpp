class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        int size = flowerbed.size();

        while (i < size && n > 0) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                i = i + 2;
                n--;
            }
            else i++;
        }
        return n == 0;
    }
};