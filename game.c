/********************************************/
/* ���´���Ϊ�����ļ��������ѧԺ��������ϵ */
/* ��Ϸ�����������05482�࣬����һ���Ա����*/
/* δ������������ɾ�ġ�����������Υ�ߣ��� */
/* �Ը���                                   */
/********************************************/



/********************************************/
/* ����Ϊͷ�ļ�����                         */
/********************************************/
/*��ʾ������ͷ�ļ���*/
#include "graphics.h"
/*��������ͷ�ļ���*/
#include "stdio.h"
/*DOSϵͳ����ͷ�ļ���*/
#include "dos.h"
#include "fcntl.h"
#include "io.h"
/*�Զ���С�ӿ�*/
#include "ziku.c"
/*�Զ������ɨ���뿪����*/
#include "mykey.h"
/*�Զ���ʱ�亯����*/
#include "mytime.h"
/*�ַ���ͷ�ļ�������*/
#include "string.h"
/*������������SVGA640x480x256��������2*/
#define SVGA640x480x256 2 


/*�������̵�ͼͼƬ���飬���ڴ洢ͼƬ·������Ļ���Ͻǿ�ʼ��һ���ͼ01-01*/
char * bmpdir[10][10]=
{{
"bmp\\tp-01-01.bmp","bmp\\tp-01-02.bmp","bmp\\tp-01-03.bmp","bmp\\tp-01-04.bmp",\
"bmp\\tp-01-05.bmp","bmp\\tp-01-06.bmp","bmp\\tp-01-07.bmp","bmp\\tp-01-08.bmp",\
"bmp\\tp-01-09.bmp","bmp\\tp-01-10.bmp"},{"bmp\\tp-02-01.bmp","bmp\\tp-02-02.bmp",\
"bmp\\tp-02-03.bmp","bmp\\tp-02-04.bmp","bmp\\tp-02-05.bmp","bmp\\tp-02-06.bmp",\
"bmp\\tp-02-07.bmp","bmp\\tp-02-08.bmp","bmp\\tp-02-09.bmp","bmp\\tp-02-10.bmp"},{\
"bmp\\tp-03-01.bmp","bmp\\tp-03-02.bmp","bmp\\tp-03-03.bmp","bmp\\tp-03-04.bmp",\
"bmp\\tp-03-05.bmp","bmp\\tp-03-06.bmp","bmp\\tp-03-07.bmp","bmp\\tp-03-08.bmp",\
"bmp\\tp-03-09.bmp","bmp\\tp-03-10.bmp"},{"bmp\\tp-04-01.bmp","bmp\\tp-04-02.bmp",\
"bmp\\tp-04-03.bmp","bmp\\tp-04-04.bmp","bmp\\tp-04-05.bmp","bmp\\tp-04-06.bmp",\
"bmp\\tp-04-07.bmp","bmp\\tp-04-08.bmp","bmp\\tp-04-09.bmp","bmp\\tp-04-10.bmp"},{\
"bmp\\tp-05-01.bmp","bmp\\tp-05-02.bmp","bmp\\tp-05-03.bmp","bmp\\tp-05-04.bmp",\
"bmp\\tp-05-05.bmp","bmp\\tp-05-06.bmp","bmp\\tp-05-07.bmp","bmp\\tp-05-08.bmp",\
"bmp\\tp-05-09.bmp","bmp\\tp-05-10.bmp"},{"bmp\\tp-06-01.bmp","bmp\\tp-06-02.bmp",\
"bmp\\tp-06-03.bmp","bmp\\tp-06-04.bmp","bmp\\tp-06-05.bmp","bmp\\tp-06-06.bmp",\
"bmp\\tp-06-07.bmp","bmp\\tp-06-08.bmp","bmp\\tp-06-09.bmp","bmp\\tp-06-10.bmp"},{\
"bmp\\tp-07-01.bmp","bmp\\tp-07-02.bmp","bmp\\tp-07-03.bmp","bmp\\tp-07-04.bmp",\
"bmp\\tp-07-05.bmp","bmp\\tp-07-06.bmp","bmp\\tp-07-07.bmp","bmp\\tp-07-08.bmp",\
"bmp\\tp-07-09.bmp","bmp\\tp-07-10.bmp"},{"bmp\\tp-08-01.bmp","bmp\\tp-08-02.bmp",\
"bmp\\tp-08-03.bmp","bmp\\tp-08-04.bmp","bmp\\tp-08-05.bmp","bmp\\tp-08-06.bmp",\
"bmp\\tp-08-07.bmp","bmp\\tp-08-08.bmp","bmp\\tp-08-09.bmp","bmp\\tp-08-10.bmp"},{\
"bmp\\tp-09-01.bmp","bmp\\tp-09-02.bmp","bmp\\tp-09-03.bmp","bmp\\tp-09-04.bmp",\
"bmp\\tp-09-05.bmp","bmp\\tp-09-06.bmp","bmp\\tp-09-07.bmp","bmp\\tp-09-08.bmp",\
"bmp\\tp-09-09.bmp","bmp\\tp-09-10.bmp"},{"bmp\\tp-10-01.bmp","bmp\\tp-10-02.bmp",\
"bmp\\tp-10-03.bmp","bmp\\tp-10-04.bmp","bmp\\tp-10-05.bmp","bmp\\tp-10-06.bmp",\
"bmp\\tp-10-07.bmp","bmp\\tp-10-08.bmp","bmp\\tp-10-09.bmp","bmp\\tp-10-10.bmp"}};

/*��������ͼƬ�������ڴ洢ͼƬ·������0��ʼ 0��ͼ 1��� 2���� 3�쳵 4���� 5���� 6��ʿ 7��˧ */
/*8���� 9���� 10���� 11���� 12���� 13��ʿ 14����*/
char *qizi[15]={"bmp\\0.bmp","bmp\\1.bmp","bmp\\2.bmp","bmp\\3.bmp","bmp\\4.bmp","bmp\\5.bmp",\
"bmp\\6.bmp","bmp\\7.bmp","bmp\\8.bmp","bmp\\9.bmp","bmp\\10.bmp","bmp\\11.bmp",\
"bmp\\12.bmp","bmp\\13.bmp","bmp\\14.bmp"};

