//�����������ֵ�����Խף� 
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
	//��������СΪ�㣬ֱ���˳� 
	if (a.size() == 0){
			return -1; 
	}
	//�������� 
	for (int i = 0; i < n; i++){
		sum += a[i];
		//�����ǰ��ֵΪ�㣬��ѵ�ǰ��ֵ��Ϊ�� 
		if(sum < 0){
			sum = 0;
		} 
		//�����ǰ��ֵ��������ֵ��������ֵ��¼��ǰ��ֵ 
		if (sum > BetterSum){
			BetterSum = sum; 
		}
	}
	//�������ֵȫΪ��ֵ,����һ�����ĸ�ֵ����BetterSum��¼ 
	if (BetterSum == 0){
		BetterSum = a[0];
		for (int i = 0; i < n; i++){
			if (a[i] > BetterSum){
				BetterSum = a[i];
			}
		}
	}
	//�����¼��ֵ 
	cout << BetterSum << endl;
	
	return 0;
}
