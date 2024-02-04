/*
    Author: Rovia Simmons
    main.cpp is used for testing functions in mymatrix.h
*/

#include <iostream>
#include <exception>
#include <stdexcept>
#include "mymatrix.h"

using namespace std;

// Default tests test if size, rows, and columns are accurate.
bool testDefSize(){
    mymatrix<int> M;
    if(M.size() == 16) 
        return true;
    else{
        cout << "Failed test: testDefSize\n";
        return false;
    }
}
bool testDefRows(){
    mymatrix<int> M;
    if(M.numrows() == 4) 
        return true;
    else{
        cout << "Failed test: testDefRows\n";
        return false;
    }
}
bool testDefCols(){
    mymatrix<int> M;
    for(int i = 0; i < M.numrows(); i++){
      if(M.numcols(0) != 4){
        cout << "Failed test: testDefCols\n";
        return false;
      }
    }
    return true;
}

//Tests if different types work
bool testValChar(){
    mymatrix<char> M;
    if(M.size() == 16) 
        return true;
    else{
        cout << "Failed test: testValChar\n";
        return false;
    }
}
bool testValStr(){
    mymatrix<string> M;
    if(M.size() == 16) 
        return true;
    else{
        cout << "Failed test: testValStr\n";
        return false;
    }
}
bool testValBool(){
    mymatrix<bool> M;
    if(M.size() == 16) 
        return true;
    else{
        cout << "Failed test: testValBool\n";
        return false;
    }
}

//tests paramaterized constructor
bool testSmallRows(){
    mymatrix<int> M(1,1);
    if(M.numrows() == 1) 
        return true;
    else{
        cout << "Failed test: testSmallRows\n";
        return false;
    }
}
bool testLargeRows(){
    mymatrix<int> M(67,1);
    if(M.numrows() == 67) 
        return true;
    else{
        cout << "Failed test: testLargeRows\n";
        return false;
    }
}
bool testSmallCols(){
    mymatrix<int> M(2,1);
    if(M.numcols(0) == 1 && M.numcols(1) == 1)
        return true;
    else{
        cout << "Failed test: testSmallCols\n";
        return false;
    }
}
bool testLargeCols(){
    mymatrix<int> M(2,67);
    if(M.numcols(0) == 67 && M.numcols(1) == 67)
        return true;
    else{
        cout << "Failed test: testLargeCols\n";
        return false;
    }
}
bool testColsRect(){
    mymatrix<int> M(7,3);
    for(int i = 0; i < M.numrows(); i++){
        for(int j = i; j < M.numrows(); j++){
            if(M.numcols(i) != M.numcols(j)){
                cout << "Failed test: testLargeCols\n";
                return false;
            }
        }
    }
    return true;
}

//copy constructor tests
bool testCopyBasic(){
    mymatrix<int> M;
    mymatrix<int> N(M);

    for(int r = 0; r < M.numrows(); r++){
        for(int c = 0; c < M.numcols(r); c++){
            if(M.at(r,c) != N.at(r,c)){
                cout << "Failed test: testCopyBasic\n";
                return false;
            }
        }
    }
    return true;
}
bool testCopyChanges(){
    mymatrix<int> M;
    mymatrix<int> N(M);

    M.at(0,0) = 24;
    if(N.at(0,0) != 24)
        return true;
    else{
        cout << "Failed test: testCopyChanges\n";
        return false;
    }
}
bool testCopyJagged(){
    mymatrix<int> M;
    M.growcols(1, 8);
    mymatrix<int> N(M);

    if(N.numcols(1) == 8)
        return true;
    else{
        cout << "Failed test: testCopyJagged\n";
        return false;
    }
}

//test growcols
bool testShrinkCols(){
    mymatrix<int> M;
    M.growcols(0,1);
    if(M.numcols(0) == 4)
        return true;
    else{
        cout << "Failed test: testShrinkCols\n";
        return false;
    }
}
bool testGrowOneCol(){
    mymatrix<int> M;
    M.growcols(0,10);
    if(M.numcols(0) == 10)
        return true;
    else{
        cout << "Failed test: testGrowOneCol\n";
        return false;
    }
}
bool testGrowMultiCol(){
    mymatrix<int> M;
    M.growcols(0,7);
    M.growcols(0,10);
    M.growcols(0,6);
    M.growcols(0,9);
    M.growcols(1,7);
    if(M.numcols(0) == 10 && M.numcols(1) == 7)
        return true;
    else{
        cout << "Failed test: testGrowMultiCol\n";
        return false;
    }
}

