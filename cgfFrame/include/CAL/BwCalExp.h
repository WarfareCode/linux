
#ifndef __BW_BASE_HEADERS__
#define __BW_BASE_HEADERS__
#pragma once

#if !defined(_WIN32)
#define BW_CAL_API
#elif defined(BW_CAL_EXPORTS)
#define BW_CAL_API __declspec(dllexport)
#else
#define BW_CAL_API __declspec(dllimport)
#endif

#ifdef _DEBUG
#pragma comment(lib, "BwCald.lib")
#else
#pragma comment(lib, "BwCalr.lib")
#endif

//DS .h Files
#include "CAL/BwCal.h"
#include "CAL/BwAxisAlignedBox.h"
#include "CAL/BwCoordinates.h"
#include "CAL/BwMath.h"

#include "CAL/BwPt.h"
#include "CAL/BwQuaternion.h"
#include "CAL/BwRay.h"

#include "CAL/BwVec2.h"
#include "CAL/BwVec3.h"
#include "CAL/BwVec4.h"
#include "CAL/BwVector.h"

#include "CAL/BwMatrix3.h"
#include "CAL/BwMatrix4.h"
#include "CAL/BwMatrix.h"

#include "CAL/BwOrbitalMechanicsAlgorithms.h"

using namespace BwCal;

#endif
