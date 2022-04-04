#include<vector>
#include<algorithm>
using namespace std;

int chooseMaxStudents(vector<int> &h, int n) {
    sort(h.begin(), h.end());
    int i = 0, j = 0;
    int ans = 1;

    while (j < n)
    {
        if (h[j] - h[i] <= 5)
        {
            ans = max(ans, j-i+1);
            j++;
        }
        else
        {
            i++;
        }
    }

    return ans;
}