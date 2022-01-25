#include <stdio.h>
#include<graphics.h>
#include <conio.h>
#include<string.h>
#include<dos.h>
#include<time.h>
int i,x,pin=1234,amounttowithdraw , amounttodeposit ,othertransaction ;

float balance = 10000;

struct details
{
char name[20];
long int acc;
char cvv[3];
int pin;
}d1;
void transaction()
{

  int choice;
  clrscr();
  textcolor(9);gotoxy(3,2);
  cprintf("WELCOME,Mr.");
  delay(1000);
  cprintf("%s...",d1.name);
  delay(1000);
  textcolor(2);gotoxy(14,4);

  cprintf("*********************************************");
  textcolor(14);gotoxy(14,5);
  cprintf("      PLEASE,SELECT YOUR PREFFERED CHOICE    ");
  textcolor(2);gotoxy(14,6);
  cprintf("*********************************************");
   //label4:
  printf("\n\n\t[1].WITHDRAW");

  printf("\n\n\t[2].DEPOSIT");

  printf("\n\n\t[3].CHECK ACCOUNT BALANCE");

  printf("\n\n\t[4].EXIT");

  printf("\n\n\t\tEnter your choice:-");
  label4:
  scanf("%d",  &choice);


  switch(choice)
{

    case 1:
    clrscr();
    textcolor(2);gotoxy(18,2);
    cprintf("**********************************");
    textcolor(14);gotoxy(18,3);
    cprintf("           WITHDRAW               ");
    textcolor(2);gotoxy(18,4);
    cprintf("**********************************");
    label3:
    printf("\n\n\n\t<<<ENTER AMOUNT= ");

    scanf("%d", &amounttowithdraw);

    if(amounttowithdraw > balance)
    {
       textcolor(6);gotoxy(25,10);
       cprintf("THERE IS INSUFFICIENT BALANCE IN YOUR ACCOUNT");

       printf("\n\n\n\n\t<<<Do you Want Another Transaction>>>");
       printf("\n\n\t\t\t1>.YES");
       printf("\n\n\t\t\t2>.NO");
       printf("\n\n\t\t\tYOUR CHOICE");

       scanf("%d", &othertransaction);

       if(othertransaction == 1)
       {
	transaction();
       }
       else
       {
	textcolor(6);gotoxy(22,18);
	cprintf("THANK YOU!!,for using State Bank ATM");
	}

   }
     else
    {

      if(amounttowithdraw%100==0)
      {

      balance = balance - amounttowithdraw;

      printf("\n\n\tYou have Successfully Witdraw Rs.%d. ", amounttowithdraw);
      gotoxy(25,17);textcolor(6);
      cprintf("YOUR CURRENT ACCOUNT BAANCE IS Rs.%f. ",balance);

      printf("\n\n\n\n\t<<<Do you Want Another Transaction>>>");

      printf("\n\n\t\t\t1>.YES");
      printf("\n\n\t\t\t2>.NO");
      printf("\n\n\t\t\tYOUR CHOICE");

      scanf("%d", &othertransaction);

      if(othertransaction == 1)
	{
	   transaction();
	}
	else
	{
	textcolor(6);gotoxy(22,22);
	cprintf("THANK YOU!!,for using State Bank ATM");
	}
   }

      else
      {
      gotoxy(22,8);
      textcolor(6+128);
      cprintf("Please,Enter Amount in Muiples of 100/- only..");
      goto label3;
      }
    }

    break;

    case 2:
    clrscr();
    textcolor(2);gotoxy(18,2);
    cprintf("************************************");
    textcolor(YELLOW);gotoxy(18,3);
    cprintf("             DEPOSIT                ");
    textcolor(2);gotoxy(18,4);
    cprintf("************************************");

    printf("\n\n\n\t\t>>>ENTER AMOUNT TO DEPOSIT:- ");

    scanf("%d", &amounttodeposit);


    balance = amounttodeposit + balance;



    delay(800);
    printf("\n\n\t\tyour Account has been successfully credited by Rs.%d",amounttodeposit);
    textcolor(6);gotoxy(25,12);
    cprintf("YOUR CURRENT ACCOUNT BALANCE IS RS.%f.",balance);

      printf("\n\n\n\n\t\t<<<Do you Want Another Transaction>>>");

       printf("\n\n\t\t\t1>.YES");
	printf("\n\n\t\t\t2>.NO");
	printf("\n\n\t\t\tYOUR CHOICE ");
      scanf("%d", &othertransaction);

      if(othertransaction == 1)
      {

	transaction();

      }
      else
      {
      textcolor(6);gotoxy(22,22);
      cprintf("THANK YOU!!,for using State Bank ATM");
      }


    break;

    case 3:

    clrscr();
    gotoxy(18,2);textcolor(2);
    cprintf("********************************************");
    gotoxy(18,3);textcolor(14);
    cprintf("                 BALANCE                    ");
    gotoxy(18,4);textcolor(2);
    cprintf("********************************************");

    gotoxy(25,9);textcolor(6);
    cprintf("YOUR ACCOUNT BALANCE IS Rs.%f.  ",balance);

       printf("\n\n\n\n\t<<<Do you Want Another Transaction>>>");
       printf("\n\n\t\t\t1>.YES");
       printf("\n\n\t\t\t2>.NO");

       scanf("%d", &othertransaction);

    if(othertransaction == 1)

      {
	transaction();
      }
      else
      {
      textcolor(6);gotoxy(22,22);
      cprintf("THANK YOU!!,for using State Bank ATM");
      }

    break;

 case 4:
 textcolor(6);gotoxy(22,18);
 cprintf("THANK YOU!!,for using State Bank ATM");

 getch();

 exit(0);

 break;
 default:
 textcolor(4+128);gotoxy(22,18);
 cprintf("please enter correct choice");
 goto label4;

 }

}

void create()
{
printf("\t\tENNTER YOUR CARD NUMBER:- ");
scanf("%d",&d1.acc);
label1:
printf("\n\t\tENTER 'CVV' CODE :- ");
scanf("%s",&d1.cvv);
x=strlen(d1.cvv);
if(x!=3)
{
goto label1;
}
printf("\n\t\tACCOUNT HOLDER'S NAME:- ");
scanf("%s",&d1.name);
label2:
printf("\n\n\t\t\t=>ENTER YOUR'4'DIGIT SECRET PIN:- ");
scanf("%d",&d1.pin);
if(d1.pin==pin)
{
transaction();
}
else
{
textcolor(4+128);
sound(400);
gotoxy(40,16);
cprintf("wrong pin!!");
delay(800);
nosound();
goto label2;
}
}


void main()
{
 time_t tm;
 time(&tm);
 clrscr();
  textcolor(10);
  gotoxy(20,2);

  cprintf("--------------------------------------");
  gotoxy(20,3);textcolor(YELLOW); delay(800);
  cprintf("    WELCOME TO STATE BANK OF INDIA    ");
  gotoxy(20,4);textcolor(10);

  cprintf("--------------------------------------");

  textcolor(6);gotoxy(50,6);
  cprintf(" %s ",ctime(&tm));
  printf("\n");

  create();


  getch();


}