/*���忪ʼ�˵�ͼƬ�������ڴ洢ͼƬ·��*/
char *select1[7]={"bmp\\bujian.bmp","bmp\\kaishi.bmp","bmp\\duqu.bmp","bmp\\caozuo.bmp","bmp\\youxi.bmp","bmp\\zhizuo.bmp",\
"bmp\\tuichu.bmp"};

/*�����Ա��ͼƬ�������ڴ洢ͼƬ·��*/
char *cybiao[7]={"bmp\\cy01.bmp","bmp\\cy02.bmp","bmp\\cy03.bmp","bmp\\cy04.bmp","bmp\\cy05.bmp","bmp\\cy06.bmp",\
"bmp\\cy07.bmp"};

/*����浵�ļ��������ڴ洢�浵�ļ�·��*/
char *savedir[5]={"save\\save00.dat","save\\save01.dat","save\\save02.dat","save\\save03.dat","save\\save04.dat"};

/*������Ϸ����ͼƬ�������ڴ洢ͼƬ·��*/
char *help2[12]={"help\\guize01.bmp","help\\guize02.bmp","help\\guize03.bmp","help\\guize04.bmp","help\\guize05.bmp","help\\guize06.bmp","help\\guize07.bmp","help\\guize08.bmp","help\\guize09.bmp","help\\guize10.bmp","help\\guize11.bmp"};


/*������Ϸ����ͼƬ�������ڴ洢ͼƬ·��*/
char *loadbmp[5]={"","bmp\\save01.bmp","bmp\\save02.bmp","bmp\\save03.bmp","bmp\\save04.bmp"};






/*����������Ϸϵͳ���õĽṹ�壬������3����Ա��X��¼X���� Y��¼Y���� T ��¼��X��Y��λ�õ�����*/
struct system1{
int xy[9][10];
int x;
int y;
int t;
}qipan[9][10],shu[9][10];

/*����SX���X SY���Y KONG �������ܱ��� TX TY ��ʱλ�õ�XY*/
/*HLZ �жϸ����ķ��ߵı���1Ϊ���� -1Ϊ���� */
/*HLC Ϊ��ŵ����ݣ�ʱ�䣩LLCΪ���ŵ�*/
/*LOΪ�浵ָ���־*/
/*MEΪ�˵�ѡ��ָ���־*/
int sx,sy,kong,tx,ty,hlz=1,hlc=910,llc=900,lo=5,me=1,huiqi=0,firstplay=1;
/*AUTOSAVEΪ�浵����*/
int autosave[95];
int savefile[5][95];

/*���õ�ɫ��*/
typedef unsigned char DacPalette256[256][3];
void setvgapalette256(DacPalette256*PalBuf)
{
    struct REGPACK reg ;
    reg.r_ax=0x1012 ;
    reg.r_bx=0 ;
    reg.r_cx=256 ;
    reg.r_es=FP_SEG(PalBuf);
    reg.r_dx=FP_OFF(PalBuf);
    intr(0x10,&reg);
}
int huge Return_SVGA256(void)
{
    return(SVGA640x480x256);
}

/*ͼ�������������ͼ��*/
int tuxiang(int x0,int y0,int fp)
{
    int width,height,i=0,j=0;
    unsigned char fix,*buffer,pix24b[4];
     DacPalette256 dac256 ;
    lseek(fp,18,SEEK_SET);
    read(fp,&width,4);
    read(fp,&height,4);
    fix=(width%4)?(4-width%4):0 ;

    lseek(fp,54,SEEK_SET);
    for(i=0;i<256;i+=1)
    {
        read(fp,pix24b,4);
        dac256[i][0]=pix24b[2]>>2 ;
        dac256[i][1]=pix24b[1]>>2 ;
        dac256[i][2]=pix24b[0]>>2 ;
    }
    setvgapalette256(&dac256);
    buffer=(unsigned char*)malloc(width);
    for(j=height-1;j>=0;j-=1)
    {
        read(fp,buffer,width);
        lseek(fp,fix,SEEK_CUR);
        for(i=0;i<width;i++)
         {
/*�����㷨1 if (buffer[i]==30)continue;  �жϣ�����õ���ɫΪ�ۺ�ɫ��ֵΪ30��*/
/*��ô�Ͳ����������㷨����͸������*/
         if (buffer[i]==30)continue;
        putpixel(x0+i,y0+j,buffer[i]);
        }
    }
    
    free(buffer);

}

