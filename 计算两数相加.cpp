//不使用四则运算计算两个数的加法 
#include <iostream>
using namespace std; 
/*
*计算加法 
*/
int add(int a, int b);

int main(){
	int a, b;
	
    cin >> a >> b;
    cout << Add(a, b);
    
    return 0;
}

int add(int a, int b){
    char *temp = (char *)a;
	/*
	*[]只是下标运算符 
    */ 
    return (int)&temp[b];
}
