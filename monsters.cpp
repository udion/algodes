#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,hit,t;
	cin>>n>>hit>>t;

	vector<int> health_vals;

	for(int i=0; i<n; i++){
		int x; cin>>x;
		health_vals.push_back(x);
	}

	//sorting
	sort(health_vals.begin(),health_vals.end());

	int n_killed =0;
	int count =0;

	for(int i=0; i<health_vals.size(); i++){
		if(count == t){
			//health_vals[i] -= hit;
			//if(health_vals[i] <= 0)
			//	n_killed++;
			break;
		}
		
		health_vals[i] -= hit;
		if(health_vals[i] > 0){
			i--;
			count++;
		}
		else{
			count++;
			n_killed++;
		}
	}
	cout<<n_killed<<endl;
}