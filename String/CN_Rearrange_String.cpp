#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "CN_Rearrange_String -> AMAZON";
    return 0;
}

string rearrangeString(string &str) {
    vector<int> hash(26, 0);
    int n = str.size();
    int mostFreq = 0; // index maintains which character is most frequent
    for (int i = 0; i < n; i++)
    {
        int index = str[i] - 'a';
        hash[index]++;
        if (hash[index] > hash[mostFreq])
        {
            mostFreq = index;
        }
    }

    if (hash[mostFreq] > (n + 1) / 2)
        return "NO SOLUTION";

    vector<char> result(n);
    int position = 0;
    // start filling most freq. character in even positions (start from 0 based indexing)
    while (hash[mostFreq] > 0)
    {
        result[position] = (char)(mostFreq + (int)'a');
        hash[mostFreq]--;
        position += 2;
    }

    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            if (position >= n) // re- initialize index to fill at odd indexes
                position = 1;

            result[position] = (char)(i + (int)'a');
            hash[i]--;
            position += 2;
        }
    }

    string finalString(result.begin(), result.end());
    return finalString;
}