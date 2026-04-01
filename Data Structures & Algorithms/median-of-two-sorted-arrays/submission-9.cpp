class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make a be smaller
        vector<int> a = nums1;
        vector<int> b = nums2;
        int n = a.size();
        int m = b.size();
        if (n == 0) {
            if (m == 0) {
                return 0;
            } else {
                return m % 2 == 1 ? b[m/2] : (double)(b[m/2]+b[m/2-1])/2;
            }
        } 
        if (m == 0) {
            if (n == 0) {
                return 0;
            } else {
                return n % 2 == 1 ? a[n/2] : (double)(a[n/2]+a[n/2-1])/2;
            }
        } 
        if (n < m) {
            swap(n,m);
            swap(a,b);
        }
        // do binary search on a
        int l = 0, r = n-1;
        int c1 = 0;
        int c2 = 0;
        // keeps the number on both left sides = total/2
        while (l <= r) {
            c1 = (l+r)/2;
            c2 = (n+m+1)/2 - c1 - 1;
            int aLeft = c1 == 0 ? INT_MIN : a[c1-1]; 
            int aRight = c1 == n ? INT_MAX : a[c1]; 
            int bLeft = c2 == 0 ? INT_MIN : b[c2-1]; 
            int bRight = c2 == n ? INT_MAX : b[c2]; 
            cout << "c1: " << c1 << ", c2: " << c2 << endl;
            if (aLeft <= bRight && aRight >= bLeft) {
                cout << "aLeft: " << aLeft << ", bLeft: " << bLeft << endl;
                cout << "aRight: " << aRight << ", bRight: " << bRight << endl;
                if ((n+m) % 2 == 1) {
                    return min(aRight,bRight);
                } else {
                    return (double)(aRight + bRight)/2;
                }
            }
            if (aLeft > bRight) {
                r = c1-1;
                continue;
            }
            if (aRight < bLeft) {
                l = c1+1;
                continue;
            }
        }
        return 0;
    }
};
