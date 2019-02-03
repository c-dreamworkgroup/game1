#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#define getdarkblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
#define getdarkgreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
#define getblue SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
#define getred SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
#define getdarkpink SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
#define getyellow SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
#define getwhite SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
#define getgreen SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
#define getpink SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
using namespace std;
string name;
bool lmf;
int zs,jgz,lys,tybj=1;
int sm,gj,fy,mf,jy,jb;//生命，攻击，防御，魔法，经验，金币
int zsm;
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
void MLHF()
{
	int tjht=0;
	int gj1=35,gj2=60;
	int sj;
	srand(time(0));
	int xz,dx=300;
	system("cls");
	printf("【BOSS简介】\n"
			"地藏菩萨弟子闵老护法，因儿子道明被迷惑，不得已在九华山麓把关，助纣为虐。\n"
			"【出没地点】\n"
			"九华山麓\n"
			"【技能介绍】\n"
			"藤甲护体：免除50%伤害，并反弹50%伤害，持续2回合。\n"
			"荡尽诸邪：扬起棍棒保护周身，并发出一道无形之气，玩家会受到伤害。\n"
			"生死一击：集中全力往前水平捅出一棍，并发出一道无形之气，数秒后暴击。(在血量低于50%会使用)\n"
			"【掉落物品】\n"
			"经验:90\n金币:5\n");
	while(dx>0&&sm>0)
	{
	    system("pause");
	    system("cls");
	    cout<<"\t\t\t《九华山麓》\n";
		tjht--;
	    if(zs>0)
	    {
	        if(tjht>0)cout<<"闵老护法受到"<<gj*tybj*0.5<<"点灼烧伤害\n",cout<<"同时你也受到"<<tybj*gj*0.5<<"点伤害\n",sm-=gj*tybj*0.5,dx-=0.5*gj*tybj;
	        else cout<<"闵老护法受到"<<gj*tybj<<"点灼烧伤害\n",dx-=gj*tybj;
	        zs--;
	    }
	    if(!jgz&&gj2==30)gj1=35,gj2=60;
        if(jgz)
        {
        	if(gj2==60)gj1/=2,gj2/=2;
        	jgz--;
		}
	    if(!lmf)
	    {
	    	int ssssj;
        	if(lys)
        	{
        		ssssj=rand()%2;
        		if(ssssj==0)
				{
					cout<<"闪避成功\n\n";
					goto SB;
				}
				lys--;
			}
	        if(dx<150)sj=rand()%3+1;
	        else sj=rand()%2+1;
	        switch(sj)
	        {
	            case 1:{cout<<"闵老护法使用了藤甲护体\n";tjht=2;break;}
	            case 2:{cout<<"闵老护法使用了荡尽诸邪,你受到"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=(gj1-fy>0?gj1-fy:1);break;}
	            case 3:{cout<<"闵老护法使用了生死一击,你受到"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n";sm-=(gj2-fy>0?gj2-fy:1);break;}
	        }
	    }
	    SB:if(lmf)lmf=false;
	    mf+=5;
	    if(sm<1)
	    {
	    	ofstream fout("副本--主程序.txt");
	        cout<<"闵老护法将你打败了!\n";fout<<"0"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    if(dx<1)
	    {
	    	ofstream fout("副本--主程序.txt");
	        cout<<"你将闵老护法打败了!\n";fout<<"1"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    JX:getgreen;
        	if(dx<=150)getyellow;
        	if(dx<=75)getred;
			cout<<"闵老护法生命:"<<dx;
			getgreen;
			if(sm<=zsm/2)getyellow;
  			if(sm<=zsm/4)getred;
			cout<<"\t"<<name<<"生命:"<<sm<<"\t";
			getblue;
			cout<<name<<"魔法:"<<mf<<endl;
			getwhite;
	    cout<<"藤甲护体【";
	    if(tjht>0)cout<<"是】\n";
		else cout<<"否】\n";
	    cout<<"1、普通攻击\n";
	    cout<<"2、使用技能\n";
	    cout<<"3、逃跑\n";
	    cout<<"\t\n\t\t请选择:";
	    xz=read();
	    int xxz;
	    switch(xz)
	    {
	        case 1:
			{
				if(tjht>0)cout<<"你对闵老护法造成"<<tybj*gj/2<<"点伤害\n而且你也受到"<<tybj*gj/2<<"点伤害\n",dx-=tybj*gj/2,sm-=tybj*gj/2;
				else cout<<"你对闵老护法造成"<<tybj*gj<<"点伤害\n",dx-=tybj*gj;
				break;
			}
	        case 2:
	        {
	            int hsm=0,sh=0;
            	ofstream fout("技能处理.txt");
            	fout<<zsm<<" "<<lmf<<" "<<zs<<" "<<hsm<<" "<<jgz<<" "<<lys<<" "<<tybj<<" "<<sh<<" "<<mf<<" "<<gj<<endl;
            	fout.close();
            	system("选择技能");
            	ifstream fin("技能处理.txt");
    			fin>>zsm>>lmf>>zs>>hsm>>jgz>>lys>>tybj>>sh>>mf>>gj;
    			fin.close();
    			if(sh>0)if(tjht>0)cout<<"由于有藤甲护体，所以只受到了"<<sh/2<<"点伤害\n而且你也受到"<<sh/2<<"点伤害\n",dx-=sh/2,sm-=sh/2;
				else dx-=sh;
    			sm+=hsm;
	            break;
	        }
	        case 3:
	        {
	        	ofstream foutt("副本--主程序.txt");
	            foutt<<"0"<<endl;
	            foutt.close();
	            return;
	        }
	    }
	}
	ofstream fout("副本--主程序.txt");
	if(dx<1)
	{
	    cout<<"你战胜了闵老护法!\n";
	    fout<<"1"<<endl;
	}
	else cout<<"闵老护法将你打败了!\n",fout<<"0"<<endl;
	system("pause");
	fout.close();
	return;
}
int main()
{
	int d;
    ifstream fin("进入副本.txt");
    fin>>d>>name>>zsm>>sm>>gj>>fy>>mf;
    fin.close();
    switch(d)
    {
    	case 1:{MLHF();break;}
	}
	return 0;
}