//test grow
bool testShrink(){
    mymatrix<int> M;
    M.grow(1,1);
    if(M.numcols(0) == 4 && M.numrows() == 4)
        return true;
    else{
        cout << "Failed test: testShrink\n";
        return false;
    }
}
bool testGrowRowsOnly(){
    mymatrix<int> M;
    M.grow(10,1);
    if(M.numcols(0) == 4 && M.numrows() == 10)
        return true;
    else{
        cout << "Failed test: testGrowRowsOnly\n";
        return false;
    }
}
bool testGrowColsOnly(){
    mymatrix<int> M;
    M.grow(1,10);
    if(M.numcols(0) == 10 && M.numrows() == 4)
        return true;
    else{
        cout << "Failed test: testGrowColsOnly\n";
        return false;
    }
}
bool testGrow(){
    mymatrix<int> M;
    M.grow(10,10);
    if(M.numcols(0) == 10 && M.numrows() == 10)
        return true;
    else{
        cout << "Failed test: testGrow\n";
        return false;
    }
}
bool testJaggedColGrow(){
    mymatrix<int> M;
    M.growcols(1,10);
    M.grow(4,7);
    if(M.numcols(0) == 7 && M.numcols(1) == 10)
        return true;
    else{
        cout << "Failed test: testJaggedColGrow\n";
        return false;
    }
}
bool testJaggedGrow(){
    mymatrix<int> M;
    M.grow(6,2);
    if(M.numcols(0) == 4 && M.numcols(5) == 2)
        return true;
    else{
        cout << "Failed test: testJaggedGrow\n";
        return false;
    }
}

//test & operator
void refTest(mymatrix<int> &M){
    M.at(2,2) = 6;
}
bool refTest(){
    mymatrix<int> M;
    refTest(M);
    if(M.at(2,2) == 6)
        return true;
    else{
        cout << "Failed test: refTest\n";
        return false;
    }
}

//test scalar
bool testScalar(){
    mymatrix<int> M;
    
    M.at(0,0) = 2;
    M.at(2,2) = 4;
    M = M * 2;

    if(M.at(0,0) == 4 && M.at(2,2) == 8)
        return true;
    else{
        cout << "Failed test: testScalar\n";
        return false;
    }
}
bool testScalarMultiple(){
    mymatrix<int> M;
    M.at(0,0) = 2;
    M.at(2,2) = 4;

    M = M * 2 * 2;
    M = M * 3;

    if(M.at(0,0) == 24 && M.at(2,2) == 48)
        return true;
    else{
        cout << "Failed test: testScalarMultiple\n";
        return false;
    }
}
bool testScalarDouble(){
    mymatrix<double> M;
    
    M.at(0,0) = 2.4;
    M.at(2,2) = 6.2;
    M = M * 0.5;

    if(M.at(0,0) < 1.21 && M.at(0,0) > 1.19
    && M.at(2,2) < 3.11 && M.at(2,2) > 3.09)
        return true;
    else{
        cout << "Failed test: testScalarDouble\n";
        return false;
    }
}
bool testScalarNegative(){
    mymatrix<int> M;
    
    M.at(0,0) = 2;
    M.at(2,2) = 4;
    M = M * -1;

    if(M.at(0,0) == -2 && M.at(2,2) == -4)
        return true;
    else{
        cout << "Failed test: testScalarNegative\n";
        return false;
    }
}
bool testScalarJagged(){
    mymatrix<int> M(3,3);
    M.growcols(2,7);
    M.at(0,0) = 2;
    M.at(2,6) = 4;
    M = M * 2;

    if(M.at(0,0) == 4 && M.at(2,6) == 8)
        return true;
    else{
        cout << "Failed test: testScalarJagged\n";
        return false;
    }
}

