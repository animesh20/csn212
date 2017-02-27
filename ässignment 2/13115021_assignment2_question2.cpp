#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll num(int w, int h, string b){
	vector<vector<ll> > ans(h+1, vector<ll>(w+1, 0));
	vector<vector<int> > e(h+1, vector<int>(w+1, 0));
	vector<int> au(4,0);
	int i = 1, j = 0, n;
	while(i != b.size()){
		if(b[i] == ','){
			au[j] = n;
			n = 0;
			j = 0;
			if(au[1] == au[3]){
				if(e[au[1]][max(au[0], au[2])] == 0) 
					e[au[1]][max(au[0], au[2])] = 1;
				else
					e[au[1]][max(au[0], au[2])] = 3;
			}
			else{
				if(e[max(au[1], au[3])][au[0]] == 0) 
					e[max(au[1], au[3])][au[0]] = 2;
				else
					e[max(au[1], au[3])][au[0]] = 3;	
			}	
		}
		else if(b[i] == ' ') au[j++] = n,n = 0;
		else if(b[i] == '\"');
		else{
			n *= 10;
			n += (b[i]-'0');
		}	
		i++;
	}
	ans[0][0] = 1;
	for(int i = 0;i <= h;i++){
		for(int j = 0;j <= w;j++){
			if(i == 0 || j == 0){
				if(i == 0 && j == 0) continue;
				if(e[i][j] != 0) ans[i][j] = 0;
				else ans[i][j] = (i == 0)?ans[0][j-1]:ans[i-1][0];
			}
			else{
				if(e[i][j] == 0) ans[i][j] = ans[i-1][j] + ans[i][j-1];
				else if(e[i][j] == 1) ans[i][j] = ans[i-1][j];
				else if(e[i][j] == 2) ans[i][j] = ans[i][j-1];
			}
		}
	}
	return ans[h][w];
}

int main(){
	int w,h;
	string b;
	scanf("%d %d", &w, &h);
	cin.ignore();
	getline(cin, b);
	b[b.size()-1] = ',';
	
	
	ll sol = num(w,h,b);
	printf("%lld\n", sol);
	return 0;
}
