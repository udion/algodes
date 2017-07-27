#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned long sequence_checker(unsigned long);
unsigned long sumuptill(unsigned long);

int main(){
	int T; cin>>T;
	for(int i=0;i<T;i++){
		unsigned long L,R;
		cin>>L>>R;

		unsigned long xseq;
		xseq = sumuptill(R)^sumuptill(L-1);
		cout<<xseq<<endl;
	}
	return 0;
}

unsigned long sequence_checker(unsigned long t){
	//three types of sequece which are disjounsigned long
	//checking where t belongs

	if((t-0)%4 == 0)
		return t;
	else if((t-1)%4 == 0)
		return 1;
	else if((t-2)%4 == 0)
		return t+1;
	else
		return 0;
}

unsigned long sumuptill(unsigned long n){
	//unsigned longresting pattern which can be observed in trying to find 
	//xor sum of the xequence of type [0....N]

	if((n%8==0)||((n-1)%8 == 0)){
		return n;
	}
	else if(((n-2)%8==0)||((n-3)%8==0)){
		return 2;
	}
	else if(((n-4)%8==0)||((n-5)%8==0)){
		return n+2;
	}
	else
		return 0;
}