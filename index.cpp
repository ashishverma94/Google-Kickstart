#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	// row and colum of matrix
  	int row = 7, col = 4 ; 
    // Matrix of size row and col
  	int Matrix[row][col] = {{1,0,0,0},
		                    {1,0,0,1},
		                    {1,1,1,1},
		                    {1,0,1,0},
		                    {1,0,1,0},
		                    {1,1,1,0},
		                    {0,0,0,0}};
  
  // prefix sum arrays 
  int left[row][col] , right[row][col] , top[row][col] , down[row][col] ;

  // Calculation of prefix sum       
 for( int i = 0 ; i < row ; i ++ )
 {
	 left[i][0] = Matrix[i][0] ;
	 right[i][col-1] = Matrix[i][col-1] ;
 }

 for( int i = 0 ; i < col ; i ++ )
 {
	 top[0][i] = Matrix[0][i] ;
	 down[row-1][i] = Matrix[row-1][i] ;
 }

// left prefix sum 
        
 for(int i=0; i<row; i++)
 {
     for(int j=1; j<col ; j++)
     {
         if(Matrix[i][j]==1)
              left[i][j]= left[i][j-1] + 1 ;
 		 else
              left[i][j]=0;
      }
 }
  
 //right prefix sum 
 for ( int i = 0 ; i < row ; i ++ )
 {
	 for ( int j = col - 2 ; j>= 0 ; j -- )
	 {
		 if ( Matrix[i][j] == 1 )
		 	right[i][j] = right[i][j+1] + 1 ;
		 else
			 right[i][j] = 0 ;
	 }
 }

 //Up prefix sum 
  for ( int i = 0 ; i < col ; i ++ )
 {
	 for ( int j = 1 ; j < row ; j ++ )
	 {
		 if ( Matrix[j][i] == 1 )
		 	top[j][i] = top[j-1][i] + 1 ;
		 else 
		 	top[j][i] = 0 ;
	 }
 }

 // Down prefix sum 

for ( int i = 0 ; i < col ; i ++ )
 {
	 for ( int j = row-2 ; j >=0 ; j -- )
	 {
		 if ( Matrix[j][i] == 1 )
		 	down[j][i] = down[j+1][i] + 1 ;
		 else 
		 	down[j][i] = 0 ;
	 }
 }

 int ans = 0 ; // ans store Total no of L in a matrix
 int segment1 , segment2 , x , y ;
 for ( int i = 0 ; i < row ; i ++ )
 {
	 for ( int j = 0 ; j < col ; j ++ )
	 {
		 // if the value of Matrix[i][j] is one then it can be a 
		 // point where two segment can meet and form L shape
		 if ( Matrix[i][j] == 1 )
		 {
		 // L formed by top segment and left segment
		 segment1 = left[i][j];
		 segment2 = top[i][j];
		 /* 
		 x contain value of total L in which segment1 is smaller
		 and segment 2 is larger 
		 y contain value of total L in which segment2 is smaller and
		 segment 1 is larger
		  */
		 x = min( segment1/2 , segment2 )-1;
		 y = min( segment1 , segment2/2 )-1;
		 // if the value of x is greater than one then add it to ans 
		 // if x==1 then L shape is not possible
		 if ( x > 0 )
		 	 ans +=x ;
		 if ( y > 0 )
		     ans +=y ;

		 // L formed by top segment and right segment
		 segment1 = right[i][j];
		 segment2 = top[i][j];

		 x = min( segment1/2 , segment2 )-1;
		 y = min( segment1 , segment2/2 )-1;
		 if ( x > 0 )
		 	 ans +=x ;
		 if ( y > 0 )
		     ans +=y ;

		 // L formed by down segment and right segment 
		 segment1 = down[i][j];
		 segment2 = right[i][j];

		 x = min( segment1/2 , segment2 )-1;
		 y = min( segment1 , segment2/2 )-1;
		 if ( x > 0 )
		 	 ans +=x ;
		 if ( y > 0 )
		     ans +=y ;

		 // L formed by down segment and left segment
		 segment1 = left[i][j];
		 segment2 = down[i][j];

		 x = min( segment1/2 , segment2 )-1;
		 y = min( segment1 , segment2/2 )-1;
		 if ( x > 0 )
		 	 ans +=x ;
		 if ( y > 0 )
		     ans +=y ;
 		 }
	 }
  }
  // Answer
  cout<<ans <<endl; 
  return 0 ;
}