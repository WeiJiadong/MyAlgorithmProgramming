//某公司有几万名员工，请完成一个时间复杂度为O(n)的算法对该公司员工的年龄作排序，可使用O(1)的辅助空间。
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
	//随机产生n个人的年龄 
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
