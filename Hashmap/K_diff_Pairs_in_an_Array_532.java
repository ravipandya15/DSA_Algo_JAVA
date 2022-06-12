package Hashmap;

import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;

public class K_diff_Pairs_in_an_Array_532 {
    // approach -> 1
    // 2 pointer approach TC -> O(nlong)
    public int findPairs(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int i = 0, j = 1;
        int count = 0;
        while (i < n && j < n)
        {
            if (nums[j] - nums[i] == k)
            {
                count++;
                i++;
                j++;

                while (j < n && nums[j] == nums[j-1])
                {
                    j++;
                }
            }
            else if (nums[j] - nums[i] > k)
            {
                i++;
                if (j - i == 0)
                {
                    j++;
                }
            }
            else
            {
                j++;
            }
        }
        return count;
    }

    // approach -> 2
    // HashMap approach TC -> O(N), SC -> O(N)
    public int findPairs_2(int[] nums, int k) {
        int count = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int num : nums)
        {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry : map.entrySet())
        {
            if ((k == 0 && entry.getValue() > 1) || (k > 0 && map.get(entry.getKey() + k) != null))
            {
                count++;
            }
        }
        return count;
    }
}
