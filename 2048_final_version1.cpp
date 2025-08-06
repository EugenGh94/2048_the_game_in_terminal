#include <windows.h>
#include <iostream>
#include <conio.h>
#include <vector>
#include <random>


//Defining keys needed to move and quit the game:
//-----------------------------------------------------------------------------
#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_SPACE 32
//-----------------------------------------------------------------------------


//Declaring functions:
//-----------------------------------------------------------------------------
void timer(double sec);
void random();
void board();
void move_right();
void move_left();
void move_up();
void move_down();
std::string str(int no);
std::string num(int g);
//-----------------------------------------------------------------------------


//Declaring variables with global scope:
//-----------------------------------------------------------------------------
std::vector<int> numbers = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//-----------------------------------------------------------------------------


//Main:
//-----------------------------------------------------------------------------
int main(){
    
    //Needed for Windows to output wide Unicode characters:
    SetConsoleOutputCP(65001); 
    
    std::cout << "\n";
    std::cout << std::string( 25, ' ' ) << "██████╗░░█████╗░░░██╗██╗░█████╗░\n";
    std::cout << std::string( 25, ' ' ) << "╚════██╗██╔══██╗░██╔╝██║██╔══██╗\n";
    std::cout << std::string( 25, ' ' ) << "░░███╔═╝██║░░██║██╔╝░██║╚█████╔╝\n";
    std::cout << std::string( 25, ' ' ) << "██╔══╝░░██║░░██║███████║██╔══██╗\n";
    std::cout << std::string( 25, ' ' ) << "███████╗╚█████╔╝╚════██║╚█████╔╝\n";
    std::cout << std::string( 25, ' ' ) << "╚══════╝░╚════╝░░░░░░╚═╝░╚════╝░\n\n";
    std::cout << std::string( 10, ' ' ) <<  "Use the arrow keys (🠈 🠊 🠉 🠋) on your keyboard to move the tiles\n";
    std::cout << std::string( 10, ' ' ) <<  "When two tiles with the same number touch, they merge into one!\n";
    std::cout << std::string( 10, ' ' ) <<  " All tiles move as far as possible, some move more than others\n";
    std::cout << std::string( 10, ' ' ) <<  "   A new tile is spawned at the end of each turn, randomly\n";
    std::cout << std::string( 10, ' ' ) <<  "                          Have fun!\n";

    random();
    random();
    random();
    random();
    board();
    timer(0.5);
    random();
    board();
    
    int u = 1;
    int c = 0;

    while(u){
        c = 0;
        switch((c=getch())){
        case KEY_UP:
            move_up();
            timer(0.5);
            random();
            board();
            break;
        case KEY_DOWN:
            move_down();
            timer(0.5);
            random();
            board();
            break;
        case KEY_LEFT:
            move_left();
            timer(0.5);
            random();
            board();
            break;
        case KEY_RIGHT:
            move_right();
            timer(0.5);
            random();
            board();
            break;
        case KEY_SPACE:
            std::cout << std::string (11, '\n');
            u--;
            break;
        default:
            break;}}}
//-----------------------------------------------------------------------------


//------------------------- Defining functions --------------------------------


//Timer for refresh rate:
//-----------------------------------------------------------------------------
void timer(double sec){Sleep(sec*1000);}
//-----------------------------------------------------------------------------


//int to string made easier:
//-----------------------------------------------------------------------------
std::string str(int no){return std::to_string(no);}
//-----------------------------------------------------------------------------


//Makes each cell the correct size and format based on the number in it:
//-----------------------------------------------------------------------------
std::string num(int g){if (numbers[g] == 0)
    {return std::string(4,' ');}else{return std::string(4 - str(numbers[g]).length(),' ') + str(numbers[g]);}}
//-----------------------------------------------------------------------------


//Outputs the board:
//-----------------------------------------------------------------------------
void board(){
std::cout << "\n";
std::cout << std::string( 30, ' ' ); printf("╔════╤════╤════╤════╗\n");
std::cout << std::string( 30, ' ' ) << "║" << num(0) << "│" << num(1) << "│" << num(2) << "│" << num(3) << "║" <<"\n";
std::cout << std::string( 30, ' ' ); printf("╟────┼────┼────┼────╢\n");
std::cout << std::string( 30, ' ' ) << "║" << num(4) << "│" << num(5) << "│" << num(6) << "│" << num(7) << "║" <<"\n";
std::cout << std::string( 30, ' ' ); printf("╟────┼────┼────┼────╢\n");
std::cout << std::string( 30, ' ' ) << "║" << num(8) << "│" << num(9) << "│" << num(10) << "│" << num(11) << "║" <<"\n";
std::cout << std::string( 30, ' ' ); printf("╟────┼────┼────┼────╢\n");
std::cout << std::string( 30, ' ' ) << "║" << num(12) << "│" << num(13) << "│" << num(14) << "│" << num(15) << "║" <<"\n";
std::cout << std::string( 30, ' ' ); printf("╚════╧════╧════╧════╝\n");
printf("\033[10F");}
//-----------------------------------------------------------------------------