/*PLAYBOX��˾��־�������*/
void logo1()
{int fp;
  if((fp=open("bmp\\logo1.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
     tuxiang(0,0,fp);
     close(fp);

}

/*���ݼ��㺯��*/
void liangshi()
{if (hlz==1)
{hlc--;
liang(hlc); }
if (hlz==-1)
{llc--;
liang(llc);
}

}






/*��������ʼ*/


main()
{

 /*�������õ��ĺ���*/
 void initgraph1();
  int initqipan();
  void initqizi();
  void topb(int n);
  void liangshi();
  int loadmenu1();
  void load1(int n);
  void save1(int n);
  int chengyuan();
  void autosavesub();
  void autoloadsub();
  int menu1();
  int liang(int liang);
  int over1();
  int help3();
  int win1();
  void putword(char *mat,int matsize,int x,int y,int color);
  int he,fp;

  /*��ʼ��ͼ��ģʽSVGA256X640X480X256*/
  initgraph1();
  /*����ʱ�亯����ÿ��19����λʱ�����һ�����ݼ��㺯��*/
  chuangtimer(19,liangshi);

  logo1();
  getch();
/*���뿪ʼ�˵���ѡ����Ŀ*/
 while(1)
 {
 if (huiqi!=1)
 me=menu1();
 if(me==6)break;

 if(me==1)
 {
 lo=5;
 }
 else if (me==2)
 {int i;
 i=loadmenu1();
 load1(i);
 lo=i;

 }

 if (me==4)
 {cleardevice();
 help3();
 continue;
 }


  if (me==3)
  { cleardevice();
   if((he=open("help\\help1.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
      tuxiang(0,0,he);
    close(he);
    getch();
    if((he=open("help\\help2.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
      tuxiang(0,0,he);
    close(he);
    getch();


     cleardevice();
   continue;
  }
 if(me==5)
 {
 chengyuan();
 continue;
 }
  cleardevice();




  while(1)
  {int ov1;

   initqipan();

   if (huiqi==1)
   {
   break;
   }
   ov1=over1();
   if(ov1==0)
   {cleardevice();
   break;}
   else if (ov1==1) lo=5;


  }
  }

  cleardevice();
  if((fp=open("bmp\\thanks.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
    tuxiang(0,0,fp);
    close(fp);

    getch();
  closegraph();


}
/*��ʼ��ͼ��ģʽ����*/
void initgraph1()
{
int width,height,gr=DETECT,mo=0,fp,i,j;
    int tuxiang(int x0,int y0,int fp);

    installuserdriver("Svga256",Return_SVGA256);
    initgraph(&gr,&mo,"");


}


/*��ʼ�����̺���*/
int initqipan()
{
    int width,height,fp,x=0,y=42,i,j,sb;


    /*�Ƚ����������������*/
     for (i=0;i<9;i++)
     {
      for (j=0;j<10;j++)
      {
      qipan[i][j].t=0;
      qipan[i][j].x=j*64;
      qipan[i][j].y=i*48+42;

       }
       if (x==640)x=0;

     }

     x=0,y=42;
   /*�������ͼƬ*/

    fp=open("bmp\\back.bmp",O_RDONLY|O_BINARY);
 tuxiang(0,0,fp);
    close(fp);


      if(firstplay==1) 
    getch();
    firstplay=0;
    /*�����ӷ����������ϣ�LOĬ��Ϊ0����ʾ������ʼ2��3��4��5��ʾ����*/
    initqizi(lo);




    /*�������ϵĸ����*/
    for (i=0;i<9;i++)
    {

    for (j=0;j<10;j++)
    {

      if((fp=open(bmpdir[i][j],O_RDONLY|O_BINARY))==-1)
     {
        puts("Cannot find file " "map_256.bmp" ".");

      }


      tuxiang(x,y,fp);
      close(fp);
       x=x+64;


      if (x==640)x=0;



    }
    y=y+48;
    }



       x=0,y=42;



    /*��������*/
       for (i=0;i<9;i++)
     {

     for (j=0;j<10;j++)
     {

      if((fp=open(qizi[qipan[i][j].t],O_RDONLY|O_BINARY))==-1)
     {
        puts("Cannot find file " "bmp" ".");

      }

      tuxiang(qipan[i][j].x,qipan[i][j].y,fp);
      close(fp);


      }
      }


 /**************���½�����Ϸ��������**************/




/*�����ͼƬ�ѵ�ַ���SB*/
 if((sb=open("bmp\\sb.bmp",O_RDONLY|O_BINARY))==-1)
     {
        puts("Cannot find file " "bmp" ".");

      }
  sx=5;
  sy=4;

 while(1){
/*���ж������Ƿ���ʤ��*/
 if (win1()==1)
 {
   if((fp=open("bmp\\redwin.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
      tuxiang(135,180,fp);
    close(fp);

   getch(); getch();
   return 1;
 }
  if (win1()==-1)
 {
   if((fp=open("bmp\\bluewin.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
      tuxiang(135,180,fp);
    close(fp);
   getch();  getch();
   return -1;
 }

   tx=sx;
   ty=sy;


/*���ʣ�����ݣ���ʱ�䣩*/
    putword(liang16H,16,25+360,13,0);
     putword(cao16H,16,50+360,13,0);
      putword(sheng16H,16,75+360,13,0);
     putword(yu16H,16,100+360,13,0);

  if (hlz==1)
  liang(hlc);
  else if (hlz==-1)
  liang(llc);






  if (hlz==1)
 {
   putword(hong24H,24,25,11,218);
   putword(fang24H,24,50,11,218);
   putword(zhi24H,24,75,11,218);
   putword(zi24H,24,100,11,218);

 }
 else if (hlz==-1)
 {

   putword(lan24H,24,25,11,240);
   putword(fang24H,24,50,11,240);
   putword(zhi24H,24,75,11,240);
   putword(zi24H,24,100,11,240);
  }
/*��ʼ����ʱ��*/
 kaishitimer();

 /*���ܼ��̰����������ֵ�����MYKEY.H��*/
   kong=mykeyscan();

   if (kong==KEYESC){return 0; }

   else if (kong==KEYW||kong==KEYS8)

   sy=sy-1;

   else if (kong==KEYS||kong==KEYS5||kong==KEYS2)

    sy=sy+1;
   else if (kong==KEYA||kong==KEYS4)

   sx=sx-1;
   else if (kong==KEYD||kong==KEYS6)

   sx=sx+1;

   else if (kong==KEYJ||kong==KEYS0);

   else if (kong==KEYF1)save1(1);

   else if (kong==KEYF2)save1(2);

   else if (kong==KEYF3)save1(3);

   else if (kong==KEYF4)save1(4);

   else if (kong==KEYF5)
   {huiqi=1;
      return 1;
   }

   else if (kong==KEYF8)
   {save1(loadmenu1());
    huiqi=1;
      return 1;
   }
   else continue;

   if (sy>8)sy=0;
   else if (sy<0)sy=8;
   if (sx<0)sx=9;
   else if (sx>9)sx=0;



/*����Ϊѡ�����Ӻ����ӹ���*/









   if ((kong==KEYJ||kong==KEYS0)&&qipan[ty][tx].t!=0)
   {
     int tempsx,tempsy,tempt,temptx,tempty;
     tempt=qipan[ty][tx].t;
     temptx=tx;
     tempty=ty;
 /*����Ϊ��������*/


     if((fp=open(bmpdir[ty][tx],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
      tuxiang(qipan[ty][tx].x,qipan[ty][tx].y,fp);
    close(fp);
   tuxiang(qipan[sy][sx].x,qipan[sy][sx].y,sb);
   if((fp=open(qizi[qipan[ty][tx].t],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
     tuxiang(qipan[ty][tx].x,qipan[ty][tx].y,fp);
     close(fp);




 /*�������Ӻ�����µ�ѭ��*/
    while(1){
     kaishitimer();
    topb(2);
   tx=sx;
   ty=sy;

/*���ܼ��̰���,ͬ��*/
   kong=mykeyscan();

   if (kong==KEYESC){return 0; }

   else if (kong==KEYW||kong==KEYS8)

   sy=sy-1;

   else if (kong==KEYS||kong==KEYS5||kong==KEYS2)

    sy=sy+1;
   else if (kong==KEYA||kong==KEYS4)

   sx=sx-1;
   else if (kong==KEYD||kong==KEYS6)

   sx=sx+1;

   else if (kong==KEYF1)save1(1);

   else if (kong==KEYF2)save1(2);

   else if (kong==KEYF3)save1(3);

   else if (kong==KEYF4)save1(4);



   else if (kong==KEYJ||kong==KEYS0)
   { int pd=0;

    /*����Ϊ�ж��������*/


   /*������ұ�*/
   if (tempt==1&&hlz==1)
    {
        if (sx>=5&&sx<=9)
    {
   /*��������*/
    if (((sx-1==temptx&&sy==tempty)||(sy-1==tempty&&sx==temptx)||(sy+1==tempty&&sx==temptx))&&(qipan[sy][sx].t==0||qipan[sy][sx].t>=8&&qipan[sy][sx].t<=14)){ pd=1;hlz=-1; }
      }
        else if ((sx-1==temptx&&sy==tempty)&&(qipan[sy][sx].t==0||qipan[sy][sx].t>=8&&qipan[sy][sx].t<=14))
    {
        pd=1;
        hlz=-1;
    }
    }
   /*�����ӱ�*/
    if (tempt==8&&hlz==-1)
    {
        if (sx>=0&&sx<=4)
    {
    /*�������ұ�*/
    if (((sx+1==temptx&&sy==tempty)||(sy+1==tempty&&sx==temptx)||(sy-1==tempty&&sx==temptx))&(qipan[sy][sx].t==0||qipan[sy][sx].t>=1&&qipan[sy][sx].t<=7)){ pd=1; hlz=1;  }
      }
        else if ((sx+1==temptx&&sy==tempty)&&(qipan[sy][sx].t==0||qipan[sy][sx].t>=1&&qipan[sy][sx].t<=7))
    {
        pd=1;
        hlz=1;
    }
    }


     /*�콫*/
    if (tempt==7&&hlz==1)
    {
     if (((sx+1==temptx&&sy==tempty)||(sx-1==temptx&&sy==tempty)||(sy-1==tempty&&sx==temptx)||(sy+1==tempty&&sx==temptx)) &&(qipan[sy][sx].t==0||qipan[sy][sx].t>=8&&qipan[sy][sx].t<=14))
    {


         if ((sy==3&&sx==0)||(sy==3&&sx==1)||(sy==3&&sx==2)||(sy==4&&sx==0)||(sy==4&&sx==1)||(sy==4&&sx==2)||(sy==5&&sx==0)||(sy==5&&sx==1)||(sy==5&&sx==2))
       { pd=1;
        hlz=-1;
        }
    }
    }
    /*����*/
       if (tempt==14&&hlz==-1)
    {
     if (((sx+1==temptx&&sy==tempty)||(sx-1==temptx&&sy==tempty)||(sy-1==tempty&&sx==temptx)||(sy+1==tempty&&sx==temptx)) &&(qipan[sy][sx].t==0||qipan[sy][sx].t>=1&&qipan[sy][sx].t<=7))
    {


         if ((sy==3&&sx==7)||(sy==3&&sx==8)||(sy==3&&sx==9)||(sy==4&&sx==7)||(sy==4&&sx==8)||(sy==4&&sx==9)||(sy==5&&sx==9)||(sy==5&&sx==7)||(sy==5&&sx==8))
       { pd=1;
        hlz=1;
        }
    }
    }

      /*��ʿ*/
      if (tempt==6&&hlz==1)
    {
     if (((sx+1==temptx&&sy+1==tempty)||(sx-1==temptx&&sy-1==tempty)||(sy-1==tempty&&sx+1==temptx)||(sy+1==tempty&&sx-1==temptx)) &&(qipan[sy][sx].t==0||qipan[sy][sx].t>=8&&qipan[sy][sx].t<=14))
    {


         if ((sy==3&&sx==0)||(sy==3&&sx==2)||(sy==4&&sx==1)||(sy==5&&sx==0)||(sy==5&&sx==2))
       { pd=1;
        hlz=-1;
        }
    }
    }

         /*��ʿ*/
 
      if (tempt==13&&hlz==-1)
    {
     if (((sx+1==temptx&&sy+1==tempty)||(sx-1==temptx&&sy-1==tempty)||(sy-1==tempty&&sx+1==temptx)||(sy+1==tempty&&sx-1==temptx)) &&(qipan[sy][sx].t==0||qipan[sy][sx].t>=1&&qipan[sy][sx].t<=7))
    {


         if ((sy==3&&sx==7)||(sy==3&&sx==9)||(sy==4&&sx==8)||(sy==5&&sx==7)||(sy==5&&sx==9))
       { pd=1;
        hlz=1;
        }
    }
    }

        /*����*/
     if (tempt==5&&hlz==1)
    {
     if (((sx+2==temptx&&sy+2==tempty)||(sx-2==temptx&&sy-2==tempty)||(sy-2==tempty&&sx+2==temptx)||(sy+2==tempty&&sx-2==temptx)) &&(qipan[sy][sx].t==0||qipan[sy][sx].t>=8&&qipan[sy][sx].t<=14))
    {


         if ((sy==2&&sx==0)||(sy==0&&sx==2)||(sy==2&&sx==4)||(sy==4&&sx==2)||(sy==6&&sx==0)||(sy==6&&sx==4)||(sy==8&&sx==2))
       {


      if (qipan[(sy+tempty)/2][(sx+temptx)/2].t==0)
       {
        pd=1;
        hlz=-1;


       }

        }
    }
    }


       /*����*/
     if (tempt==12&&hlz==-1)
    {
     if (((sx+2==temptx&&sy+2==tempty)||(sx-2==temptx&&sy-2==tempty)||(sy-2==tempty&&sx+2==temptx)||(sy+2==tempty&&sx-2==temptx)) &&(qipan[sy][sx].t==0||qipan[sy][sx].t>=0&&qipan[sy][sx].t<=7))
    {


         if ((sy==2&&sx==9)||(sy==0&&sx==7)||(sy==2&&sx==5)||(sy==6&&sx==5)||(sy==8&&sx==7)||(sy==6&&sx==9)||(sy==4&&sx==7))
       {
       if (qipan[(sy+tempty)/2][(sx+temptx)/2].t==0)
      {
       pd=1;
        hlz=1;
        }

        }
    }
    }


    /*����*/
      if (tempt==4&&hlz==1)
    {
     if (((sx+2==temptx&&sy+1==tempty)||(sx+2==temptx&&sy-1==tempty)||(sx-2==temptx&&sy-1==tempty)||(sx-2==temptx&&sy+1==tempty)||(sy+2==tempty&&sx-1==temptx)||(sy+2==tempty&&sx+1==temptx)||(sy-2==tempty&&sx-1==temptx)||(sy-2==tempty&&sx+1==temptx))&&(qipan[sy][sx].t==0||qipan[sy][sx].t>=8&&qipan[sy][sx].t<=14))
    {

     if ((sx+2==temptx||sx-2==temptx)&&(qipan[tempty][(temptx+sx)/2].t==0))
      {
     pd=1;
     hlz=-1;
     }

    else if ((sy+2==tempty||sy-2==tempty)&&(qipan[(tempty+sy)/2][temptx].t==0))
      {
     pd=1;
     hlz=-1;
     }

    }
    }


       /*����*/
      if (tempt==11&&hlz==-1)
    {
     if (((sx+2==temptx&&sy+1==tempty)||(sx+2==temptx&&sy-1==tempty)||(sx-2==temptx&&sy-1==tempty)||(sx-2==temptx&&sy+1==tempty)||(sy+2==tempty&&sx-1==temptx)||(sy+2==tempty&&sx+1==temptx)||(sy-2==tempty&&sx-1==temptx)||(sy-2==tempty&&sx+1==temptx))&&(qipan[sy][sx].t==0||qipan[sy][sx].t>=1&&qipan[sy][sx].t<=7))
    {

     if ((sx+2==temptx||sx-2==temptx)&&(qipan[tempty][(temptx+sx)/2].t==0))
      {
     pd=1;
     hlz=1;
     }

    else if ((sy+2==tempty||sy-2==tempty)&&(qipan[(tempty+sy)/2][temptx].t==0))
      {
     pd=1;
     hlz=1;
     }

    }
    }




    /*�쳵*/
     if (tempt==3&&hlz==1)
    { int i,k=0;
     if (((sx>temptx&&sy==tempty)||(sx<temptx&&sy==tempty)||(sy<tempty&&sx==temptx)||(sy>tempty&&sx==temptx)) &&(qipan[sy][sx].t==0||qipan[sy][sx].t>=8&&qipan[sy][sx].t<=14))
    {
    if (sy==tempty)
    { /*��ǰ����*/

    if (sx>temptx)
    {
    for (i=0;i<=sx-temptx;i++)
       { if (qipan[tempty][temptx+i].t!=0) k++;
         }

    }


    else if (sx<temptx)
    {
    for (i=0;i<=temptx-sx;i++)
       { if (qipan[tempty][temptx-i].t!=0) k++;
         }

    }
    }

    else   if (sx==temptx)
    { /*��������*/

    if (sy>tempty)
    {
    for (i=0;i<=sy-tempty;i++)
       { if (qipan[tempty+i][temptx].t!=0) k++;
         }

    }


    else if (sy<tempty)
    {
    for (i=0;i<=tempty-sy;i++)
       { if (qipan[tempty-i][temptx].t!=0) k++;
         }

    }
    }


    if (k==1||(k==2&&qipan[sy][sx].t!=0))
    {   pd=1;
        hlz=-1;
     }
    }
    }







 
    /*����*/
     if (tempt==10&&hlz==-1)
    { int i,k=0;
     if (((sx>temptx&&sy==tempty)||(sx<temptx&&sy==tempty)||(sy<tempty&&sx==temptx)||(sy>tempty&&sx==temptx)) &&(qipan[sy][sx].t==0||qipan[sy][sx].t>=1&&qipan[sy][sx].t<=7))
    {
    if (sy==tempty)
    { /*��ǰ����*/

    if (sx>temptx)
    {
    for (i=0;i<=sx-temptx;i++)
       { if (qipan[tempty][temptx+i].t!=0) k++;
         }

    }


    else if (sx<temptx)
    {
    for (i=0;i<=temptx-sx;i++)
       { if (qipan[tempty][temptx-i].t!=0) k++;
         }

    }
    }

    else   if (sx==temptx)
    { /*��������*/

    if (sy>tempty)
    {
    for (i=0;i<=sy-tempty;i++)
       { if (qipan[tempty+i][temptx].t!=0) k++;
         }

    }


    else if (sy<tempty)
    {
    for (i=0;i<=tempty-sy;i++)
       { if (qipan[tempty-i][temptx].t!=0) k++;
         }

    }
    }


    if (k==1||(k==2&&qipan[sy][sx].t!=0))
    {   pd=1;
        hlz=1;
     }
    }
    }






   

     if (tempt==2&&hlz==1)
    {
     if (((sx>temptx&&sy==tempty)||(sx<temptx&&sy==tempty)||(sy<tempty&&sx==temptx)||(sy>tempty&&sx==temptx)) &&(qipan[sy][sx].t==0||qipan[sy][sx].t>=8&&qipan[sy][sx].t<=14))
    {
      int i,k=0;
    /*����*/
      if (sx==temptx)
      {

      if (tempty>sy)
      {
      /*����Ϊ�����ϴ�*/
      for (i=0;i<=tempty-sy;i++)
       { if (qipan[tempty-i][temptx].t!=0) k++;
         }

       }

      else if (tempty<sy)
      {
      /*����Ϊ�����´�*/
      for (i=0;i<=sy-tempty;i++)
       { if (qipan[tempty+i][temptx].t!=0) k++;
         }

       }

       }


       else if (sy==tempty)
      {

      if (temptx>sx)
      {
      /*����Ϊ�����Ҵ�*/
      for (i=0;i<=temptx-sx;i++)
       { if (qipan[tempty][temptx-i].t!=0) k++;
         }

       }

      else if (temptx<sx)
      {
      /*����Ϊ�������*/
      for (i=0;i<=sx-temptx;i++)
       { if (qipan[tempty][temptx+i].t!=0) k++;
         }

       }

       }



      if (k==1||(k==3&&qipan[sy][sx].t!=0))
        {
        pd=1;
        hlz=-1;
        }

    }
    }


     
    

     if (tempt==9&&hlz==-1)
    {
     if (((sx>temptx&&sy==tempty)||(sx<temptx&&sy==tempty)||(sy<tempty&&sx==temptx)||(sy>tempty&&sx==temptx)) &&(qipan[sy][sx].t==0||qipan[sy][sx].t>=1&&qipan[sy][sx].t<=7))
    {
      int i,k=0;
    /*����*/
      if (sx==temptx)
      {

      if (tempty>sy)
      {
      /*����Ϊ�����ϴ�*/
      for (i=0;i<=tempty-sy;i++)
       { if (qipan[tempty-i][temptx].t!=0) k++;
         }

       }

      else if (tempty<sy)
      {
      /*����Ϊ�����´�*/
      for (i=0;i<=sy-tempty;i++)
       { if (qipan[tempty+i][temptx].t!=0) k++;
         }

       }

       }


       else if (sy==tempty)
      {

      if (temptx>sx)
      {
      /*����Ϊ�����Ҵ�*/
      for (i=0;i<=temptx-sx;i++)
       { if (qipan[tempty][temptx-i].t!=0) k++;
         }

       }

      else if (temptx<sx)
      {
      /*����Ϊ�������*/
      for (i=0;i<=sx-temptx;i++)
       { if (qipan[tempty][temptx+i].t!=0) k++;
         }

       }

       }



      if (k==1||(k==3&&qipan[sy][sx].t!=0))
        {
        pd=1;
        hlz=1;
        }

    }
    }









  /*����Ϊ�ж��������*/


 /*����Ϊ��������*/


  /*����PD����1ʱ�Ż�ִ�з�������,�������ָ̻�������֮ǰ������*/
   if (pd==1)
   { int yan=0;

   topb(1);
    autosavesub();
    if(qipan[sy][sx].t!=0) yan=1;
    qipan[tempty][temptx].t=0;
    qipan[sy][sx].t=tempt;


    if((fp=open(bmpdir[tempty][temptx],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
      tuxiang(qipan[tempty][temptx].x,qipan[tempty][temptx].y,fp);
    close(fp);


     if((fp=open("bmp\\yanwu.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");
        return 1 ;
    }
     if(yan==1)tuxiang(qipan[sy][sx].x,qipan[sy][sx].y,fp);
     close(fp);




     if((fp=open(qizi[qipan[sy][sx].t],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
     tuxiang(qipan[sy][sx].x,qipan[sy][sx].y,fp);
     close(fp);

    topb(2);
    }
    else
    {
    int color,txtx;
    color=0,txtx=-100;

    if (hlz==1) color=219;
    else if (hlz==-1) color=240;


    putword(bu24H,24,280-13+txtx,11,color);
    putword(neng24H,24,305-13+txtx,11,color);
    putword(zhe24H,24,330-13+txtx,11,color);
    putword(yang24H,24,355-13+txtx,11,color);
    putword(zou24H,24,380-13+txtx,11,color);
    }


     break;





   }

   else if (kong==KEYK||kong==KEYSDIANH)
   {
   break;



   }
   else continue;

   if (sy>8)sy=0;
   else if (sy<0)sy=8;
   if (sx<0)sx=9;
   else if (sx>9)sx=0;





   if((fp=open(bmpdir[ty][tx],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
      tuxiang(qipan[ty][tx].x,qipan[ty][tx].y,fp);
    close(fp);



    if((fp=open(qizi[qipan[ty][tx].t],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
     tuxiang(qipan[ty][tx].x,qipan[ty][tx].y,fp);
     close(fp);

    tuxiang(qipan[sy][sx].x,qipan[sy][sx].y,sb);

   if((fp=open(qizi[tempt],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
        tuxiang(qipan[sy][sx].x,qipan[sy][sx].y,fp);
     close(fp);

 /*����Ϊ��������*/




   }


   }
   /*����Ϊ�����ƶ�*/
   else {

   if((fp=open(bmpdir[ty][tx],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
      tuxiang(qipan[ty][tx].x,qipan[ty][tx].y,fp);
    close(fp);

   if((fp=open(qizi[qipan[ty][tx].t],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
     tuxiang(qipan[ty][tx].x,qipan[ty][tx].y,fp);
     close(fp);
     tuxiang(qipan[sy][sx].x,qipan[sy][sx].y,sb);
    }

    }

 /********************����Ϊ��Ϸ��������***************************/

qingtimer();
    getch();
closegraph();




}






/*��ʼ�����Ӻ���*/

void initqizi(int n)
{   int i,j;



if (n==5)
{
     for (i=0;i<9;i++)
     {
      for (j=0;j<10;j++)
      {
      qipan[i][j].t=0;
   }
      }
/*�������Ϲ̶�����32��λ�õ��Ӷ����ú�*/

 qipan[0][0].t=3;
 qipan[8][0].t=3;
 qipan[0][9].t=10;
 qipan[8][9].t=10;
 qipan[1][2].t=2;
 qipan[7][2].t=2;
 qipan[1][7].t=9;
 qipan[7][7].t=9;

 qipan[0][3].t=1;
 qipan[2][3].t=1;
 qipan[4][3].t=1;
 qipan[6][3].t=1;
 qipan[8][3].t=1;
 qipan[0][6].t=8;
 qipan[2][6].t=8;
 qipan[4][6].t=8;
 qipan[6][6].t=8;
 qipan[8][6].t=8;

 qipan[4][0].t=7;
 qipan[4][9].t=14;

 qipan[3][0].t=6;
 qipan[3][9].t=13;
 qipan[5][0].t=6;
 qipan[5][9].t=13;

 qipan[2][0].t=5;
 qipan[2][9].t=12;
 qipan[6][0].t=5;
 qipan[6][9].t=12;

 qipan[1][0].t=4;
 qipan[1][9].t=11;
 qipan[7][0].t=4;
 qipan[7][9].t=11;

hlc=950;
llc=900;
hlz=1;
}

else {
     load1(n);
    }

if(huiqi==1)
{autoloadsub();
huiqi=0;
}

}



/*��������ַ�����*/
void putword(char *mat,int matsize,int x,int y,int color)
/*���Σ���ģָ�롢�����С����ʼ����(x,y)����ɫ*/
{int i,j,k,n;
 n=(matsize-1)/8+1;
 for(j=0;j<matsize;j++)
  for(i=0;i<n;i++)
   for(k=0;k<8;k++)
    if(mat[j*n+i]&(0x80>>k))  /*����Ϊ1��λ����ʾ*/
     putpixel(x+i*8+k,y+j,color);
}



/*�ж�ʤ������,Ѱ���������Ƿ��н���˧����*/
int win1()
{int i,j,hk=0,lk=0,hjy,ljy,hjx,ljx,bai=0;

     for (i=0;i<9;i++)
     {
      for (j=0;j<10;j++)
      {
      if (qipan[i][j].t==7)hk=1,hjy=i,hjx=j;
      if (qipan[i][j].t==14)lk=1,ljy=i,ljx=j;

       }
       }




      if (hjy==ljy)
      {
      for (j=hjx;j<=ljx;j++)
      {if (qipan[hjy][j].t!=0) bai++;

       }
      if (bai<=2) return (hlz);
      }


     if ((hk==0)||(hlc==0))return(-1);
     if ((lk==0)||(llc==0))return(1);

     if (hk==1&&lk==1) return(0);

}


/*�����˵�����*/
int over1()
{int fp,fp1,fp2,kb=KEYS,orc=1;
 
    if((fp=open("bmp\\gameover.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");
        return 1 ;
    }
     tuxiang(0,0,fp);
     close(fp);





   while(1)
   {


   kb=mykeyscan();

   if (kb==KEYW||kb==KEYS8)
   {
   if((fp1=open("bmp\\over2.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");
        return 1 ;
    }
     tuxiang(0,283,fp1);
     close(fp1);

    orc=1;

   }

   else if (kb==KEYS||kb==KEYS5||kb==KEYS2)
   {
   if((fp2=open("bmp\\over1.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");
        return 1 ;
    }
     tuxiang(0,283,fp2);
     close(fp2);
    orc=2;

   }

   else if (kb==KEYJ||kb==KEYS0)
      if (orc==2)
   {
   return 0;}

   else if (orc==1) return(1);
     }


}

/*���ֺ���,���ڵ�ס�����϶���Ĳ���*/
void topb(int n)
{int fp1;

if (n==1)
{
 if((fp1=open("bmp\\L1-161.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
tuxiang(0,0,fp1);
close(fp1);
}
if (n==2)
{
if((fp1=open("bmp\\L2-159.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
tuxiang(161,0,fp1);
close(fp1);
}


if (n==3)
{
if((fp1=open("bmp\\R1-160.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
tuxiang(159+161,0,fp1);
close(fp1);
}
if (n==4)
{
 if((fp1=open("bmp\\R2-160.bmp",O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
tuxiang(640-160,0,fp1);
close(fp1);
}
}



 /*����ʣ�����������*/
int liang(int liang)
{  void putword(char *mat,int matsize,int x,int y,int color);
int w,q,b,wei=10,color1=0;
b=liang%10;
q=liang/10%10;
w=liang/100%10;

topb(4);
 /*����Ϊ����������ת����������*/
switch (w)
{
case 1:
 putword(yi16H,16,500+wei,13,color1);
 break;
case 2:
 putword(er16H,16,500+wei,13,color1);
 break;
case 3:
 putword(san16H,16,500+wei,13,color1);
 break;
case 4:
 putword(si16H,16,500+wei,13,color1);
  break;
case 5:
 putword(wu16H,16,500+wei,13,color1);
  break;
case 6:
 putword(liu16H,16,500+wei,13,color1);
  break;
case 7:
 putword(qi16H,16,500+wei,13,color1);
  break;
case 8:
 putword(ba16H,16,500+wei,13,color1);
  break;
case 9:
 putword(jiu16H,16,500+wei,13,color1);
  break;
case 0:
 putword(ling16H,16,500+wei,13,color1);
  break;
}

 putword(wan16H,16,518+wei,13,color1);


switch (q)
{
case 1:
 putword(yi16H,16,536+wei,13,color1);
 break;
case 2:
 putword(er16H,16,536+wei,13,color1);
 break;
case 3:
 putword(san16H,16,536+wei,13,color1);
 break;
case 4:
 putword(si16H,16,536+wei,13,color1);
  break;
case 5:
 putword(wu16H,16,536+wei,13,color1);
  break;
case 6:
 putword(liu16H,16,536+wei,13,color1);
  break;
case 7:
 putword(qi16H,16,536+wei,13,color1);
  break;
case 8:
 putword(ba16H,16,536+wei,13,color1);
  break;
case 9:
 putword(jiu16H,16,536+wei,13,color1);
  break;
case 0:
 putword(ling16H,16,536+wei,13,color1);
  break;
}

 putword(qian16H,16,554+wei,13,color1);



switch (b)
{
case 1:
 putword(yi16H,16,572+wei,13,color1);
 break;
case 2:
 putword(er16H,16,572+wei,13,color1);
 break;
case 3:
 putword(san16H,16,572+wei,13,color1);
 break;
case 4:
 putword(si16H,16,572+wei,13,color1);
  break;
case 5:
 putword(wu16H,16,572+wei,13,color1);
  break;
case 6:
 putword(liu16H,16,572+wei,13,color1);
  break;
case 7:
 putword(qi16H,16,572+wei,13,color1);
  break;
case 8:
 putword(ba16H,16,572+wei,13,color1);
  break;
case 9:
 putword(jiu16H,16,572+wei,13,color1);
  break;
case 0:
 putword(ling16H,16,572+wei,13,color1);
  break;
}

 putword(bai16H,16,590+wei,13,color1);

 putword(shi16H,16,608+wei,13,color1);

}


/*��ʼ�˵�����*/
int menu1()
{int n=0,i=1,temp=1,fp;


 while(1)
 {


  if((fp=open(select1[i],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
    tuxiang(0,0,fp);
    close(fp);

  n=mykeyscan();

  if(n==KEYW||n==KEYS8)
  i--;
  else if(n==KEYS||n==KEYS5||n==KEYS2)
  i++;

  if(i<1)i=6;
  if(i>6)i=1;
  if (n==KEYJ||n==KEYS0||n==KEYENTER) return (i);
  if(temp!=i)
   {
  if((fp=open(select1[0],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
      tuxiang(0,0,fp);
    close(fp);

   }

   temp=i;

 }




}


/*�浵����*/
void save1(int n)
{int i,j,k=0;
 FILE *savefp;
savefp=fopen(savedir[n],"w+");
  for (i=0;i<9;i++)
     {
      for (j=0;j<10;j++)
      {
           savefile[n][k]=qipan[i][j].t;
         k++;

       }


     }

     savefile[n][91]=hlc;
     savefile[n][92]=llc;
     savefile[n][93]=hlz;

   for (i=0;i<94;i++)
   {
   fprintf(savefp,"    %d",savefile[n][i]);


   }
     fclose(savefp);

 }

/*��������*/
 void load1(int n)
{int i,j,nul;
  FILE *savefp;
if ((savefp=fopen(savedir[n],"r"))==NULL) printf("----------");



     for (i=0;i<9;i++)
     {
      for (j=0;j<10;j++)
      {
      fscanf(savefp,"    %d",&qipan[i][j].t);
        }
  }
     fscanf(savefp,"    %d",&nul);
     fscanf(savefp,"    %d",&hlc);
     fscanf(savefp,"    %d",&llc);
     fscanf(savefp,"    %d",&hlz);
 }

/*������Ա��������*/
int  chengyuan()
{int i,fp3;
for (i=0;i<=6;i++)
{
  if((fp3=open(cybiao[i],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
tuxiang(0,0,fp3);
close(fp3);


sleep(2);

if (kbhit()!=0)return 0;
}
}

/*��Ϸ������*/
int help3()
{int n=0,i=0,fp;


 while(1)
 {


  if((fp=open(help2[i],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
    tuxiang(0,0,fp);
    close(fp);

  n=mykeyscan();

  if(n==KEYW||n==KEYS8)
  i--;
  else if(n==KEYS||n==KEYS5||n==KEYS2)
  i++;

  if(i<0)i=10;
  if(i>10)i=0;
  if (n==KEYJ||n==KEYS0||n==KEYENTER) return (i);

 }




}


int loadmenu1()
{int n=0,i=1,fp;


 while(1)
 {


  if((fp=open(loadbmp[i],O_RDONLY|O_BINARY))==-1)
   {
        puts("Cannot find file " "bmp" ".");

    }
    tuxiang(0,0,fp);
    close(fp);

  n=mykeyscan();

  if(n==KEYW||n==KEYS8)
  i--;
  else if(n==KEYS||n==KEYS5||n==KEYS2)
  i++;

  if(i<1)i=4;
  if(i>4)i=1;
  if (n==KEYJ||n==KEYS0||n==KEYENTER) return (i);


}
}



/*�浵����*/
void autosavesub()
{int i,j,k=0;
  for (i=0;i<9;i++)
     {
      for (j=0;j<10;j++)
      {
           autosave[k]=qipan[i][j].t;
         k++;

       }


     }

     autosave[91]=hlc;
     autosave[92]=llc;
     autosave[93]=hlz;
   }


  void autoloadsub()
{int i,j,k=0;
 int d[94];

  for (i=0;i<9;i++)
     {
      for (j=0;j<10;j++)
      { qipan[i][j].t=autosave[k];
        k++;
         }
  }
     hlc=autosave[91];
     llc=autosave[92];
     hlz=autosave[93]*-1;
}
