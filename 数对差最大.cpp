//�������У����ּ�ȥ���ұߵ����ֵõ�һ������֮�����������֮������ֵ�� 
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
	//b��¼����Ԫ�صĲ�ֵ 
	for (int i = 0; i < m; i++){
		b.push_back(a[i] - a[i + 1]);
	}
	//����������ֵ�ͣ��൱�ڼ���ԭ����Ԫ�صĲ�ֵ 
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
