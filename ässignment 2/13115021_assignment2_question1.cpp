#include <iostream>
#include <vector>
#define MAX 50
using namespace std;

int main(){
	int s;
	cout<<"Enter size of the array input: ";
	cin>>s;
	int a[s];
	cout<<"Enter input: ";
	for (int i=0;i<s;i++)
	cin>>a[i];
    int si[s] = {0};
    int ans[s] = {1};
    for(int i=1;i<s;i++){
    for(int j = i-1; j>=0; j--){
    int b = si[j];
    if( (b == 0) || ( (b < 0) && (a[i] - a[j] > 0) ) || 
    ( (b > 0) && (a[i] - a[j] < 0) ) ){        	
    ans[i] = ans[j] + 1;            
    si[i] = a[i] - a[j];
    break;
    }
	}
    }
    cout<<"Answer is: ";
    cout << ans[s-1] << endl;
    return 0;
}