//Matrix Multiplication
void fillTwos(mymatrix<int> &M){
    for(int r = 0; r < M.numrows(); r++){
        for(int c = 0; c < M.numcols(r); c++){
            M.at(r,c) = 2;
        }
    }
}
bool testMtxMultBasic(){
    mymatrix<int> M;
    fillTwos(M);
    M = M * M;

    for(int r = 0; r < M.numrows(); r++){
        for(int c = 0; c < M.numcols(r); c++){
            if(M.at(r,c) != 16){
                cout << "Failed test: testMtxMultBasic\n";
                return false;
            }
        }
    }

    return true;
}
bool testMtxMultDiff(){
    mymatrix<int> M(3,2), N(2,4);
    fillTwos(M);
    fillTwos(N);
    M = M * N;

    if(M.size() != 12){
        cout << "Failed test: testMtxMultDiff\n";
        return false;
    }
    for(int r = 0; r < M.numrows(); r++){
        for(int c = 0; c < M.numcols(r); c++){
            if(M.at(r,c) != 8){
                cout << "Failed test: testMtxMultDiff\n";
                return false;
            }
        }
    }
    return true;
}
bool testMtxMultMult(){
    mymatrix<int> M(3,2), N(2,4), P(4,3);
    fillTwos(M);
    fillTwos(N);
    fillTwos(P);
    M = M * N * P;

    if(M.size() != 9){
        cout << "Failed test: testMtxMultMult\n";
        return false;
    }
    for(int r = 0; r < M.numrows(); r++){
        for(int c = 0; c < M.numcols(r); c++){
            if(M.at(r,c) != 64){
                cout << "Failed test: testMtxMultMult\n";
                return false;
            }
        }
    }
    return true;
}
bool testMultnScale(){
    mymatrix<int> M;
    fillTwos(M);
    M = M * M * 2;

    for(int r = 0; r < M.numrows(); r++){
        for(int c = 0; c < M.numcols(r); c++){
            if(M.at(r,c) != 32){
                cout << "Failed test: testMultnScale\n";
                return false;
            }
        }
    }

    return true;
}

//Exception Tests
//Exception tests for the parameterized constructor
bool exceptionConstructor(){
    try{
        mymatrix<int> M(-1,4);
        cout << "constructor test failed: invalid number of rows did not throw exception\n";
        return false;
    }  
    catch(exception &e){
        try{
            mymatrix<int> M(4,-1);
            cout << "constructor test failed: invalid number of columns did not throw exception\n";
            return false;
        }
        catch(exception &e){
            return true;
        }
    }
}
//Exception tests for the numcols function
bool exceptionNumcols(){
    mymatrix<int> M;
    try{
        M.at(5000,0);
        cout << "numcols test failed: row out of bounds did not throw exception\n";
        return false;
    }  
    catch(exception &e){
        try{
            M.at(-1,0);
            cout << "numcols test failed: row out of bounds did not throw exception\n";
            return false;
        }
        catch(exception &e){
            return true;
        }
    }
}
//Exception tests for the growcols function
bool exceptionGrowcolsC(){
    mymatrix<int> M, result;
    try{
        M.growcols(0,0);
        result = M * M;
        cout << "growcols test failed: invalid columns did not throw exception\n";
        return false;
    }
    catch(exception &e){
        return true;
    }
}
bool exceptionGrowcolsR(){
    mymatrix<int> M;
    try{
        M.growcols(5000,10);
        cout << "growcols test failed: invalid row did not throw exception\n";
        return false;
    }  
    catch(exception &e){
        try{
            M.growcols(-10,10);
            cout << "growcols test failed: invalid row did not throw exception\n";
            return false;
        }
        catch(exception &e){
            return true;
        }
    }
}
//Exception tests for the grow function
bool exceptionGrow(){
    mymatrix<int> M;
    try{
        M.grow(-6,10);
        cout << "grow test failed: invalid row did not throw exception\n";
        return false;
    }  
    catch(exception &e){
        try{
            M.grow(10,-6);
            cout << "grow test failed: invalid column did not throw exception\n";
            return false;
        }
        catch(exception &e){
            return true;
        }
    }
}
//Exception Tests for the at function
bool exceptionOOBRow(){
    mymatrix<int> M;
    try{
        M.at(5000,0);
        cout << "accessor test failed: row out of bounds did not throw exception\n";
        return false;
    }  
    catch(exception &e){
        try{
            M.at(-1,0);
            cout << "accessor test failed: row out of bounds did not throw exception\n";
            return false;
        }
        catch(exception &e){
            return true;
        }
    }
}
bool exceptionOOBCol(){
    mymatrix<int> M;
    try{
        M.at(0,5000);
        cout << "accessor test failed: column out of bounds did not throw exception\n";
        return false;
    }
    catch(exception &e){
        try{
            M.at(0,-10);
            cout << "accessor test failed: column out of bounds did not throw exception\n";
            return false;
        }
        catch(exception &e){
            return true;
        }
    }
}
//Exception tests for Matrix Multiplication
bool exceptionJaggedMult(){
    mymatrix<int> M, result;
    M.grow(6,2);
    try{
        result = M * M;
        cout << "matrix multiply test failed: jagged matrix did not throw exception\n";
        return false;
    }
    catch(exception &e){
        return true;
    }
}
bool exceptionMismatchMult(){
    mymatrix<int> M(5,4), N(3,2), result;
    try{
        result = M * N;
        cout << "matrix multiply test failed: size mismatch did not throw exception\n";
        return false;
    }
    catch(exception &e){
        return true;
    }
}


