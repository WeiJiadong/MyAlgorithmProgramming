/*编写一个程序，读入一组整数（不超过20个），
*当用户输入0时，表示输入结束。
*然后程序将从这组整数中，
*把第二大的那个整数找出来，
*并把它打印出来。说明：
*（1）0表示输入结束，它本身并不计入这组整数中。
*（2）在这组整数中，既有正数，也可能有负数。
*（3）这组整数的个数不少于2个。
*　输入格式：输入只有一行，包括若干个整数，
*中间用空格隔开，最后一个整数为0。
*　　输出格式：输出第二大的那个整数。
*　　输入输出样例
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> a;
	int temp;
	
	while(1){
		cin >> temp; 
		if (temp == 0){
			break;
		}
		a.push_back(temp);
	} 
	
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < a.size() - i - 1; j++){
			if (a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
			}
		}
	}
	
	cout << a[a.size() - 2] << endl;
		
	return 0;
} 
