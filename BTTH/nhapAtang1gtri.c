#include <math.h>
#include <stdio.h>

using namespace std;
int main(){
	int n, i, sum;
	printf ("nhap vao gia tri a:");
	cin>>n;
	while (n<=0){
	}
	sum = 0;
	i = 1;
	while (i <= n){
		sum = i + sum;
		i = i + 1;
		cout << sum << endl;
	}
	return 0;
}
