#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void start(int,int);

void menu() {
	printf("WELCOME TO NUMBER GUESSING GAME\n\t\t\t\tby Shourjo\n  PLAY\t\t(Press 'p')\n  HOW TO PLAY   (Press 'h')\n  OPTIONS\t(Press 'o')\n  EXIT\t\t(Press 'x')\n");
}

int percentcalculate(int num,int per) {
	int percent=(per*num)/100;
	return per;
}

void askplayagain(int x,int y) {
	char choice;
	printf("\n\nPress 'p' to PLAY AGAIN\nPress 'm' to GO BACK TO MENU\n\nInput: ");
	fflush(stdin);
	scanf(" %c",&choice);
	switch(choice) {
		default:
			printf("\nINVALID CHOICE! Going back to menu\n\n");
		case 'M':
		case 'm':
			menu();
			break;
		case 'P':
		case 'p':
			start(x,y);
	}
}

void start(int max,int maxguess) {
	int i,guess,num,guessed=0,per2,per5,per10,per20;
	srand(time(0));
	num=(rand()%max)+1;
	printf("\nComputer has decided its number! Now its your time to guess it!");
	per2=percentcalculate(num,2);	//Calculates 2 percent of the guessed number
	per5=percentcalculate(num,5);	//Calculates 5 percent of the guessed number
	per10=percentcalculate(num,10);	//Calculates 10 percent of the guessed number
	per20=percentcalculate(num,20);	//Calculates 20 percent of the guessed number
	for(i=1;i<=maxguess;i++) {
		printf("\n\n[%d] Enter guess: ",i);
		fflush(stdin);
		scanf("%d",&guess);
		if (guess==num) {
			printf("\nWELL DONE! The number was indeed %d",num);
			guessed=1;
			break;
		}
		else {
			if((guess<num&&guess+per2>=num)||(guess>num&&guess-per2<=num)) {
				printf("\nALMOST GUESSED IT!");
			}
			else if((guess<num&&guess+per5>=num)||(guess>num&&guess-per5<=num)) {
				printf("\nWRONG GUESS! Very Close!");
			}
			else if((guess<num&&guess+per10>=num)||(guess>num&&guess-per10<=num)) {
				printf("\nWRONG GUESS! Close!");
			}
			else if((guess<num&&guess+per20>=num)||(guess>num&&guess-per20<=num)) {
				printf("\nWRONG GUESS! Not Very Far!");
			}
			else {
				printf("\nWRONG GUESS! Try Again!");
			}
		}
	}
	if(i>maxguess) {
		printf("\n\nThe number was %d, better luck next time!\n",num);
	}
	askplayagain(max,maxguess);
}

void howtoplay() {
	printf("\nHOW TO PLAY:\n\n");
    printf("1. The computer will randomly choose a number within a specified range.\n");
    printf("2. You have a limited number of guesses to find the number.\n");
    printf("3. After each guess, you'll receive feedback on how close you are to the correct number.\n");
    printf("4. Use this feedback to make better guesses and try to win!\n\n");
    menu();
}

void options(int *max,int *maxguess) {
	int check=1;
	char choice;
	do {
		printf("\nOPTIONS:\n\nRandom number: 1 to %d\nNumber of guesses: %d",*max,*maxguess);
		printf("\n\n CHANGE SETTINGS  (Press 's')\n BACK TO MENU \t  (Press 'm')\n\nInput: ");
		fflush(stdin);
		scanf(" %c",&choice);
		switch(choice) {
			default:
				printf("\nINVALID CHOICE! Going back to menu\n\n");
			case 'M':
			case 'm':
				menu();
				check=0;
				break;
			case 'S':
			case 's':
				printf("\nInput maximum number computer can think upto: ");
				do {
					scanf("%d",max);
					if(*max<=1000) {
						break;
					}
					printf("\nMAXIMUM OF 1000 ALLOWED!\n\nInput: ");
				} while(*max>1000);
				printf("\nInput number of guesses: ");
				do {
					scanf("%d",maxguess);
					if(*maxguess<=10) {
						break;
					}
					printf("\nMAXIMUM OF 10 ALLOWED!\n\nInput: ");
				} while(*maxguess>10);
		}
	} while(check);
}

int main(void) {
	int check,max=100,maxguess=5;
	char ch;
	menu();
	do {
		printf("\nInput: ");
		fflush(stdin);
		scanf(" %c",&ch);
		check=1;
		switch(ch) {
			case 'P':
			case 'p':
				start(max,maxguess);
				break;
			case 'H':
			case 'h':
				howtoplay();
				break;
			case 'O':
			case 'o':
				options(&max,&maxguess);
				break;
			case 'X':
			case 'x':
				printf("\nTHANKS FOR PLAYING!\n");
				check=0;
				break;
			default:
				printf("\nINVALID INPUT!\n");
		}
	} while(check);
}
