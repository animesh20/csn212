#include<bits/stdc++.h>
using namespace std;

int order(pair<int,int> a, pair<int,int> b, pair<int,int> c){
	int d=(b.first-a.first)*(c.second-b.second)-(c.first-b.first)*(b.second-a.second);
	if(d==0) return 0;           
	if(d<0) return 1;            
	return 2;						 
}

double getDist(pair<int, int> t0, pair<int, int> a, pair<int, int> b){
	double m=(double)((b.second-a.second)*1.0)/(b.first-a.first);
	double c=a.second-m*a.first;		
	double d=(abs(m*t0.first-t0.second+c))/sqrt(m*m+1);
	return d;
}

void quickhull(vector<pair<int,int> > t, pair<int, int> a, pair<int, int> b, vector<pair<int, int> >&ans){
	int n=t.size();
	if(n==0) return;
	double dis = 0;
	int d;
	for(int i=0;i<n;i++){
		if(dis<getDist(t[i],a,b)){
			d=i;
			dis=getDist(t[i],a,b);
		}
	}
	ans.push_back(t[d]);
	vector<pair<int, int> >t1, t2;
	for(int i=0;i<n;i++){
		if(order(a,t[i],t[d])==2) t1.push_back(t[i]);
		else if(order(t[d],t[i],b)==2) t2.push_back(t[i]);
	}
	quickhull(t1,a,t[d],ans);
	quickhull(t2,t[d],b,ans);
}

void convexHull(vector<pair<int,int> > t){
	int n=t.size();
	vector<pair<int, int> > ans,t1,t2;
	int d1=0,d2=0;
	for(int i=1;i<n;i++){
		if(t[i].first<t[d1].first) d1 = i;
		else if(t[i].first>t[d2].first) d2 = i;
	}
	ans.push_back(t[d1]); 
	ans.push_back(t[d2]);
	int q;
	for(int i=0;i<n;i++){
		q=order(t[d1],t[i],t[d2]);
		if(q==2) t1.push_back(t[i]);
		else if(q==1) t2.push_back(t[i]);
	}
	quickhull(t1,t[d1],t[d2],ans);
	quickhull(t2,t[d2],t[d1],ans);
	cout<<"Points in convex hull are:"<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<"("<<ans[i].first<<","<<ans[i].second<<")\t";
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
