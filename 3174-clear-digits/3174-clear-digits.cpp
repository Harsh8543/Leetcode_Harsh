class Solution {
public:
    string clearDigits(string s) {
             stack<char> st;

        for (char ch : s) {
            if (isdigit(ch)) {
                // Remove the closest non-digit character to its left
                if (!st.empty() && isalpha(st.top())) {
                    st.pop();
                }
            } else {
                // Push non-digit character onto the stack
                st.push(ch);
            }
        }

        // Build the final string
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());  // Reverse because we used a stack
        return result;
    }
};