int main() {
    int passed = 0, failed = 0;
    //tests
    (testDefSize()) ? passed++ : failed++;
    (testDefRows()) ? passed++ : failed++;
    (testDefCols()) ? passed++ : failed++;
    (testValChar()) ? passed++ : failed++;
    (testValStr()) ? passed++ : failed++;
    (testValBool()) ? passed++ : failed++;
    (testSmallRows()) ? passed++ : failed++;
    (testLargeRows()) ? passed++ : failed++;
    (testSmallCols()) ? passed++ : failed++;
    (testLargeCols()) ? passed++ : failed++;
    (testColsRect()) ? passed++ : failed++;
    (testCopyBasic()) ? passed++ : failed++;
    (testCopyChanges()) ? passed++ : failed++;
    (testCopyJagged()) ? passed++ : failed++;
    (testShrinkCols()) ? passed++ : failed++;
    (testGrowOneCol()) ? passed++ : failed++;
    (testGrowMultiCol()) ? passed++ : failed++;
    (testShrink()) ? passed++ : failed++;
    (testGrowRowsOnly()) ? passed++ : failed++;
    (testGrowColsOnly()) ? passed++ : failed++;
    (testGrow()) ? passed++ : failed++;
    (testJaggedColGrow()) ? passed++ : failed++;
    (testJaggedGrow()) ? passed++ : failed++;
    (refTest()) ? passed++ : failed++;
    (testScalar()) ? passed++ : failed++;
    (testScalarMultiple()) ? passed++ : failed++;
    (testScalarDouble()) ? passed++ : failed++;
    (testScalarNegative()) ? passed++ : failed++;
    (testScalarJagged()) ? passed++ : failed++;
    (testMtxMultBasic()) ? passed++ : failed++;
    (testMtxMultDiff()) ? passed++ : failed++;
    (testMtxMultMult()) ? passed++ : failed++;
    (testMultnScale()) ? passed++ : failed++;
    //exceptions
    (exceptionConstructor()) ? passed++ : failed++;
    (exceptionNumcols()) ? passed++ : failed++;
    (exceptionGrowcolsC()) ? passed++ : failed++;
    (exceptionGrowcolsR()) ? passed++ : failed++;
    (exceptionGrow()) ? passed++ : failed++;
    (exceptionOOBCol()) ? passed++ : failed++;
    (exceptionOOBRow()) ? passed++ : failed++;
    (exceptionJaggedMult()) ? passed++ : failed++;
    (exceptionMismatchMult()) ? passed++ : failed++;
    
    
    cout << "tests passed: " << passed << " | tests failed: " << failed << endl;
    return 0;
}
