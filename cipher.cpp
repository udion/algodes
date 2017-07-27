#include <bits/stdc++.h>

using namespace std;

char myxor(char,string,int);

int main(){
	int N,K;
	string S;
	cin>>N>>K;
	cin>>S;

	string right_most_known = S[N+K-2];
	string ptext = right_most_known;
	for(int i=K-2; i>=0; i--){
		right_most_known = myxor(S[N+i-1],ptext,K-i);
		ptext = right_most_known+ptext;
	}
}

char myxor(char C, string P, int l){
	int xorval=0;
	for(int i=0;i<l-1;i++){
		xorval = xorval^(int(P[i])-48);
	}
	xorval = xorval ^ (int(C)-48)
	return char(xorval+48);
}