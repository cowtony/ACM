#include<stdio.h>
#include<string.h>
int f[10][10];
int ok;
int tu[10][10];
int row[10][10];
int cu[10][10];
int map[10][10];

int tst[10][10][10];
int top[10][10];


void DFS( int i, int j )
{
     int t, k, r, z;
     if( i == 10 && j == 1 )
     {
         for( i = 1; i <= 9; i++ )
         {
             for( j = 1; j <= 9; j++ )
             {
                 printf( "%d", map[i][j] );
             }
             printf( "\n" );
         }
         ok = 1;
         return;
     }
     if( map[i][j] == 0 )
     {
         r = i;
         k = j+1;
         if( j+1 > 9 )
         {   
             r = i+1;
             k = 1;
         }
         for( z = 0; z < top[i][j]; z++ )
         {
             t = tst[i][j][z];
             if( tu[f[i][j]][t] == 0 && row[i][t] == 0 && cu[j][t] == 0 )
             {
                 tu[f[i][j]][t] = row[i][t] = cu[j][t] = 1;
                 map[i][j] = t;
                 DFS( r, k );
                 if( ok )return;
                 map[i][j] = 0;
                 tu[f[i][j]][t] = row[i][t] = cu[j][t] = 0;
             }
         }
     }
     else
     {
         r = i;
         k = j+1;
         if( j+1 > 9 )
         {
                    
             r = i+1;
             k = 1;
         }
         DFS( r, k );
         if( ok )return;
     }
    
}   

void Work()
{
     ok = 0;
     DFS( 1, 1 );
}


int main()
{
     int i, j, kcase, k;
     char c[10][10];
     scanf( "%d", &kcase );
     for( i = 1; i <= 9; i++ )
     {
         for( j = 1; j <= 9; j++ )
         {
             if( i <= 3 && j <= 3 )f[i][j] = 1;
             else if( j >= 4 && j <= 6 && i <= 3 )f[i][j] = 2;
             else if( j >= 7 && i <= 3 )f[i][j] = 3;
             else if( i <= 6 && j <= 3 )f[i][j] = 4;
             else if( j >= 4 && j <= 6 && i <= 6 )f[i][j] = 5;
             else if( j >= 7 && i <= 6 )f[i][j] = 6;
             else if( i <= 9 && j <= 3 )f[i][j] = 7;
             else if( j >= 4 && j <= 6 && i <= 9 )f[i][j] =8;
             else f[i][j] = 9;
         }
     }       
     while( kcase-- )
     {
         memset( tu, 0, sizeof( tu ) );
         memset( cu, 0, sizeof( cu ) );
         memset( row, 0, sizeof( row ) );
        
         for( i = 0; i < 9; i++ )scanf( "%s", c[i] );
         for( i = 0; i < 9; i++ )
         {
             for( j = 0; j < 9; j++ )
             {
                
                 if( c[i][j] > '0' && c[i][j] <= '9' )
                 {
                     tu[f[i+1][j+1]][c[i][j]-'0'] = 1;
                     row[i+1][c[i][j]-'0'] = 1;
                     cu[j+1][c[i][j]-'0'] = 1;
                 }
                 map[i+1][j+1] = c[i][j] - '0';
             }
         }
         for( i = 1; i <= 9; i++ )
         {
             for( j = 1; j <= 9; j++ )
             {
                 top[i][j] = 0;
                 for( k = 9; k >=1; k-- )
                 {
                     if( tu[f[i][j]][k] == 0 && row[i][k] == 0 && cu[j][k] == 0 )
                     {
                         tst[i][j][top[i][j]++] = k;
                     }
                 }
             }
            
            
         }
        
         Work();
     }
    
    
}
