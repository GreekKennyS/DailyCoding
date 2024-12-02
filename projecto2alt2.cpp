//Γιώργος Καγκασίδης
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>

void GameScreen(char[3][3]); //Loop to show the GameBoard of TicTacToe
bool checkwhowins(char[3][3],char,int,int); //checks if someone won on TicTacToe
void StartScreen(); //Init Main Menu for TicTacToe
void EndScreen(); //Init End Screen
void FileWriting(); //Creates (or loads if it exists) a Score.txt file and writes the rounds played and how many times each player won
void TicTacToe(); //Init TicTacToe
void RockPaperScissors(); //Init RockPaperScissors
void StartScreen2(); //Init Main Menu for RockPaperScissors
void StartScreen3();//PARTIAL
void GuessingGame();//NOT FINISHED

//Global Variables for the FileWriting Function
int rounds_total = 0;
int player1won = 0,player2won = 0;

int main(){

    StartScreen();

    FileWriting();

	EndScreen();
	
    return 0;
}


//Init Main Menu for TicTacToe
void StartScreen(){
char menu = 'o';
while ((menu != 'S') && (menu != 'Q'))
{

std::cout<<"/////////////////////\n/////Tic-Tac-Toe\\\\\\\\\\\n/////////////////////\n";

std::cout<<"(S)tart game\n";
std::cout<<"(H)elp\n";
std::cout<<"(N)ext Game\n";
std::cout<<"(Q)uit\n";
std::cin>>menu;
menu = toupper(menu);

if (menu == 'H')
{
std::cout<<"Player 1 is the X and Player 2 is the O"
         <<"\nAnd have to choose a row and a column from 0 to 2"
         <<"\nBy entering the number and pressing enter to confirm you input\n\n";
}
if (menu == 'N')
{
    StartScreen2();
    return;
}

}
if (menu == 'S')
{
    TicTacToe();
    return;
}
return;
}

//Init End Screen
void EndScreen(){
    std::cout<<"\n\n----------------------------------------\n";
    std::cout<<"\tEnd\t Of\t  Game"<<std::endl;
    std::cout<<"----------------------------------------\n";
}
//Loop to show the GameBoard of TicTacToe
void GameScreen(char gameboard[3][3]){
    std::cout<<"    0   1   2\n";
    std::cout<<"  --------------\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout<<i <<" | ";
        
        for (int j = 0; j < 3; j++)
        {
            std::cout<<gameboard[i][j]<<" | ";
        }
        std::cout<<"\n";
    
    std::cout<<"  --------------\n";
}
}
//checks if someone won on TicTacToe
bool checkwhowins(char gameboard[3][3],char player,int row,int column){
//Checks if the selected square has been occupied
while(gameboard[row][column] != ' ')
    {
        std::cout<<"Grid is occupied try some other row or column \n";
        std::cin>>row>>column;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');//System to ignore anything but numbers
    }
    gameboard[row][column] = player;

        /*straights
        |x|x|x|
        | | | |
        | | | |
        */
    if(gameboard[0][0] == player && gameboard[0][1] == player && gameboard[0][2] == player){
        return true;}
        /*straights
        | | | |
        |x|x|x|
        | | | |*/
       else if (gameboard[1][0] == player && gameboard[1][1] == player && gameboard[1][2] == player)
    {
        return true;
    }
        /*straights
        | | | |
        | | | |
        |x|x|x|
        */
    else if(gameboard[2][0] == player && gameboard[2][1] == player && gameboard[2][2] == player){
        return true;
    }
        /*|x|| | |
          |x|| | | 
          |x|| | |
          3 combined*/
    else if((gameboard[0][0] == player && gameboard[1][0] == player && gameboard[2][0] == player) || (gameboard[0][1] == player && gameboard[1][1] == player && gameboard[2][1] == player) || (gameboard[0][2] == player && gameboard[1][2] == player && gameboard[2][2] == player)){
        return true;
    }
        /*diagonal
          |x|| | | /+\ | | |x| 
          | ||x| | /+\ | |x| |
          | || |x| /+\ |x| | |
          2 combined*/
    else if((gameboard[0][0] == player && gameboard[1][1] == player && gameboard[2][2] == player) || (gameboard[0][2] == player && gameboard[1][1] == player && gameboard[2][0] == player)){
        return true;
    }
    else
        return false;
    
}

