
#include <iostream>
#include <stdlib.h>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int choice;
int row,column;
char turn = 'X';
bool draw = false;
string p_name1;
string p_name2;


void player_names(){
    cout<<"\n\nENTER THE PLAYER_1[X] NAME: ";
    getline(cin,p_name1);
    cout<<"\nENTER THE PLAYER_2[0] NAME: ";
    getline(cin,p_name2);
    cout<<"\n\n";
    cout<<p_name1<<" is THE PLAYER_1[X]\n";
    cout<<p_name2<<" is THE PLAYER_2[O]\n";
}


void display_board(){
    
    cout<<"\n\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

void player_turn(){
    if(turn == 'X'){
        
        cout<<"\n"<<p_name1<<" [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n"<<p_name2<<" [O] turn : ";
    }

    cin>> choice;

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move!!\n";
    }

    
    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'X';
        turn = 'O';
    }
    
    else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'O';
        turn = 'X';
    }
    
    else {
        cout<<"Box already filled!\n Please choose another!!\n\n";
        player_turn();
    }

    
}


bool gameover(){

    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    draw = true;
    return false;
}




int main()
{
    cout<<"**************************************************************************************************************************************\n";
    cout<<"\t\t\t\t  W E L C O M E  T O  T H E  T I C  -- T A C -- T O E -- G A M E\t\t\n";
    cout<<"**************************************************************************************************************************************\n";
    cout<<"\n\t\t\t\t\tFOR 2 PLAYERS\t\t";
    cout<<"\n\t\t\t----------------------------------------------------\n";
    cout<<"\t\t\t\tPLAYER - 1 [X]\t PLAYER - 2 [O]";
    cout<<"\n\t\t\t----------------------------------------------------";
    

    player_names();
    while(gameover()){

        display_board();
        player_turn();
        gameover();
    }
    
    if(turn == 'X' && draw == false){
        display_board();
        cout<<p_name2<<" Congratulations! You won the game";
    }
    
    else if(turn == 'O' && draw == false){
        display_board();
        cout<<p_name1<<" Congratulations! You won the game";
    }
            
    else{
        display_board();
        cout<<"\n\nGAME DRAW!!!\n\n";
    }
    
return 0;    
}


   
            
                