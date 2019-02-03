#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
struct Node{
    int hm;
    string name;
}jin[1001];
int jjn[5];
int zsm,lmf,zs,hsm,jgz,lys,tybj,sh,mf,gj;
inline void chushihua()
{
    jin[1].name="灭神一击";jin[1].hm=15;jin[2].name="绿蔓缚";jin[2].hm=15;jin[3].name="烈焰风暴";jin[3].hm=20;
    jin[4].name="天降甘露";jin[4].hm=25;jin[5].name="紧箍咒";jin[5].hm=25;jin[6].name="烈焰闪";jin[6].hm=30;
    jin[7].name="天眼标记";jin[7].hm=30;jin[8].name="火魔九连斩";jin[8].hm=40;jin[9].name="火猿出击";jin[9].hm=45;
    jin[10].name="归魂神灭";jin[10].hm=60;
}
int read()
{
	int tot=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		tot=tot*10+c-'0';
		c=getchar();
	}
	return tot*f;
}
int main()
{
    chushihua();
    ifstream finn("技能.txt");
    for(int i=1;i<=4;i++)finn>>jjn[i];
    finn.close();
    
	ifstream fin("技能处理.txt");
    fin>>zsm>>lmf>>zs>>hsm>>jgz>>lys>>tybj>>sh>>mf>>gj;
    fin.close();
    CX:system("cls");
	cout<<"\t\t\t《技能》\n";
    cout<<"你的魔法:"<<mf<<endl;
    for(int i=1;i<=4;i++)
    {
        cout<<i<<"、"<<jin[jjn[i]].name<<"   耗魔:"<<jin[jjn[i]].hm<<endl;
    }
    cout<<"5、普通攻击   耗魔:0\n";
	cout<<"请选择(千万不要按错哦!):\n";
	int xz;
	xz=read();
	if(xz==5)
	{
		cout<<"你对敌人造成了"<<gj*tybj<<"点伤害\n";
		sh=gj*tybj;
		tybj=1;
		ofstream fout("技能处理.txt");
		fout<<zsm<<" "<<lmf<<" "<<zs<<" "<<hsm<<" "<<jgz<<" "<<lys<<" "<<tybj<<" "<<sh<<" "<<mf<<" "<<gj<<endl;
		fout.close();
		return 0;
	}
	if(mf<jin[jjn[xz]].hm){cout<<"你魔法不足!\n";goto CX;}
	cout<<"你使用了"<<jin[jjn[xz]].name<<endl;mf-=jin[jjn[xz]].hm;
	switch(jjn[xz])
	{
		case 1:{cout<<"对敌人造成"<<2*gj*tybj<<"点伤害\n";sh=2*gj*tybj;tybj=1;break;}
		case 2:{cout<<"对敌人造成"<<gj*tybj<<"点伤害,并形成绿蔓缚\n";sh=gj*tybj;lmf=true;tybj=1;break;}
		case 3:{cout<<"对敌人造成"<<2*gj*tybj<<"点伤害,并形成灼烧\n";sh=2*gj*tybj;zs=3;tybj=1;break;}
		case 4:{cout<<"回复了"<<zsm*0.45<<"点血量\n";hsm=zsm*0.40;tybj=1;break;}
		case 5:{cout<<"使敌人在后2回合攻击降为原来的50%\n";jgz=2;tybj=1;break;}
		case 6:{cout<<"使你在后3回合闪避率变为50%\n";lys=3;tybj=1;break;}
		case 7:{cout<<"形成天眼标记\n";tybj=3;break;}
		case 8:{cout<<"对敌人造成"<<3*gj*tybj<<"点伤害，并形成灼烧\n";sh=3*gj*tybj;zs=3;tybj=1;break;}
		case 9:{cout<<"对敌人造成"<<4*gj*tybj<<"点伤害，并形成绿蔓缚\n";sh=4*gj*tybj;lmf=true;tybj=1;break;}
		case 10:{cout<<"对敌人造成"<<5*gj*tybj<<"点伤害，并形成天眼标记\n";sh=5*gj*tybj;tybj=3;int ssj=rand()%100+1;if(ssj==1)sh=0x3f3f3f3f;break;}
	}
	ofstream fout("技能处理.txt");
	fout<<zsm<<" "<<lmf<<" "<<zs<<" "<<hsm<<" "<<jgz<<" "<<lys<<" "<<tybj<<" "<<sh<<" "<<mf<<" "<<gj<<endl;
	fout.close();
	return 0;
}
