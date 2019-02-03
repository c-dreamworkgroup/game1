#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
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
int sm,gj,fy,mf;//生命，攻击，防御，魔法
int zsm;
bool xy;
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
    ifstream fin("进入副本.txt");
    fin>>name>>zsm>>sm>>gj>>fy>>mf;
    //cout<<sm<<endl;system("pause");
    fin.close();
	getwhite;
	int gj1=gj+5,gj2=gj*0.8,gj3=gj*0.35;
	int zgj1=gj1;
    int sj;
    srand(time(0));
    int xz,dx=zsm+50;
    int zdx=dx;
    system("cls");
    printf("【BOSS简介】\n"
			"年兽,古代神话传说中的恶兽\n"
			"【出没地点】\n"
			"未知\n"
			"【技能介绍】\n"
			"屠戮之角：低头，将角抵向前方，向前发起冲锋。\n"
			"八荒俱灭：仰天怒吼，地动山摇，眩晕玩家并造成伤害。\n"
			"凶星陨落：连续落下七颗陨石，攻击玩家。\n"
			"古藤兽甲(被动)：身披古藤制成的兽甲，能够抵御30%的伤害。\n"
			"【掉落物品】\n"
			"年兽断角:0~1\n"
			"年兽牙:0~1\n");
    while(dx>0&&sm>0)
    {
        system("pause");
        system("cls");
        cout<<"\t\t\t《未知之地》\n";
        if(zs>0)
        {
            cout<<"年兽受到"<<gj*tybj*0.7<<"点灼烧伤害\n";
            zs--;
            dx-=gj*tybj*0.7;
        }
		if(!jgz&&gj1!=zgj1)gj1=zgj1,gj2*=2,gj3*=2;
        if(jgz)
        {
        	if(gj1==zgj1)gj1/=2,gj2/=2,gj3/=2;
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
            sj=rand()%3+1;
            switch(sj)
            {
                case 1:{cout<<"年兽使用了屠戮之角，对你造成了"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=gj1-fy>0?gj1-fy:1;break;}
                case 2:
                {
                    cout<<"年兽使用了八荒俱灭，对你造成了"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n";sm-=gj2-fy>0?gj2-fy:1;
                    cout<<"并使你眩晕1回合\n";xy=true;
                    break;
                }
                case 3:
                {
                    int a;
                    a=rand()%5+1;
                    cout<<"年兽使用了凶星陨落\n";
					for(int i=1;i<=7;i++)cout<<"对你造成了"<<(gj3-fy>0?gj3-fy:1)<<"点伤害\n",sm-=gj3-fy>0?gj3-fy:1;
                }
            }
        }
        SB:if(lmf)lmf=false;
        mf+=5;
        if(sm<1)
        {
        	ofstream fout("副本--主程序.txt");
            cout<<"年兽将你打败了!\n";fout<<"0"<<endl;
            fout.close();
            return 0;
        }
        if(dx<1)
        {
        	ofstream fout("副本--主程序.txt");
            cout<<"你将年兽打败了!\n";fout<<"1"<<endl;
            fout.close();
            return 0;
        }
		getgreen;
       	if(dx<=zdx/2)getyellow;
       	if(dx<=zdx/4)getred;
		cout<<"年兽生命:"<<dx;
		getgreen;
		if(sm<=zsm/2)getyellow;
		if(sm<=zsm/4)getred;
		cout<<"\t"<<name<<"生命:"<<sm<<"\t";
		getblue;
		cout<<name<<"魔法:"<<mf<<endl;
		getwhite;
		if(xy)
		{
		    cout<<"你处于眩晕状态，无法攻击!\n";
		    xy=false;
		}
		else
		{
	        cout<<"1、普通攻击\n";
	        cout<<"2、使用技能\n";
	        cout<<"3、逃跑\n";
	        cout<<"\t\n\t\t请选择:";
	        xz=read();
	        int xxz;
	        switch(xz)
	        {
	            case 1:{cout<<"你对敌人造成了"<<gj*tybj*0.7<<"点伤害\n";dx-=gj*tybj*0.7;tybj=1;break;}
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
	    			dx-=sh*0.7;
	    			sm+=hsm;
	                break;
	            }
	            case 3:
	            {
	            	ofstream foutt("副本--主程序.txt");
	                foutt<<"0"<<endl;
	                foutt.close();
	            }
	        }
	    }
	}
	ofstream fout("副本--主程序.txt");
    if(dx<1)
    {
        cout<<"你战胜了年兽!\n";
        fout<<"1"<<endl;
        return 0;
    }
    else cout<<"年兽将你打败了!\n",fout<<"0"<<endl;
	fout.close();
    return 0;
}
