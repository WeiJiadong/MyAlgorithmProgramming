//��ʹ��������������������ļӷ� 
#include <iostream>
using namespace std; 
/*
*����ӷ� 
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
	*[]ֻ���±������ 
    */ 
    return (int)&temp[b];
}