//Right movement:
//-----------------------------------------------------------------------------
void move_right(){
    for ( int z = numbers.size() - 1 ; z >= 1; z-- ){
        //Checks if any movement is possbile
        if ((numbers[z-1] != 0 && numbers[z] == 0) || (numbers[z-1] != 0 && numbers[z]==numbers[z-1])){
            board();
            for ( int y = 0; y < 1; y++){
                for ( int z = numbers.size() -1 ; z >= 1; z--){
                    //Breaks loop if space is at the edge
                    if ( z-1 == 3 || z-1 == 7 || z-1 == 11 || z-1 == 15 ){continue;}
                    //The next space is not 0 and the current space is 0 (free)
                    else if ( numbers[z-1] != 0 && numbers[z] == 0 ){
                        numbers[z] = numbers[z-1];
                        numbers[z-1] = 0;}
                    //Next space is not 0 and current space = next space
                    else if ( numbers[z-1] != 0 && numbers[z]==numbers[z-1] ){
                        numbers[z] = numbers[z-1]*2;
                        numbers[z-1] = 0;}}}
            timer(0.5);
            board();}}}
//-----------------------------------------------------------------------------


//Left movement:
//-----------------------------------------------------------------------------
void move_left(){
    for ( int z = 0 ; z <= numbers.size() - 2; z++){
        //Checks if any movement is possbile
        if ((numbers[z+1] != 0 && numbers[z] == 0) || (numbers[z+1] != 0 && numbers[z+1] == numbers[z])){
            board();
            for ( int y = 0; y < 1; y++){
                for ( int z = 0 ; z <= numbers.size()-2; z++){
                    //Breaks loop if space is at the edge
                    if ( z+1 == 4 || z+1 == 8 || z+1 == 12 ){continue;}
                    //The next space is not 0 and the current space is 0 (free)
                    else if ( numbers[z+1] != 0 && numbers[z] == 0 ){
                        numbers[z] = numbers[z+1];
                        numbers[z+1] = 0;}
                    //Next space is not 0 and current space = next space
                    else if ( numbers[z+1] != 0 && numbers[z+1] == numbers[z] ){
                        numbers[z] = numbers[z+1]*2;
                        numbers[z+1] = 0;}}}
            timer(0.5);
            board();}}}
//-----------------------------------------------------------------------------


//Up movement:
//-----------------------------------------------------------------------------
void move_up(){
    for ( int u = 1; u <= 19; u ++ ){
        for ( int z = 0 ; z <= numbers.size() - 5; z++ ){
            //Checks if any movement is possbile
            if ((numbers[z+4] != 0 && numbers[z] == 0) || (numbers[z+4] != 0 && numbers[z+4] == numbers[z])){
                board();
                for ( int y = 0; y < 1; y++){
                    //No need to move the last row, so z <= numbers.size() - 5
                    for ( int z = 0 ; z <= numbers.size() - 5; z++){
                        //The next space is not 0 and the current space is 0 (free)
                        if ( numbers[z+4] != 0 && numbers[z] == 0 ){
                            numbers[z] = numbers[z+4];
                            numbers[z+4] = 0;}
                        //Next space is not 0 and current space = next space
                        else if ( numbers[z+4] != 0 && numbers[z+4] == numbers[z] ){
                            numbers[z] = numbers[z+4]*2;
                            numbers[z+4] = 0;}}}
                timer(0.5);
                board();}}}}
//-----------------------------------------------------------------------------


//Down movement:
//-----------------------------------------------------------------------------
void move_down(){
    for ( int u = 1; u <= 19; u ++ ){
        for ( int z = numbers.size() - 1 ; z >= 4; z-- ){
            //Checks if any movement is possbile
            if ((numbers[z-4] != 0 && numbers[z] == 0) || (numbers[z-4] != 0 && numbers[z-4] == numbers[z])){
                board();
                for ( int y = 0; y < 1; y++ ){
                    //No need to move the first row, so z >= 4
                    for ( int z = numbers.size() - 1 ; z >= 4; z-- ){
                        //The next space is not 0 and the current space is 0 (free)
                        if ( numbers[z-4] != 0 && numbers[z] == 0 ){
                            numbers[z] = numbers[z-4];
                            numbers[z-4] = 0;}
                        //Next space is not 0 and current space = next space
                        else if ( numbers[z-4] != 0 && numbers[z-4] == numbers[z] ){
                            numbers[z] = numbers[z-4] * 2;
                            numbers[z-4] = 0;}}}
                timer(0.5);
                board();}}}}
//-----------------------------------------------------------------------------


//Generates a random number, 2 or 4, and adds it to the board
//-----------------------------------------------------------------------------
void random(){
    std::vector<int> new_list = {2,4};
    std::random_device rd;
    std::mt19937 gen(rd());
    
    std::uniform_int_distribution<> dist_1(0, 1);
    int new_number = new_list[dist_1(gen)];

    std::uniform_int_distribution<> dist_2(0, 15);
    int new_index = dist_2(gen);

    do {
        new_index = dist_2(gen);
    }
    while (numbers[new_index] != 0);
    numbers[new_index] = new_number;}
//-----------------------------------------------------------------------------