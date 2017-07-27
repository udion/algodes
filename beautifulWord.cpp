#include <bits/stdc++.h>

using namespace std;

bool isVowel(string);
bool isRepeating(string);

int main(){
	string w;
	cin>>w;
	bool repetetive = isRepeating(w);
	bool consVowel = isVowel(w);
	
	if(!repetetive && !consVowel)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}

bool isVowel(string w){
	char chrs[] = {'a','e','i','o','u','y'};
	set<char> V (chrs,chrs+6);
	for(int i=0;i<w.length()-1;i++){
		if(V.find(w[i]) != V.end() && V.find(w[i+1]) != V.end()){
			//cout<<w[i]<<" "<<w[i+1]<<endl;
			return true;
		}
			
	}
	return false;
}

bool isRepeating(string w){
	for(int i=0;i<w.length()-1;i++){
		if(w[i] == w[i+1]){
			//cout<<w[i]<<" "<<w[i+1]<<endl;
			return true;
		}
	}
	return false;
}