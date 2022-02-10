#include<stdio.h>
//#include<graphics.h>
#include<winsock.h>
#include<mysql.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<time.h>
#include<conio.h>
char usercode[100];

void ViewAll(void);
void CheckStatus( void);
void ViewAssignment(void);
void AssingmentDate( void);
void RequestActivation(void);
void connection(void);
void checkforactivation(void);
void finish_with_error(MYSQL* conn){
fprintf(stderr,"%s\n",mysql_error(conn));
mysql_close(conn);
exit(1);}
struct student {
    char letter;
    int characters[7][4];
};
int main() {
    char password[155];
    char sqlquery[255];
    system("Color B1");
    //clrscr();
    char assignment[255] = {"6"};
   const char *s1="ViewAll";
   const char *s2="CheckStatus";
   const char *s3="ViewAssignment";
   const  char *s4="AssignmentDate";
  const  char *s5="RequestActivation";

    //unsigned int num_fields;

    MYSQL *connect;
MYSQL_RES *res1;
MYSQL_ROW rowres;
//connect= mysql_init(0);
char choice[50];
connect=mysql_init(NULL);
//connect=mysql_real_connect(connect,"localhost","root","","kindercare",0,NULL,0);
//mysql_close(connect);

//DISPLAYING TOP WELCOME HEADING
for(int i=0;i<=141;i++){ printf("%s","=");}
printf("\n\t\t\t\t\t\tWELCOME TO KINDERCARE CHARACTER SYSTEM\n");
for(int i=0;i<=141;i++){ printf("%s","=");}
printf("\n");

//reading user log in
//56

char Fname[16];
char Lname[16];
char pass_code[55];

 if (!mysql_real_connect(connect,"localhost","root","","kindercare", 0,NULL, 0)) {
fprintf(stderr, "%s\n", mysql_error(connect));
exit(1);
}
password:
printf("\nPLEASE ENTER YOUR FIRST-NAME:");
scanf("%s",Fname);
strcpy(sqlquery,"select fname from student where fname like \'");
strcat(sqlquery,Fname);
strcat(sqlquery,"\'");


printf("\nPLEASE ENTER YOUR LAST-NAME:");
scanf("%s",Lname);
strcpy(sqlquery,"select lname from student where lname like \'");
strcat(sqlquery,Lname);
strcat(sqlquery,"\'");

/*printf("\nENTER PASSWORD:");
scanf("%s",pass_code);*/
//reading user's password and printing stars instead
//char passcode[125];
 char pword[128],c;
 int index=0;
 printf("\nPLEASE ENTER YOUR PASSWORD:");
 while((c=_getch())!=13){
  if(index<0)
  index=0;
  if(c==8){
   putch('\b');
   putch(NULL);
   putch('\b');
   index--;
   continue;
  }
  pword[index++]=c;
  putch('*');
 }
 pword[index] = '\0';
 strcpy(pass_code,pword);
 //printf("\npasswordstring is:%s", pass_code);
 strcpy(sqlquery,"SELECT pkey FROM student WHERE pkey LIKE \'");
 strcat(sqlquery,pass_code);
 strcat(sqlquery,"\'");
 if (mysql_query(connect,sqlquery) != 0)
{
fprintf(stderr, "UNKOWN LOG IN CREDENTIALS\n");
goto password;}

res1=mysql_store_result(connect);
if(res1==NULL){finish_with_error(connect);}
int count_fields1=mysql_num_fields(res1);
while((rowres=mysql_fetch_row(res1))){
    for(int i=0;i<count_fields1;i++){
        strcpy(password,rowres[0]);}
    printf("\n");}
    mysql_free_result(res1);
    mysql_close(connect);
if(strcmp(pass_code,password)==0){

checkforactivation();
//function to check for useractivation



 printf("\nENTER COMMANDS:\nViewALL\nCheckStatus\nViewAssignment\nAssignmentDate\nRequestActivation\n");
 scanf("%s",choice);
if((strcmp(s1,choice))==0){
    ViewAll();
}else if((strcmp(s2,choice))==0){
CheckStatus();}else if((strcmp(s3,choice))==0){
ViewAssignment();}else if((strcmp(s4,choice))==0){
AssingmentDate();}else if((strcmp(s5,choice))==0){
RequestActivation();}
else{printf("\nUnknown Entry\nPliz Make sure the words are matching correctily\n");
main();}
printf("\n");



return 0;
}else{printf("\nUNKNOWN LOG IN CREDENTIALS");
goto password;

}
}

