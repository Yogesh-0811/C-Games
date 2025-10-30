#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void resetBoard(){
    char cell = '1';
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=cell++;
        }
    }
}

void displayBoard(){
    cout<<endl;
    cout<<"---------------"<<endl;
    for(int i=0;i<3;i++){
        cout<<"| ";
        for(int j=0;j<3;j++){
            cout<<board[i][j]<<" | ";
        }
        cout<<endl<<"---------------"<<endl;
    }
    cout<<endl;
}

void makeMove(){
    int move;
    cout<<"Player "<<currentPlayer<<", enter a number (1-9): ";
    cin>>move;

    if(move<1 || move>9){
        cout<<"Invalid move! Try again."<<endl;
        makeMove();
        return;
    }

    int row = (move-1)/3;
    int col = (move-1)%3;

    if(board[row][col]=='X' || board[row][col]=='O'){
        cout<<"That spot is already taken! Try different position."<<endl;
        makeMove();
    }else{
        board[row][col]=currentPlayer;
    }
}

bool checkWin(){
    for(int i=0;i<3;i++){
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i]==board[1][i] && board[1][i]==board[2][i])){
            return true;
        }
    }
    if((board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[0][2]==board[1][1] && board[1][1]==board[2][0])){
        return true;
    }
    return false;
}

bool checkDraw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!='X'&&board[i][j]!='O'){
                return false;
            }
        }
    }
    return true;
}

int main(){
    char playAgain;

    do{
        resetBoard();
        currentPlayer='X';
        bool gameOver = false;

        cout<<endl<<"=== Tic-Tac-Toe Game ==="<<endl;
        displayBoard();

        while(!gameOver){
            makeMove();
            displayBoard();

            if(checkWin()){
                cout<<"Player "<<currentPlayer<<" wins!!"<<endl;
                gameOver=true;
            }else if(checkDraw()){
                cout<<"It's a draw!!"<<endl;
                gameOver=true;
            }else{
                currentPlayer = (currentPlayer=='X')?'O':'X';
            }
        }

        cout<<endl<<"Do you want to play again? (y/n): ";
        cin>>playAgain;
    }while(playAgain=='y'||playAgain=='Y');

    cout<<"Thanks for playing!!"<<endl;
    return 0;
}