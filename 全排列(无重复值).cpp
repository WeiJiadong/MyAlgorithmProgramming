/*
*	ȫ����(�������ظ�ֵ) 
*/ 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//ȫ���еݹ麯�� 
template <typename T> 
void fullPermutation(T &a, unsigned int k, unsigned int n);
 
int main(){
	//������������������Ϊ�� 
	vector<int> array;
	unsigned int n;
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		array.push_back(temp);
	} 
	
	fullPermutation(array, 0, n);	
	
	return 0;
}
template <typename T>
void fullPermutation(T &a, unsigned int k, unsigned int n){
	if (k == n){	//���k��m��� 
		for (int i = 0; i < n; i++){
			cout << a[i] << ' ';
		} 
		cout << endl;
	}
	for (int i = k; i < n; i++){
		if (a[i] != a[k])
		swap(a[k], a[i]);
		fullPermutation(a, k + 1, n);
		if (a[i] != a[k])
		swap(a[k], a[i]);
	} 
}
