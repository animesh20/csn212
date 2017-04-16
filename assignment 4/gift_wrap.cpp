#include<bits/stdc++.h>
using namespace std;

int order(pair<int,int> a, pair<int,int> b, pair<int,int> c){
	int d=(b.first-a.first)*(c.second-b.second)-(c.first-b.first)*(b.second-a.second);
	if(d==0) return 0;           
	if(d<0) return 1;            
	return 2;						 
}

void convexHull(vector<pair<int,int> > t){
	int n=t.size();
	vector<pair<int,int> > ans;
	
	if(n<3) return;
		
	int d=0;
	for(int i=1;i<n;i++){
		if(t[i].first<t[d].first) d = i;
	}
	
	int a=d,b;
	do{
		ans.push_back(t[a]);
		b = (a+1)%n;
		
		for(int i=0;i<n;i++){
			if(order(t[a],t[i],t[b])==2) b=i;
		}
		
		a=b;
	}while(a!=d);
	
	cout<<"Points on convex hull in anti-clockwise order are";
	cout<<endl;
	for(int i=0; i<ans.size();i++)
		cout<<"("<<ans[i].first<<","<<ans[i].second<<")"<<endl;
}

void userInput(){
	int N,a,b;
	vector<pair<int,int> > t;
	
	//for case when all points do not lie on convex hull
	ifstream in;
	in.open("10000_points.txt");
	in>>N;
	for(int i=0;i<N;i++){
		in>>a>>b;
		t.push_back(make_pair(a,b));
	}
	
	//for case when all points on convex hull
	/*cout<<"Enter input size: ";
	cin>>N;
	for(int i=1;i<N;i++){
		t.push_back(make_pair(i,i));
	}
	t.push_back(make_pair(0,1));*/
	
	convexHull(t);
}

int main(){
	clock_t startTime = clock();
	userInput();
	double exe_time = double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
	cout<<endl<<exe_time<<endl;
	return 0;
}
