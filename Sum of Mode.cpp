#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfModes(vector<int> &arr, int k)
    {
        int n = arr.size();
        unordered_map<int, int> freq;
        map<int, set<int>> freqToVals;

        for (int i = 0; i < k; ++i)
        {
            int oldFreq = freq[arr[i]];
            if (oldFreq > 0)
            {
                freqToVals[oldFreq].erase(arr[i]);
            }
            freq[arr[i]]++;
            freqToVals[freq[arr[i]]].insert(arr[i]);
        }

        int maxFreq = freqToVals.rbegin()->first;
        int sum = *freqToVals[maxFreq].begin();

        for (int i = k; i < n; ++i)
        {
            int outVal = arr[i - k], inVal = arr[i];
            int oldFreqOut = freq[outVal];
            freqToVals[oldFreqOut].erase(outVal);

            if (freqToVals[oldFreqOut].empty())
            {
                freqToVals.erase(oldFreqOut);
            }

            freq[outVal]--;
            if (freq[outVal] > 0)
            {
                freqToVals[freq[outVal]].insert(outVal);
            }
            else
            {
                freq.erase(outVal);
            }

            int oldFreqIn = freq[inVal];
            if (oldFreqIn > 0)
            {
                freqToVals[oldFreqIn].erase(inVal);
            }

            freq[inVal]++;
            freqToVals[freq[inVal]].insert(inVal);
            maxFreq = freqToVals.rbegin()->first;
            sum += *freqToVals[maxFreq].begin();
        }

        return sum;
    }
};