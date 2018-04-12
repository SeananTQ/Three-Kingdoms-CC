#define KEYESC 1
#define KEY1 2
#define KEY2 3
#define KEY3 4
#define KEY4 5
#define KEY5 6
#define KEY6 7
#define KEY7 8
#define KEY8 9
#define KEY9 10
#define KEY0 11
#define KEYJIAN 12
#define KEYJIA 13
#define KEYGANG1 14
#define KEYTAB 15
#define KEYQ 16
#define KEYW 17
#define KEYE 18
#define KEYR 19
#define KEYT 20
#define KEYY 21
#define KEYU 22
#define KEYI 23
#define KEYO 24
#define KEYP 25
#define KEYFKUOL 26
#define KEYFKUOR 27
#define KEYENTER 28

#define KEYA 30
#define KEYS 31
#define KEYD 32
#define KEYF 33
#define KEYG 34
#define KEYH 35
#define KEYJ 36
#define KEYK 37
#define KEYL 38
#define KEYMAOH 39
#define KEYYINH 40

#define KEYZ 44
#define KEYX 45
#define KEYC 46
#define KEYV 47
#define KEYB 48
#define KEYN 49
#define KEYM 50
#define KEYDOUH 51
#define KEYJUH 52
#define KEYGANG2 53

#define KEYSPACE 57
#define KEYF1 59
#define KEYF2 60
#define KEYF3 61
#define KEYF4 62
#define KEYF5 63
#define KEYF6 64
#define KEYF7 65
#define KEYF8 66
#define KEYF9 67
#define KEYF10 68

#define KEYS7 71
#define KEYS8 72
#define KEYS9 73
#define KEYSJIANH 74
#define KEYS4 75
#define KEYS5 76
#define KEYS6 77
#define KEYSJIAH 78
#define KEYS1 79
#define KEYS2 80
#define KEYS3 81
#define KEYS0 82
#define KEYSDIANH 83



unsigned char mykeyscan(void)
{
  int  start,end;
unsigned int key=0;
  start=peek(0,0x41a); /* peek内存中读出一个字（16位） */
  end=peek(0,0x41c);
  if (start==end) return(0);
  else
  {
    key=peek(0x40,start);
    start+=2;
    if (start==0x3e) start=0x1e;
    poke(0x40,0x1a,start);   /*往内存中写入一个字（16位）   */
    return(key/256);
  }
}

