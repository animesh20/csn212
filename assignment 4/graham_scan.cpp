#include<bits/stdc++.h>
using namespace std;
pair<int,int> t0;

int order(pair<int,int> a, pair<int,int> b, pair<int,int> c){
	int d=(b.first-a.first)*(c.second-b.second)-(c.first-b.first)*(b.second-a.second);
	if(d==0) return 0;           
	if(d<0) return 1;            
	return 2;						 
}

bool comp(pair<int,int> a, pair<int,int> b){
	int q=order(t0,a,b);
	
	if(q==0)return (((t0.first-a.first)*(t0.first-a.first)+(t0.second-a.second)*(t0.second-a.second))<=((t0.first-b.first)*(t0.first-b.first)+(t0.second-b.second)*(t0.second-b.second)));
	return (q==1)?0:1;
}

pair<int,int> next2top(stack<pair<int,int> > &s){
	pair<int,int> t=s.top();
	s.pop();
	pair<int,int> item=s.top();
	s.push(t);
	return item;
}

void convexHull(vector<pair<int,int> > t){
	int n=t.size();
	
	int d=0;
	for(int i=1;i<n;i++){
		if(t[i].second<t[d].second) d=i;
		else if(t[i].second==t[d].second && t[i].first<t[d].first) d=i;
	}
	swap(t[0],t[d]);
	t0=t[0];
	sort(t.begin()+1,t.end(),comp);
	int j=1;
	for(int i=1;i<n-1;i++){
		if(order(t0,t[i],t[i+1])!=0) t[j++]=t[i];
	}
	t[j++]=t[n-1];
	if(j<3) return;
	stack<pair<int,int> > s;
	s.push(t[0]);s.push(t[1]);s.push(t[2]);
	for(int i=3;i<j;i++){
		while(order(next2top(s),s.top(),t[i])!=2) s.pop();
		s.push(t[i]);
	}
	int ct = 0;
	cout<<"Points on the convex hull in clockwise order are:"<<endl;
	while(!s.empty()){
		cout<<"("<<s.top().first<<","<<s.top().second<<")\t";
		ct++;
		s.pop();
	}
	cout<<endl<<"Minimum no. of points: "<<ct<<endl;
}

void userInput(){
	int N,a,b;
	vector<pair<int,int> > t;
	//for case when all points do not lie on convex hull
	/*ifstream in;
	in.open("5000_points.txt");
	in>>N;
	for(int i=0;i<N;i++){
		in>>a>>b;
		t.push_back(make_pair(a,b));
	}*/
	
	//for case when all points on convex hull
	cout<<"Enter input size: ";
	cin>>N;
	for(int i=1;i<N;i++){
		t.push_back(make_pair(i,i));
	}
	t.push_back(make_pair(0,1));
	convexHull(t);
}

int main(){
	clock_t startTime = clock();
	userInput();
	double exe_time = double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
	cout<<endl<<exe_time<<endl;
	return 0;
}
