#include <iostream>
#include <vector>

using namespace std;

pair <int,int> matrix_start(pair <char,int> start) {
    pair <int,int> s;
    s.first=start.first-'a';
    s.second=start.second-1;
    return s;
}

int available(int chessBoard[8][8], int column, int row) {
    int available=0;
    pair <int,int> start;
    start.first=column;
    start.second=row;
    if (start.first-2<8 && start.first-2>=0 && start.second-1<8 && start.second-1>=0 && chessBoard[start.first-2][start.second-1]==0) {
        available++;
    }
    if (start.first+2<8 && start.first+2>=0 && start.second-1<8 && start.second-1>=0 && chessBoard[start.first+2][start.second-1]==0) {
        available++;
    }
    if (start.first-2<8 && start.first-2>=0 && start.second+1<8 && start.second+1>=0 && chessBoard[start.first-2][start.second+1]==0) {
        available++;
    }
    if (start.first+2<8 && start.first+2>=0 && start.second+1<8 && start.second+1>=0 && chessBoard[start.first+2][start.second+1]==0) {
        available++;
    }
    if (start.first-1<8 && start.first-1>=0 && start.second-2<8 && start.second-2>=0 && chessBoard[start.first-1][start.second-2]==0) {
        available++;
    }
    if (start.first+1<8 && start.first+1>=0 && start.second-2<8 && start.second-2>=0 && chessBoard[start.first+1][start.second-2]==0) {
        available++;
    }
    if (start.first-1<8 && start.first-1>=0 && start.second+2<8 && start.second+2>=0 && chessBoard[start.first-1][start.second+2]==0) {
        available++;
    }
    if (start.first+1<8 && start.first+1>=0 && start.second+2<8 && start.second+2>=0 && chessBoard[start.first+1][start.second+2]==0) {
        available++;
    }
    return available;
}

void next(int chessBoard[8][8], pair <int,int> start) {
    static int now=2;
    int min=9;
    pair<int,int> next_move;
    if (start.first-2<8 && start.first-2>=0 && start.second-1<8 && start.second-1>=0 && chessBoard[start.first-2][start.second-1]==0) {
        if (min>available(chessBoard,start.first-2,start.second-1)) {
            min=available(chessBoard,start.first-2,start.second-1);
            next_move.first=start.first-2;
            next_move.second=start.second-1;
        }
    }
    if (start.first+2<8 && start.first+2>=0 && start.second-1<8 && start.second-1>=0 && chessBoard[start.first+2][start.second-1]==0) {
        if (min>available(chessBoard,start.first+2,start.second-1)) {
            min=available(chessBoard,start.first+2,start.second-1);
            next_move.first=start.first+2;
            next_move.second=start.second-1;
        }
    }
    if (start.first-2<8 && start.first-2>=0 && start.second+1<8 && start.second+1>=0 && chessBoard[start.first-2][start.second+1]==0) {
        if (min>available(chessBoard,start.first-2,start.second+1)) {
            min=available(chessBoard,start.first-2,start.second+1);
            next_move.first=start.first-2;
            next_move.second=start.second+1;
        }
    }
    if (start.first+2<8 && start.first+2>=0 && start.second+1<8 && start.second+1>=0 && chessBoard[start.first+2][start.second+1]==0) {
        if (min>available(chessBoard,start.first+2,start.second+1)) {
            min=available(chessBoard,start.first+2,start.second+1);
            next_move.first=start.first+2;
            next_move.second=start.second+1;
        }
    }
    if (start.first-1<8 && start.first-1>=0 && start.second-2<8 && start.second-2>=0 && chessBoard[start.first-1][start.second-2]==0) {
        if (min>available(chessBoard,start.first-1,start.second-2)) {
            min=available(chessBoard,start.first-1,start.second-2);
            next_move.first=start.first-1;
            next_move.second=start.second-2;
        }
    }
    if (start.first+1<8 && start.first+1>=0 && start.second-2<8 && start.second-2>=0 && chessBoard[start.first+1][start.second-2]==0) {
        if (min>available(chessBoard,start.first+1,start.second-2)) {
            min=available(chessBoard,start.first+1,start.second-2);
            next_move.first=start.first+1;
            next_move.second=start.second-2;
        }
    }
    if (start.first-1<8 && start.first-1>=0 && start.second+2<8 && start.second+2>=0 && chessBoard[start.first-1][start.second+2]==0) {
        if (min>available(chessBoard,start.first-1,start.second+2)) {
            min=available(chessBoard,start.first-1,start.second+2);
            next_move.first=start.first-1;
            next_move.second=start.second+2;
        }
    }
    if (start.first+1<8 && start.first+1>=0 && start.second+2<8 && start.second+2>=0 && chessBoard[start.first+1][start.second+2]==0) {
        if (min>available(chessBoard,start.first+1,start.second+2)) {
            min=available(chessBoard,start.first+1,start.second+2);
            next_move.first=start.first+1;
            next_move.second=start.second+2;
        }
    }
    chessBoard[next_move.first][next_move.second]=now;
    now++;
    if (now<=64) {
        next(chessBoard,next_move);
    }
}

int main() {
    pair <char,int> s;
    cin>>s.first>>s.second;
    int chessBoard[8][8]={0};
    pair <int,int> start=matrix_start(s);
    chessBoard[start.first][start.second]=1;
    next(chessBoard,start);
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            cout<<chessBoard[i][j]<<" ";
        }
        cout<<endl;
    }
}