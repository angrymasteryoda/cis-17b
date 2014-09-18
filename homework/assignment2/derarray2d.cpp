#include "derarray2d.h"

using namespace std;

const char* derArray2d::toString(){
    stringstream ss;
    ss << "<table>";
    for( int r = 0; r < nRows; r++ ){
        ss << "<tr>";
        for( int c = 0; c < nCols; c++ ){
            ss << "<td>" << array[r][c] << ",</td>";
        }
        ss << "</tr>";
    }
    ss << "</table>";
    char* chars = new char[ ss.str().length() ];
    strcpy( chars, ss.str().c_str() );
    return chars;
}
