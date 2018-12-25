#ifndef ___BwVehicleKinematic_H___
#define ___BwVehicleKinematic_H___
#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <ctype.h>
#include <wchar.h>

#include <math.h>
#include <float.h>
#include <limits.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>

// STL algorithms & functions
#include <algorithm>
#include <functional>
#include <limits>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <string>

#if !defined(_WIN32)
#define BW_VEHICLEKINEMATIC_API
#elif defined(BWVEHICLEKINEMATIC_EXPORTS)
#define BW_VEHICLEKINEMATIC_API __declspec(dllexport)
#else
#define BW_VEHICLEKINEMATIC_API __declspec(dllimport)
#endif
/*
#ifdef BWVEHICLEKINEMATIC_EXPORTS
#define BW_VEHICLEKINEMATIC_API __declspec(dllexport)
#else
#define BW_VEHICLEKINEMATIC_API __declspec(dllimport)
#endif
*/

#endif