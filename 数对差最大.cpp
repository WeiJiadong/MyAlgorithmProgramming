//在数组中，数字减去它右边的数字得到一个数对之差。求所有数对之差的最大值。 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<int> a;
	vector<int> b; 
	int n, m;
	cin >> n;
	m = n - 1;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		a.push_back(t);
	}
	if (a.size() == 0){
		return -1;
	} 
	//b记录相邻元素的差值 
	for (int i = 0; i < m; i++){
		b.push_back(a[i] - a[i + 1]);
	}
	//计算连续差值和，相当于计算原数组元素的差值 
	int sum, BetterSum;
	sum = BetterSum = 0;
	for (int i = 0; i < m; i++){
		sum += b[i];
		if (sum < 0){
			sum = 0;
		}
		if (sum > BetterSum){
			BetterSum = sum; 
		}
	}
	if (BetterSum == 0){
		BetterSum = a[0];
		for (int i = 0; i < m; i++){
			if (a[i] > BetterSum){
				BetterSum = a[i];
			}
		}
	}
	cout << BetterSum << endl;
	return 0;
}
