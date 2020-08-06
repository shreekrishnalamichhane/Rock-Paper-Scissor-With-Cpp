#include<iostream>
#include<windows.h>    	//used for PlaySound function
#include<mmsystem.h>
#include <time.h>		//To fetch system time
#include<conio.h> 		//To Use Getch()
#include<string.h>
using namespace std;
#define PossibleInput 3 
char Input[PossibleInput] = { 'R' , 'P' , 'S' };
int WinTrack = 0 , LooseTrack = 0 , DrawTrack = 0;
char AI(){
	int Random[5];
	int AIGuess = 0;
	srand(time(0));
	AIGuess= abs(rand() + rand() * rand() / rand() % rand() - rand() ) %3 ;
	AIGuess = AIGuess % 3 ;
	return Input[AIGuess];
}
char Human(){
	char UserChoice;
	fflush(stdin);
	cout<<"Enter your Choice :"<<endl;
	cout<<"'R' for Rock"<<endl;
	cout<<"'P' for Paper"<<endl;
	cout<<"'S' for Scissors"<<endl;
	cout<<"'E' to exit"<<endl;
	cin>>UserChoice;
	if( UserChoice == 'R' || UserChoice == 'P' || UserChoice == 'S' || UserChoice == 'r' || UserChoice == 'p' || UserChoice == 's' ){
		if(UserChoice == 'r' || UserChoice == 'p' || UserChoice == 's'){
			if(UserChoice == 'r'){
			UserChoice = 'R';
			}
			else if(UserChoice == 'p'){
				UserChoice = 'P';
			}
			else {
				UserChoice = 'S';
			}
		}
		return UserChoice;
	}
	else if(UserChoice == 'E' || UserChoice =='e'){
		exit(0);
	}
	else{
		cout<<endl<<"Wrong Input.."<<endl<<"Possible Input : R/r , P/p , S/s"<<endl;
		system("cls");
		cout<<"Please Try Again.."<<endl;
		Human();
	}
}
void RockPaperScissor(){
	system("cls");
	char A = AI();
	char H = Human();
	if(A == H){
		if( A == 'R'){
			cout<<"Computer Choose: Rock"<<endl;
			cout<<"You Choose: Rock"<<endl;
		}
		else if( A == 'P'){
			cout<<"Computer Choose: Paper"<<endl;
			cout<<"You Choose: Paper"<<endl;
		}
		else if( A == 'S'){
			cout<<"Computer Choose: Scissor"<<endl;
			cout<<"You Choose: Scissor"<<endl;
		}
		cout<<"Game Drawn."<<endl;
		PlaySound("sounds/draw.wav", NULL, SND_SYNC);
		cout<<"Press Any Key to Continue.."<<endl;
	}
	else if(A == 'R' && H == 'S'){
		cout<<"Computer Choose: Rock"<<endl;
		cout<<"You Choose: Scissor"<<endl;
		cout<<"Computer Won.."<<endl;
		PlaySound("sounds/loose.wav", NULL, SND_SYNC);
		cout<<"Press Any Key to Continue.."<<endl;	
	}
	else if(A == 'R' && H == 'P'){
		cout<<"Computer Choose: Rock"<<endl;
		cout<<"You Choose: Paper"<<endl;
		cout<<"You Won.."<<endl;
		PlaySound("sounds/win.wav", NULL, SND_SYNC);
		cout<<"Press Any Key to Continue.."<<endl;	
	}
	else if(A == 'S' && H == 'R'){
		cout<<"Computer Choose: Scissor"<<endl;
		cout<<"You Choose: Rock"<<endl;
		cout<<"You Won.."<<endl;
		PlaySound("sounds/win.wav", NULL, SND_SYNC);
		cout<<"Press Any Key to Continue.."<<endl;	
	}
	else if(A == 'S' && H == 'P'){
		cout<<"Computer Choose: Scissor"<<endl;
		cout<<"You Choose: Paper"<<endl;
		cout<<"Computer Won.."<<endl;
		PlaySound("sounds/loose.wav", NULL, SND_SYNC);
		cout<<"Press Any Key to Continue.."<<endl;	
	}
	else if(A == 'P' && H == 'R'){
		cout<<"Computer Choose: Paper"<<endl;
		cout<<"You Choose: Rock"<<endl;
		cout<<"Computer Won.."<<endl;
		PlaySound("sounds/loose.wav", NULL, SND_SYNC);
		cout<<"Press Any Key to Continue.."<<endl;	
	}
	else if(A == 'P' && H == 'S'){
		cout<<"Computer Choose: Paper"<<endl;
		cout<<"You Choose: Scissor"<<endl;
		cout<<"You Won.."<<endl;
		PlaySound("sounds/win.wav", NULL, SND_SYNC);	
		cout<<"Press Any Key to Continue.."<<endl;
	}
	getch();
	RockPaperScissor();
}

int main()
{
	RockPaperScissor();
  return 0;
}
