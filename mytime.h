/*********************************************************/
/*                     �ļ���mytime.h                    */
/*********************************************************/
/*********************************************************/

/* ϵͳ���ü�ʱ���������Ŀ */
# define  BYTE         unsigned char
# define  BOOL         BYTE
# define  WORD         unsigned int
# define  DWORD        unsigned long
# define  TRUE         1
# define  FALSE        !TRUE
# define  MAXTIMER     10




/* ��ʱ���ṹ */
struct TM
{
  DWORD Interval;            /*      ���       */
  DWORD LastTimer;             /* �ϴ�ʱ�䷢��ʱ��*/
  BOOL  Enable;                /*      �       */
  BOOL  Used;                  /*      ����       */
  void  (*Pointer)();          /*   �¼�Զָ��    */
};

struct TM tmTM[MAXTIMER+1];
int    TimerUsed=0;

/* ��ȡBIOS��������ֵ */
DWORD BiosTimer(void)
{
  DWORD BIOSTIMER=0;
  BIOSTIMER=peek(0x0,0x46e);
  BIOSTIMER<<=8;
  BIOSTIMER+=peek(0x0,0x46c);
  return (BIOSTIMER);
}

/* ʱ���¼���ʱ��ϵͳ���ģ� */
void kaishitimer()
{
  int   i;
  DWORD TimerDiff;

  for (i=1;i<=MAXTIMER;i++)
  {
      if (tmTM[i].Used&&tmTM[i].Enable)
      {
         TimerDiff=BiosTimer()-tmTM[i].LastTimer;/*��ǰboisʱ����ֵ����һ�η���ʱ�����   */
     if (tmTM[i].Interval<=TimerDiff)
         {
            tmTM[i].Pointer();
            tmTM[i].LastTimer=BiosTimer();
         }
      }
  }
}

/* ����һ��ʱ�ӣ��ɹ�����ʱ�ӵľ�������򷵻�NULL�� */
int chuangtimer(DWORD Interval,void (*Pointer)())
{
  int i=0;
  if (TimerUsed==MAXTIMER) return NULL;

  while (tmTM[++i].Used);

  tmTM[i].Pointer=Pointer;
  tmTM[i].Interval=Interval;
  tmTM[i].Enable=TRUE;
  tmTM[i].Used=TRUE;
  tmTM[i].LastTimer=BiosTimer();

  TimerUsed++;
  return i;
}

/* ɾ��һ��ʱ�� */
void shantimer(int *TimerID)
{
  if (tmTM[*TimerID].Used)
  {
     TimerUsed--;
     tmTM[*TimerID].Used=FALSE;
  }
  *TimerID=0;
}

/* ɾ������ʱ�� */
void qingtimer()
{
  int i;
  for (i=0;i<=MAXTIMER;i++) tmTM[i].Used=FALSE;
  TimerUsed=0;
}
