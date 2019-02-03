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
bool WL=false;
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
void BOSS()
{
	tybj=1;jgz=zs=lmf=0;
	int gj1=66,gj2=45;
    int sj;
    int hxjf=0;
    srand(time(0));
    int xz,dx=500;
	system("cls");
	cout<<"进度：5/5\n";Sleep(1000);
	getred;cout<<"\t\t\t警告：前方高能！\n";Sleep(2000);
	cout<<"【BOSS简介】\n";
	getpink;cout<<"金之祖巫，十二祖巫之一，被通天教主释放之后，前往长安，为祸一方。\n蓐收：人面虎身，身披金鳞，胛生双翼，左耳穿蛇，足乘两龙，西方金之祖巫。\n";
	getred;cout<<"【出没地点】\n";
	getgreen;cout<<"未央宫\n";
	getred;cout<<"【技能介绍】\n";
	getyellow;cout<<"金龙吐息：锁定玩家所在的方向，发射出一个光球，光球对玩家造成巨大伤害\n";
	getdarkblue;cout<<"回旋巨斧：在低空处缓慢地来回移动(持续两回合)，玩家被碰触到后会受到伤害(普通攻击有20%的概率打断它)\n";
	getred;cout<<"【掉落物品】\n";
	getblue;cout<<"BOSS结晶*2\n";
	getwhite;
	while(dx>0&&sm>0)
    {
        system("pause");
        system("cls");
        cout<<"\t\t\t《未央宫》\n";
        if(zs>0)
        {
            cout<<"金之祖巫受到"<<gj*tybj<<"点灼烧伤害\n";
            zs--;
            dx-=gj*tybj;
        }
        if(hxjf>0)
        {
        	hxjf--;
        	cout<<"回旋巨斧对你造成了"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n";sm-=gj2-fy>0?gj2-fy:1;
		}
		if(!jgz&&gj1==33)gj1=60,gj2=45;
        if(jgz)
        {
        	if(gj1==30)gj1/=2,gj2/=2;
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
                case 1:{cout<<"金之祖巫使用了金龙吐息，对你造成了"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=gj1-fy>0?gj1-fy:1;break;}
                case 2:
                {
                    cout<<"金之祖巫使用了回旋巨斧\n";hxjf=2;
                    break;
                }
            }
        }
        SB:if(lmf)lmf=false;
        mf+=5;
        if(sm<1)
        {
            cout<<"金之祖巫将你打败了!\n";system("pause");
            return;
        }
        if(dx<1)
        {
            cout<<"你将金之祖巫打败了!\n";
            system("pause");
            WL=true;
            return;
        }
        JX:
        	getgreen;
        	if(dx<=250)getyellow;
        	if(dx<=125)getred;
			cout<<"金之祖巫生命:"<<dx;
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
				int sj222=rand()%100+1;
				if(sj222<=20)hxjf=0;
				cout<<"你对敌人造成了"<<gj*tybj<<"点伤害\n";dx-=gj*tybj;tybj=1;break;
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
            	system("pause");
                return;
            }
        }
    }
    if(dx<1)
    {
        cout<<"你战胜了金之祖巫!\n";
        WL=true;
        system("pause");
		return;
    }
    else cout<<"金之祖巫将你打败了!\n",system("pause");
	return;
}
void GJY()
{
	tybj=1;jgz=zs=lmf=0;
	bool bgyx=false,gklh=false;
	int gj1=40;
	int sj;
	srand(time(0));
	int xz,dx=300;
	system("cls");
	cout<<"进度：4/5\n";Sleep(1000);
	printf("【Orz·鬼金羊简介】\n"
			"Orz·鬼金羊：属金，为羊。是为南方第二宿，属鬼宿，主惊吓，故多凶。\n"
			"【出没地点】\n"
			"未央宫北门\n"
			"【技能介绍】\n"
			"Orz·神出鬼没闪：当受到攻击的时候有40%的概率闪避此攻击。(除了灼烧)\n"
			"Orz·百鬼夜行：身上飞出许多鬼魂，绕着鬼金羊旋转，攻击触碰到的玩家(你的防御不起作用！【持续一回合】)。\n"
			"Orz·鬼哭狼嚎：玩家减少50%攻击力(持续一回合)，并受到巨大伤害。\n"
			"【掉落物品】\n"
			"血瓶*1(回25点生命)\n");
	while(dx>0&&sm>0)
	{
	    system("pause");
	    system("cls");
	    cout<<"\t\t\t《未央宫北门》\n";
	    if(zs>0)
	    {
	        cout<<"Orz·鬼金羊受到"<<gj*tybj<<"点灼烧伤害\n";
	        if(bgyx)cout<<"同时你也受到"<<tybj*gj<<"点伤害\n";sm-=gj*tybj;
	        zs--;
	        dx-=gj*tybj;
	    }
	    if(gklh)gj*=2;
	    bgyx=false;gklh=false;
	    if(!jgz&&gj1==20)gj1=40;
        if(jgz)
        {
        	if(gj1==40)gj1/=2;
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
	            case 1:{cout<<"Orz·鬼金羊使用了Orz·百鬼夜行,可以使你受到100%的伤害\n";bgyx=true;break;}
	            case 2:{cout<<"Orz·鬼金羊使用了Orz·鬼哭狼嚎,你的攻击力降为"<<gj/2<<"并受到"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=(gj1-fy>0?gj1-fy:1);gj/=2;gklh=true;break;}
	        }
	    }
	    SB:if(lmf)lmf=false;
	    mf+=5;
	    if(sm<1)
	    {
	        cout<<"Orz·鬼金羊将你打败了!\n";
	        system("pause");
	        return;
	    }
	    if(dx<1)
	    {
	        cout<<"你将Orz·鬼金羊打败了!\n";
	        sm+=25;
	        system("pause");
	        BOSS();
	        return;
	    }
	    JX:getgreen;
        	if(dx<=150)getyellow;
        	if(dx<=75)getred;
			cout<<"Orz·鬼金羊生命:"<<dx;
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
	    bool sb=(rand()%100+1)<40?1:0;
	    switch(xz)
	    {
	        case 1:
			{
				if(!sb){cout<<"你对敌人造成了"<<gj*tybj<<"点伤害\n";dx-=gj*tybj;if(bgyx)cout<<"同时你也受到"<<gj*tybj<<"点伤害\n",sm-=gj*tybj;}
				else cout<<"Orz·鬼金羊使用Orz·神出鬼没闪,闪避此攻击\n";
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
    			if(bgyx)cout<<"同时你也受到"<<sh<<"点伤害\n",sm-=sh;
	            break;
	        }
	        case 3:
	        {
	        	system("pause");
	            return;
	        }
	    }
	}
	if(dx<1)
	{
	    cout<<"你战胜了Orz·鬼金羊!\n";
	    sm+=25;
	    system("pause");
	    BOSS();
	}
	else cout<<"Orz·鬼金羊将你打败了!\n",system("pause");
	return;
}
void XZF()
{
	tybj=1;jgz=zs=lmf=0;
	int gj1=35,gj2=32;
	int sj;
	srand(time(0));
	int xz,dx=270;
	system("cls");
	cout<<"进度：3/5\n";Sleep(1000);
	printf("【Orz·小钻风简介】\n"
			"巡山小妖怪，口头禅“大王叫我来巡山，巡了南山巡北山……”。\n"
			"【出没地点】\n"
			"未央宫南门\n"
			"【技能介绍】\n"
			"Orz·敲锣打鼓：使用棒子敲锣，发出音波范围攻击。\n"
			"Orz·旋转龙卷：摇动背上的旗子，出现一道龙卷风直线移动。\n"
			"【掉落物品】\n"
			"血瓶*1(回25点生命)\n");
	while(dx>0&&sm>0)
	{
	    system("pause");
	    system("cls");
	    cout<<"\t\t\t《未央宫南门》\n";
	    if(zs>0)
	    {
	        cout<<"Orz·小钻风受到"<<gj*tybj<<"点灼烧伤害\n";
	        zs--;
	        dx-=gj*tybj;
	    }
	    if(!jgz&&gj2==16)gj1=35,gj2=32;
        if(jgz)
        {
        	if(gj2==32)gj1/=2,gj2/=2;
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
	            case 1:{cout<<"Orz·小钻风使用了Orz·敲锣打鼓，对你造成了"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=(gj1-fy>0?gj1-fy:1);break;}
	            case 2:
	            {
	                int sj2;
	                sj2=rand()%10+10;
	                cout<<"Orz·小钻风使用了Orz·旋转龙卷，对你造成了"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n";sm-=(gj2-fy>0?gj2-fy:1);
	                cout<<"又对你造成了Orz·旋风伤害"<<(sj2-fy>0?sj2-fy:1)<<"点\n";sm-=(sj2-fy>0?sj2-fy:1);
	                break;
	            }
	        }
	    }
	    SB:if(lmf)lmf=false;
	    mf+=5;
	    if(sm<1)
	    {
	    	ofstream fout("副本--主程序.txt");
	        cout<<"Orz·小钻风将你打败了!\n";fout<<"0"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    if(dx<1)
	    {
	        cout<<"你将Orz·小钻风打败了!\n";
	        sm+=25;
	        system("pause");
	        GJY();
	        return;
	    }
	    JX:getgreen;
        	if(dx<=130)getyellow;
        	if(dx<=65)getred;
			cout<<"Orz·小钻风生命:"<<dx;
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
	        case 1:{cout<<"你对敌人造成了"<<gj*tybj<<"点伤害\n";dx-=gj*tybj;tybj=1;break;}
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
	        	system("pause");
	            return;
	        }
	    }
	}
	ofstream fout("副本--主程序.txt");
	if(dx<1)
	{
	    cout<<"你战胜了Orz·小钻风!\n";
	    sm+=25;
	    system("pause");
	    GJY();
	}
	else cout<<"Orz·小钻风将你打败了!\n",system("pause");
	return;
}
void TCS()
{
	tybj=1;jgz=zs=lmf=0;
	bool xy=false;
	int gj1=30,gj2=20,gj3=20;
	int sj;
	srand(time(0));
	int xz,dx=250;
	system("cls");
	cout<<"进度：2/5\n";Sleep(1000);
	printf("【Orz·特处士简介】\n"
			"牛精一头，Orz·寅将军的兄弟，同为金之祖巫手下，在未央宫西门烧杀抢掠，百姓苦不堪言。\n"
			"【出没地点】\n"
			"未央宫西门\n"
			"【技能介绍】\n"
			"Orz·蛮力凿击：挥舞狼牙棒进行攻击，对范围内的玩家造成伤害。\n"
			"Orz·蛮牛冲撞：向前方冲撞，对碰撞到的玩家造成多段伤害\n"
			"Orz·地动山摇：猛踩地面，发出一道巨大的震波，并有70%几率晕眩玩家\n"
			"【掉落物品】\n"
			"血瓶*1(回25点生命)\n");
	while(dx>0&&sm>0)
	{
		system("pause");
		system("cls");
		cout<<"\t\t\t《未央宫西门》\n";
		if(zs>0)
		{
		    cout<<"Orz·特处士受到"<<gj*tybj<<"点灼烧伤害\n";
		    zs--;
		    dx-=gj*tybj;
		}
		if(!jgz&&gj1==15)gj1=30,gj2=20,gj3=20;
        if(jgz)
        {
        	if(gj1==30)gj1/=2,gj2/=2,gj3/=2;
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
		        case 1:{cout<<"Orz·特处士使用了Orz·蛮力凿击，对你造成了"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=(gj1-fy>0?gj1-fy:1);break;}
		        case 2:
		        {
		            int a;
		            a=rand()%4+1;
		            for(int i=1;i<=a;i++)cout<<"Orz·特处士使用了Orz·蛮牛冲撞，对你造成了"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n",sm-=(gj2-fy>0?gj2-fy:1);
		            break;
		        }
		        case 3:
		        {
		            int sj2;
		            sj2=rand()%100+1;
		            cout<<"Orz·特处士使用了Orz·地动山摇，对你造成了"<<(gj3-fy>0?gj3-fy:1)<<"点伤害\n",sm-=(gj3-fy>0?gj3-fy:1);
		            if(sj2<70)cout<<"并使你晕眩1回合\n",xy=true;
		            break;
		        }
		    }
		}
		SB:if(lmf)lmf=false;
		mf+=5;
		if(sm<1)
		{
		    cout<<"Orz·特处士将你打败了!\n";
			system("pause");
			return;
		}
		if(dx<1)
		{
		    cout<<"你将Orz·特处士打败了!\n";
		    sm+=25;
		    system("pause");
		    XZF();
		    return;
		}
		JX:getgreen;
        	if(dx<=125)getyellow;
        	if(dx<=62)getred;
			cout<<"Orz·特处士生命:"<<dx;
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
		        case 1:{cout<<"你对敌人造成了"<<gj*tybj<<"点伤害\n";dx-=gj*tybj;tybj=1;break;}
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
		        	system("pause");
		            return;
		        }
		    }
		}
	}
	if(dx<1)
	{
		cout<<"你战胜了Orz·特处士!\n";
		sm+=25;
		system("pause");
		XZF();
	}
	else cout<<"Orz·特处士将你打败了!\n",system("pause");
	return;
}
void YJJ()
{
	tybj=1;jgz=zs=lmf=0;
	int gj1=30,gj2=20,gj3=25;
    int sj;
    srand(time(0));
    int xz,dx=200;
	system("cls");
	cout<<"进度：1/5\n";Sleep(1000);
    printf("【Orz·寅将军简介】\n"
			"虎妖一只，特来投奔金之祖巫，自诩Orz·寅将军，在朱雀街处为所欲为，百年城楼几近损塌。\n"
			"【出没地点】\n"
			"未央宫东门\n"
			"【技能介绍】\n"
			"Orz·虎爪掏心：用双爪进行攻击，对前方范围内的玩家造成巨大伤害。\n"
			"Orz·猛虎下山：往前上方跃起后，对下方的敌人进行猛扑,并在落地后再次造成冲击伤害。"
			"Orz·虎啸山林：发出巨大的怒吼，对周围的玩家造成多段伤害。\n"
			"【掉落物品】\n"
			"血瓶*1(回25点生命)\n");
	while(dx>0&&sm>0)
    {
        system("pause");
        system("cls");
        cout<<"\t\t\t《未央宫东门》\n";
        if(zs>0)
        {
            cout<<"Orz·寅将军受到"<<gj*tybj<<"点灼烧伤害\n";
            zs--;
            dx-=gj*tybj;
        }
		if(!jgz&&gj1==15)gj1=30,gj2=20,gj3=25;
        if(jgz)
        {
        	if(gj1==30)gj1/=2,gj2/=2,gj3/=2;
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
                case 1:{cout<<"Orz·寅将军使用了Orz·虎爪掏心，对你造成了"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=gj1-fy>0?gj1-fy:1;break;}
                case 2:
                {
                    cout<<"Orz·寅将军使用了Orz·猛虎下山，对你造成了"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n";sm-=gj2-fy>0?gj2-fy:1;
                    cout<<"又对你造成了Orz·冲击伤害"<<(gj3-fy>0?gj3-fy:1)<<"点\n";sm-=gj3-fy>0?gj3-fy:1;
                    break;
                }
                case 3:
                {
                    int a;
                    a=rand()%5+1;
                    cout<<"Orz·寅将军使用了Orz·虎啸山林，对你造成了"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n",sm-=gj2-fy>0?gj2-fy:1;
                    for(int i=1;i<=a;i++)cout<<"Orz·余波又对你造成了5点伤害\n",sm-=5;
                }
            }
        }
        SB:if(lmf)lmf=false;
        mf+=5;
        if(sm<1)
        {
            cout<<"Orz·寅将军将你打败了!\n";system("pause");
            return;
        }
        if(dx<1)
        {
            cout<<"你将Orz·寅将军打败了!\n";
            sm+=25;
            system("pause");
            TCS();
            return;
        }
        JX:
        	getgreen;
        	if(dx<=100)getyellow;
        	if(dx<=50)getred;
			cout<<"Orz·寅将军生命:"<<dx;
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
            case 1:{cout<<"你对敌人造成了"<<gj*tybj<<"点伤害\n";dx-=gj*tybj;tybj=1;break;}
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
            	system("pause");
                return;
            }
        }
    }
    if(dx<1)
    {
        cout<<"你战胜了Orz·寅将军!\n";
        sm+=25;
        system("pause");
        TCS();
    }
    else cout<<"Orz·寅将军将你打败了!\n",system("pause");
	return;
}
int main()
{
	ifstream fin("进入副本.txt");
	fin>>name>>zsm>>sm>>gj>>fy>>mf;
	fin.close();
	YJJ();
	ofstream fout("副本--主程序.txt");
	if(WL==true)fout<<1<<endl;
	else fout<<0<<endl;
	fout.close();
	return 0;
}
