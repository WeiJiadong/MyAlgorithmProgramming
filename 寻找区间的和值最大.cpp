//求区间的最大和值（线性阶） 
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> a;	
	int n;
	int BetterSum, sum;
	BetterSum = sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		a.push_back(t);
	}
	//如果数组大小为零，直接退出 
	if (a.size() == 0){
			return -1; 
	}
	//遍历数组 
	for (int i = 0; i < n; i++){
		sum += a[i];
		//如果当前和值为零，则把当前和值置为零 
		if(sum < 0){
			sum = 0;
		} 
		//如果当前和值大于最优值，则最优值记录当前和值 
		if (sum > BetterSum){
			BetterSum = sum; 
		}
	}
	//如果数组值全为负值,则找一个最大的负值，让BetterSum记录 
	if (BetterSum == 0){
		BetterSum = a[0];
		for (int i = 0; i < n; i++){
			if (a[i] > BetterSum){
				BetterSum = a[i];
			}
		}
	}
	//输出记录的值 
	cout << BetterSum << endl;
	
	return 0;
}
