/*
*�ж�һ�����ǲ���2���ݣ��������������Ӧ������һ�ĸ��� 
*/ 
#include <iostream>  

using namespace std;

//����������Ӧ������һ�ĸ��� 
int getCount(unsigned int n);
//�ж��ǲ���2����
bool isDouble(unsigned int n);

int main(){
	unsigned int n;
	
	cin >> n;
	
	cout << getCount(n) << endl;
	/*
	*boolalpha
	*���true/false
	*/ 
	cout << boolalpha << isDouble(n) << endl;
	
	return 0;
}
int getCount(unsigned int n){
	int count = 0;		//���岢��ʼ�������� 
	
	while (n){	//��ǰ״̬����0 
		if (n & 1){	//���ĩβΪ1 
			count ++;	//��������һ 
		}
		n >>= 1;		//n����һλ 
	}
	
	return count;
}
bool isDouble(unsigned int n){

	return !(n & (n - 1));	
}
