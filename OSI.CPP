#include<stdio.h>
#include<process.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#define IN 99
#define N 6
#define max_rlen 50
#define str_len 5
#define bool int
void mod2();
void applayer();
void prelayer();
  char* encode(char* src) ;
void seslayer();
void translayer();
void netlayer();
  int dijkstra(int cost[][N], int source, int target);
bool getparity(unsigned int);
void phylayer();
void mod3();
void mod4();
					//FRONT
void mod1()
 {
   setbkcolor(WHITE);
   setcolor(5);
   settextstyle(7,0,3);
   outtextxy(130,8,"OSI MODEL (SENDER'S SIDE)");
   setcolor(BLUE);

  for(int i=1;i<=2;i++)
    {
   //AL
    rectangle(450+i,50,190+i,100);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(250,72,"APPLICATION LAYER");

   //PL
    rectangle(450+i,105,190+i,155);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(250,128,"PRESENTATION LAYER");

   //SL
    rectangle(450+i,160,190+i,210);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(260,182,"SESSION LAYER");

   //TL
    rectangle(450+i,215,190+i,265);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(255,236,"TRANSPORT LAYER");

   //NL
    rectangle(450+i,270,190+i,320);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(260,292,"NETWORK LAYER");

   //DLL
    rectangle(450+i,325,190+i,375);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(255,345,"DATALINK LAYER");

   //PHL
    rectangle(450+i,380,190+i,430);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(260,400,"PHYSICAL LAYER");

  }
}



void ALMessage();
 void PLMessage();
  void SLMessage();
   void TLMessage();
  void NLMessage();
 void DLLMessage();
void PHLMessage();



int main()                                      //MAIN FUNCTION
{
   char str[25];
   int gdrive=DETECT, gmode;
   initgraph(&gdrive,&gmode,"C:\\TURBOC3\\BGI");

   mod1();
    delay(1500);
     cleardevice();

   mod2();
    ALMessage();
     PLMessage();
      SLMessage();
       TLMessage();
	NLMessage();
	 DLLMessage();
	  PHLMessage();
	  delay(1500);
	 cleardevice();


    setbkcolor(BLACK);
    setcolor(15);
    printf("\n\n--------ENTER STRING--------\n\t");
    scanf("\t%s",str);
    printf("\tEntered String is : %s",str);
    delay(1500);
    cleardevice();

   applayer();
    delay(2000);
     cleardevice();

   prelayer();
    delay(2000);
     cleardevice();

   setbkcolor(BLACK);
    setcolor(15);
     int choice,i=0;
     int test[25],j;
     do
     {
     printf("\n\n\t----menu----\n");
     printf("\tEncryption/Decryption key is 3\n");
     printf("\t1.Encryption\n");
     printf("\t2.Decryption\n");
     printf("\t3.Translaion\n");
     printf("\t4.Compression\n");
     printf("\t5.exit\n");
     scanf("%d",&choice);

     switch(choice)
     {
     case 1: {
	      for(i=0;(i<10 && str[i]!='\0');i++)
	       str[i]=str[i]+3;
	       printf("\n\tEncrypted string: %s\n",str);
	      break;
	     }
     case 2: {
	      for(i=0;(i<10 && str[i] !='\0');i++)
		str[i]=str[i]-3;
		printf("\n\tDecrypted string: %s\n",str);
	      break;
	     }
     case 3: { //-----translation-----
	       //---- char to ascii----
	      while(str[i]!='\0')
	      {test[i]=str[i];
	       i++;
	       }
	       for(j=0;j<i-1;j++)
	      printf("\t%d",test[j]);
	      break;
	     }
     case 4: {   //----compression----
		 //loseless
	     char* res = encode(str);
	     printf("%s",res);
	     getchar();
	     break;
	     }
     case 5:  cleardevice();
	      }
    }while(choice!=5);
    cleardevice();

   seslayer();
    delay(2000);
     cleardevice();

   translayer();
    delay(2000);
     cleardevice();


   setbkcolor(BLACK);
   setcolor(15);
   settextstyle(7,0,3);
   outtextxy(170,8,"NETWORK LAYER");
   int cost[N][N],w,ch,co;
   int source, target, x, y;
   printf("\t----Dijkstra's algorithm----\n");
   for(i=1;i<N;i++)
   for(j=1;j<N;j++)
   cost[i][j]=IN;
   for(x=1;x<N;x++)
   {
    for(y=x+1;y<N;y++)
     {
     printf("\tEnter the weight of the path between nodes %d and %d\t",x,y);
     scanf("\t%d",&w);
     cost[x][y]=cost[y][x]=w;
     }
     }
     printf("\tEnter the source:\t");
     scanf("\t%d",&source);
     printf("\tEnter the target:\t");
     scanf("\t%d",&target);
     co=dijkstra(cost,source,target);
     printf("\tThe shortest Path:%d",co);
     delay(1500);
     cleardevice();

   setbkcolor(BLACK);
   setcolor(15);
   settextstyle(7,0,3);
   outtextxy(170,8,"DATA LINK LAYER");


   unsigned int n;
   printf("\t----Enter value----\n ");
   printf("\t");
   scanf("%d",&n);
   printf("\tParity of no %d = %s",n,(getparity(n)?"odd":"even"));
   getchar();
   delay(1500);
   cleardevice();


   phylayer();
    delay(2000);
     cleardevice();


   mod3();
    PHLMessage();
     DLLMessage();
      NLMessage();
       TLMessage();
	SLMessage();
	 PLMessage();
	  ALMessage();
	  delay(1500);
	 cleardevice();


  mod4();
  delay(1500);
  cleardevice();

   getch();
   return 0;
}

				//SECOND
