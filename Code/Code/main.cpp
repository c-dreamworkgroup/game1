#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define c1 cout<<"已领取\n";else cout<<"未领取\n";
#define c2 else cout<<"领取失败\n";system("pause");break;
#define c3 cout<<"你确定这玩意儿能使用？\n"
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
int year,month,day,hour,minute,second;
int syear,smonth,sday,ylsj=0;
char aa[1010];
string mm1,mm2;string mm,zzh,tmm;
int gjjs,fyjs,spjs;//计数
bool qth[11],pd,zdbc=1;
string nowwq="silly",nowfj="silly",nowsp="silly";
int gjgs=1,fygs=1,spgs=1;
struct l_1
{
    string mz;
    int level,jy,gj,sm,fy,mf,gjzjc,fyzjc,jb,jyls,smzjc;
    int zsm,mfzjc;
    int zbsmjc,zbfyjc,zbgjjc,zbmfjc;
    int js;
    int jsm,jmf,jgj,jfy;
    double smcs,gjcs,fycs;
}p;//player
struct l_2{
    bool sfkq;
    string mz;
}xg[101],boss[101];/*小怪*/
struct l_3{
    string mz;
    int jc1,jc2,jg,pz;
}gjsp[101],fysp[101],sp[101];
struct l_4{
    string name;
    int hm;
}jin[101];
struct l_5{
    string mz;//名字
    int jc;//加成/数量
}gjzb[110],fyzb[110],spzb[110],dj[110];//道具
int x1;
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
void zh()
{
    char b[4]={'.','t','x','t'};
    string zh;
    int xz;
    JX2:system("cls");
    cout<<"登录按1，注册按2\n";
    xz=read();if(xz==2)
    {
        cout<<"请输入账号名:\n";
        cin>>aa;
        ifstream fin("已有账号.txt");
        while(fin>>zh)
        {
            if(zh==aa)
            {
                cout<<"已有账号，是否覆盖?\n覆盖:0\t不覆盖:1\n请选择:";
                int xz;
                xz=read();
                if(!xz)break;
                else goto JX2;
            }
        }
        ofstream fout("已有账号.txt",ios::app);
        fout<<aa<<endl;fout.close();strncat(aa,b,4);
        CS:cout<<"请设置密码:";cin>>mm1;
        cout<<"请再输一次:";cin>>mm2;
        if(mm1==mm2)cout<<"注册成功！\n",x1=1,tmm=mm1;
        else {cout<<"两次输入的密码不一致，请重新输入！\n",system("pause");goto CS;}
        ofstream fout1(aa);
        fout1<<mm1;
        fout1.close();
    }
    else
    {
        bool th=false;
        cout<<"输入账号名:";cin>>aa;
        ifstream fin("已有账号.txt");
        while(fin>>zzh)
        {
            if(zzh==aa){th=true;break;}
        }
        if(!th){cout<<"没有这个账号!\n",system("pause");goto JX2;}
        else
        {
            strncat(aa,b,4);
            ifstream fin(aa);
            fin>>tmm>>p.mz>>p.level>>p.jy>>p.gjzjc>>p.fyzjc>>p.smzjc>>p.mfzjc>>p.jb>>syear>>smonth>>sday>>ylsj;
            fin>>zdbc;
            for(int i=1;i<=10;i++)fin>>qth[i];
            for(int i=1;i<=100;i++)fin>>xg[i].sfkq;
            for(int i=1;i<=50;i++)fin>>boss[i].sfkq;
            for(int i=1;i<=100;i++)fin>>dj[i].jc;
            fin>>gjjs;
            for(int i=1;i<=gjjs;i++)fin>>gjzb[i].mz>>gjzb[i].jc;
            fin>>fyjs;
            for(int i=1;i<=fyjs;i++)fin>>fyzb[i].mz>>fyzb[i].jc;
            fin>>spjs;
            for(int i=1;i<=spjs;i++)fin>>spzb[i].mz>>spzb[i].jc;
            fin>>nowwq>>nowfj>>nowsp;
            fin>>p.zbgjjc>>p.zbfyjc>>p.zbsmjc>>p.zbmfjc;
            fin>>p.js;
            fin.close();
            cout<<"请输入密码:";cin>>mm;
            if(mm==tmm)cout<<"登陆成功！\n",x1=0;
            else {cout<<"密码错误!\n",system("pause");goto JX2;}
        }
    }
}
void save()
{
    ofstream fout(aa);
    int nhour,nminute;
    time_t now_time=time(0);
    struct tm*timeinfo;
    timeinfo=localtime(&now_time);
    nhour=timeinfo->tm_hour;
    nminute=timeinfo->tm_min;
    fout<<tmm<<" "<<p.mz<<" "<<p.level<<" "<<p.jy<<" "<<p.gjzjc<<" "<<p.fyzjc<<" "<<p.smzjc<<" "<<p.mfzjc<<" "<<p.jb<<" "<<year<<" "<<month<<" "<<day<<" "<<(nhour-hour)*60+nminute-minute+ylsj<<endl;
    fout<<zdbc<<endl;
    for(int i=1;i<=10;i++)fout<<qth[i]<<" ";
    fout<<endl;
    for(int i=1;i<=100;i++)fout<<xg[i].sfkq<<" ";fout<<endl;
    for(int i=1;i<=50;i++)fout<<boss[i].sfkq<<" ";fout<<endl;
    for(int i=1;i<=100;i++)fout<<dj[i].jc<<" ";fout<<endl;
    fout<<gjjs<<endl;
    for(int i=1;i<=gjjs;i++)fout<<gjzb[i].mz<<" "<<gjzb[i].jc<<endl;
    fout<<fyjs<<endl;
    for(int i=1;i<=fyjs;i++)fout<<fyzb[i].mz<<" "<<fyzb[i].jc<<endl;
    fout<<spjs<<endl;
    for(int i=1;i<=spjs;i++)fout<<spzb[i].mz<<" "<<spzb[i].jc<<endl;
    fout<<nowwq<<" "<<nowfj<<" "<<nowsp<<endl;
    fout<<p.zbgjjc<<" "<<p.zbfyjc<<" "<<p.zbsmjc<<" "<<p.zbmfjc<<endl;
    fout<<p.js<<endl;
    fout.close();
}
void qd()
{
    int nhour,nminute;
    time_t now_time=time(0);
    struct tm*timeinfo;
    timeinfo=localtime(&now_time);
    nhour=timeinfo->tm_hour;
    nminute=timeinfo->tm_min;
    system("cls");
    int qxz,onlinetime=(nhour-hour)*60+nminute-minute+ylsj;
    cout<<"请选择:\n";
    cout<<"1| 在线5分钟礼包\t状态:";if(qth[1])c1
    cout<<"2| 在线10分钟礼包\t状态:";if(qth[2])c1
    cout<<"3| 在线20分钟礼包\t状态:";if(qth[3])c1
    cout<<"4| 在线30分钟礼包\t状态:";if(qth[4])c1
    cout<<"5| 在线60分钟礼包\t状态:";if(qth[5])c1
    cout<<"6| 在线90分钟礼包\t状态:";if(qth[6])c1
    cout<<"7| 在线120分钟礼包\t状态:";if(qth[7])c1
    cout<<"8| 在线150分钟礼包\t状态:";if(qth[8])c1
    cout<<"9| 在线170分钟礼包\t状态:";if(qth[9])c1
    cout<<"10| 在线180分钟礼包\t状态:";if(qth[10])c1
    cout<<"11| 退出\n";
    cout<<"12| 刷新\n";
    cout<<"13| 一键领取\n";
    cout<<"你已在线:"<<onlinetime<<"分钟\n";
    qxz=read();
    switch(qxz)
    {
        case 11:{return;break;}
        case 12:{qd();break;}
        case 13:
		{
			if(onlinetime>=5&&!qth[1])p.jb++,qth[1]=1;
			if(onlinetime>=10&&!qth[2])p.jb++,qth[2]=1;
			if(onlinetime>=20&&!qth[3])p.jb+=2,qth[3]=1;
			if(onlinetime>=30&&!qth[4])p.jb+=2,qth[4]=1;
			if(onlinetime>=60&&!qth[5])p.jb+=3,qth[5]=1;
			if(onlinetime>=90&&!qth[6])p.jb+=3,qth[6]=1;
			if(onlinetime>=120&&!qth[7])p.jb+=4,qth[7]=1;
			if(onlinetime>=150&&!qth[8])p.jb+=4,qth[8]=1;
			if(onlinetime>=170&&!qth[9])p.jb+=5,qth[9]=1;
			if(onlinetime>=180&&!qth[10])p.jb+=5,qth[10]=1;
			system("pause");
			break;
		}
        case 1:{if(onlinetime>=5&&!qth[1])cout<<"领取成功，你获得了1枚金币\n",p.jb++,qth[1]=1;c2}
        case 2:{if(onlinetime>=10&&!qth[2])cout<<"领取成功，你获得了1枚金币\n",p.jb++,qth[2]=1;c2}
        case 3:{if(onlinetime>=20&&!qth[3])cout<<"领取成功，你获得了2枚金币\n",p.jb+=2,qth[3]=1;c2}
        case 4:{if(onlinetime>=30&&!qth[4])cout<<"领取成功，你获得了2枚金币\n",p.jb+=2,qth[4]=1;c2}
        case 5:{if(onlinetime>=60&&!qth[5])cout<<"领取成功，你获得了3枚金币\n",p.jb+=3,qth[5]=1;c2}
        case 6:{if(onlinetime>=90&&!qth[6])cout<<"领取成功，你获得了3枚金币\n",p.jb+=3,qth[6]=1;c2}
        case 7:{if(onlinetime>=120&&!qth[7])cout<<"领取成功，你获得了4枚金币\n",p.jb+=4,qth[7]=1;c2}
        case 8:{if(onlinetime>=150&&!qth[8])cout<<"领取成功，你获得了4枚金币\n",p.jb+=4,qth[8]=1;c2}
        case 9:{if(onlinetime>=170&&!qth[9])cout<<"领取成功，你获得了5枚金币\n",p.jb+=5,qth[9]=1;c2}
        case 10:{if(onlinetime>=180&&!qth[10])cout<<"领取成功，你获得了5枚金币\n",p.jb+=5,qth[10]=1;c2}
        default:{cout<<"what are you doing?\n";system("pause");break;}
    }
}
void chushihua()
{
    GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i=1;i<=100;i++)xg[i].sfkq=false,boss[i].sfkq=false;
    xg[1].sfkq=true;
    xg[1].mz="寅将军";xg[2].mz="特处士";xg[3].mz="小钻风";xg[4].mz="鬼金羊";xg[5].mz="闵老护法";
    gjsp[gjgs].mz="|究天棍|(拨云见日，无阻坦途)";gjsp[gjgs].jg=8;gjsp[gjgs].jc1=1;gjsp[gjgs].jc2=5;gjsp[gjgs++].pz=0; 
    gjsp[gjgs].mz="|摩愿棍|(指间现寒意，一棍破空来)";gjsp[gjgs].jg=10;gjsp[gjgs].jc1=4;gjsp[gjgs].jc2=8;gjsp[gjgs++].pz=0; 
    gjsp[gjgs].mz="|罗悲棍|(棍出腾龙凌月，横波千万丈滔)";gjsp[gjgs].jg=14;gjsp[gjgs].jc1=5;gjsp[gjgs].jc2=11;gjsp[gjgs++].pz=1; 
    gjsp[gjgs].mz="|浮行棍|(烈如炎爆裂山色，玄火惊天燎野原)";gjsp[gjgs].jg=16;gjsp[gjgs].jc1=6;gjsp[gjgs].jc2=14;gjsp[gjgs++].pz=1; 
    gjsp[gjgs].mz="|多智流转棍|(棍上常若霜雪，九华灵玉为饰)";gjsp[gjgs].jg=18;gjsp[gjgs].jc1=9;gjsp[gjgs].jc2=17;gjsp[gjgs++].pz=2; 
    gjsp[gjgs].mz="|风廉定海棍|(月下飞天镜，云生结海楼)";gjsp[gjgs].jg=20;gjsp[gjgs].jc1=10;gjsp[gjgs].jc2=20;gjsp[gjgs++].pz=2;
    gjsp[gjgs].mz="|萍雨青晶棍|(月下飞天镜，云生结海楼)";gjsp[gjgs].jg=22;gjsp[gjgs].jc1=13;gjsp[gjgs].jc2=23;gjsp[gjgs++].pz=3;
    gjsp[gjgs].mz="|震雷疾星棍|(星星仙语人听尽，却向五云翻翅飞)";gjsp[gjgs].jg=24;gjsp[gjgs].jc1=14;gjsp[gjgs].jc2=26;gjsp[gjgs++].pz=3;
    gjsp[gjgs].mz="|朱电霹雳棍|(霹雳灯烛灭，蒹葭风雨来)";gjsp[gjgs].jg=26;gjsp[gjgs].jc1=17;gjsp[gjgs].jc2=29;gjsp[gjgs++].pz=4;
    gjsp[gjgs].mz="|奢天暴瀑棍|(千寻有影沧江底，万里无踪碧落边)";gjsp[gjgs].jg=28;gjsp[gjgs].jc1=18;gjsp[gjgs].jc2=32;gjsp[gjgs++].pz=4;

    fysp[fygs].mz="|究天甲|(灼目不可视，闪闪映日光)";fysp[fygs].jg=9;fysp[fygs].jc1=1;fysp[fygs].jc2=4;fysp[fygs++].pz=0;
    fysp[fygs].mz="|摩愿木甲|(饰山岳之纹，木魂浸之)";fysp[fygs].jg=12;fysp[fygs].jc1=3;fysp[fygs].jc2=6;fysp[fygs++].pz=0;
    fysp[fygs].mz="|罗悲水甲|(分水入海，避浪不伤)";fysp[fygs].jg=15;fysp[fygs].jc1=7;fysp[fygs].jc2=10;fysp[fygs++].pz=1;
    fysp[fygs].mz="|浮行火甲|(奇光烁鳞甲，威武玄火将)";fysp[fygs].jg=18;fysp[fygs].jc1=13;fysp[fygs].jc2=16;fysp[fygs++].pz=1;
    fysp[fygs].mz="|多智战甲|(立志欲坚不欲锐,成功在久不在速)";fysp[fygs].jg=21;fysp[fygs].jc1=21;fysp[fygs].jc2=24;fysp[fygs++].pz=2;
    fysp[fygs].mz="|风廉麟甲|(阵阵风寒彻骨，悠悠梅香扑鼻)";fysp[fygs].jg=24;fysp[fygs].jc1=31;fysp[fygs].jc2=34;fysp[fygs++].pz=2;
    fysp[fygs].mz="|萍雨软甲|(柳枝经雨重，松色带烟深)";fysp[fygs].jg=27;fysp[fygs].jc1=43;fysp[fygs].jc2=46;fysp[fygs++].pz=3;
    fysp[fygs].mz="|震雷锁甲|(鼓气雷作敌，剑光电为双)";fysp[fygs].jg=30;fysp[fygs].jc1=45;fysp[fygs].jc2=48;fysp[fygs++].pz=3;
    fysp[fygs].mz="|朱电烈甲|(行云吞皎月，飞电扫长空)";fysp[fygs].jg=33;fysp[fygs].jc1=47;fysp[fygs].jc2=50;fysp[fygs++].pz=4;
    fysp[fygs].mz="|奢天雾甲|(落纸烟雲纷态度，照人冰玉峙高寒)";fysp[fygs].jg=36;fysp[fygs].jc1=49;fysp[fygs].jc2=52;fysp[fygs++].pz=4; 

    sp[spgs].mz="|究天链|(翠碧玲珑，彩光清韵)";sp[spgs].jg=18;sp[spgs].jc1=10;sp[spgs].jc2=30;sp[spgs++].pz=0;
    sp[spgs].mz="|摩愿手环|(火树银花，流光百里)";sp[spgs].jg=20;sp[spgs].jc1=12;sp[spgs].jc2=32;sp[spgs++].pz=0;
    sp[spgs].mz="|罗悲玉璧|(千年磨砺，温润有方)";sp[spgs].jg=22;sp[spgs].jc1=14;sp[spgs].jc2=34;sp[spgs++].pz=1;
    sp[spgs].mz="|浮行珠|(千纱轻胧，华光雾蕴)";sp[spgs].jg=24;sp[spgs].jc1=16;sp[spgs].jc2=36;sp[spgs++].pz=1;
    sp[spgs].mz="|多智锦囊|(莹莹彩光，内蕴芳华)";sp[spgs].jg=26;sp[spgs].jc1=18;sp[spgs].jc2=38;sp[spgs++].pz=2;
    sp[spgs].mz="|风廉手钏|(莹莹彩光，内蕴芳华)";sp[spgs].jg=28;sp[spgs].jc1=20;sp[spgs].jc2=40;sp[spgs++].pz=2;
    sp[spgs].mz="|萍雨璎珞|(红珠碧石，水雾轻覆)";sp[spgs].jg=30;sp[spgs].jc1=22;sp[spgs].jc2=42;sp[spgs++].pz=3;
    sp[spgs].mz="|震雷桃木簪|(木体沁香，驱邪镇魂)";sp[spgs].jg=32;sp[spgs].jc1=24;sp[spgs].jc2=44;sp[spgs++].pz=3;
    sp[spgs].mz="|朱电勾玉|(阴阳调和，万物皆得)";sp[spgs].jg=34;sp[spgs].jc1=26;sp[spgs].jc2=46;sp[spgs++].pz=4;
    sp[spgs].mz="|奢天古铃|(叮咚铃音，迷魂摄魄)";sp[spgs].jg=36;sp[spgs].jc1=28;sp[spgs].jc2=48;sp[spgs++].pz=4;
    boss[1].mz="金之祖巫";
    p.gjzjc=0;p.fyzjc=0;p.jy=0;p.level=1;p.jb=0;p.mf=50;p.jyls=50;p.mfzjc=0;
    jin[1].name="灭神一击";jin[1].hm=15;jin[2].name="绿蔓缚";jin[2].hm=15;jin[3].name="烈焰风暴";jin[3].hm=20;
    jin[4].name="天降甘露";jin[4].hm=25;jin[5].name="紧箍咒";jin[5].hm=25;jin[6].name="烈焰闪";jin[6].hm=30;
    jin[7].name="天眼标记";jin[7].hm=30;jin[8].name="火魔九连斩";jin[8].hm=40;jin[9].name="火猿出击";jin[9].hm=45;
    jin[10].name="归魂神灭";jin[10].hm=60;
    dj[1].mz="BOSS结晶";dj[2].mz="魔法石";dj[3].mz="生命石";dj[4].mz="周末积分";dj[5].mz="角色更换卡";
    dj[6].mz="年兽断角";dj[7].mz="年兽牙";dj[8].mz="攻击石";dj[9].mz="一袋金币";
}
void shop()
{
    int xxz;
    system("cls");
    cout<<"\t\t\t《商店》\n";
    cout<<"\t你要买什么？\n";
    cout<<"1、武器\n2、防具\n3、饰品\n";
    cout<<"\t\t注:武器加攻击，防具加防御，饰品提升生命\n\n";
    cout<<"请选择:";cin>>xxz;
    system("cls");
    int xzz;
    switch(xxz)
    {
        case 1:
        {
            cout<<"\t\t\t《武器》\n";
            for(int i=1;i<gjgs;i++)
            {
                cout<<i<<"、"<<gjsp[i].mz<<" 加成为"<<gjsp[i].jc1<<"-"<<gjsp[i].jc2<<"(随机),价格为:"<<gjsp[i].jg<<" ";
                switch(gjsp[i].pz)
                {
                    case 0:{getwhite;cout<<"品质:普通"<<endl;break;}
                    case 1:{getgreen;cout<<"品质:优秀"<<endl;break;}
                    case 2:{getdarkblue;cout<<"品质:精良"<<endl;break;}
                    case 3:{getdarkpink;cout<<"品质:史诗"<<endl;break;}
                    case 4:{getyellow;cout<<"品质:传说"<<endl;break;}
                    case 5:{getred;cout<<"品质:神器"<<endl;break;}
                }
                getwhite;
            }
            cout<<p.mz<<"的金币:"<<p.jb<<endl;
            cout<<"请选择:";xzz=read();
            if(p.jb<gjsp[xzz].jg)cout<<"想吃霸王餐？\n";
            else
            {
                p.jb-=gjsp[xzz].jg;
                cout<<"你买了:"<<gjsp[xzz].mz<<endl;
                int sj=rand()%(gjsp[xzz].jc2-gjsp[xzz].jc1+1)+gjsp[xzz].jc1;
                gjzb[++gjjs].mz=gjsp[xzz].mz;gjzb[gjjs].jc=sj;cout<<"请自行进入背包查看\n";
            }
            system("pause");
            break;
        }
        case 2:
        {
            cout<<"\t\t\t《防具》\n";
            for(int i=1;i<fygs;i++)
            {
                cout<<i<<"、"<<fysp[i].mz<<" 加成为"<<fysp[i].jc1<<"-"<<fysp[i].jc2<<"(随机),价格为:"<<fysp[i].jg<<" ";
                switch(fysp[i].pz)
                {
                    case 0:{getwhite;cout<<"品质:普通"<<endl;break;}
                    case 1:{getgreen;cout<<"品质:优秀"<<endl;break;}
                    case 2:{getdarkblue;cout<<"品质:精良"<<endl;break;}
                    case 3:{getdarkpink;cout<<"品质:史诗"<<endl;break;}
                    case 4:{getyellow;cout<<"品质:传说"<<endl;break;}
                    case 5:{getred;cout<<"品质:神器"<<endl;break;}
                }
                getwhite;
            }
            cout<<p.mz<<"的金币:"<<p.jb<<endl;
            cout<<"请选择:";xzz=read();
            if(p.jb<fysp[xzz].jg)cout<<"想吃霸王餐？\n";
            else
            {
                p.jb-=fysp[xzz].jg;
                cout<<"你买了:"<<fysp[xzz].mz<<endl;
                int sj=rand()%(fysp[xzz].jc2-fysp[xzz].jc1+1)+fysp[xzz].jc1;
                fyzb[++fyjs].mz=fysp[xzz].mz;fyzb[fyjs].jc=sj;cout<<"请自行进入背包查看\n";
            }
            system("pause");
            break;
        }
        case 3:
        {
            cout<<"\t\t\t《饰品》\n";
            for(int i=1;i<spgs;i++)
            {
                cout<<i<<"、"<<sp[i].mz<<" 加成为"<<sp[i].jc1<<"-"<<sp[i].jc2<<"(随机),价格为:"<<sp[i].jg<<" ";
                switch(sp[i].pz)
                {
                    case 0:{getwhite;cout<<"品质:普通"<<endl;break;}
                    case 1:{getgreen;cout<<"品质:优秀"<<endl;break;}
                    case 2:{getdarkblue;cout<<"品质:精良"<<endl;break;}
                    case 3:{getdarkpink;cout<<"品质:史诗"<<endl;break;}
                    case 4:{getyellow;cout<<"品质:传说"<<endl;break;}
                    case 5:{getred;cout<<"品质:神器"<<endl;break;}
                }
                getwhite;
            }
            cout<<p.mz<<"的金币:"<<p.jb<<endl;
            cout<<"请选择:";xzz=read();
            if(p.jb<sp[xzz].jg)cout<<"想吃霸王餐？\n",system("pause");
            else
            {
                p.jb-=sp[xzz].jg;
                cout<<"你买了:"<<sp[xzz].mz<<endl;
                int sj=rand()%(sp[xzz].jc2-sp[xzz].jc1+1)+sp[xzz].jc1;
                spzb[++spjs].mz=sp[xzz].mz;spzb[spjs].jc=sj;cout<<"请自行进入背包查看\n";
            }
            system("pause");
            break;
        }
    }
}
void help()
{
    system("cls");
    cout<<"\t\t\t帮助:\n副本:副本的难度较为简单，打掉相应的怪物会获得相应的经验和金币\n商店:可以用金币买东西\nboss:有一定的难度，5级及以上可挑战\n";
    cout<<"在线礼包:在线相应时间可获得礼包，同一天在线时间不会少去(退出也不会),不过第二天就会清0\n";
    cout<<"技能选择在<设置>里\t个人资料在<背包>里\n";
    cout<<"关于本游戏：本游戏会不定时更新\n如果你发现了BUG，或有什么好的建议，那么就在“www.luogu.org”里私信我或在某个帖子里@我\n\t作者：hulean\n";
    system("pause");
    return;
}
void boss_pd()
{
    if(xg[5].sfkq)boss[1].sfkq=true;
    if(xg[9].sfkq)boss[2].sfkq=true;
    if(xg[13].sfkq)boss[3].sfkq=true;
}
void choose_boss()
{
    system("cls");
    boss_pd();
    int xxxz;
    cout<<"\t\t\t《BOSS》\n";
    cout<<"0| BOSS商店\n\n";
    for(int i=1;i<=1;i++)
    {
        cout<<i<<"| "<<boss[i].mz<<"\n";
        cout<<"先决条件:\n";
        for(int j=4*i-2;j<=4*i+1;j++)
        {
            cout<<xg[j-1].mz<<":";if(xg[j].sfkq)cout<<"完成\n";
            else cout<<"未完成\n";
        }
        cout<<endl;
    }
    cout<<"请选择:"<<endl;
    xxxz=read();
    if(xxxz==0)
    {
		cout<<"1| 魔法石(魔法永久+5) BOSS结晶:7";
		cout<<"2| 生命石(生命永久+30) BOSS结晶:7\n";
		cout<<"3| 退出\n";
		cout<<"你的BOSS结晶:"<<dj[1].jc<<endl;
        int zx=read();
        switch(zx)
        {
            case 1:{if(dj[1].jc<7){cout<<"你买不起!";goto Q1;}dj[1].jc-=7;dj[2].jc++;cout<<"自行进入背包查看\n";break;}
            case 2:{if(dj[1].jc<7){cout<<"你买不起!";goto Q1;}dj[1].jc-=7;dj[3].jc++;cout<<"自行进入背包查看\n";break;}
            default:{cout<<"what are you doing?\n";break;}
        }
        Q1:system("pause");
        return;
    }
    if(!boss[xxxz].sfkq){cout<<"what are you doing?\n",system("pause");return;}
    cout<<"加载中...\n";
    ofstream fout("进入副本.txt");
    fout<<p.mz<<" "<<p.zsm<<" "<<p.sm<<" "<<p.gj<<" "<<p.fy<<" "<<p.mf<<endl;
    fout.close();
    ifstream fin("副本--主程序.txt");
    bool PD;
    switch(xxxz)
    {
        case 1:{system("金之祖巫");fin>>PD;if(PD)dj[1].jc+=2,cout<<"你获得了BOSS结晶*2\n";break;}
        default:{cout<<"what are you doing?\n";system("pause");break;}
    }
}
void weekend()
{
    system("cls");
    int dayx,monthx,yearx,wdayx;
    time_t t;
    struct tm*timeinfo;
    time(&t);
    timeinfo=localtime(&t);
    dayx=timeinfo->tm_mday;
    monthx=timeinfo->tm_mon + 1;
    yearx=timeinfo->tm_year + 1900;
    wdayx=timeinfo->tm_wday;
    //cout<<wdayx<<endl;
    cout<<"1| 商店\n2| 挑战\n";
    cout<<"请选择:";
    int xzz=read();
    if(xzz==2)
    {
    	if(wdayx==6||wdayx==7)
	    {
	        getyellow;
	        cout<<"进入后，将会随机分配到【蛋之祖巫】or【作业祖巫】，进行挑战\n";
	        system("pause");
	        cout<<"加载中...\n";
	        ofstream fout("进入副本.txt");
	        fout<<p.mz<<" "<<p.zsm<<" "<<p.sm<<" "<<p.gj<<" "<<p.fy<<" "<<p.mf<<endl;
	        fout.close();
	        system("weekend");
	        ifstream fin("副本--主程序.txt");
	        bool PD;
	        fin>>PD;
	        if(PD)dj[4].jc+=5;
	        fin.close();
	    }
	    else cout<<"然而今天不是周末\n",system("pause");
	}
    else
    {
    	cout<<"1| 角色更换卡  周末积分:25\n";
    	cout<<"2| 退出\n";
    	cout<<"你的周末积分:"<<dj[4].jc<<endl;
    	cout<<"请选择:";
    	int xzz=read();
    	switch(xzz)
    	{
    		case 1:if(dj[4].jc>=25)dj[5].jc++,dj[4].jc-=25,cout<<"购买成功，进入背包查看\n";else cout<<"购买失败\n";break;
    		default:break;
		}
		system("pause");
	}
}
void spring_F()
{
	system("cls");
    int dayx,monthx,yearx,wdayx;
    time_t t;
    struct tm*timeinfo;
    time(&t);
    timeinfo=localtime(&t);
    dayx=timeinfo->tm_mday;
    monthx=timeinfo->tm_mon + 1;
    yearx=timeinfo->tm_year + 1900;
    if(!(monthx==2&&(dayx>=5&&dayx<=13))){cout<<"现在不是春节期间\n";system("pause");return;}
    getred;
    printf(
    "\t\t\t狗年已展千重锦；猪岁再登百步楼。\n"
	"\t\t\t狗问平安随腊去；猪生财富报春来。\n"
	"\t\t\t狗蹲户外家长泰；猪拱门前户发财。\n"
	"\t\t\t肥猪拱户门庭富；紫燕报春岁月新。\n"
	"\t\t\t猪多粮足农家富；子孝孙贤亲寿高。\n"
	"\t\t\t科技财神尊上座；吉祥猪崽报新春。\n"
	"\t\t\t恰逢盛世猪如象；喜庆新春鱼化龙。\n"
	"\t\t\t高老庄中称快婿；天逢府内是元戎。\n"
	"\t\t\t景象升平开泰运；金猪如意获丰财。\n"
	"\t\t\t窗花剪猪招财富；壁上画虎镇鬼神。\n"
	"\t\t\t蕃繁六畜猪堪饲；富裕千家君献功。\n"
	"\t\t\t燕衔喜信春光好；猪拱财门幸福长。\n"
	"\t\t\t爆竹升天送狗岁；春花遍地缀猪年。\n");
	cout<<"\t\t\t";cout<<"在";Sleep(100);cout<<"这";Sleep(100);cout<<"里";Sleep(100);cout<<"，";
	Sleep(100);cout<<"作";Sleep(100);cout<<"者";Sleep(100);cout<<"给";
	Sleep(100);cout<<"大";Sleep(100);cout<<"家";Sleep(300);getred;
	cout<<"  拜";Sleep(300);cout<<"  年";Sleep(300);cout<<"  啦！\n";
	system("pause");
	cout<<"1| 商店\n2| 挑战\n";
    cout<<"请选择:";
    int xzz=read();
	system("cls");
    if(xzz==2)
    {
    	cout<<"进入后，将会去挑战【年兽】，成功者可获得【年兽断角】与【年兽牙】\n";
		system("pause");
		cout<<"加载中...\n";
		ofstream fout("进入副本.txt");
		fout<<p.mz<<" "<<p.zsm<<" "<<p.sm<<" "<<p.gj<<" "<<p.fy<<" "<<p.mf<<endl;
		fout.close();
		system("spring_F");
		system("pause");
		ifstream fin("副本--主程序.txt");
		bool PD;
	    fin>>PD;
	    if(PD)
	    {
			int sj=rand()%4+1;
			if(sj==1)cout<<"获得年兽断角*1\n",dj[6].jc++;
			if(sj==2)cout<<"获得年兽牙*1\n",dj[7].jc++;
			if(sj==3)cout<<"获得年兽断角*1，年兽牙*1\n",dj[6].jc++,dj[7].jc++;
			if(sj==4)cout<<"什么也没获得\n";
		}
	    fin.close();
	    system("pause");
	}
	else
	{
		cout<<"1| 一袋金币(5个)  年兽断角:2\n";
		cout<<"2| 魔法石(魔法永久+5) 年兽断角:3\n";
		cout<<"3| 生命石(生命永久+30) 年兽断角:3\n";
		cout<<"4| 攻击石(攻击永久+5) 年兽牙:3\n";
    	cout<<"5| 退出\n";
    	cout<<"你的年兽断角:"<<dj[6].jc<<endl;
    	cout<<"你的年兽牙:"<<dj[7].jc<<endl;
    	cout<<"请选择:";
    	int xzz=read();
    	switch(xzz)
    	{
    		case 1:if(dj[6].jc>=2)dj[9].jc++,dj[6].jc-=2,cout<<"购买成功，进入背包查看\n";else cout<<"购买失败\n";break;
    		case 2:if(dj[6].jc>=3)dj[2].jc++,dj[6].jc-=3,cout<<"购买成功，进入背包查看\n";else cout<<"购买失败\n";break;
    		case 3:if(dj[6].jc>=3)dj[3].jc++,dj[6].jc-=3,cout<<"购买成功，进入背包查看\n";else cout<<"购买失败\n";break;
    		case 4:if(dj[7].jc>=3)dj[8].jc++,dj[7].jc-=3,cout<<"购买成功，进入背包查看\n";else cout<<"购买失败\n";break;
    		default:break;
		}
		system("pause");
	}
}
void BAG();
int main()
{
	srand(time(0));
    getwhite;
    int xz;
    chushihua();zh();
    system("pause");system("cls");
    cout<<"\t\t\t<造梦西游v2.9>\n";Sleep(1000);
    time_t now_time=time(0);
    struct tm*timeinfo;
    timeinfo=localtime(&now_time);
    year=1900+timeinfo->tm_year;
    month=1+timeinfo->tm_mon;
    day=timeinfo->tm_mday;
    hour=timeinfo->tm_hour;
    minute=timeinfo->tm_min;
    second=timeinfo->tm_sec;
    if(x1||syear!=year||smonth!=month||sday!=day)memset(qth,false,sizeof(qth)),ylsj=0;
    if(x1)cout<<"请输入你的昵称:",cin>>p.mz;
    cout<<"\t\t\t\n";
    if(x1)
    {
        getred;
        cout<<"1| 齐天大圣孙悟空\n";
        cout<<"攻击:***\n防御:**\n生命:***\n魔法:**\n";
        getyellow;
		cout<<"2| 天蓬元帅猪悟能\n";
		cout<<"攻击:*\n防御:****\n生命:****\n魔法:*\n";
		getgreen;
		cout<<"3| 卷帘大将沙悟净\n";
		cout<<"攻击:**\n防御:***\n生命:**\n魔法:***\n";
		getblue;
        cout<<"4| 三藏法师唐三藏\n";
        cout<<"攻击:****\n防御:*\n生命:*\n魔法:****\n";
        getwhite;
		cout<<"选择你的角色:"<<endl;
        cin>>p.js;
        cout<<"选择成功！！！"<<endl;
    }
    switch(p.js)
    {
        case 1:p.jsm=105;p.jmf=45;p.jgj=14;p.jfy=3;p.smcs=5;p.gjcs=2.5;p.fycs=0.9;break;
        case 2:p.jsm=120;p.jmf=40;p.jgj=10;p.jfy=5;p.smcs=6;p.gjcs=1.9;p.fycs=1.3;break;
        case 3:p.jsm=100;p.jmf=50;p.jgj=12;p.jfy=4;p.smcs=5;p.gjcs=2;p.fycs=1;break;
        case 4:p.jsm=80;p.jmf=55;p.jgj=16;p.jfy=2;p.smcs=4;p.gjcs=2.7;p.fycs=0.8;break;
    }
    if(hour>=7&&hour<=10)cout<<"上午好,";
    else if(hour>=5&&hour<=6)cout<<"早上好,";
    else if(hour==12||hour==11)cout<<"中午好,";
    else if(hour>=13&&hour<=18)cout<<"下午好,";
    else cout<<"晚上好,";cout<<p.mz<<endl;
    system("pause");
    while(1)
    {
        p.mf=p.jmf+p.mfzjc+p.zbmfjc;
        p.jyls=p.level*50;
        if(p.jy>=p.jyls)p.jy-=p.jyls,++p.level;
        p.jyls=p.level*50;
        p.sm=p.level*p.smcs+p.jsm+p.smzjc+p.zbsmjc;
        p.gj=p.level*p.gjcs+p.jgj+p.gjzjc+p.zbgjjc;
        p.fy=p.level*p.fycs+p.jfy+p.fyzjc+p.zbfyjc;
        p.zsm=p.sm;
        system("cls");
        if(zdbc)save();
        cout<<endl;
        getyellow;cout<<"\t\t     <造梦西游v2.9>\n\n";
        getwhite;
        cout<<"你的角色:"; 
        switch(p.js)
        {
        	case 1:getred;cout<<"齐天大圣孙悟空\n";break;
        	case 2:getyellow;cout<<"天蓬元帅猪悟能\n";break;
        	case 3:getgreen;cout<<"卷帘大将沙悟净\n";break;
        	case 4:getblue;cout<<"三藏法师唐三藏\n";break;
		}
        getgreen;cout<<p.mz<<"的等级:"<<p.level<<"\t";
        cout<<p.mz<<"的金币:"<<p.jb<<"\t";
        cout<<p.mz<<"的经验:"<<p.jy<<"/"<<p.jyls<<endl;
        getred;cout<<"\t\t-------------------------\n";
        cout<<"\t\t|";getblue;cout<<"\t1| 副本\t\t";getred;cout<<"|\n";
        cout<<"\t\t|";getblue;cout<<"\t2| 商店\t\t";getred;cout<<"|\n";
        cout<<"\t\t|";getblue;cout<<"\t3| BOSS领地\t";getred;cout<<"|\n";
        cout<<"\t\t|";getblue;cout<<"\t4| 活动与礼包\t";getred;cout<<"|\n";
        cout<<"\t\t|";getblue;cout<<"\t5| 保存并退出\t";getred;cout<<"|\n";
        cout<<"\t\t|";getred;cout<<"\t6| 帮助\t\t";getred;cout<<"|\n";
        cout<<"\t\t|";getblue;cout<<"\t7| 设置\t\t";getred;cout<<"|\n";
        cout<<"\t\t|";getblue;cout<<"\t8| 背包\t\t";getred;cout<<"|\n";
        cout<<"\t\t-------------------------\n";
        getpink;cout<<setw(30)<<"请选择:";
        getwhite;
        xz=read();
        int xxz;
        switch(xz)
        {
            case 1:
            {
                system("cls");
                cout<<"\t\t\t《副本》\n";
                for(int i=1;i<=5;i++)
                {
                    if(xg[i].sfkq)cout<<i<<"| "<<xg[i].mz<<endl;
                }
                cout<<"\n\n";
                cout<<"\t请选择:";
                xxz=read();
                ofstream fout("进入副本.txt");
                if(xxz%4==0)fout<<4<<" ";
                else fout<<xxz%4<<" ";
                fout<<p.mz<<" "<<p.zsm<<" "<<p.sm<<" "<<p.gj<<" "<<p.fy<<" "<<p.mf<<endl;
                fout.close();
                cout<<"加载中......\n";
                ifstream fin("副本--主程序.txt");
                switch(xxz)
                {
                    case 1:{system("1-4");fin>>pd;if(pd)p.jy+=30,p.jb+=2,xg[2].sfkq=true;break;}
                    case 2:{if(!xg[2].sfkq){cout<<"what are you doing?\n";system("pause");break;}system("1-4");fin>>pd;if(pd)p.jy+=50,p.jb+=3,xg[3].sfkq=true;break;}
                    case 3:{if(!xg[3].sfkq){cout<<"what are you doing?\n";system("pause");break;}system("1-4");fin>>pd;if(pd)p.jy+=70,p.jb+=4,xg[4].sfkq=true;break;}
                    case 4:{if(!xg[4].sfkq){cout<<"what are you doing?\n";system("pause");break;}system("1-4");fin>>pd;if(pd)p.jy+=80,p.jb+=4,xg[5].sfkq=true;break;}
                    case 5:{if(!xg[5].sfkq){cout<<"what are you doing?\n";system("pause");break;}system("5-8");fin>>pd;if(pd)p.jy+=90,p.jb+=5,xg[6].sfkq=true;break;}
                    default:{cout<<"what are you doing?\n";system("pause");break;}
                }
                fin.close();
                break;
            }
            case 2:{shop();break;}
            case 3:{if(p.level<5)cout<<"等级不足5级，稍后再来\n",system("pause");else choose_boss();break;}
            case 4:
                {
                    system("cls");
                    cout<<"1| 在线礼包\n2| 周末活动\n3| 春节活动\n";
                    int xxzz;
                    xxzz=read();
                    switch(xxzz)
                    {
                        case 1:{qd();break;}
                        case 2:{weekend();break;}
                        case 3:spring_F();break;
                        default:{cout<<"what are you doing?\n";system("pause");break;}
                    }
                    break;
                }
            case 5:{save();return 0;}
            case 6:{help();break;}
            case 7:
            {
                system("cls");
                cout<<"\t\t\t《设置》\n";
                cout<<"1| 技能设置\n2| 自动保存\n3| 返回\n";
                xxz=read();
                switch(xxz)
                {
                    case 1:
                    {
                        int jin1,jin2,jin3,jin4;
                        system("cls");
                        cout<<"\t\t\t《选择技能页面》\n";
                        for(int i=1;i<=10;i++)
                        {
                            cout<<i<<"| 名字:"<<jin[i].name<<"    耗魔:"<<jin[i].hm<<endl;
                        }
                        cout<<"\n\n《技能说明》\n";
                        printf( "灭神一击：造成2倍伤害\n"
                                "绿蔓缚：造成1倍伤害，并禁锢对手一回合\n"
                                "烈焰风暴：造成2倍伤害，并每回合扣除对手1*攻击的血量，持续三回合\n"
                                "天降甘露：回复40%的生命\n"
                                "紧箍咒：使对手在下两个回合内攻击力扣除50%\n"
                                "烈焰闪：使后3回合内闪避率变为50%\n"
                                "天眼标记：对敌人进行标记，使下一回合造成的伤害提高3倍\n"
                                "火魔九连斩：打出3倍伤害，并形成灼烧\n"
                                "火猿出击：打出4倍伤害，形成绿蔓缚\n"
                                "归魂神灭：打出5倍伤害，形成天眼标记，并有1%的几率秒杀对手\n");
                        cout<<"\n\n请选择4个技能带上阵(用空格分隔，如选择两个重复技能或选择没有的技能，后果自己承担！)：\n";
                        jin1=read();jin2=read();jin3=read();jin4=read();
                        ofstream fout("技能.txt");
                        fout<<jin1<<" "<<jin2<<" "<<jin3<<" "<<jin4<<endl;
                        break;
                    }
                    case 2:
                    {
                        int xzx;
                        cout<<"\n\n\t\t\t自动保存功能处于【";
                        if(zdbc)cout<<"开启";else cout<<"关闭";
                        cout<<"】状态\n";cout<<"是否开启/关闭？\n1| 是\n2| 否\n";
                        xzx=read();
                        if(xzx==1)zdbc=!zdbc,cout<<"\n\t\t\t成功！\n";
                        system("pause");
                        break;
                    }
                }
                break;
            }
            case 8:{BAG();break;}
            default:{cout<<"what are you doing?\n";system("pause");break;}
        }
    }
    return 0;
}
void BAG()
{
    system("cls");
    cout<<"以下为个人资料，看看就好\n";
    getgreen;cout<<p.mz<<"的等级:"<<p.level<<"\n"<<p.mz<<"的血量:"<<p.sm<<"\n"<<p.mz<<"的魔法:"<<p.mf<<"\n";
    cout<<p.mz<<"的攻击:"<<p.gj<<"\n"<<p.mz<<"的防御:"<<p.fy<<"\n"<<p.mz<<"的金币:"<<p.jb<<"\n";
    cout<<p.mz<<"的经验:"<<p.jy<<"/"<<p.jyls<<endl;
    getwhite;
    cout<<"进入背包按1\n返回主页按2\n请选择:";
    int xzx=read();
    if(xzx==2)return;
    system("cls");
    cout<<"\t\t当前武器【";
    if(nowwq=="silly")cout<<"空";
    else cout<<nowwq;
    cout<<"】加成为:"<<p.zbgjjc<<endl<<endl;
    cout<<"\t\t当前防具【";
    if(nowfj=="silly")cout<<"空";
    else cout<<nowfj;
    cout<<"】加成为:"<<p.zbfyjc<<endl<<endl;
    cout<<"\t\t当前饰品【";
    if(nowsp=="silly")cout<<"空";
    else cout<<nowsp;
    cout<<"】加成为:"<<p.zbsmjc<<endl<<endl;
    cout<<"\t\t\t<"<<p.mz<<"的东西>\n";
    struct BAAG{
        string mz;
        int jc,lx;
    }zsp[1001];
    int zjs=0;
    for(int i=1;i<=gjjs;i++)zsp[++zjs].mz=gjzb[i].mz,zsp[zjs].jc=gjzb[i].jc,zsp[zjs].lx=1;
    for(int i=1;i<=fyjs;i++)zsp[++zjs].mz=fyzb[i].mz,zsp[zjs].jc=fyzb[i].jc,zsp[zjs].lx=2;
    for(int i=1;i<=spjs;i++)zsp[++zjs].mz=spzb[i].mz,zsp[zjs].jc=spzb[i].jc,zsp[zjs].lx=3;
    for(int i=1;i<=100;i++)if(dj[i].jc!=0)zsp[++zjs].mz=dj[i].mz,zsp[zjs].jc=dj[i].jc,zsp[zjs].lx=4;
    for(int i=1;i<=zjs;i++)
    {
        if(i<=gjjs+fyjs+spjs)cout<<i<<"| "<<zsp[i].mz<<"\t加成:"<<zsp[i].jc<<endl;
        else cout<<i<<"| "<<zsp[i].mz<<"\t数量:"<<zsp[i].jc<<endl;
    }
    cout<<zjs+1<<"| 返回\n";
    cout<<"请选择进行装备或使用:\n";
    xzx=read();
    if(xzx==zjs+1)return;
    switch(zsp[xzx].lx)
    {
        case 1:{nowwq=zsp[xzx].mz,p.zbgjjc=zsp[xzx].jc;break;}
        case 2:{nowfj=zsp[xzx].mz,p.zbfyjc=zsp[xzx].jc;break;}
        case 3:{nowsp=zsp[xzx].mz,p.zbsmjc=zsp[xzx].jc;break;}
        case 4:
        {
            if(zsp[xzx].mz=="BOSS结晶"){c3;goto X;}
            if(zsp[xzx].mz=="周末积分"){c3;goto X;}
            if(zsp[xzx].mz=="年兽断角"){c3;goto X;}
            if(zsp[xzx].mz=="年兽牙"){c3;goto X;}
            if(zsp[xzx].mz=="魔法石")p.mfzjc+=5,dj[2].jc--;
            if(zsp[xzx].mz=="生命石")p.smzjc+=30,dj[3].jc--;
            if(zsp[xzx].mz=="攻击石")p.gjzjc+=5,dj[8].jc--;
            if(zsp[xzx].mz=="一袋金币")p.jb+=5,dj[9].jc--;
            if(zsp[xzx].mz=="角色更换卡")
            {
                dj[5].jc--;
                system("cls");
                cout<<"放心选，不会从头开始的\n";
                getred;
			    cout<<"1| 齐天大圣孙悟空\n";
			    cout<<"攻击:***\n防御:**\n生命:***\n魔法:**\n";
			    getyellow;
				cout<<"2| 天蓬元帅猪悟能\n";
				cout<<"攻击:*\n防御:****\n生命:****\n魔法:*\n";
				getgreen;
				cout<<"3| 卷帘大将沙悟净\n";
				cout<<"攻击:**\n防御:***\n生命:**\n魔法:***\n";
				getblue;
			    cout<<"4| 三藏法师唐三藏\n";
			    cout<<"攻击:****\n防御:*\n生命:*\n魔法:****\n";
			    getwhite;
				cout<<"重新选择你的角色:"<<endl;
			    cin>>p.js;
			    switch(p.js)
				{
				    case 1:p.jsm=105;p.jmf=45;p.jgj=14;p.jfy=3;p.smcs=5;p.gjcs=2.5;p.fycs=0.9;break;
				    case 2:p.jsm=120;p.jmf=40;p.jgj=10;p.jfy=5;p.smcs=6;p.gjcs=1.9;p.fycs=1.3;break;
				    case 3:p.jsm=100;p.jmf=50;p.jgj=12;p.jfy=4;p.smcs=5;p.gjcs=2;p.fycs=1;break;
				    case 4:p.jsm=80;p.jmf=55;p.jgj=16;p.jfy=2;p.smcs=4;p.gjcs=2.7;p.fycs=0.8;break;
				}
			}
            break;
        }
    }
    cout<<"成功！\n";
    X:system("pause");
}
