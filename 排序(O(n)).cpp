//ĳ��˾�м�����Ա���������һ��ʱ�临�Ӷ�ΪO(n)���㷨�Ըù�˾Ա�������������򣬿�ʹ��O(1)�ĸ����ռ䡣
#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
using namespace std;
int main(){
	vector<int> a;
	srand(time(NULL));
	int n;
	cin >> n;
	//�������n���˵����� 
	for (int i = 0; i < n; i++){
		int temp;
		temp = rand() % 60;
		if (temp < 20){
			temp += 20;
		}
		a.push_back(temp);
	}
	int b[61] = {0};
	
	for (int i = 0; i < n; i++){
		b[a[i]]++;	
	}
	for (int i = 20; i < 61; i++){
		cout << b[i] << ' '; 
	}
	return 0;
}
