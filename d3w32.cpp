#include <bits/stdc++.h>

using namespace std;

struct res{
	int count;
	bool resbool;
};

res checkReachabilitySingleStep(int, int, int, int, int*);


int main(){
	int n, s, t; cin>>n>>s>>t;
	int R0, g, seed, p;
	cin>>R0>>g>>seed>>p;

	int R[n];

	for(int i=0;i<n;i++){
		if(i==0){
			R[i] = R0;
		}
		else{
			R[i] = (R[i-1]*g + seed)%p;
		}
	}

	if(t == s){
		cout<<0<<endl;
		return 0;
	}
	else{
		res f = checkReachabilitySingleStep(s,t,n,0,R);
		cout<<f.count+1<<endl;
		return 0;
	}
}

res checkReachabilitySingleStep(int s, int t, int n, int count, int* R){
	if(t<(s+R[s])%n && t>(s-R[s])%n){
		res r;
		r.count = count++;
		r.resbool = true;
		return r;
	}
	else{
		res r;
		
		int l = 2*R[s]+1;
		res ressteps[l];
		
		for(int i=-1*R[s]; i<=R[s]; i++){
			if(i != 0){
				ressteps[i+R[s]] = checkReachabilitySingleStep((s+i)%n,t,n,count+1,R);
			}
			else{
				res t;
				t.count = -1;
				t.resbool = false;
				ressteps[i+R[s]] = t;
			}
		}

		bool finalres = false;
		int z;
		for(z=0; z<l; z++){
			finalres = finalres || ressteps[z].resbool;
			if(finalres){
				break;
			}
		}
		if(finalres){
			r = ressteps[z];
			return r;
		}
		else{
			r.count = -1;
			r.resbool = false;
			return r;
		}
	}
}