void ViewAll(void){
printf("You HAVE CHOSEN  TO VIEW ALL \n\n");



}
//function to check status of the assignment
void CheckStatus(void){ //connection();
check:
     printf("You Have chosen  to Check status of assignments\n\n");}

//function to view assignment
void ViewAssignment(void){
    int correct_E;
  float score, letterscore, TOTAL_SCORE;
  score=0;
 float TOTAL_TIME,time_r;
 TOTAL_TIME=0;
 char assignment[100]="";
 char TOTAL_SCORE_DB[255];
 char SQL_QUERY[500];
//conn=mysql_real_connect(conn,"localhost","root","","kindercare",0,NULL,0);
printf("\n\t\t\t\tYOU CHOSE OPTION  TO VIEW OR ATTEMPT THE ASSIGNMENT\n");

 MYSQL *conns;
 MYSQL_RES *results;
 MYSQL_ROW  rows;
 char activate_deactivate[55];
 char compare_array[55];
 conns=mysql_init(NULL);
  if (!mysql_real_connect(conns,"localhost","root","","kindercare", 0,NULL, 0)) {
fprintf(stderr, "%s\n", mysql_error(conns));
exit(1);
}
  printf("\nENTER YOUR USERCODE PLEASE:\n");
  scanf("%s",usercode);
 strcpy(activate_deactivate,"SELECT status FROM student WHERE usercode LIKE \'");
 strcat(activate_deactivate,usercode);
 strcat(activate_deactivate,"\'");
 if (mysql_query(conns,activate_deactivate) != 0)
{
fprintf(stderr, "NOTHING FOUND\n");
exit(1);}
/*if(mysql_query(conns,"SELECT status from student where usercode LIKE \'")){finish_with_error(conns);}*/

results=mysql_store_result(conns);
if(results==NULL){finish_with_error(conns);}
int count_fields=mysql_num_fields(results);
while((rows=mysql_fetch_row(results))){
    for(int i=0;i<count_fields;i++){
        //printf("%s",rows[i]?rows[i]:"NULL");
        //printf("%s",rows[0]);
        strcpy(compare_array,rows[0]);


    }
    printf("\n");
}

mysql_free_result(results);
mysql_close(conns);


//printf("%s",compare_array);
const char *STRING="ACTIVATED";

if(strcmp(STRING,compare_array)==0){

printf("\nHERE IS THE LIST OF CHARACTERS YOU'RE ATTEMPTING\n");
    //RETRIEVE THE CHARACTERS FROM DATABASE
    //printf("\n\t\t\t\t\t\tPLEASE ATTEMPT THESE CHARACTERS\n");
     //pick assignment from databas

        //char code[15];
        MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn=mysql_init(NULL);

        char assignment_query[155];
        if (!mysql_real_connect(conn,"localhost","root","","kindercare", 0,
NULL, 0)) {
fprintf(stderr, "%s\n", mysql_error(conn));
exit(1);
}
 if(mysql_query(conn,"SELECT*FROM characters ")){
        finish_with_error(conn);}
 res=mysql_store_result(conn);
int fields=mysql_num_fields(res);

        while(row=mysql_fetch_row(res)){
            for(int i=0;i<fields;i++){
                    printf("%s\t",row[i]?row[i]:NULL);
            }
            printf("\n");
        }
mysql_free_result(res);
mysql_close(conn);


char assignment_id[57];//empty array to hold assignment id values
attempt:
printf("\nENTER THE ASSIGNMENT ID TO ATTEMPT\n");
scanf("%s",assignment_id);
//137
MYSQL_RES *resultset;
MYSQL *con;
con=mysql_init(NULL);

//CHOOSING THE SELECTED ASSIGNMENT FROM DATABASE
if (!mysql_real_connect(con,"localhost","root","","kindercare", 0,
NULL, 0)) {
fprintf(stderr, "%s\n", mysql_error(con));
exit(1);
}
strcpy(assignment_query,"SELECT * FROM characters where assignment_id  like \'");
strcat(assignment_query,assignment_id);
strcat(assignment_query,"\'");
if (mysql_query(con, assignment_query) != 0)
{
fprintf(stderr, "NO ASSIGNMENT FOUND\n");
exit(1);}
resultset=mysql_store_result(con);

        if(resultset==NULL){
            finish_with_error(con);
        }


        int num_fields=mysql_num_fields(resultset);

        while(row=mysql_fetch_row(resultset)){
                strcpy(assignment,row[0]);
            for(int i=1;i<num_fields;i++){
                    //printf("%s\t",row[i]?row[i]:NULL);

                    strcat(assignment,row[i]);
            }
            printf("\n");
        }
        printf("\n\t\t===========================================================\t\t\n");
        printf("\t\t\t\t\t%s\t\t\t\t",assignment);
        printf("\n\t\t===========================================================\t\t\n");
//looping through the assignmnent and comparing the characters
struct student S[26] = {
      'A',
      {0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
      'B',
      {{1, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 1, 1, 0}},
      'C',

      {0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1},
      'D',
      {1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0},
      'E',
      {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1},
      'F',
      {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
      'G',
      {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1},
      'G',
      {1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
      'H',
      {1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1},
      'I',
      {1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0},
      'K',
      {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1},
      'L',
      {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1},
      'M',
      {1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
      'N',
      {1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1},
      'O',
      {0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0},
      'P',
      {0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
      'Q',
      {0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1},
      'R',
      {0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
      'S',
      {0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0},
      'T',
      {1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
      'U',
      {1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1},
      'V',
      {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      'W',
      {1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
      'X',
      {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
      'Y',
      {1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
      'Z',
      {1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1}

  }; //int letter;

  size_t u = strlen(assignment);
  printf("\n\n\t\t\t FOR EACH  ENTRY TYPE 0.. TO  SKIP A STAR AND 1.. TO PRINT IT FOLLOWING THE EXAMPLE ABOVE\n");
  printf("\n\t\t\t\t\tREMRMBER TIME TAKEN IS BEING RECORDED\n\t\t\t\t\t=====START====\n\t\t\t\t\tTIME STARTED\n\n");

  for (size_t a = 0; a < u; a++)
  {

    if (assignment[a] == 'A')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[0].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[0].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;//variable to record  start time
      time_t end;//variable to store end time
      start = time(NULL);//initiate timer

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);//end the time
          time_r = difftime(end, start);//calculatevthe difference in time
          ++time_r;//increment time on eachattempt
          if (answer[i][j] == S[0].characters[i][j])
          {++correct_E;}}
          printf("\n");}
       TOTAL_TIME+=time_r;//variable to handle total time duration for every later
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore=((float)correct_E/28)*(100);
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n",letterscore);
      score=score+letterscore;
      letterscore=0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[0].letter, time_r);
     time_r=0;
    }
    else if (assignment[a] == 'B')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[1].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[1].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r= difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[1].characters[i][j])
          {
            ++correct_E;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[1].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'C')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[2].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[2].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r= difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[2].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME=TOTAL_TIME+time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[2].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'D')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[3].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[3].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }

      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("\nENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[3].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME=TOTAL_TIME+time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[3].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'E')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[4].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[4].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r= difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[4].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[4].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'F')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[5].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[5].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[5].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[5].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'G')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[6].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[6].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[6].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[6].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'H')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[7].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[7].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[7].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[7].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'I')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[8].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[8].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[8].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[8].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'J')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[9].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[9].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[9].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[9].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'K')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[10].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[10].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[10].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[10].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'L')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[11].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[11].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r= difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[11].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[11].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'M')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[12].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[12].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[12].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[12].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'N')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[13].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[13].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[13].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[13].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'O')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[14].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[14].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r= difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[14].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[14].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'P')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[15].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[15].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[15].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[15].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'Q')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[16].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[16].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r= difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[16].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[16].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'R')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[17].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[17].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[17].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[17].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'S')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[18].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[18].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[18].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[18].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'T')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[19].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[19].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[19].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[19].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'U')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[20].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[20].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[20].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[20].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'V')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[21].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[21].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[21].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[21].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'W')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[22].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[22].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[22].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[22].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'X')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[23].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[23].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r= difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[23].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[23].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'Y')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[24].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[24].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[24].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds", S[24].letter, time_r);
      time_r = 0;
    }
    else if (assignment[a] == 'Z')
    {
      printf("\nHERE IS AN EXAMPLE OF LETTER %c\n", S[25].letter);
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *p;
          p = &S[25].characters[i][j];
          if (*p == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }
        }
        printf("\n");
      }
      int answer[7][4];

      time_t start;
      time_t end;
      start = time(NULL);

      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          printf("ENTER 1 OR AT POSITION[%d][%d]", i, j);
          scanf("%d", &answer[i][j]);
          end = time(NULL);
          time_r = difftime(end, start);
          ++time_r;
          if (answer[i][j] == S[25].characters[i][j])
          {
            ++correct_E;
            //++letterscore;
          }
        }
        printf("\n");
      }
      TOTAL_TIME+=time_r;
      printf("\n\t\t\t\tTHE PRINTED LETTER IS\n");
      for (int i = 0; i < 7; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          int *q;
          q = &answer[i][j];
          if (*q == 1)
          {
            printf("*");
          }
          else
          {
            printf(" ");
          }


        }
        printf("\n");
      }
      letterscore = ((float)correct_E / 28) * 100;
      printf("\n NUMBER OF CORRECTILY PLOTTED POINTS IS %d \n", correct_E);
      printf("\nSCORE ON THIS LETTER IS %.2f\n", letterscore);
      score = score + letterscore;
      letterscore = 0;
      correct_E=0;

      printf("\nTIME SPENT ON THE LETTER  %c is %.2f seconds\n", S[25].letter, time_r);
      time_r = 0;
    }
  }
