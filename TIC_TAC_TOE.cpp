/**         "DOCUMENTATION"
Implement the TIC-TAC-TOE game using C/C++.
Rules of the game
1. The game is to be played between two people.
-Between two users or
-Between a user and the computer
2. One of the players chooses ‘O’ and the other ‘X’ to mark their respective cells.
3. The game ends when one of the players has one whole row/ column/ diagonal filled with their respective character (‘O’ or ‘X’).
4. If no one wins, then the game is said to be drawn.
NOTE:
-The game could be played from the CLI or with a GUI
-Display the state of the game and appropriate messages for each round
-Implement with your own code and do not copy any part of the code from other sources.
**/

//Link Section
#include<bits/stdc++.h>

using namespace std;

//Global Variables Declaration
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice,row=-1,column=-1,computer_first_move=1;
char turn='X';
bool draw=false;

//Funcation Defination Section

void game_board(int user){
    if(user==1)
        cout<<"\n\t\t\tComputer [X]\t PLAYER [O]\n\n";
    if(user==2)
        cout<<"\n\t\t\tPLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"\t\t\t\t     |     |     \n";
}

int computer_move(){
    int X_marked[8]={0,0,0,0,0,0,0,0};  //{row1,row2,row3,col1,col2,col3,diag1,diag2} count of X marks
    int O_marked[8]={0,0,0,0,0,0,0,0};  //{row1,row2,row3,col1,col2,col3,diag1,diag2} count of O marks
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]=='X')
                X_marked[3+j]++;
            if(board[j][i]=='X')
                X_marked[j]++;
            if(board[i][j]=='O')
                O_marked[3+j]++;
            if(board[j][i]=='O')
                O_marked[j]++;
        }
        if(board[i][i]=='X')
            X_marked[6]++;
        if(board[i][2-i]=='X')
            X_marked[7]++;
        if(board[i][i]=='O')
            O_marked[6]++;
        if(board[i][2-i]=='O')
            O_marked[7]++;
    }
    if(computer_first_move==1){
        srand(time(NULL));
        int randon_index = rand() % 9;
        computer_first_move=0;
        return randon_index+1;
    }
    vector<int> best_moves;
    for(int i=0; i<8; i++)
        if(X_marked[i]==2)
            best_moves.push_back(i);

    for(int k=0;k<best_moves.size();k++){
        if(best_moves[k]<3 && best_moves[k]>=0){
            for(int i=0;i<3;i++)
                if(board[best_moves[k]][i]!='X' && board[best_moves[k]][i]!='O')
                    return int((board[best_moves[k]][i])-'0');

        }
        if(best_moves[k]<6 && best_moves[k]>=3){
            for(int i=0;i<3;i++)
                if(board[i][best_moves[k]-3]!='X' && board[i][best_moves[k]-3]!='O' )
                    return int((board[i][best_moves[k]-3])-'0');

        }
        if(best_moves[k]==6){
            for(int i=0;i<3;i++)
                if(board[i][i]!='X' && board[i][i]!='O' )
                    return int((board[i][i])-'0');
        }
        if(best_moves[k]==7){
            for(int i=0;i<3;i++)
                if(board[i][2-i]!='X' && board[i][2-i]!='O')
                    return int((board[i][2-i])-'0');
        }
    }
    best_moves.clear();
    for(int i=0; i<8; i++)
        if(O_marked[i]==2)
            best_moves.push_back(i);

    for(int k=0;k<best_moves.size();k++){
        if(best_moves[k]<3 && best_moves[k]>=0){
        for(int i=0;i<3;i++)
            if(board[best_moves[k]][i]!='X' && board[best_moves[k]][i]!='O')
                return int((board[best_moves[k]][i])-'0');
        }
        if(best_moves[k]<6 && best_moves[k]>=3){
            for(int i=0;i<3;i++)
                if(board[i][best_moves[k]-3]!='X' && board[i][best_moves[k]-3]!='O')
                    return int((board[i][best_moves[k]-3])-'0');
        }
        if(best_moves[k]==6){
            for(int i=0;i<3;i++)
                if(board[i][i]!='X' && board[i][i]!='O')
                    return int((board[i][i])-'0');
        }
        if(best_moves[k]==7){
            for(int i=0;i<3;i++)
                if(board[i][2-i]!='X' && board[i][2-i]!='O')
                    return int((board[i][2-i])-'0');
        }
    }
    if(board[1][1]=='5')
        return 5;
    if(board[0][0]=='1')
        return 1;
    if(board[0][2]=='3')
        return 3;
    if(board[2][0]=='7')
        return 7;
    if(board[2][2]=='9')
        return 9;
    if(board[0][1]=='2')
        return 2;
    if(board[1][0]=='4')
        return 4;
    if(board[1][2]=='6')
        return 6;
    if(board[2][1]=='8')
        return 8;
}

void player_turn(int user){
    if(user==2){
        if(turn == 'X'){
            cout<<"\n\tPlayer - 1 [X] turn : ";
        }
        else if(turn == 'O'){
            cout<<"\n\tPlayer - 2 [O] turn : ";
        }
        cin>> choice;
    }
    if(user==1){
        if(turn == 'X'){
            choice=computer_move();
            cout<<"\n\tComputer [X] turn : "<<choice<<endl;
        }
        else if(turn == 'O'){
            cout<<"\n\tPlayer [O] turn : ";
            cin>> choice;
        }
    }
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
        default:cout<<"\tInvalid Move";
    }
    if(row==-1 && column==-1){
        return;
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
        cout<<"\tBox already filled!\n\tPlease choose another!!\n\n";
        player_turn(user);
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

int tictactoe_with_player(){
    cout<<"\n\t\t\t\tPlayer Vs Player\n\t\t\t\n";
    while(gameover()){
        game_board(2);
        player_turn(2);
        gameover();
    }
    if(turn == 'X' && draw == false){
        game_board(2);
        cout<<"\n\nCongratulations! Player with 'O' has won the game\n\n";
    }
    else if(turn == 'O' && draw == false){
        game_board(2);
        cout<<"\n\nCongratulations! Player with 'X' has won the game\n\n";
    }
    else{
        game_board(2);
        cout<<"\n\nGAME DRAW!!!\n\n";
    }
    return 0;
}

int tictactoe_with_computer(){
    int first_move;
    cout<<"\n\t\t\t\tComputer Vs Player\n\t\t\t";
    cout<<"\n\tDo you wish to start first:(1-yes or 2-no):";
    cin>>first_move;
    if(first_move==1){
        turn='O';
        computer_first_move=0;
    }
    while(gameover()){
        game_board(1);
        player_turn(1);
        gameover();
    }
    if(turn == 'X' && draw == false){
        game_board(1);
        cout<<"\n\nCongratulations! Player with 'O' has won the game\n\n";
    }
    else if(turn == 'O' && draw == false){
        game_board(1);
        cout<<"\n\nCongratulations! Computer with 'X' has won the game\n\n";
    }
    else{
        game_board(1);
        cout<<"\n\nGAME DRAW!!!\n\n";
    }
    return 0;
}

int main(){
    int ch;
    cout<<"\t\tT I C --- T A C --- T O E --- G A M E\t\t\n\n";
    cout<<"\tEnter The Mode (1-for 1 Player OR 2-for 2 Players):";
    cin>>ch;
    switch(ch){
        case 1:tictactoe_with_computer();break;
        case 2:tictactoe_with_player();break;
        default: cout<<"Invalid Mode\n";
    }
    return 0;
}