void mod2()
 {
  setbkcolor(WHITE);
  setcolor(5);
  settextstyle(7,0,3);
  outtextxy(70,8,"OSI MODEL HEADERS(SENDER 'S SIDE)");
  setcolor(BLUE);

   for(int j=1;j<=1;j++)
    {
     //AL
       rectangle(610,50+j,360,100+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(410,72,"APPLICATION LAYER");

     //PL
       rectangle(610,105+j,360,155+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(410,128,"PRESENTATION LAYER");

     //SL
       rectangle(610,160+j,360,210+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(420,182,"SESSION LAYER");

     //TL
       rectangle(610,215+j,360,265+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(420,236,"TRANSPORT LAYER");

      //NL
       rectangle(610,270+j,360,320+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(420,292,"NETWORK LAYER");

      //DLL
       rectangle(610,325+j,360,375+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(420,345,"DATALINK LAYER");

      //PHL
       rectangle(610,380+j,360,430+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(420,400,"PHYSICAL LAYER");
    }
}



void ALMessage()                             //HEADERS
{
  for(int k=1;k<=3;k++)
   {
    rectangle(205+k,85,345+k,60);
     rectangle(345+k,85,245+k,60);
      delay(500);
   }
      settextstyle(11,0,5);
     outtextxy(220,70,"AH");
    settextstyle(11,0,5);
   outtextxy(280,70,"DATA");
}

void PLMessage()
{
  for(int y=1;y<=3;y++)
   {
    rectangle(205+y,145,345+y,120);
     rectangle(345+y,145,245+y,120);
      rectangle(165+y,145,205+y,120);
       delay(500);
   }
       outtextxy(180,130,"PH");
      settextstyle(11,0,5);
     outtextxy(220,130,"AH");
    settextstyle(11,0,5);
   outtextxy(280,130,"DATA");
}

void SLMessage()
{
  for(int x=1;x<=3;x++)
   {
    rectangle(165+x,200,205+x,175);
     rectangle(125+x,200,165+x,175);
      rectangle(205+x,200,345+x,175);
       rectangle(345+x,200,245+x,175);
	delay(500);
   }
	outtextxy(140,185,"SH");
       outtextxy(180,185,"PH");
      settextstyle(11,0,5);
     outtextxy(220,185,"AH");
    settextstyle(11,0,5);
   outtextxy(280,185,"DATA");
}

void TLMessage()
{
  for(int z=1;z<=3;z++)
   {
    rectangle(125+z,255,165+z,230);
     rectangle(85+z,255,125+z,230);
      rectangle(165+z,255,205+z,230);
       rectangle(205+z,255,345+z,230);
	rectangle(345+z,255,245+z,230);
	 delay(500);
   }
	 outtextxy(100,240,"TH");
	outtextxy(140,240,"SH");
       outtextxy(180,240,"PH");
      settextstyle(11,0,5);
     outtextxy(220,240,"AH");
    settextstyle(11,0,5);
   outtextxy(280,240,"DATA");
}

void NLMessage()
{
  for(int p=1;p<=3;p++)
   {
    rectangle(125+p,310,165+p,285);
     rectangle(85+p,310,125+p,285);
      rectangle(45+p,310,85+p,285);
       rectangle(165+p,310,205+p,285);
	rectangle(205+p,310,345+p,285);
	 rectangle(345+p,310,245+p,285);
	  delay(500);
   }
	  outtextxy(60,295,"NH");
	 outtextxy(100,295,"TH");
	outtextxy(140,295,"SH");
       outtextxy(180,295,"PH");
      settextstyle(11,0,5);
     outtextxy(220,295,"AH");
    settextstyle(11,0,5);
   outtextxy(280,295,"DATA");
}

void DLLMessage()
{
  for(int w=1;w<=3;w++)
   {
    rectangle(45+w,365,85+w,340);
     rectangle(5+w,365,45+w,340);
      rectangle(85+w,365,125+w,340);
       rectangle(125+w,365,165+w,340);
	rectangle(165+w,365,205+w,340);
	 rectangle(205+w,365,345+w,340);
	  rectangle(305+w,365,245+w,340);
	   delay(500);
    }
	   outtextxy(17,350,"DLH");
	  outtextxy(60,350,"NH");
	 outtextxy(100,350,"TH");
	outtextxy(140,350,"SH");
       outtextxy(180,350,"PH");
      settextstyle(11,0,5);
     outtextxy(220,350,"AH");
    settextstyle(11,0,5);
   outtextxy(263,350,"DATA");
  outtextxy(317,350,"DLT");
}

void PHLMessage()
{
  for(int q=1;q<=3;q++)
   {
    rectangle(5+q,420,345+q,395);
     delay(500) ;
   }
     settextstyle(11,0,5);
    outtextxy(170,405,"BITS");
}


void applayer()                  //APPLICATION LAYER
{
  setbkcolor(WHITE);
  setcolor(5);
  settextstyle(7,0,3);
  outtextxy(200,8,"APPLICATION LAYER");
  setcolor(BLUE);

  settextstyle(11,0,5);
  outtextxy(180,60,"PROTOCOLS OF APPLICATION LAYER");
  outtextxy(180,90,"TELNET");
  outtextxy(180,120,"SMTP");
  outtextxy(180,150,"FTP");
  outtextxy(180,180,"DNS");
}

				    //PRESENTATION LAYER
void prelayer()
{
  setbkcolor(WHITE);
  setcolor(5);
  settextstyle(7,0,3);
  outtextxy(170,8,"PRESENTATION LAYER");

  setcolor(BLUE);
  settextstyle(11,0,5);
  outtextxy(180,60,"FUNCTIONS OF PRESENTATION LAYER");
  outtextxy(180,90,"TRANSLATION");
  outtextxy(180,120,"DATA COMPRESSION");
  outtextxy(180,150,"ENCRYPTION/DECRYPTION");
}


   char* encode(char* src)
   {
   int rlen;
   char count[max_rlen];
   int len=strlen(src);
   char* dest=(char*)malloc(sizeof(char)*(len*2+1));
   int i,j=0,k;
   for(i=0;i<len;i++){
   dest[j++]=src[i];
   rlen=1;
   while(i+1<len && src[i+1]){
   rlen++;
   i++;
   }
   sprintf(count,"%d",rlen);
   for(k=0;*(count+k);k++,j++){
   dest[j]=count[k];}
   }
   dest[j]='\0';
   return dest;
   }


void seslayer()
{
  setbkcolor(WHITE);
  setcolor(5);
  settextstyle(7,0,3);
  outtextxy(170,8,"SESSION LAYER");

  setcolor(BLUE);
  settextstyle(11,0,5);
  outtextxy(180,60,"FUNCTIONS OF SESSION LAYER");
  outtextxy(180,90,"ESTABLISHMENT OF CONNECTION");
  outtextxy(180,120,"MAINTENANCE OF SESSION");
  outtextxy(180,150,"AUTHENTICATION");
  outtextxy(180,180,"ENSURE SECURITY");

}

void translayer()
{
  setbkcolor(WHITE);
  setcolor(5);
  settextstyle(7,0,3);
  outtextxy(170,8,"TRANSPORT LAYER");

  setcolor(BLUE);
  settextstyle(11,0,5);
  outtextxy(180,60,"FUNCTIONS OF TRANSPORT LAYER");
  outtextxy(180,90,"SEGMENTATION");
  outtextxy(180,120,"FLOW AND ERROE CONTROL");
  outtextxy(180,150,"REASSEMBLY");
  outtextxy(180,180,"SERVICE POINT ADDRESSING");
}


//-----NETWORK LAYER------
//-----DIJKSTRA'S ALGORITHM-----
int dijkstra(int cost[][N], int source, int target)
 {
  int dist[N],prev[N],selected[N]={0},i,m,min,start,d,j;
  char path[N];
  for(i=1;i<N;i++)
  {
   dist[i]=IN;
   prev[i]=-1;
  }
  start=source;
  selected[start]=1;
  dist[start]=0;
  while(selected[target]==0)
 {
  min=IN;
  m=0;
  for(i=1;i<N;i++)
  {
  d=dist[start]+cost[start][i];
  if(d<dist[i]&&selected[i]==0)
  {
  dist[i]=d;
  prev[i]=start;
  }
  if(min>dist[i]&&selected[i]==0)
  {
  min=dist[i];
  m=i;
  }
  }
  start=m;
  selected[start]=1;
  }
  start=target;
  j=0;
  while(start!=-1)
  { path[j++]=start+65;
    start=prev[start];
  }
  path[j]='\0';
  strrev(path);
  printf("\t%s",path);
  return dist[target];
 }


//-----datalayer-----

bool getparity(unsigned int n)
{
bool parity=0;
while(n)
{
parity=!parity;
n=n&(n-1);
}
return parity;
}


void phylayer()
{
  setbkcolor(WHITE);
  setcolor(5);
  settextstyle(7,0,3);
  outtextxy(170,8,"PHYSICAL LAYER");

  setcolor(BLUE);
  settextstyle(11,0,5);
  outtextxy(180,60,"FUNCTIONS OF PHYSICAL LAYER");
  outtextxy(180,90,"BIT SYNCHRONIZATION");
  outtextxy(180,120,"BIT RATE CONTROL");
  outtextxy(180,150,"PHYSICAL TOPOLOGIES");
  outtextxy(180,180,"TRANSMISSION MODE");

}


void mod3()
{
setbkcolor(WHITE);
  setcolor(5);
  settextstyle(7,0,3);
  outtextxy(60,8,"OSI MODEL HEADERS(RECEIVER 'S SIDE)");
  setcolor(BLUE);

   for(int j=1;j<=1;j++)
    {
     //PL
       rectangle(610,380+j,360,430+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(420,400,"PHYSICAL LAYER");

     //DLL
       rectangle(610,325+j,360,375+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(420,345,"DATALINK LAYER");

     //NL
       rectangle(610,270+j,360,320+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(420,292,"NETWORK LAYER");

     //TL
       rectangle(610,215+j,360,265+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(420,236,"TRANSPORT LAYER");

      //SL
       rectangle(610,160+j,360,210+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(420,182,"SESSION LAYER");

      //PL
       rectangle(610,105+j,360,155+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(410,128,"PRESENTATION LAYER");

      //AL
       rectangle(610,50+j,360,100+j);
	delay(200);
	 settextstyle(11,0,5);
	  outtextxy(410,72,"APPLICATION LAYER");
    }
}


void mod4()
{
setbkcolor(WHITE);
   setcolor(5);
   settextstyle(7,0,3);
   outtextxy(125,8,"OSI MODEL(RECEIVER 'S SIDE)");
   setcolor(BLUE);

  for(int i=1;i<=2;i++)
    {
   //PL
    rectangle(450+i,380,190+i,430);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(260,400,"PHYSICAL LAYER");

   //DLL
    rectangle(450+i,325,190+i,375);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(260,345,"DATALINK LAYER");

   //NL
    rectangle(450+i,270,190+i,320);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(260,292,"NETWORK LAYER");

   //TL
    rectangle(450+i,215,190+i,265);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(255,236,"TRANSPORT LAYER");

   //SL
    rectangle(450+i,160,190+i,210);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(260,182,"SESSION LAYER");

   //PL
    rectangle(450+i,105,190+i,155);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(255,128,"PRESENTATION LAYER");

   //AL
    rectangle(450+i,50,190+i,100);
     delay(1000);
      settextstyle(11,0,5);
       outtextxy(250,72,"APPLICATION LAYER");

  }
}