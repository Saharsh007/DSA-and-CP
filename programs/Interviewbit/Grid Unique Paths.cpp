int Solution::uniquePaths(int A, int B) {
   int path = 1; 
    for (int i = B; i < (A + B - 1); i++) { 
        path *= i; 
        path /= (i - B + 1); 
    } 
    return path; 
}


/*
There is a mathematical approach to solving this problem.

Note that you have to take m + n - 2 steps in total. You have to take (m - 1) steps going down and (n-1) steps going right.

Let 0 denote a down step and 1 denote a right step.

So we need to find out the number of strings of length m + n - 2 which have exactly m - 1 zeroes and n - 1 ones.

Essentially we need to choose the positions of ‘1s’, and then ‘0s’ fall into the remaining positions.

So, the answer becomes Choose(m+n-2, n - 1).
*/