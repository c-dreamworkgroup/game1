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
int sm,gj,fy,mf;//������������������ħ��
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
    ifstream fin("���븱��.txt");
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
    printf("��BOSS��顿\n"
			"����,�Ŵ��񻰴�˵�еĶ���\n"
			"����û�ص㡿\n"
			"δ֪\n"
			"�����ܽ��ܡ�\n"
			"��¾֮�ǣ���ͷ�����ǵ���ǰ������ǰ�����档\n"
			"�˻ľ�������ŭ�𣬵ض�ɽҡ��ѣ����Ҳ�����˺���\n"
			"�������䣺���������߿���ʯ��������ҡ�\n"
			"�����޼�(����)�����������Ƴɵ��޼ף��ܹ�����30%���˺���\n"
			"��������Ʒ��\n"
			"���޶Ͻ�:0~1\n"
			"������:0~1\n");
    while(dx>0&&sm>0)
    {
        system("pause");
        system("cls");
        cout<<"\t\t\t��δ֪֮�ء�\n";
        if(zs>0)
        {
            cout<<"�����ܵ�"<<gj*tybj*0.7<<"�������˺�\n";
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
					cout<<"���ܳɹ�\n\n";
					goto SB;
				}
				lys--;
			}
            sj=rand()%3+1;
            switch(sj)
            {
                case 1:{cout<<"����ʹ������¾֮�ǣ����������"<<(gj1-fy>0?gj1-fy:1)<<"���˺�\n";sm-=gj1-fy>0?gj1-fy:1;break;}
                case 2:
                {
                    cout<<"����ʹ���˰˻ľ��𣬶��������"<<(gj2-fy>0?gj2-fy:1)<<"���˺�\n";sm-=gj2-fy>0?gj2-fy:1;
                    cout<<"��ʹ��ѣ��1�غ�\n";xy=true;
                    break;
                }
                case 3:
                {
                    int a;
                    a=rand()%5+1;
                    cout<<"����ʹ������������\n";
					for(int i=1;i<=7;i++)cout<<"���������"<<(gj3-fy>0?gj3-fy:1)<<"���˺�\n",sm-=gj3-fy>0?gj3-fy:1;
                }
            }
        }
        SB:if(lmf)lmf=false;
        mf+=5;
        if(sm<1)
        {
        	ofstream fout("����--������.txt");
            cout<<"���޽�������!\n";fout<<"0"<<endl;
            fout.close();
            return 0;
        }
        if(dx<1)
        {
        	ofstream fout("����--������.txt");
            cout<<"�㽫���޴����!\n";fout<<"1"<<endl;
            fout.close();
            return 0;
        }
		getgreen;
       	if(dx<=zdx/2)getyellow;
       	if(dx<=zdx/4)getred;
		cout<<"��������:"<<dx;
		getgreen;
		if(sm<=zsm/2)getyellow;
		if(sm<=zsm/4)getred;
		cout<<"\t"<<name<<"����:"<<sm<<"\t";
		getblue;
		cout<<name<<"ħ��:"<<mf<<endl;
		getwhite;
		if(xy)
		{
		    cout<<"�㴦��ѣ��״̬���޷�����!\n";
		    xy=false;
		}
		else
		{
	        cout<<"1����ͨ����\n";
	        cout<<"2��ʹ�ü���\n";
	        cout<<"3������\n";
	        cout<<"\t\n\t\t��ѡ��:";
	        xz=read();
	        int xxz;
	        switch(xz)
	        {
	            case 1:{cout<<"��Ե��������"<<gj*tybj*0.7<<"���˺�\n";dx-=gj*tybj*0.7;tybj=1;break;}
	            case 2:
	            {
	            	int hsm=0,sh=0;
	            	ofstream fout("���ܴ���.txt");
	            	fout<<zsm<<" "<<lmf<<" "<<zs<<" "<<hsm<<" "<<jgz<<" "<<lys<<" "<<tybj<<" "<<sh<<" "<<mf<<" "<<gj<<endl;
	            	fout.close();
	            	system("ѡ����");
	            	ifstream fin("���ܴ���.txt");
	    			fin>>zsm>>lmf>>zs>>hsm>>jgz>>lys>>tybj>>sh>>mf>>gj;
	    			fin.close();
	    			dx-=sh*0.7;
	    			sm+=hsm;
	                break;
	            }
	            case 3:
	            {
	            	ofstream foutt("����--������.txt");
	                foutt<<"0"<<endl;
	                foutt.close();
	            }
	        }
	    }
	}
	ofstream fout("����--������.txt");
    if(dx<1)
    {
        cout<<"��սʤ������!\n";
        fout<<"1"<<endl;
        return 0;
    }
    else cout<<"���޽�������!\n",fout<<"0"<<endl;
	fout.close();
    return 0;
}