//calculate totaltime
TOTAL_SCORE=(score/strlen(assignment));


printf("\nYOU HAVE SCORED :%.2f%% ON THIS ASSIGNMENT\n ",TOTAL_SCORE);
printf("\n\nYOU HAVE SPENT :%.2f MINUTES ON THIS ASSIGNMENT\n",TOTAL_TIME/60);
con=mysql_init(NULL);
    if (!mysql_real_connect(con, "localhost","root", "", "kindercare", 0,NULL, 0)) {
fprintf(stderr, "%s\n", mysql_error(con));
exit(1);
}

//inserting assignment e
sprintf(TOTAL_SCORE_DB,"%.2f",TOTAL_SCORE);
//strcpy(TOTAL_SCORE_DB,TOTAL_SCORE);
int h,m,s;
h=(int)TOTAL_TIME/3600;
m=((int)TOTAL_TIME-(3600*h))/60;
s=((int)TOTAL_TIME-(3600*h)-(m*60));
printf("\nH:M:S- %d:%d:%d\n",h,m,s);


printf(" the user code is %s",usercode);

char TOTAL_TIME_DB[255];//variable to store total time
sprintf(TOTAL_TIME_DB,"%.2f",(TOTAL_TIME/60));
printf("\n%s",TOTAL_SCORE_DB);
printf("\n%s",TOTAL_TIME_DB);
//prepare a string to insert student results into database
strcpy(SQL_QUERY,"INSERT INTO assignment_duration(score,dur,usercode,assignment_id)VALUES (\'");
strcat(SQL_QUERY,TOTAL_SCORE_DB);
strcat(SQL_QUERY,"\', \'");
strcat(SQL_QUERY,TOTAL_TIME_DB);
strcat(SQL_QUERY,"\',\'");
strcat(SQL_QUERY,usercode);
strcat(SQL_QUERY,"\',\'");
strcat(SQL_QUERY,assignment_id);
strcat(SQL_QUERY,"\')");

