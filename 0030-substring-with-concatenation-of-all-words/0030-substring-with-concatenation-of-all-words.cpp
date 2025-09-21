class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) {
            return {};
        }

        int numWords = words.size();
        int wordLen = words[0].length();
        int totalLen = numWords * wordLen;

        if (s.length() < totalLen) {
            return {};
        }

        unordered_map<string, int> wordCounts;
        for (const string& word : words) {
            wordCounts[word]++;
        }

        vector<int> result;

        for (int i = 0; i < wordLen; ++i) {
            unordered_map<string, int> seen;
            int left = i;
            int count = 0;

            for (int j = i; j <= (int)s.length() - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);

                if (wordCounts.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > wordCounts[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords) {
                        result.push_back(left);
                        
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};