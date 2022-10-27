#include <string>
#include <iostream>
#include <fstream>
using namespace std;
string keyword[]={"switch","else","case","default","if","union","this","int",
	"double","char","unsigned","const","goto","virtual","for","float","break",
	"auto","class","operator","while","do","long","typedef",
	"static","friend","template","signed","new","void","register","extern",
	"return","enum","inline","try","short","continue","size of","throw",
	"private","protected","asm","while","catch","delete","public","volatile","struct"};

int main(){
	int level;
	string root; 
	cout<<"File name (including suffix)"<<endl;
	cin>>root;
	cout<<"what level of stastic you want(from 1 to 4)"<<endl;
	cin>> level;
	ifstream inFile,inFile1,inFile2;
	inFile.open(root.c_str());   //���ļ�����ַ�������ios::in
	inFile1.open(root.c_str());
	inFile2.open(root.c_str());
	if(!inFile||!inFile1||!inFile2){
		cout <<"�ļ���ʧ��" << endl;
		exit(0); 
	}
	string str;
	int total=49,numt=0; ;
	int count[total] = {0}; 
	while (getline (inFile, str)){     //ʹ��getline�������Խ��ܿո����
		for(int i=0;i<total;i++){
			int position;
			while(1){
				if(str.find(keyword[i])!= -1){      //�Ҳ�����Ӧ�Ĺؼ��ʷ���-1
					if(str.find("//")!= -1) break;
					else{
						position = str.find(keyword[i]);    //��¼��һ���ҵ���λ��
						count[i]++;						//��Ӧ�Ĺؼ��ʳ��ִ�����һ
						str = str.substr(position + keyword[i].length(),str.length() - position - keyword[i].length());		//��ԭ����str����Ӧ�ؼ��ʵĲ��ֽ�ȡ������һ�γ��ֿ�ʼ���¼���
					}
				} 
				else break;
			}	
		}
	}
	for(int j=0;j<total;j++){
		if(count[j]!=0){
			numt+=count[j];	
		}
	}
	int num[5]={0,2,3,4,1},x[3]={0,0,-1};
	int struc[count[num[0]]]={0};
	string pick[3]={"else if", "if","else"};
	while (getline (inFile1, str)){		//���»�ȡһ���ļ�
		int position;
		while(1){
			if(str.find(keyword[num[1]]) != -1){
				if(str.find("//") != -1) break;
				else{
					struc[x[0]]++;			
					break;
				}
			}
			if(str.find(keyword[num[2]]) != -1){
				if(str.find("//") != -1) break;
				else{
					x[0]++;
					break;
				}
			}
			if(str.find(pick[0]) != -1){
				position = str.find(pick[0]);
				str = str.substr(position + pick[0].length(),str.length() - position - pick[0].length());
			}
			if(str.find(pick[1]) != -1){
				if(str.find("//") != -1) break;
				else{
					x[1]++;
					break;
				}
			}
			else break;
		}	
	}
	int divide[x[1]]={0}, el=0,wrong=0;				//����else��ifelseifelse������������ifelseifelse��Ϊef��������Ϊwrong
	while (getline (inFile2, str)){
		int position;
		while(1){
			if(str.find(pick[0]) != -1){
				if(str.find("//") != -1) break;
				else{
					divide[x[2]]++;
					break;
				} 
			}
			if(str.find(keyword[num[3]]) != -1){		//Ѱ��str��if���״γ���λ��
				if(str.find("//") != -1) break;
				else{
					x[2]++;
					break;
				}
			}
			else break;
		}
	}
	for(int m=0;m<x[1];m++){
		if(divide[m]==0){
			wrong++;
		}
		else{
			el++;				
		}	
	}
	for(int i=1; i<level+1; i++){
		switch(i){
		case 1:
			cout<<"total num is: "<<numt<<endl;
			for(int j=0;j<total;j++){	
				if(count[j]!=0){
					cout<<keyword[j]<<" number: "<<count[j]<<endl;		//�����鵽�Ĺؼ��ʸ���
				}
			}
			break;
		case 2:
			if(count[num[0]]!=count[num[2]]){
				cout<<" wrong!"<<endl;
			}
			else{
				cout<<"The number of switch structure is:"<<count[num[0]]<<endl;
				for(int k=0;k<count[num[0]];k++){
					cout<<"switch "<<k+1<<" number of case is: "<<struc[k]<<endl;		//���switch��case/
				}
			}
			break;
		case 3:
			cout<<"if-else: "<<wrong<<endl;
			break;
		case 4:
			cout<<"if-else if-else: "<<el<<endl;
			break;
			default:
				cout<<"wrong!"<<endl;
		}
	}
	inFile.close();
	inFile1.close();
	inFile2.close();
	return 0;
}