if (mysql_query(con, SQL_QUERY) != 0)

{

fprintf(stderr, "\nALREADY ATTEMPTED CAN'T SUBMIT\n");
    exit(1);
}else {


printf("\nASSIGNMENTHAS BEEN SUBMETTIED SUCCESSFULLY");}
mysql_close(con);
int cont;
checkswitch:
printf("\nWould You like to attempt another Assignment?\n 1..YES 2..CheckStatus:");
/*switch(cont){

    case 1:goto attempt;
    break;
    case 2:CheckStatus();
    break;
    default:printf("\nInvalid Value Entered");
    goto checkswitch;
    break;

}*/}else{
printf("\nDEAR STUDENT YOU'RE NOT ACTIVATED TO DO THE ASSIGNMENT");
 printf("\nWould you like to be activated?\nEnter:1..YES or 2..NO GO BACK TO MENU:\n");
 check:
     int student_choice;

 scanf("%d",&student_choice);
 switch(student_choice){
     case 1:RequestActivation();
     break;
     case 2:main();
     break;
     default:printf("INVALID CHOICE");
     goto check;
     break;
 }}
//2000
//goto check;



}
//function to view all the pending assignments
void AssingmentDate(void){printf("\nHERE IS THE LIST OF PENDING ASSIGNMENTS \n\n" );

MYSQL* conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    conn=mysql_init(0);
conn=mysql_real_connect(conn,"localhost","root","","kindercare",0,NULL,0);
if(mysql_query(conn,"SELECT*FROM assignment")){
        finish_with_error(conn);}
        res=mysql_store_result(conn);
        if(res==NULL){
            finish_with_error(conn);
        }
        //for(int i=0;i<=141;i++){ printf("%s","=");}
        int num_fields=mysql_num_fields(res);
        while(row=mysql_fetch_row(res)){
            for(int i=0;i<num_fields;i++){
                    printf("%s\t",row[i]?row[i]:NULL);
            }
            printf("\n");
        }
        mysql_free_result(res);
mysql_close(conn);
int option;
printf("\nENTER 1 TO ATTEMPT OR GO BACK TO MAIN MENU:\n");
scanf("%d",&option);
if(option==1){
    ViewAssignment();}else{
    main();}
}



