class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes += 'R';
        int last_r = -1;
        int last_l = -1;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] == 'R') {
                if (last_r >= 0) {
                    for (int l = last_r + 1; l < i; l++) {
                        dominoes[l] = 'R';
                    }
                }
                last_r = i;
            } else if (dominoes[i] == 'L') {
                if (last_r >= 0) {
                    for (int l = last_r + 1, r = i - 1; l < r; l++, r--) {
                        dominoes[l] = 'R';
                        dominoes[r] = 'L';
                    }
                    last_r = -1;
                } else {
                    for (int r = last_l + 1; r < i; r++) {
                        dominoes[r] = 'L';
                    }
                }
                last_l = i;
            } 
        }
        dominoes.pop_back();
        return dominoes;
    }
};
