class TicTacToe {
private:
    vector<int> rows;
    vector<int> cols;
    int diag;
    int reverse_diag;
    int N;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n): N(n), diag(0), reverse_diag(0){
        rows.resize(n, 0);
        cols.resize(n, 0);
    }

    int move(int row, int col, int player) {
        int add = (player==1)? 1 : -1;
        rows[row] += add;
        cols[col] += add;
        diag += (row==col)? add : 0;
        reverse_diag += (row==N-col-1)? add : 0;
        return (abs(rows[row])==N || abs(cols[col])==N
               || abs(diag)==N || abs(reverse_diag)==N)? player : 0;
    }
};
