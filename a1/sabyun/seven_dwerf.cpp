#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> arr;
vector <int> result;
int ret[7];
int vi[9];
void req(int num, int sum)
{
	if(num == 7)
	{
		if (sum <= 100 && result.empty())
		{
			for(int i =0; i < 7; i++)
				result.push_back(ret[i]);
		}
		return;
	}
	for(int i = 0; i < arr.size(); i++)
	{
		if(vi[i] != 0)
			continue;
		ret[num] = arr[i];
		vi[i] = 1;
		req(num+1,sum + arr[i]);
		vi[i] = 0;
		ret[num] = 0;
	}
}
int main()
{
	for(int i = 0; i < 9; i++)
	{
		int a ; cin >> a;
		arr.push_back(a);
	}
	req(0,0);
	sort(result.begin(), result.end());
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
}