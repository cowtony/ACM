class Solution {
public:
    string fractionAddition(string expression) {
        istringstream in(expression);
        int nomerator = 0, denominator = 1;
        char slash;
        int nom, denom;
        while (in >> nom >> slash >> denom) {
            // Common denominator of fraction
            nomerator = nomerator * denom + nom * denominator;
            denominator *= denom;
            // Fractional reduction
            int gcd = abs(__gcd(nomerator, denominator));
            nomerator /= gcd;
            denominator /= gcd;
        }

        return to_string(nomerator) + "/" + to_string(denominator);
    }
};
