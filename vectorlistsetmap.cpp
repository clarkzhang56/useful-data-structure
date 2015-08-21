#include <iostream>
#include <vector>
#include <list>
#include <algorithm>/*vector中的sort*/
#include <iomanip>
#include <set>/*为了实现输出位数的控制*/
#include <map>
using namespace std;

int main(){
	cout<<"vector:"<<endl;
	vector<int> v(5,2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(1);
	v.push_back(5);
	v.push_back(3);
	v.push_back(11);
	cout<<setw(3)<<v.size()<<" "<<v.back()<<" "<<v.capacity()<<" "<<v.front()<<" "<<v.max_size()<<" "<<endl;
	for(unsigned int i=0;i<v.size();i++){
		cout<<setw(3)<<v.at(i)<<" ";
	}
	cout<<endl;
	vector<int>::iterator it;
	for(it=v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	v.resize(15);
	for(unsigned int i=0;i<v.size();i++){
		cout<<v.at(i)<<" ";
	}
	cout<<endl;
	v.resize(17);
	for(unsigned int i=0;i<v.size();i++){
		cout<<v.at(i)<<" ";
	}
	sort(v.begin(),v.end());
	cout<<endl;
	for(unsigned int i=0;i<v.size();i++){
		cout<<v.at(i)<<" ";
	}
	cout<<endl<<"***********************"<<endl;
	cout<<"list:"<<endl;
	list<int> li(3,4);
	list<int>::iterator lit;
	for(lit=li.begin();lit!=li.end();lit++){
		cout<<*lit<<" ";
	}
	cout<<endl;
	for(int i=0;i<10;i++) li.push_front(i);
	for(lit=li.begin();lit!=li.end();lit++){
		cout<<*lit<<" ";
	}
	li.sort();
	cout<<endl;
	for(lit=li.begin();lit!=li.end();lit++){
		cout<<*lit<<" ";
	}
	cout<<endl<<"***********************"<<endl;
	cout<<"set:"<<endl;
	set<int> set1;
	set1.insert(7);
	for(int i=0;i<6;i++)
		set1.insert(i);
	cout<<set1.empty()<<" "<<set1.size()<<" "<<set1.count(6)<<" "<<set1.count(2)<<endl;
	set<int>::iterator setit;
	setit=set1.begin();
	while(setit!=set1.end()){
		cout<<*setit<<" ";
		setit++;
	}
	setit=set1.find(4);
	if(setit!=set1.end())
		cout<<endl<<"find it!"<<endl;
	set1.insert(4);
	for(setit=set1.begin();setit!=set1.end();setit++)
		cout<<*setit<<" ";
	cout<<endl<<"***********************"<<endl;
	cout<<"map:"<<endl;
	map<int,int> map1;
	for(int i=0;i<5;i++){
		map1[i]=i;
	}
	cout<<map1.size()<<endl;
	map<int,int>::iterator mapit;
	for(mapit=map1.begin();mapit!=map1.end();mapit++){
		cout<<mapit->first<<" "<<mapit->second<<" ";
	}
	cout<<endl;
	map1.erase(3);
	for(mapit=map1.begin();mapit!=map1.end();mapit++){
		cout<<mapit->first<<" "<<mapit->second<<" ";
	}
	cout<<endl;
	mapit=map1.find(4);
	mapit->second=55;
	for(mapit=map1.begin();mapit!=map1.end();mapit++){
		cout<<mapit->first<<" "<<mapit->second<<" ";
	}
	pair<int,int> value(5,44);
	map1.insert(value);
	pair<int,int> value2(5,34);
	map1.insert(value2);
	cout<<endl;
	for(mapit=map1.begin();mapit!=map1.end();mapit++){
		cout<<mapit->first<<" "<<mapit->second<<"  ";
	}
	return 0;
}