//request activation for a deactivated student
void RequestActivation(void){
printf("\nFOLLOW THE GUIDELINES BELOW IN ORDER TO BE ACTIVATED \n");
MYSQL *conn2;
MYSQL_RES *res2;
MYSQL_ROW  row2;
char activate_student[100];
char activate_query[155];
conn2=mysql_init(NULL);

if (!mysql_real_connect(conn2,"localhost","root","","kindercare", 0,NULL, 0)) {
fprintf(stderr, "%s\n", mysql_error(conn2));
exit(1);
}
  printf("\nEnter Your UserCode to Be activated:\n");
  scanf("%s",activate_student);
 strcpy(activate_query,"SELECT status FROM student WHERE usercode LIKE \'");
 strcat(activate_query,activate_student);
 strcat(activate_query,"\'");
 if (mysql_query(conn2,activate_query) != 0)
{
fprintf(stderr, "NOTHING FOUND\n");
exit(1);}
res2=mysql_store_result(conn2);
if(res2==NULL){finish_with_error(conn2);}
int count_rows=mysql_num_fields(res2);
while((row2=mysql_fetch_row(res2))){
    for(int i=0;i<count_rows;i++){
        //printf("%s",rows[i]?rows[i]:"NULL");
        printf("%s",row2[0]);
        //strcpy(,row2[0]);


    }
    printf("\n");
}
}
void checkforactivation(void){
    MYSQL *conn2;
MYSQL_RES *res2;
MYSQL_ROW  row2;
char activate_student[100];
char activate_query[155];
conn2=mysql_init(NULL);

if (!mysql_real_connect(conn2,"localhost","root","","kindercare", 0,NULL, 0)) {
fprintf(stderr, "%s\n", mysql_error(conn2));
exit(1);
}
  printf("\nENTER YOUR USERCODE TO CHECK FOR ACTIVATION:");
   scanf("%s",activate_student);
  printf("\nNote:Some Of The Services Will Not Be Accessible For Deactivated Students\n");
  printf("\t\t\tIt's Better To Be Activated First If Not..\n");

 strcpy(activate_query,"SELECT status FROM student WHERE usercode  LIKE \'");
 strcat(activate_query,activate_student);
 strcat(activate_query,"\'");
 if (mysql_query(conn2,activate_query) != 0)
{
fprintf(stderr, "NOTHING FOUND\n");
exit(1);}
res2=mysql_store_result(conn2);
if(res2==NULL){finish_with_error(conn2);}
int count_rows=mysql_num_fields(res2);
while((row2=mysql_fetch_row(res2))){
    for(int i=0;i<count_rows;i++){
        //printf("%s",rows[i]?rows[i]:"NULL");
        printf("%s",row2[0]);
        //strcpy(,row2[0]);




    }
    printf("\n");
}
}



