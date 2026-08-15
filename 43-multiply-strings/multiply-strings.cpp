class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        vector<int> ans(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int p1 = i + j;
                int p2 = i + j + 1;

                int product = a * b;
                int sum = product + ans[p2];
                ans[p2] = sum % 10;
                ans[p1] += sum / 10;
            }
        }

        string output = "";

        for (int dig : ans) {
            if (output.empty() && dig == 0) {
                continue;
            }

            output += dig + '0';
        }

        return output;
    }
};