/*
*判断一个数是不是2的幂，并计算这个数对应二进制一的个数 
*/ 
#include <iostream>  

using namespace std;

//获得这个数对应二进制一的个数 
int getCount(unsigned int n);
//判断是不是2的幂
bool isDouble(unsigned int n);

int main(){
	unsigned int n;
	
	cin >> n;
	
	cout << getCount(n) << endl;
	/*
	*boolalpha
	*输出true/false
	*/ 
	cout << boolalpha << isDouble(n) << endl;
	
	return 0;
}
int getCount(unsigned int n){
	int count = 0;		//定义并初始化计数器 
	
	while (n){	//当前状态不是0 
		if (n & 1){	//如果末尾为1 
			count ++;	//计数器加一 
		}
		n >>= 1;		//n右移一位 
	}
	
	return count;
}
bool isDouble(unsigned int n){

	return !(n & (n - 1));	
}
