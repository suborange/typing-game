#pragma once
#include<string>
#include<fstream> // to use file stream
#include<vector>
#include<windows.h> // for gotoxy. 
using std::string;


//GLOABLS
const unsigned long long int ALL = (std::numeric_limits<std::streamsize>::max)(); // interesting collision with windows.h - https://stackoverflow.com/questions/11544073/how-do-i-deal-with-the-max-macro-in-windows-h-colliding-with-max-in-std
const unsigned short int ZERO = 0;
const unsigned short int ONE = 1;
const short int SCORE_X = 30;
const short int SCORE_Y = 2;
//keys
const char BACKSPACE = 8; // char or integer?
const char CON_DELETE = 127;
const char CON_ESCAPE = 27; // do i need escape?
const char CON_UPPERBOUND_LIMIT = 126;
const char CON_LOWERBOUND_LIMIT = 32;
//const char CORRECT_CHAR = 1; // GOOD
//const char WRONG_CHAR = 0; // 0 IS BAD! WRONG!!!
//const char BACKSPACE_CHAR = 2; // 2 IS BACKSPACE
//const char SPACE_CHAR = 3; // 3 is a space char typed.
const char SPACE = ' ';
const char NEW_LINE_KEY = 13;
const char NEW_LINE = '\n';
const string FILE_PATH = "word_list.txt";
const enum character_typed {CORRECT_CHAR, WRONG_CHAR, BACKSPACE_CHAR, SPACE_CHAR, NEXT_WORD_CHAR}; // whatever cases needed for what the user input. 


// look into const output handle. 
// DEFINITINONS - for colors
#define FOREGROUND_WHITE 0xf
#define FOREGROUND_NORMAL 0x00
// #define FOREGROUND_BLUE_DARK 0x01

// function prototypes
void DisplayGameRules();

void SetupGame();

int PlayGame();

void Play(std::vector<Node*>&, int&, HANDLE& ); // this will loop to play, insert char, then compare char, then calculate? 

// std::vector<Node*> SetupFile(std::fstream&);
void SetupFile(std::fstream& , std::vector<Node*>& ); // this will take vector, and insert linked list of a word into each element. 1 element = 1 word

bool OpenFile(std::fstream&);

void CloseFile(std::fstream&);

void ShowScore(int);
void ScoreSetup();

character_typed CompareChar(char,char, HANDLE& ); // compares the correct char to the user entered char?

void CalculateScore(character_typed, int& );

void DisplayKeyWords(std::vector<Node*>, short int); // should display all the key words in the top line, for the game

void SetupUserInput(std::vector<Node*>, short int,  int&, short int&, short int&, short int , HANDLE&); // should redisplay each character that was typed by the user. ( and can handle some of the logic, or maybe simplify more)

void DisplayUserCharInput(character_typed, char, Node*&, short int&, short int&, bool&,  HANDLE&); // now based off the state, display the right thing, correct, wrong, backspace, or space. 




void RedisplayChar(); // takes in one character, and redisplays it. (try using space)

char InsertChar(); // use getch() and returns? {{ is there a point in this?? }}

void DisplyEndScore(); // displalys the total end score. it should almost never be negative, unless u really do bad. score should refelct mistakes, but not failure

void KeyBackspace();




