#include "includes.include"
using namespace std;
string name;
bool lmf;
int fs,zs,jgz,lys,tybj=1;
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
void EGG()
{
	int gj1=10+gj,gj2=gj;
	int sj;
	srand(time(0));
	int xz,dx=50+sm,zdx=50+sm;
	system("cls");
	printf("【BOSS简介】\n"
			"蛋之祖巫？这是个什么鸟蛋东东！！\n"
			"【出没地点】\n"
			"鸡笼\n"
			"【技能介绍】\n"
			"鸡飞蛋打：召唤一大堆蛋从天而降，对你造成巨大伤害\n"
			"臭蛋攻击：扔出一枚臭蛋，形成腐蚀（持续2回合）\n"
			"金蛋重生：在死亡时有50%的几率满血复活\n"
			"【掉落物品】\n"
			"周末积分*5\n");
	while(dx>0&&sm>0)
	{
	    FH:system("pause");
	    system("cls");
	    cout<<"\t\t\t《鸡笼》\n";
	    if(zs>0)
	    {
	        cout<<"蛋之祖巫受到"<<gj*tybj<<"点灼烧伤害\n",dx-=gj*tybj;
	        zs--;
	    }
	    if(!jgz&&gj1<5+2*gj)gj1=5+2*gj,gj2=10+gj;
        if(jgz)
        {
        	if(gj1==5+2*gj)gj1/=2,gj2/=2;
        	jgz--;
		}
		if(fs)
		{
			fs--;
			cout<<"你受到"<<gj2<<"点腐蚀伤害\n";sm-=(gj2-fy>0?gj2-fy:1);
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
	        sj=rand()%2+1;
	        switch(sj)
	        {
	            case 1:{cout<<"蛋之祖巫使用了鸡飞蛋打,你受到"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=(gj1-fy>0?gj1-fy:1);break;}
	            case 2:{cout<<"蛋之祖巫使用了臭蛋攻击\n";fs=2;break;}
	        }
	    }
	    SB:if(lmf)lmf=false;
	    mf+=5;
	    if(sm<1)
	    {
	    	ofstream fout("副本--主程序.txt");
	        cout<<"蛋之祖巫将你打败了!\n";fout<<"0"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    if(dx<1)
	    {
	    	int sjj=rand()%2;
			if(sjj==0)
	    	{
	    		dx=zdx;
	    		cout<<"蛋之祖巫使用了金蛋重生\n";
	    		continue;
			}
	    	ofstream fout("副本--主程序.txt");
	        cout<<"你将蛋之祖巫打败了!\n";fout<<"1"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    JX:getgreen;
        	if(dx<=zdx/2)getyellow;
        	if(dx<=zdx/4)getred;
			cout<<"蛋之祖巫生命:"<<dx;
			getgreen;
			if(sm<=zsm/2)getyellow;
  			if(sm<=zsm/4)getred;
			cout<<"\t"<<name<<"生命:"<<sm<<"\t";
			getblue;
			cout<<name<<"魔法:"<<mf<<endl;
			getwhite;
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
				cout<<"你对蛋之祖巫造成"<<tybj*gj<<"点伤害\n",dx-=tybj*gj;
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
				dx-=sh;
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
		int sjj=rand()%2;
		if(sjj==0)
	    {
	    	dx=zdx;
	    	cout<<"蛋之祖巫使用了金蛋重生\n";
	    	goto FH;
		}
	    cout<<"你战胜了蛋之祖巫!\n";
	    fout<<"1"<<endl;
	}
	else cout<<"蛋之祖巫将你打败了!\n",fout<<"0"<<endl;
	system("pause");
	fout.close();
	return;
}
void HomeWork()
{
	int gj1=2*gj;
	int sj;
	srand(time(0));
	int xz,dx=60+sm,zdx=60+sm;
	system("cls");
	printf("【BOSS简介】\n"
			"作业祖巫？这难道是我老师？\n"
			"【出没地点】\n"
			"办公室\n"
			"【技能介绍】\n"
			"教鞭挥舞：像你挥舞教鞭，造成巨大伤害\n"
			"火眼金睛(被动技能)：无视天眼标记\n"
			"快交作业：使你的攻击降为原来的90%\n"
			"【掉落物品】\n"
			"周末积分*5\n");
	while(dx>0&&sm>0)
	{
	    FH:system("pause");
	    system("cls");
	    cout<<"\t\t\t《办公室》\n";
	    tybj=1; 
	    if(zs>0)
	    {
	        cout<<"作业祖巫受到"<<gj*tybj<<"点灼烧伤害\n",dx-=gj*tybj;
	        zs--;
	    }
	    if(!jgz&&gj1<=10+gj)gj1=10+gj;
        if(jgz)
        {
        	if(gj1==10+gj)gj1/=2;
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
	        sj=rand()%2+1;
	        switch(sj)
	        {
	            case 1:{cout<<"作业祖巫使用了教鞭挥舞,你受到"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=(gj1-fy>0?gj1-fy:1);break;}
	            case 2:{cout<<"作业祖巫使用了快交作业\n";gj=gj*0.9;break;}
	        }
	    }
	    SB:if(lmf)lmf=false;
	    mf+=5;
	    if(sm<1)
	    {
	    	ofstream fout("副本--主程序.txt");
	        cout<<"作业祖巫将你打败了!\n";fout<<"0"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    if(dx<1)
	    {
	    	ofstream fout("副本--主程序.txt");
	        cout<<"你将作业祖巫打败了!\n";fout<<"1"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    JX:getgreen;
        	if(dx<=zdx/2)getyellow;
        	if(dx<=zdx/4)getred;
			cout<<"作业祖巫生命:"<<dx;
			getgreen;
			if(sm<=zsm/2)getyellow;
  			if(sm<=zsm/4)getred;
			cout<<"\t"<<name<<"生命:"<<sm<<"\t";
			getblue;
			cout<<name<<"魔法:"<<mf<<endl;
			getwhite;
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
				cout<<"你对作业祖巫造成"<<tybj*gj<<"点伤害\n",dx-=tybj*gj;
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
				dx-=sh;
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
	    cout<<"你战胜了作业祖巫!\n";
	    fout<<"1"<<endl;
	}
	else cout<<"作业祖巫将你打败了!\n",fout<<"0"<<endl;
	system("pause");
	fout.close();
	return;
}
int main()
{
	getwhite;
	ifstream fin("进入副本.txt");
    fin>>name>>zsm>>sm>>gj>>fy>>mf;
    fin.close();
	srand(time(0));
	int sj=rand()%2+1;
	if(sj==1)EGG();
	else HomeWork();
	return 0;
}
