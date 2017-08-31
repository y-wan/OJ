/*²Î¿¼CSDN*/
#include <iostream>  
#include <cstdio>  
using namespace std;  
int cmp(int a[2],int b[2])  
{  
	int i,j,flag=0;  
	for(i=0;i<2;i++){  
		for(j=0;j<2;j++){  
			if(a[i]==b[j]&&a[i]){  
				a[i]=0;  
				b[j]=0;  
				flag=1;  
				return 1;  
			}  
		}  
	}  
	if(!flag)  
		return 0;  
}  
int main()  
{  
	//freopen("input.txt","r",stdin);  
	int a[6][2],b[3][2],i,j,k;  
	while(cin>>a[0][0]>>a[0][1]){  
		for(i=1;i<6;i++)  
			cin>>a[i][0]>>a[i][1];  
		for(i=1,k=-1;i<6;i++){  
			for(j=0;j<i;j++){  
				if((a[j][0]==a[i][0]&&a[j][1]==a[i][1]||a[j][0]==a[i][1]&&a[j][1]==a[i][0])&&a[i][0]){  
					k++;  
					b[k][0]=a[i][0],b[k][1]=a[i][1],a[i][0]=0,a[i][1]=0,a[j][0]=0,a[j][1]=0;  
					break;  
				}  
			}  
		}  
		if(k<2)  
			cout<<"IMPOSSIBLE"<<endl;  
		else if(cmp(b[0],b[1])&&cmp(b[1],b[2])&&cmp(b[0],b[2]))  
			cout<<"POSSIBLE"<<endl;  
		else  
			cout<<"IMPOSSIBLE"<<endl;  
	}  
	return 0;  
}

/* 2017-07-27 ×Ô×öAC
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string str[6][2], buf;
	int s[6][2];
	stringstream ss(buf);
	while (cin >> s[0][0] >> s[0][1] >> s[1][0] >> s[1][1] >> s[2][0] >> s[2][1]
		>> s[3][0] >> s[3][1] >> s[4][0] >> s[4][1] >> s[5][0] >> s[5][1]) {
		bool printed = false;
		for (int i = 0; i < 6; i++)
			sort(s[i], s[i] + 2);
		map<string, int> dict, couple;
		map<int, int> cnt[2];
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 2; j++) {
				ss << s[i][j] << " ";
				if (!cnt[j][s[i][j]])
					cnt[j][s[i][j]] = 1;
				else
					cnt[j][s[i][j]]++;
			}
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 2; j++)
				ss >> str[i][j];
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 2; j++) {
				string tmp = str[i][j];
				if (!dict.count(tmp))
					dict[tmp] = 1;
				else if (dict[tmp] < 4)
					dict[tmp]++;
				else {
					if (!dict.count(tmp + "_1"))
						dict[tmp + "_1"] = 1;
					else if (dict[tmp + "_1"] < 4)
						dict[tmp + "_1"]++;
					else {
						if (!dict.count(tmp + "_2"))
							dict[tmp + "_2"] = 1;
						else if (dict[tmp + "_2"] < 4)
							dict[tmp + "_2"]++;
						else {
							cout << "IMPOSSIBLE" << endl;
							printed = true;
						}
					}
				}
			}
		}
		for (int i = 0; i < 6; i++) {
			string tmp = str[i][0] + "_" + str[i][1];
			if (!couple.count(tmp))
				couple[tmp] = 1;
			else if (couple[tmp] == 1)
				couple[tmp]++;
			else{
				if (!couple.count(tmp + "_1"))
					couple[tmp + "_1"] = 1;
				else if (couple[tmp + "_1"] == 1)
					couple[tmp + "_1"]++;
				else{
					if (!couple.count(tmp + "_2"))
						couple[tmp + "_2"] = 1;
					else if (couple[tmp + "_2"] == 1)
						couple[tmp + "_2"]++;
					else {
						cout << "IMPOSSIBLE" << endl;
						printed = true;
					}
				}
			}
		}
		if (dict.size() > 3 || couple.size() > 3)
			cout << "IMPOSSIBLE" << endl;
		else if (!printed)
			cout << "POSSIBLE" << endl;
	}	
	return 0;
}
*/