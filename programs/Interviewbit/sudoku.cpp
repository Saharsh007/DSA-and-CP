#define f(i,a,b) for(long long i=a;i<b;i++)
#define debug3(a,b,c) cout<<a<<"->"<<b<<"->"<<c<<"\n"



int findempty(vector<vector<char>> A,int &row,int &col){
    //pass by reference the first empty cell
    f(i,0,9){
        f(j,0,9){
            if(A[i][j] == '.'){
                row = i;
                col = j;
                // debug3(row,col,"hey");
                return 1;
            }
        }
    }
    return 0;
}

int checkrow(vector<vector<char>> A,int row, char currnum){
    f(i,0,9)
        if(A[row][i] == currnum) 
            return 0;
            
    return 1;
}

int checkcol(vector<vector<char>> A,int col, char currnum){
    f(i,0,9)
        if(A[i][col] == currnum) 
            return 0;
    
    return 1;
}

int checkbox(vector<vector<char>> A,int row,int col, char currnum){
    f(i, (row/3)*3, (row/3)*3+3){
        f(j, (col/3)*3, (col/3)*3+3 ){
            if(A[i][j] == currnum)
                return 0;
        }
    }
    return 1;
}

int issafe(vector<vector<char>> A,int row,int col, char currnum){
    if( checkrow(A,row,currnum) && checkcol(A,col,currnum) && checkbox(A,row,col,currnum) )
        return 1;
    return 0;
}

int mainsolver(vector<vector<char>> &A){
    int row,col;
    //if all cells are filled return 1,else pass by reference row and column
    if(!findempty(A,row,col)) return 1;
    
    //check which number satifies all three conditions
    f(i,1,10){
        char currnum = i+'0';
        //if this number satisfies all three coditions , put it in place
        if( issafe(A,row,col,currnum) ){
            A[row][col] = currnum;
            
            // if 1 returned then nothing else to solve
            if( mainsolver(A)){
                return 1;
            }
            // if not then this choice didn't lead to a solved sudoku
            //so we unassign it and again solve it with a different number
            A[row][col] = '.';
            
         }
    }
    return 0;
    
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    //space and time pass
    vector<int> v(20); int x=30; while(x) x--; 
    x = mainsolver(A);
    // return A;
}