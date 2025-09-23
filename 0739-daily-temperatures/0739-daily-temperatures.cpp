class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // int n=temperatures.size();
        // int cnt=0;
        // vector<int>har;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //      if(temperatures[j]>temperatures[i]){
        //         cnt++;
        //         har.push_back(cnt);
        //         cnt=0;
        //         break;
        //      }
        //       else{
        //         cnt++;
              
        //       }
        //     }
        //        if (har.size() <= i) {
        //         har.push_back(0);
        //         cnt = 0;
        //     }
            
        // }
        // return har;

        int n = temperatures.size();
        vector<int> har(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                har[idx] = i - idx;
            }
            st.push(i);
        }
        return har;
    }
};