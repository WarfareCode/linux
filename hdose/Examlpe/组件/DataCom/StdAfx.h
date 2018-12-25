// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料

// Windows 头文件:
#include <stdlib.h>
#include <windows.h>
#include <HDOSE.h>

#ifdef  DataCom_EXPORTS
#define DATACOM_API __declspec(dllexport)
#else
#define DATACOM_API __declspec(dllimport)
#endif
