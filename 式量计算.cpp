#include<cstdio>
#include<cstring>
#define N 40
#define ERR -1
char name[N][3]={"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca",
	"Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr"};
double weight[N]={1,4,7,9,11,12,14,16,19,20,23,24,27,28,31,32,35.5,40,39,40,
	45,48,51,52,55,56,59,59,64,65,70,73,75,79,80,84,85.5,88,89,91};
char s[100];
double ans;
int num,i;
int find(int l,int len)//找到元素符号所对应的序号（非原子序数）
{
	char s1[100];
	strcpy(s1,s+l);
	s1[len]=0;
	for(int i=0;i^N;++i)
		if(!strcmp(s1,name[i]))return i;
	return ERR;
}
double func(int l,int r)//求左闭右开区间[l,r)的式量
{
	double ans=0,w;
	int x,num,t;
	while(l<r)
	{
		if(s[l]>='A'&&s[l]<='Z')
		{
			for(x=1;s[l+x]>='a'&&s[l+x]<='z';++x);
			num=find(l,x);
			if(num<0)return ERR;
			l+=x;
			w=weight[num];
		}
		else if(s[l]=='(')
		{
			for(x=l,num=0;x<r;++x)
			{
				if(s[x]=='(')++num;
				else if(s[x]==')')--num;
				if(!num)
				{
					w=func(l+1,x);
					l=x+1;
					if(w<0)return ERR;
					break;
				}
			}
			if(num)return ERR;
		}
		else return ERR;
		if(s[l]>='0'&&s[l]<='9')
		{
			t=0;
			for(;s[l]>='0'&&s[l]<='9';++l)t=t*10+s[l]-'0';
		}
		else t=1;
		ans+=t*w;
	}
	return ans;
}
int main()
{
	while(1)
	{
		scanf("%s",s);
		ans=num=i=0;
		for(;s[i]>='0'&&s[i]<='9';++i)num=num*10+s[i]-'0';
		if(!num)num=1;
		if(func(i,strlen(s))>=0)printf("%.1lf\n",func(i,strlen(s))*num);
		else printf("ERROR\n");
	}
	return 0;
}
