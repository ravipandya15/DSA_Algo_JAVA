#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main()
{
    cout << "125 Valid Palindrome -> AMAZON";
    return 0;
}

int compress(vector<char>& chars) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();

        while (i < n)
        {
            int j = i + 1;
            while (j < n && chars[i] == chars[j])
            {
                j++;
            }

            // when we comes here j have some diff character or traversal of full array is completed
            
            // store old character
            chars[ansIndex++] = chars[i];

            int count = j - i;

            if (count > 1)
            {
                // convert count in string
                string str = to_string(count);
                for (char ch : str)
                {
                    chars[ansIndex++] = ch;
                }
            }
            // moving to new diff. character
            i = j;
        }
        return ansIndex;
}