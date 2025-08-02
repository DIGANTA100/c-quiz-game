#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max_lines 500
void Rules(){
    printf("\n\n");
printf("1. There will be total 50 questions\n");
printf("2. Write your answer (write only a/b/c/d)\n");
printf("3. Write stop at your answer to stop the quiz in the middle\n\n");
printf("              You are ready to participate\n");
printf("\n");
}

void Showscores(){

FILE *fp=fopen("score.txt","r");
if(fp==NULL){

    printf("Extremely Sorry !!! Failed to show scores ");
    return ;

}
char ch;
while((ch=fgetc(fp))!=EOF){
    putchar(ch);




}
fclose(fp);




}

void Showanswers(){
FILE *fp=fopen("answers.txt","r");
if(fp==NULL){

    printf("Extremely Sorry !!! Failed to show answers ");
    return ;

}
char ch; int i=1;
while((ch=fgetc(fp))!=EOF){
  if(isalnum(ch)){
  printf("%d . %c\n",i,ch);
  i++;
  }



}
fclose(fp);





}

void Showquestions(){
FILE *fp=fopen("questions.txt", "r");
if(fp==NULL){

    printf("Extremely Sorry !!! Failed to show questions ");
    return ;

}

char ch;
while((ch=fgetc(fp))!=EOF){
    putchar(ch);




}
fclose(fp);



}


void Help(){
    printf("This is a quiz system on C Language. Here you will be able to judge your knowledge on C. So enjoy the quiz.\n\n");
printf("The available commands are given below : \n");
printf("help       -Show all available commands\n");
printf("rules      -Show all rules of the quiz\n");
printf("begin      -Begins the quize\n");
printf("showQ      -Show all the questions\n");
printf("showA      -Show all the answers\n");
printf("showS      -Show the score\n");
printf("exit       -Exits the program\n");









}


void Beginquize(){
FILE *fp1, *fp2, *fp3;

    fp1 = fopen("questions.txt", "r");
    fp2 = fopen("answers.txt", "r");
    fp3 = fopen("score.txt", "w");

    if (!fp1 || !fp2 || !fp3) {
        printf("Extremely Sorry !! Failed to open any of the files");
        return ;
    }
char name[100];
    char questions[max_lines];
    char answers[50][10];
    char ans[10];

    int totalQuestions = 0, score = 0;


    while (fgets(answers[totalQuestions], 10, fp2)) {
        answers[totalQuestions][strcspn(answers[totalQuestions], "\n")] = '\0';
        totalQuestions++;
    }

    int q;

    printf("                                            -----Here The Quiz Begins-----\n\n\n");

    for ( q = 0; q < totalQuestions; q++) {

        for (int i = 0; i < 6; i++) {
            fgets(questions, max_lines, fp1);
            printf("%s", questions);
        }


        printf("Enter Your Answer: ");
        scanf("%s", ans);
if(strcasecmp(ans,"stop")==0) break;

        ans[strcspn(ans, "\n")] = '\0';


        if (strcmp(ans, answers[q]) == 0) {
            score++;
        }
        printf("\n");
    }
    getchar();

    if(q>totalQuestions)
    q=totalQuestions;

    printf("Please Enter your name : ");
    fgets(name,100,stdin);
    name[strlen(name)-1]='\0';

    fprintf(fp3, "%s !!! You got %d out of %d correct!\n", name,score,q ); //totalQuestions
    printf("%s !!! You got %d out of %d correct!\n",name, score, q);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);








}


int main() {
    Help();
    char command[100];
    while(1){
printf("Enter Command : ");
fgets(command,100,stdin);
command[strlen(command)-1]='\0';
if(strcmp(command,"begin")==0)
    Beginquize();

else if(strcmp(command,"help")==0)
    Help();

else if(strcmp(command,"showQ")==0)
   Showquestions();

   else if(strcmp(command,"showA")==0)
   Showanswers();
    else if(strcmp(command,"showS")==0)
   Showscores();
   else if(strcmp(command,"rules")==0)
   Rules();

else if(strcmp(command,"exit")==0)
break;

else printf("Wrong Command.Please use help command\n");


    }

    printf("I hope you have enjoyed the Quiz . Thank you very much");





    return 0;
}
