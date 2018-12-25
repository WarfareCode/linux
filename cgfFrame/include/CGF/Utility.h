#if !defined(HJSIM_HYCGF_UTILITY_H)
#define HJSIM_HYCGF_UTILITY_H
#pragma once

#include "CGFDS.h"

#include <string>
using namespace std;

void ReleaseObjList(CObjList& list);

string::size_type StringFindFirstAfter(
    const string & inputString,
    const char * pFindString,
    string::size_type off
    );

#endif