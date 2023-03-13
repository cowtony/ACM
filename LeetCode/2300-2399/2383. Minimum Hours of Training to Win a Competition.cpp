class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int train_exp = 0;
        for (int exp : experience) {
            if (initialExperience <= exp) {
                train_exp += exp + 1 - initialExperience;
                initialExperience += exp + 1 - initialExperience;
            }
            initialExperience += exp;
        }

        int train_eng = max(0, accumulate(energy.begin(), energy.end(), 0) + 1 - initialEnergy);
        
        return train_exp + train_eng;
    }
};
