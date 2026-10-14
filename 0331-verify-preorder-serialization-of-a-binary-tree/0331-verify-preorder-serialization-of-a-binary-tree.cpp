class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;
        int i = 0;
        while (i < preorder.size()) {
            if (slots == 0)
                return false;
            if (preorder[i] == '#') {
                slots--;
                i++;
            } 
            else {
                while (i < preorder.size() && preorder[i] != ',')
                    i++;
                slots++;
            }
            if (i < preorder.size() && preorder[i] == ',')
                i++;
        }
        return slots == 0;
    }
};