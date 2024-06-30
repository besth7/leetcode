class Solution {
public:
    void merge(vector<int>& num, vector<int> left, vector<int> right) {
        while(!left.empty() && !right.empty()) {
            int l = left.at(0);
            int r = right.at(0);
            if (l <= r) {
                num.push_back(l);
                left.erase(left.begin());
            } else {
                num.push_back(r);
                right.erase(right.begin());
            }
        }

        while(!left.empty()) {
            num.push_back(left.at(0));
            left.erase(left.begin());
        }
        while(!right.empty()) {
            num.push_back(right.at(0));
            right.erase(right.begin());
        }
    }
    void mergeSort(vector<int>& num) {
        int len = num.size(); 
        if (len < 2) return;

        int mid = len / 2;
        vector<int> left;
        vector<int> right;
        for (int i=0; i<mid; i++) {
            left.push_back(num.at(0));
            num.erase(num.begin());
        }
        while(!num.empty()) {
            right.push_back(num.at(0));
            num.erase(num.begin());
        }
        mergeSort(left);
        mergeSort(right);

        merge(num, left, right);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0.0;
        vector<int> num;
        // left nums1
        // right nums2
        num.insert(num.end(), nums1.begin(), nums1.end());
        num.insert(num.end(), nums2.begin(), nums2.end());
        mergeSort(num);

        int len = num.size();
        int mid = len / 2;
        if (len % 2 == 0) {
            // even
            double a = num.at(mid-1);
            double b = num.at(mid);
            result = (a+b) / 2;
        } else {
            result = num.at(mid);
        }
        return result;
    }
};