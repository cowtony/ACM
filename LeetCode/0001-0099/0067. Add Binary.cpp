class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        bool carry = false;
        while (!(a.empty() && b.empty()))
        {
            if (a.empty()) a = "0";
            if (b.empty()) b = "0";
            
            if (a.back() + b.back() == '0' + '0')
            {
                result.insert(result.begin(), carry? '1' : '0');
                carry = false;
            }  
            else if (a.back() + b.back() == '0' + '1')
            {
                result.insert(result.begin(), carry? '0' : '1');
            }
            else if (a.back() + b.back() == '1' + '1')
            {
                result.insert(result.begin(), carry? '1' : '0');
                carry = true;
            }

            a.pop_back();
            b.pop_back();
        }
        
        if (carry)
            result = "1" + result;
        
        return result;
    }
};
