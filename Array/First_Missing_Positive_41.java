public class First_Missing_Positive_41 {
    
    // TC -> O(N)
    // SC -> O(1)
    public int firstMissingPositive(int[] nums) {
        // Ans will always in range of [1, n+1] where n is length of array
        int n = nums.length;
        // change negative value to 0
        // when we need to change value of array then we can't use foreach loop
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0) nums[i] = 0;
        }

        // which ever value is covered, change the val - 1 position to -ve number
        for (int i = 0; i < n; i++)
        {
            int val = Math.abs(nums[i]);
            if (val - 1 >= 0 && val - 1 < n)
            {
                if (nums[val - 1] > 0)
                {
                    nums[val - 1] *= -1;
                }
                else if (nums[val - 1] == 0)
                {
                    nums[val - 1] = -(n + 1);
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (nums[i - 1] >= 0) return i; // >= 0 is IMP
        }
        return n + 1;
    }
}
