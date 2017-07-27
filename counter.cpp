#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int who_wins(unsigned long,int);
bool is_pwr2(unsigned long);
int otherPlayer(int);
unsigned long pwrJustsmaller(unsigned long);

//the counter problem

int main(){
	int T;
	unsigned long N;
	//cout<<"size of unsigned long "<<sizeof(N)<<endl;
	//cout<<"size of unsigned int "<<sizeof(unsigned int)<<endl;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N;
		int winner;
		winner = who_wins(N,0); //0 indicates that its Louis truns
		if (winner == 0)
			cout<<"Louise"<<endl;
		else
			cout<<"Richard"<<endl;
	}
}

int who_wins(unsigned long N, int curr_player){
	if(N == 0){
		cout<<"N is  0!!! How did this happen?"<<endl;
		return curr_player;
	}
	if (N == 1){
		return otherPlayer(curr_player);
	}
	else{
		int w;
		if (is_pwr2(N)){
			//cout<<N<<" is power of 2"<<endl;
			w = who_wins(N/2,otherPlayer(curr_player));
		}
		else{
			//cout<<N<<" is not a power of 2"<<endl;
			//cout<<pwrJustsmaller(N)<<endl;
			w = who_wins((N-pwrJustsmaller(N))
						,otherPlayer(curr_player));
		}
		return w;
	}
}

int otherPlayer(int curr_player){
	if(curr_player == 0)
		return 1;
	else
		return 0;
}

bool is_pwr2(unsigned long N){
	//neat trick by taking logical and of x & x-1 which returns 0 only if
	//x is a power of two
	//this method avoids the overflow problems in dealing with logs and other method
	if (N <= 0)
		return false;
	else
		return ((N & (N-1)) == 0);
}

unsigned long pwrJustsmaller(unsigned long N){
	if(N > 9223372036854775808)
		return 9223372036854775808;
	else{
		unsigned long p;
		for(p=1;p <= N; p = p*2){
			if(p == 0){
				cout<<"it became zero, wtf!!!"<<endl;
				return -1;
			}
		}
		return p/2;
	}
}