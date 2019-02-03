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
void YJJ()
{
	getwhite;
	int gj1=20,gj2=10,gj3=15;
    int sj;
    srand(time(0));
    int xz,dx=150;
    system("cls");
    printf("【BOSS简介】\n"
			"虎妖一只，特来投奔金之祖巫，自诩寅将军，在朱雀街处为所欲为，百年城楼几近损塌。\n"
			"【出没地点】\n"
			"玄武门\n"
			"【技能介绍】\n"
			"虎爪掏心：用双爪进行攻击，对前方范围内的玩家造成巨大伤害。\n"
			"猛虎下山：往前上方跃起后，对下方的敌人进行猛扑,并在落地后再次造成冲击伤害。\n"
			"虎啸山林：发出巨大的怒吼，对周围的玩家造成多段伤害。\n"
			"【掉落物品】\n"
			"经验:30\n金币:2\n");
    while(dx>0&&sm>0)
    {
        system("pause");
        system("cls");
        cout<<"\t\t\t《玄武门》\n";
        if(zs>0)
        {
            cout<<"寅将军受到"<<gj*tybj<<"点灼烧伤害\n";
            zs--;
            dx-=gj*tybj;
        }
		if(!jgz&&gj1==10)gj1=20,gj2=10,gj3=15;
        if(jgz)
        {
        	if(gj1==20)gj1/=2,gj2/=2,gj3/=2;
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
                case 1:{cout<<"寅将军使用了虎爪掏心，对你造成了"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=gj1-fy>0?gj1-fy:1;break;}
                case 2:
                {
                    cout<<"寅将军使用了猛虎下山，对你造成了"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n";sm-=gj2-fy>0?gj2-fy:1;
                    cout<<"又对你造成了冲击伤害"<<(gj3-fy>0?gj3-fy:1)<<"点\n";sm-=gj3-fy>0?gj3-fy:1;
                    break;
                }
                case 3:
                {
                    int a;
                    a=rand()%5+1;
                    cout<<"寅将军使用了虎啸山林，对你造成了"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n",sm-=gj2-fy>0?gj2-fy:1;
                    for(int i=1;i<=a;i++)cout<<"余波又对你造成了3点伤害\n",sm-=3;
                }
            }
        }
        SB:if(lmf)lmf=false;
        mf+=5;
        if(sm<1)
        {
        	ofstream fout("副本--主程序.txt");
            cout<<"寅将军将你打败了!\n";fout<<"0"<<endl;
            fout.close();
            system("pause");
            return;
        }
        if(dx<1)
        {
        	ofstream fout("副本--主程序.txt");
            cout<<"你将寅将军打败了!\n";fout<<"1"<<endl;
            system("pause");
            fout.close();
            return;
        }
        JX:
        	getgreen;
        	if(dx<=75)getyellow;
        	if(dx<=30)getred;
			cout<<"寅将军生命:"<<dx;
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
        cout<<"你战胜了寅将军!\n";
        fout<<"1"<<endl;
    }
    else cout<<"寅将军将你打败了!\n",fout<<"0"<<endl;
    system("pause");
	fout.close();
    return;
}
void TCS()
{
	bool xy=false;
	int gj1=24,gj2=12,gj3=18;
	int sj;
	srand(time(0));
	int xz,dx=170;
	system("cls");
	printf("【BOSS简介】\n"
			"牛精一头，寅将军的兄弟，同为金之祖巫手下，在五星街烧杀抢掠，百姓苦不堪言。\n"
			"【出没地点】\n"
			"朱雀街\n"
			"【技能介绍】\n"
			"蛮力凿击：挥舞狼牙棒进行攻击，对范围内的玩家造成伤害。\n"
			"蛮牛冲撞：向前方冲撞，对碰撞到的玩家造成多段伤害\n"
			"地动山摇：猛踩地面，发出一道巨大的震波，并有50%几率晕眩玩家\n"
			"【掉落物品】\n"
			"经验:50\n金币:3\n");
	while(dx>0&&sm>0)
	{
		system("pause");
		system("cls");
		cout<<"\t\t\t《朱雀街》\n";
		if(zs>0)
		{
		    cout<<"特处士受到"<<gj*tybj<<"点灼烧伤害\n";
		    zs--;
		    dx-=gj*tybj;
		}
		if(!jgz&&gj1==12)gj1=24,gj2=12,gj3=18;
        if(jgz)
        {
        	if(gj1==24)gj1/=2,gj2/=2,gj3/=2;
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
		        case 1:{cout<<"特处士使用了蛮力凿击，对你造成了"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=(gj1-fy>0?gj1-fy:1);break;}
		        case 2:
		        {
		            int a;
		            a=rand()%4+1;
		            for(int i=1;i<=a;i++)cout<<"特处士使用了蛮牛冲撞，对你造成了"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n",sm-=(gj2-fy>0?gj2-fy:1);
		            break;
		        }
		        case 3:
		        {
		            int sj2;
		            sj2=rand()%100+1;
		            cout<<"特处士使用了地动山摇，对你造成了"<<(gj3-fy>0?gj3-fy:1)<<"点伤害\n",sm-=(gj3-fy>0?gj3-fy:1);
		            if(sj2<50)cout<<"并使你晕眩1回合\n",xy=true;
		            break;
		        }
		    }
		}
		SB:if(lmf)lmf=false;
		mf+=5;
		if(sm<1)
		{
			ofstream fout("副本--主程序.txt");
		    cout<<"特处士将你打败了!\n";fout<<"0"<<endl;
		    system("pause");
		    fout.close();
		    return;
		}
		if(dx<1)
		{
			ofstream fout("副本--主程序.txt");
		    cout<<"你将特处士打败了!\n";fout<<"1"<<endl;
		    system("pause");
		    fout.close();
		    return;
		}
		JX:getgreen;
        	if(dx<=85)getyellow;
        	if(dx<=42)getred;
			cout<<"特处士生命:"<<dx;
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
		        	ofstream foutt("副本--主程序.txt");
		            foutt<<"0"<<endl;
		            foutt.close();
		            return;
		        }
		    }
		}
	}
	ofstream fout("副本--主程序.txt");
	if(dx<1)
	{
		cout<<"你战胜了特处士!\n";
		fout<<"1"<<endl;
	}
	else cout<<"特处士将你打败了!\n",fout<<"0"<<endl;
	system("pause");
	fout.close();
	return;
}
void XZF()
{
	int gj1=31,gj2=28;
	int sj;
	srand(time(0));
	int xz,dx=200;
	system("cls");
	printf("【BOSS简介】\n"
			"巡山小妖怪，口头禅“大王叫我来巡山，巡了南山巡北山……”。\n"
			"【出没地点】\n"
			"五星街\n"
			"【技能介绍】\n"
			"敲锣打鼓：使用棒子敲锣，发出音波范围攻击。\n"
			"旋转龙卷：摇动背上的旗子，出现一道龙卷风直线移动。\n"
			"【掉落物品】\n"
			"经验:70\n金币:4\n");
	while(dx>0&&sm>0)
	{
	    system("pause");
	    system("cls");
	    cout<<"\t\t\t《五星街》\n";
	    if(zs>0)
	    {
	        cout<<"小钻风受到"<<gj*tybj<<"点灼烧伤害\n";
	        zs--;
	        dx-=gj*tybj;
	    }
	    if(!jgz&&gj2==14)gj1=31,gj2=28;
        if(jgz)
        {
        	if(gj2==28)gj1/=2,gj2/=2;
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
	            case 1:{cout<<"小钻风使用了敲锣打鼓，对你造成了"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=(gj1-fy>0?gj1-fy:1);break;}
	            case 2:
	            {
	                int sj2;
	                sj2=rand()%10+10;
	                cout<<"小钻风使用了旋转龙卷，对你造成了"<<(gj2-fy>0?gj2-fy:1)<<"点伤害\n";sm-=(gj2-fy>0?gj2-fy:1);
	                cout<<"又对你造成了旋风伤害"<<(sj2-fy>0?sj2-fy:1)<<"点\n";sm-=(sj2-fy>0?sj2-fy:1);
	                break;
	            }
	        }
	    }
	    SB:if(lmf)lmf=false;
	    mf+=5;
	    if(sm<1)
	    {
	    	ofstream fout("副本--主程序.txt");
	        cout<<"小钻风将你打败了!\n";fout<<"0"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    if(dx<1)
	    {
	    	ofstream fout("副本--主程序.txt");
	        cout<<"你将小钻风打败了!\n";fout<<"1"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    JX:getgreen;
        	if(dx<=100)getyellow;
        	if(dx<=50)getred;
			cout<<"小钻风生命:"<<dx;
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
	    cout<<"你战胜了小钻风!\n";
	    fout<<"1"<<endl;
	}
	else cout<<"小钻风将你打败了!\n",fout<<"0"<<endl;
	system("pause");
	fout.close();
	return;
}
void GJY()
{
	bool bgyx=false,gklh=false;
	int gj1=30;
	int sj;
	srand(time(0));
	int xz,dx=250;
	system("cls");
	printf("【BOSS简介】\n"
			"鬼金羊：属金，为羊。是为南方第二宿，属鬼宿，主惊吓，故多凶。\n"
			"【出没地点】\n"
			"东市\n"
			"【技能介绍】\n"
			"神出鬼没闪：当受到攻击的时候有30%的概率闪避此攻击。(除了灼烧)\n"
			"百鬼夜行：身上飞出许多鬼魂，绕着鬼金羊旋转，攻击触碰到的玩家(你的防御不起作用！【持续一回合】)。\n"
			"鬼哭狼嚎：玩家减少50%攻击力(持续一回合)，并受到伤害。\n"
			"【掉落物品】\n"
			"经验:80\n金币:4\n");
	while(dx>0&&sm>0)
	{
	    system("pause");
	    system("cls");
	    cout<<"\t\t\t《东市》\n";
	    if(zs>0)
	    {
	        cout<<"鬼金羊受到"<<gj*tybj<<"点灼烧伤害\n";
	        if(bgyx)cout<<"同时你也受到"<<tybj*gj<<"点伤害\n";sm-=gj*tybj;
	        zs--;
	        dx-=gj*tybj;
	    }
	    if(gklh)gj*=2;
	    bgyx=false;gklh=false;
	    if(!jgz&&gj1==15)gj1=30;
        if(jgz)
        {
        	if(gj1==30)gj1/=2;
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
	            case 1:{cout<<"鬼金羊使用了百鬼夜行,可以使你受到100%的伤害\n";bgyx=true;break;}
	            case 2:{cout<<"鬼金羊使用了鬼哭狼嚎,你的攻击力降为"<<gj/2<<"并受到"<<(gj1-fy>0?gj1-fy:1)<<"点伤害\n";sm-=(gj1-fy>0?gj1-fy:1);gj/=2;gklh=true;break;}
	        }
	    }
	    SB:if(lmf)lmf=false;
	    mf+=5;
	    if(sm<1)
	    {
	    	ofstream fout("副本--主程序.txt");
	        cout<<"鬼金羊将你打败了!\n";fout<<"0"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    if(dx<1)
	    {
	    	ofstream fout("副本--主程序.txt");
	        cout<<"你将鬼金羊打败了!\n";fout<<"1"<<endl;
	        system("pause");
	        fout.close();
	        return;
	    }
	    JX:getgreen;
        	if(dx<=125)getyellow;
        	if(dx<=62)getred;
			cout<<"鬼金羊生命:"<<dx;
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
	    bool sb=(rand()%100+1)<30?1:0;
	    switch(xz)
	    {
	        case 1:
			{
				if(!sb){cout<<"你对敌人造成了"<<gj*tybj<<"点伤害\n";dx-=gj*tybj;if(bgyx)cout<<"同时你也受到"<<gj*tybj<<"点伤害\n",sm-=gj*tybj;}
				else cout<<"鬼金羊使用神出鬼没闪,闪避此攻击\n";
				tybj=1;
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
	    cout<<"你战胜了鬼金羊!\n";
	    fout<<"1"<<endl;
	}
	else cout<<"鬼金羊将你打败了!\n",fout<<"0"<<endl;
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
    	case 1:{YJJ();break;}
    	case 2:{TCS();break;}
    	case 3:{XZF();break;}
    	case 4:{GJY();break;}
	}
	return 0;
}
