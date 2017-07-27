#include <bits/stdc++.h>

using namespace std;

string compliment(string);
string dup_string(string,int);

int main(){
	int q; cin>>q;
	vector<int> s;
	int x;
	for(int i=0;i<q;i++){
		cin>>x;
		s.push_back(x);
	}
	int maxs = *max_element(s.begin(),s.end());

	string str = dup_string("0",maxs);
	//cout<<"The string is: "<<str<<endl;

	for(int i=0; i<s.size(); i++){
		cout<<str[s[i]]<<endl;
	}
}

string compliment(string str){
	string s1="";
	for(int i=0;i<str.length();i++){
		if(str[i] == '0')
			s1 += '1';
		else
			s1 += '0';
	}
	//cout<<str<<" "<<s1<<endl;
	return s1;
}

string dup_string(string str, int l){
	if((str.length() < l+1) && (2*str.length() >= l+1)){
		string final = str+compliment(str);
		//cout<<"final string is: "<<final<<" returning final"<<endl;
		return final;
	}
	else{
		return dup_string(str+compliment(str),l);
	}
}