#include<bits/stdc++.h>
using namespace std;

struct e{
	int a,b,weight;
};

vector<e> d;
vector<int> dis(10000);

void add(int u,int v,int w){
	e e1;
	e1.a = u;
	e1.b = v;
	e1.weight = w;
	d.push_back(e1);
}

void bf(int p, int q, int source){
	for(int i = 0;i < p;i++){
		dis[i] = INT_MAX;
	}
	int r,s,t;
	dis[source] = 0;
	
	for(int i = 1;i < p;i++){
		for(int j = 0;j < q;j++){
			r = d[j].a;
			s = d[j].b;
			t = d[j].weight;
			if(dis[r] != INT_MAX && dis[s] > dis[r]+t){
				dis[s] = dis[r]+t;
			}
		}
	}
	for(int i = 0;i < q;i++){
		r = d[i].a;
		s = d[i].b;
		t = d[i].weight;
		if(dis[r] != INT_MAX && dis[s] > dis[r]+t){
				cout<<"negative weight cycle is there";
				break;
			}
	}
}

void user(){
	d.clear();
	int p,q,r,s,t,source;
	
	ifstream in;
	in.open("n10_e15.txt");
	in>>p>>q;
	for(int i = 0;i < q;i++){
		in>>r>>s>>t;
		add(r-1,s-1,t);
	}
	srand(time(NULL));
	source = rand()%p;
	
	bf(p,q,source);
	
	cout<<"start node: "<<source<<endl;
	cout<<"node \t distance "<<endl;
	for(int i = 0;i < p;i++){
		cout<<i<<" \t "<<dis[i]<<endl;
	}
}

int main(){
	clock_t start = clock();
	
	user();
	
	double exe = double( clock() - start ) / (double)CLOCKS_PER_SEC;
	cout<<endl<<exe<<" s"<<endl;
	return 0;
}
