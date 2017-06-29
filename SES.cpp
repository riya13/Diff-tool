#include <iostream>
#include <string>

using namespace std;

int main() {

    string A, B;
    
    // Input sequences
    cin>>A>>B; 

    int N = A.length();
    int M = B.length();
    int max = N+M;
    bool flag = false;

    int V[max+1];

    int *p = & V[(max+1)/2];

    p[1] = 0;

    for ( int d = 0 ; d <= N + M ; d++ )
    {
       for ( int k = -d ; k <= d ; k += 2 )
       {
       // down or right?
       bool down = ( k == -d || ( k != d && p[ k - 1 ] < p[ k + 1 ] ) );

       int kPrev = down ? k + 1 : k - 1;

       // start point
       int xStart = p[ kPrev ];
       int yStart = xStart - kPrev;

       // mid point
       int xMid = down ? xStart : xStart + 1;
       int yMid = xMid - k;

       // end point
       int xEnd = xMid;
       int yEnd = yMid;

       // follow diagonal
       int snake = 0;
       while ( (xEnd < N) && (yEnd < M) && (A[ xEnd ] == B[ yEnd ]) ) { xEnd++; yEnd++; snake++; }

       // save end point
       p[ k ] = xEnd;

       // check for solution
       if ( xEnd >= N && yEnd >= M ) // Solution has been found!
       {
           cout<<"Minimum edits required to convert string A into B is: "<< d << endl;
           flag = true;
           break;
       }


      }

      if(flag)
        break;

   }

return 0;

}
