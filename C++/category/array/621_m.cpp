class Solution {
public:
	unsigned int largestFactor;
 
	multiset<unsigned int> primeFactors(unsigned int number)
	{
		multiset<unsigned int> factors;
		while (number % 7==0)
		{
			number /= 7;
			factors.insert(7);
		}
		while (number % 5 == 0)
		{
			number /= 5;
			factors.insert(5);
		}
		while (number % 3 == 0)
		{
			number /= 3;
			factors.insert(3);
		}
		while (number % 2 == 0)
		{
			number /= 2;
			factors.insert(2);
		}
		largestFactor = number;
		return factors;
 
	}
int smallestFactorization(int a) {
		if (a == 0)
			return 0;
		if (a < 10)
			return a;
		multiset<unsigned int> factors = primeFactors(a);
		if (largestFactor > 7)
			return 0;
		string answer = "";
		for (int i = 7; i>3; i--)
		{
			if (i == 4 || i == 6)
			{
				continue;
			}
			auto exist = factors.count(i);
			if (exist == 0)
				continue;
			for (int e = 0; e < exist; e++)
			{
				answer += std::to_string(i);
			}
		}	
 
		int twos = factors.count(2);
		int threes = factors.count(3);
		while (twos >= 3)
		{
			answer += std::to_string(8);
			twos -= 3;
		}
		while (threes >= 2)
		{
			answer += std::to_string(9);
			threes -= 2;
		}
		while (threes > 0)
		{
			if (twos >= 1)
			{
				answer += std::to_string(6);
				threes--;
				twos--;
			}
			else {
				answer += std::to_string(3);
				threes--;
			}
		}
 
		while (twos >= 1)
		{
			if (twos >= 2)
			{
				answer += std::to_string(4);
				twos -= 2;
			}
			else if(twos >= 1) {
				answer += std::to_string(2);
				twos--;
			}
		}
		std::sort(answer.begin(), answer.end());
		stringstream ss;
		ss << answer;
		unsigned long long bigNum;
		ss >> std::dec >> bigNum;
		if (bigNum <= INT_MAX)
		{
			return (unsigned int) bigNum;
		}
		else {
			return 0;
		}
	}
};

