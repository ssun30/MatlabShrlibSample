/* shrlibsample.cpp
 *
 * Sample C shared library for use with MATLAB Shared 
 * Library Calling (CALLLIB)
 * Copyright 2002-2008 The MathWorks, Inc.
 *
 */

/* shrlibsample.cpp
*
* Sample C shared library for use with MATLAB Shared 
 * Library Calling (CALLLIB)
* Copyright 2002-2008 The MathWorks, Inc.
*
*/

#include <string>
#include <iostream>
#include <vector>
#define EXPORT_FCNS
#include "shrhelp.h"

#include "shrlibsample.h"


using namespace std;

size_t copyString(char* dest, size_t length)
{
    std::string longStr = "abccdefghijklmnopqrstuvwxyzabccdefghijklmnopqrstuvwxyzabccdefghijklmnopqrstuvwxyz";
    const char* src = longStr.c_str();
    std::cout << "this is a message for staandard output" << std::endl ;
    std::cout << "length = " << length << std::endl ;
    std::cout << "longStr.length() = " << longStr.length()  << std::endl ;
    size_t N = std::min(length, longStr.length() + 1);
    std::cout << "N = " << N  << std::endl ;
    size_t ret = (length >= longStr.length() + 1) ? 0 : longStr.length() + 1;
    std::cout << "ret = " << ret  << std::endl ;
    std::cout << "src = " << src  << std::endl ;
    std::copy(src, src + N, dest);
    std::cout << "dest = " << dest  << std::endl ;
    if (length != 0) {
        dest[length-1] = '\0';
    }
    std::cout << "dest = " << dest  << std::endl ;
    return ret;
}

size_t copyArray( double* x, size_t lenx)
{
    size_t size = 80;
    std::vector<double> array(size);
    for(int i=0; i<size; ++i) {
        array[i] = i;
    }
    std::cout << "this is a message for standard output" << std::endl ;
    std::cout << "lenx = " << lenx << std::endl ;
    std::cout << "array.size() = " << array.size()  << std::endl ;
    if (lenx < array.size() ) {
        return -1;
    }
    std::cout << "array = "  ;
    for (std::vector<double>::const_iterator i = array.begin(); i != array.end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl ;

    std::copy(array.begin(), array.end(), x);

    std::cout << "x = " ;
    for (int i=0; i<array.size(); ++i)
        std::cout << x[i] << ' ';
    std::cout << std::endl ;

    return 0;
}


extern "C" { 
    EXPORTED_FUNCTION void multDoubleArray(double *x,int size)
    {
        /* Multiple each element of the array by 3 */
        int i;
        for (i=0;i<size;i++)
        *x++ *= 3;
    }

    EXPORTED_FUNCTION double addMixedTypes(short x,int y,double z)
    {
        return (x + y + z);
    }

    EXPORTED_FUNCTION double addDoubleRef(double x,double *y,double z)
    {
        return (x + *y + z);
    }

    EXPORTED_FUNCTION const char* stringToUpper(char *input)
    {
        char *p = input;

        if (p!=NULL) 
        {
            while (*p!=0)
            {
                *p = toupper(*p);
                p++;
            }
            return input;
        } 
        else 
        {
            static const char * output = "Null pointer passed to stringToUpper.";
            return output;
        } 
    }

    EXPORTED_FUNCTION char* readEnum(TEnum1 val)
    {
        static char outputs[][20] = { {"You chose en1"}, {"You chose en2"}, {"You chose en4"}, {"enum not defined"}, {"ERROR"} };
        
        switch (val) {
        case en1: return outputs[0];
        case en2: return outputs[1];
        case en4: return outputs[2];
        default : return outputs[3];
        }	
        return outputs[4];
    }

    EXPORTED_FUNCTION double addStructFields(struct c_struct st)
    {
        double t = st.p1 + st.p2 + st.p3;
        return t;
    }

    EXPORTED_FUNCTION double *multDoubleRef(double *x)
    {
        *x *= 5;
        return x;
    }

    EXPORTED_FUNCTION double addStructByRef(struct c_struct *st)
    {
        double t = st->p1+st->p2+st->p3;
        st->p1=5.5;
        st->p2=1234;
        st->p3=12345678;
        return t;
    }

    EXPORTED_FUNCTION void allocateStruct(struct c_struct** val)
    {
        /* allocate zeroed space for 5 copies of c_struct */
        struct c_struct* local=(struct c_struct*) calloc(sizeof(struct c_struct),5);
        *val=local; /* assign val to the first set of values */
        local->p1 = 12.4;
        local->p2 = 222;
        local->p3 = 333333;
        local++;
        local->p1 = 2.1;
        local->p2 = 22;
        local->p3 = 23;
    }

    
    EXPORTED_FUNCTION void deallocateStruct(void *ptr)
    {
        free(ptr);
    }

    
    EXPORTED_FUNCTION void multiplyShort(short *x, int size)
    {
        int i;
        for (i=0; i<size; i++)
        *x++ *= i;
    }

    EXPORTED_FUNCTION const char ** getListOfStrings(void)
    {
        static const char *strings[5];
        strings[0]="String 1";
        strings[1]="String Two";
        strings[2]=""; /* empty string */
        strings[3]="Last string";
        strings[4]=NULL;
        return strings;
    }

    EXPORTED_FUNCTION int createLongStr(int buflen, char* buf)
    {
        return static_cast<int>(copyString(buf, static_cast<size_t>(buflen)));
    }

    EXPORTED_FUNCTION int createDoubleArray(int buflen, double* buf)
    {
        return static_cast<int>(copyArray(buf, static_cast<size_t>(buflen)));
    }
}
