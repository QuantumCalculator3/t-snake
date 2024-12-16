#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

int main() {
   struct termios T;
   tcgetattr(STDIN_FILENO, &T);
   T.c_lflag &= ~(ICANON | ECHO);
   tcsetattr(STDIN_FILENO, TCSANOW, &T);
   int F = fcntl(STDIN_FILENO, F_GETFL, 0);
   fcntl(STDIN_FILENO, F_SETFL, F | O_NONBLOCK);
   srand(time(NULL));
   system("clear");
   int HP = 44; int SS = 0;
   int AP, x;
   char I;
   do {
      x=0;
      AP = rand() % 101;
      x = (AP==HP||AP==0||AP==100) ? 1:0;
   }
   while (x);
   int GS = 1;
   char G[201] = "";
   int SP[100];
   int D = 2;
   while (GS){
      system("clear");
      if (read(STDIN_FILENO, &I, 1)>0){
         if (I=='w'&&D%2==0){
            D=1;
         }
         else if (I=='s'&&D%2==0){
            D=3;
         }
         else if (I=='d'&&D%2!=0){
            D=2;
         }
         else if (I=='a'&&D%2!=0){
            D=4;
         }
         else{
            D=D;
         }
      }
      switch (D){
         case 1:
            if (HP>=10){
               HP-=10;
            }
            else{
               GS=0;
            }
            break;
         case 2:
            if (HP%10!=9){
               HP+=1;
            }
            else {
               GS=0;
            }
            break;
         case 3:
            if (HP<90){
               HP+=10;
            }
            else{
               GS=0;
            }
            break;
         case 4:
            if (HP%10!=0){
               HP--;
            }
            else {
               GS=0;
            }

      };
      if (HP==AP){
         SS++;
         do {
            x=0;
            AP = rand() % 101;
            x = (AP==HP||AP==0||AP==100) ? 1:0;
            for (int i=0;i<SS;i++){
              if (AP==SP[i]){
               x=1;
               break;
              }
            }
         }
         while (x);
      }
      for (int i=1;i<=SS;i++){
         if (SP[i]==HP){
            GS=0;
         }
      }
      for (int i = 0;i<200;i++){
         if (i%2!=0){
            if ((i+1)%20==0&&i!=200){
               G[i]='\n';
            }
            else {
               G[i]=' ';
            }
         }
         else if (i%2==0){
            if (i==HP*2){
               G[i]='#';
            }
            else if (i==AP*2){
               G[i]='@';
            }
            else {
               G[i]='-';
            }
         }
      }
      for (int i = 0;i<SS;i++){
         G[2*SP[i]] = '#';
      }
      for (int i=99;i>0;i--){
         SP[i]=SP[i-1];
      }
      SP[0] = HP;
      printf("%s",G);
      usleep(150000);
   }
   system("clear");
   printf("Your score is %d!\n",SS);
   tcgetattr(STDIN_FILENO, &T);
   T.c_lflag |= (ICANON | ECHO);
   tcsetattr(STDIN_FILENO,TCSANOW,&T);
   return 0;
}
