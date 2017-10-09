#include <bits/stdc++.h>
#include <stdint.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int count = 0;
		while (n)
		{
			cout << n << endl;
			if (n & 1 != 0)
			{
				count++;
			}
			n >>= 1;
		}
		return count;
	}
};

int main()
{
	Solution s;
	uint32_t integer = 11;
	int num_of_1 = s.hammingWeight(integer);
	cout << num_of_1 << endl;
	return 0;
}