//Creates (or loads if it exists) a Score.txt file and writes the rounds played and how many times each player won
void FileWriting(){

std::string teststring;

std::ofstream out("Score.txt");
//Tried to add into the file if it exists and stuff (NEEDS FIXING)
if (out.is_open())
{
    out<<"Round/s played in this file is: "<<rounds_total<<" \nPlayer 1 has won "<<player1won<<" time/s \nPlayer 2 has won "<<player2won<<" time/s";

    out.close();
//Reads the file
    std::ifstream myReadFile ("Score.txt");
    
    while(getline(myReadFile,teststring)){
		std::cout<<teststring;
	}
    
    myReadFile.close();
}else
{
//Creates file and writes into it
std::ofstream myfile("Score.txt");

myfile<<"Rounds played in this file is: "<<rounds_total<<"\n Player 1 has won "<<player1won<<" times \nAnd Player 2 has won "<<player2won<<" times";


myfile.close();

}

}
//Init TicTacToe
void TicTacToe(){

char player = 'O',tryagainchoice;
bool win = false,tryagain = true;
int row,column,rounds = 0,round_wonX = 0,round_wonO= 0,rounds_temp = 0;




while (tryagain == true)
{
   
    char gameboard[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    ++rounds_total;
    ++rounds;
    while(win!=true){
        
        if (player =='X')
        {
            player = 'O';
        }else
        {
            player = 'X';
        }
        GameScreen(gameboard);
        label:
        std::cout<<"Player "<<player<<"'s turn choose a row(0-2) and a column(0-2)"<<std::endl;
        std::cin>>row>>column;
        if (std::cin.fail())
        {
            std::cout<<"Invalid Input\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');//System to ignore anything but numbers
            goto label;
        }
        
        while((row<0 || column<0) || (row>2 || column>2)){
        std::cout<<"Input was wrong try again row(0-2) column(0-2)"<<std::endl;
        std::cin>>row>>column;
        }
    
        win=checkwhowins(gameboard,player,row,column);
      
    }

    GameScreen(gameboard);

    std::cout<<"\nPlayer "<<player<<" has won!"<<std::endl;
    
    if (player == 'X')
    {
        round_wonX++;player1won++;
    }else
    {
        round_wonO++;player2won++;
    }

    std::cout<<"Round: "<<rounds<<std::endl;
    std::cout<<"Rounds won by X: "<<round_wonX<<"   Rounds won by O: "<<round_wonO<<"\n";

    tryagainchoice = 'd';
while (tryagainchoice != 'Y' && tryagainchoice != 'N' )
{
    std::cout<<"Do you want another round?\n\nY for yes\nN for no"<<std::endl;
    std::cin>>tryagainchoice;
    tryagainchoice = toupper(tryagainchoice);
}
 if (tryagainchoice == 'Y')
    {
        win = false;
        tryagain = true;
    }else if(tryagainchoice == 'N'){
        tryagain = false;
    }
}
char answer;
    while (answer != 'Y' && answer != 'N')
{
std::cout<<"Do you want to go back to the main menu? Y for yes N for no and Quit\n";
std::cin>>answer;
answer = toupper(answer);
}
if (answer == 'Y')
{
    StartScreen();
    return;
}



    

}
//Init Main Menu for RockPaperScissors
void StartScreen2(){
char menu = 'o';
while ((menu != 'S') && (menu != 'Q'))
{

std::cout<<
"///////////////////////////////\n"
"//////Rock-Paper-Scissors\\\\\\\\\\\\\n"
"///////////////////////////////\n";

std::cout<<"(S)tart game\n";
std::cout<<"(H)elp\n";
std::cout<<"(N)ext Game\n";
std::cout<<"(Q)uit\n";
std::cin>>menu;
menu = toupper(menu);

if (menu == 'H')
{
    std::cout<<"You play by choosing a rock/paper or scissors, first player 1 chooses and then player 2 chooses and a winner is decided\n\n";
}
if (menu == 'N')
{
    StartScreen3();
    return;
}

}
if (menu == 'S')
{
   RockPaperScissors();
}

return;

}

//Init RockPaperScissors
void RockPaperScissors(){


char player1 = 'a',player2 = 'a',answer;
bool tryagain = true;
while (tryagain)
{
++rounds_total;
answer = 'a';
player1 = player2 = 'a';
while (player1 == player2)
{
    player1 = player2 = 'a';
while (player1 != 'R' && player1 != 'P' && player1 != 'S')
{
    std::cout<<"Player 1 choose:\n";
    std::cout<<"(R)ock Or\n(P)aper Or\n(S)cissors\n";
    std::cin>>player1;
    player1 = toupper(player1);
}
std::cout<< std::string(100,'\n');
while (player2 != 'R' && player2 != 'P' && player2 != 'S')
{
    std::cout<<"Player 2 choose:\n";
    std::cout<<"(R)ock Or\n(P)aper Or\n(S)cissors\n";
    std::cin>>player2;
    player2 = toupper(player2);
}
if (player1 == player2)
{
    std::cout<<"Tie try again\n\n";
}

}


if ((player1 == 'R' && player2 == 'S'))
{
    std::cout<<"Player 1 has won!\n";player1won++;
}
else if(player1 == 'P' && player2 == 'R'){
    std::cout<<"Player 1 has won!\n";player1won++;
}
else if(player1 == 'S' && player2 == 'P'){
    std::cout<<"Player 1 has won!\n";player1won++;
}
else if(player2 == 'R' && player1 == 'S'){
    std::cout<<"Player 2 has won!\n";player2won++;
}else if(player2 == 'P' && player1 == 'R'){
    std::cout<<"Player 2 has won!\n";player2won++;
}else if(player2 == 'S' && player1 == 'P'){
    std::cout<<"Player 2 has won!\n";player2won++;
}

while (answer !='Y' && answer != 'N')
{
std::cout<<"\nWanna play again? Y for yes N for no\n";
std::cin>>answer;
answer = toupper(answer);
}
if (answer == 'Y')
{
    tryagain = true;
}else{tryagain = false;}

}

answer = 'a';
while (answer != 'Y' && answer != 'N')
{
std::cout<<"Do you want to go back to the main menu? Y for yes N for no and Quit\n";
std::cin>>answer;
answer = toupper(answer);
}
if (answer == 'Y')
{
    StartScreen2();
}

}

void StartScreen3()
{
char menu = 'o';
while ((menu != 'S') && (menu != 'Q'))
{

std::cout<<
"///////////////////////////////\n"
"//////Guessing-Game\\\\\\\\\\\\\n"
"///////////////////////////////\n";

std::cout<<"(S)tart game\n";
std::cout<<"(H)elp\n";
std::cout<<"(N)ext Game\n";
std::cout<<"(Q)uit\n";
std::cin>>menu;
menu = toupper(menu);

if (menu == 'H')
{
    std::cout<<"A random number from [a number you choose to another number you choose and it will generate a random number]"; //Not Finished
}
if (menu == 'N')
{
    StartScreen();
    return;
}

}
if (menu == 'S')
{
   GuessingGame();
}

return;
}

void GuessingGame(){
srand(time(0));

int x;


}
