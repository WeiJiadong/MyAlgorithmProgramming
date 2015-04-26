/*
*	全排列(不考虑重复值) 
*/ 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//全排列递归函数 
template <typename T> 
void fullPermutation(T &a, unsigned int k, unsigned int n);
 
int main(){
	//测试数据以整型数据为例 
    vector<int> array;
    unsigned int n;
	
    cin >> n;
	
    for (int i = 0; i < n; i++){
	    int temp;
	    cin >> temp;
	    array.push_back(temp);
    } 
    cout << endl << "全排列结果为:" << endl;
	
    fullPermutation(array, 0, n);	
	
    return 0;
}
template <typename T>
void fullPermutation(T &a, unsigned int k, unsigned int n){
    if (k == n){	//如果k和m相等 
        for (int i = 0; i < n; i++){
            cout << a[i] << ' ';
       } 
        cout << endl;
    }
    for (int i = k; i < n; i++){
        //固定k，分别与后面交换 
        swap(a[k], a[i]);
        //再固定k+1与后面继续进行全排列 
        fullPermutation(a, k + 1, n);
        //调用结束再换回来 
        swap(a[k], a[i]);
    } 
}
