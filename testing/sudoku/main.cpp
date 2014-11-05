/* 
 * File:   main.cpp
 * Author: michael.risher
 *
 * Created on November 4, 2014, 2:32 PM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <ctime>

using namespace std;

/*
 * 
 */
void print( const int* matrix);
int main( int argc, char** argv ) {
    srand( time(NULL) );
    //make root sudoku
    int *matrix = new int[9 * 9];
    for ( int i = 0; i < 9; i++ ) {
        for ( int j = 0; j < 9; j++ ) {
            matrix[i * 9 + j] = (int) ( i * 3 + floor( i / 3 ) + j ) % 9 + 1;
        }
    }

    print( matrix );
    // randomly shuffle the numbers in the root sudoku. pick two
    for ( int i = 0; i < 42; i++ ) {
        int n1 = ( rand( ) % 9 ) + 1; 
        int n2;
        do {
            n2 = ( rand( ) % 9 ) + 1;
        } while ( n1 == n2 );
        
        for ( int  row = 0; row < 9; row++ ) {
            for ( int col = 0; col < 9; col++ ) {
                if ( matrix[row * 9 + col] == n1 )
                    matrix[row * 9 + col] = n2;
                else if ( matrix[row * 9 + col] == n2 )
                    matrix[row * 9 + col] = n1;
            }
        }
    }
    
    print( matrix );
    
    for( int i = 0; i < 42; i++ ){
        int s1 = ( rand() % 3 );
        int s2 = ( rand() % 3 );
        
        for( int row = 0; row < 9; row++ ){
            int temp = matrix[ row * 9 + ( s1 *3 + i % 3 )];
            matrix[row * 9 + (s1 * 3 + i % 3)] = matrix[row * 9 + (s2 * 3 + i % 3)];
            matrix[row * 9 + (s2 * 3 + i % 3)] = temp;
        }
    }
    
    //cout << "randomly swap corresponding columns from each column of\n";
    print( matrix );
    
    for( int i = 0; i < 42; i++ ){
        int c1 = ( rand() % 3 );
        int c2 = ( rand() % 3 );
        
        for( int row = 0; row < 9; row++ ){
            int temp = matrix[row * 9 + (i % 3 * 3 + c1)];
            matrix[row * 9 + (i % 3 * 3 + c1)] = matrix[row * 9 + (i % 3 * 3 + c2)];
            matrix[row * 9 + (i % 3 * 3 + c2)] = temp;
        }
    }
    
    print( matrix );
    for( int i = 0; i < 42; i++ ){
        int r1 = ( rand() % 3 );
        int r2 = ( rand() % 3 );
        
        for( int col = 0; col < 9; col++ ){
            int temp = matrix[(i % 3 * 3 + r1) * 9 + col];
            matrix[(i % 3 * 3 + r1) * 9 + col] = matrix[(i % 3 * 3 + r2) * 9 + col];
            matrix[(i % 3 * 3 + r2) * 9 + col] = temp;
        }
    }
    print( matrix );
    
   
    delete [] matrix;

    return 0;
}

void print( const int* matrix){
    cout << endl;
    for ( int i = 0; i < 9; i++ ) {
        for ( int j = 0; j < 9; j++ ) {
            cout << matrix[i * 9 + j] << " ";
        }
        cout << endl;
    }
}

