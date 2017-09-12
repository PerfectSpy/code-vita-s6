#include <stdio.h>
int d1(int a[])
    {
        int i,j;
        for(i=2;i>=0;i--)
            {
                for(j=0;j<9;j++)
                    {
                        if(a[j]==i)
                            {
                                a[j]=-1;
                                return i;
                            }
                    }
            }
        return -1;
    }
int d2(int a[],int first,int chk)
    {
        int i,j;
        if(first==0||first==1)
            {
            for(i=9;i>=0;i--)
            {
                for(j=0;j<9;j++)
                    {
                        if(a[j]==i)
                            {
                                a[j]=-1;
                                return i;
                            }
                    }
            }
        return -1;
            }
        else
            {
                for(i=4;i>=0;i--)
                    {
                        for(j=0;j<9;j++)
                        {
                            if(a[j]==i&&a[j]!=4)
                                {
                                    a[j]=-1;
                                    return i;
                                }
                            if(a[j]==i&&a[j]==4)
                                {
                                    if(chk==1)
                                        {
                                        a[j]=-1;
                                        return i;
                                        }
                                }
                       }
                        
                    }
                return -1;
            }
    }
int d3(int a[],int over)
    {
        int i,j;
        if(over==1)
            return 0;
        for(i=5;i>=0;i--)
            {
                for(j=0;j<9;j++)
                    {
                        if(a[j]==i)
                            {
                                a[j]=-1;
                                return i;
                            }
                    }
            }
        return -1;
    }
int d4(int a[],int over)
    {
        int i,j;
        if(over==1)
            return 0;
        for(i=9;i>=0;i--)
            {
                for(j=0;j<9;j++)
                    {
                        if(a[j]==i)
                            {
                                a[j]=-1;
                                return i;
                            }
                    }
            }
        return -1;
    }
int main() {
	int i,a[9],j,zr=0,chk=0,over=0,fault=0,res[6],tpr;
	char ch;
	for(i=0;i<9;i++)
	    {
	    scanf("%d%c",&a[i],&ch);
	    if(a[i]==0)
	        chk++;
	    }
        
    for(i=0;i<9;i++)
    {
        if(a[i]!=0)
            {
            zr=1;
            break;
            }
    }
    if(zr==0)
        fault=1;
        
    for(i=0;i<6;i++)
        {
            if(i==0)
                {
                    tpr=d1(a);
                    if(tpr==-1)
                        {
                            fault=1;
                            break;
                        }
                    else
                        {
                            res[i]=tpr;
                        }
                }
            else if(i==1)
                {
                    if(chk>=4)
                        {
                        chk=1;
                        over=1;
                        }
                    else
                        chk=0;
                    tpr=d2(a,res[0],chk);
                    if(tpr==-1)
                        {
                            fault=1;
                            break;
                        }
                    else
                        {
                            res[i]=tpr;
                        }

                }
            else if(i==2)
                {
                    tpr=d3(a,over);
                    if(tpr==-1)
                        {
                            fault=1;
                            break;
                        }
                    else
                        {
                            res[i]=tpr;
                        }

                }
            else if(i==3)
                {
                    tpr=d4(a,over);
                    if(tpr==-1)
                        {
                            fault=1;
                            break;
                        }
                    else
                        {
                            res[i]=tpr;
                        }

                }
            else if(i==4)
                {
                    tpr=d3(a,over);
                    if(tpr==-1)
                        {
                            fault=1;
                            break;
                        }
                    else
                        {
                            res[i]=tpr;
                        }

                }
            else if(i==5)
                {
                    tpr=d4(a,over);
                    if(tpr==-1)
                        {
                            fault=1;
                            break;
                        }
                    else
                        {
                            res[i]=tpr;
                        }

                }
        }
        
    if(fault==0)
    {
        for(i=0;i+1<4;i+=2)
            printf("%d%d:",res[i],res[i+1]);
        printf("%d%d",res[4],res[5]);
    }
    else
        printf("Impossible");
	return 0;
}
