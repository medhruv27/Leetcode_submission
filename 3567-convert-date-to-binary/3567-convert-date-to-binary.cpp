class Solution {
public:
    string solve(string temp) {
        int num = stoi(temp);
        // int n = temp.length();  // Convert string to integer
        string ans = std::bitset<32>(num).to_string();
        int firstOnePos = ans.find('1');
        
        // Return the substring starting from the first '1' bit (removing leading zeros)
        return ans.substr(firstOnePos);  // Convert number to binary (32 bits)
    }
    string convertDateToBinary(string date) {
        string temp = "";
        string res = "";
        for(int i = 0; i < date.size(); i++) {
            if (date[i] == '-') {
                res += solve(temp);
                res+= '-';  // Add binary representation of current part
                temp = "";  // Reset the temporary string for the next part
            } else {
                temp += date[i];  // Add the current character to the current part
            }
        }
        res += solve(temp);        
        return res;  // Return the concatenated binary string
    }
};
