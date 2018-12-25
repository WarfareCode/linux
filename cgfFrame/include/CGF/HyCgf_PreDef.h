#ifndef _HJSIM_HYCGF_PREDEF_H_
#define _HJSIM_HYCGF_PREDEF_H_
#pragma once

#include "CAL/BwCalExp.h"
#include "hdose.h"

#if !defined(_WIN32)
#define HYCGF_API
#elif defined(HYCGF_EXPORTS)
#define HYCGF_API __declspec(dllexport)
#else
#define HYCGF_API __declspec(dllimport)
#endif

#ifdef _HDOSE_LINUX
#ifdef _DEBUG
 //xks
	#define APIENTRY     __stdcall
	#define DLL_PROCESS_ATTACH   1
	#define DLL_THREAD_ATTACH    2
	#define DLL_THREAD_DETACH    3
	#define DLL_PROCESS_DETACH   0

	#define NULL 0

    #define __null
    #define __notnull
    #define __maybenull
    #define __readonly
    #define __notreadonly
    #define __maybereadonly
    #define __valid
    #define __notvalid
    #define __maybevalid
    #define __readableTo(extent)
    #define __elem_readableTo(size)
    #define __byte_readableTo(size)
    #define __writableTo(size)
    #define __elem_writableTo(size)
    #define __byte_writableTo(size)
    #define __deref
    #define __pre
    #define __post
    #define __precond(expr)
    #define __postcond(expr)
    #define __exceptthat
    #define __execeptthaHyCgf_PreDeft
    #define __inner_success(expr)
    #define __inner_checkReturn
    #define __inner_typefix(ctype)
    #define __inner_override
    #define __inner_callback
    #define __inner_blocksOn(resource)
    #define __inner_fallthrough_dec
    #define __inner_fallthrough
    #define __refparam
    #define __inner_control_entrypoint(category)
    #define __inner_data_entrypoint(category)

#define __ecount(size)                                          __notnull __elem_writableTo(size)
#define __bcount(size)                                          __notnull __byte_writableTo(size)
#define __in                                                    __pre __valid __pre __deref __readonly
#define __in_ecount(size)                                       __in __pre __elem_readableTo(size)
#define __in_bcount(size)                                       __in __pre __byte_readableTo(size)
#define __in_z                                                  __in __pre __nullterminated
#define __in_ecount_z(size)                                     __in_ecount(size) __pre __nullterminated
#define __in_bcount_z(size)                                     __in_bcount(size) __pre __nullterminated
#define __in_nz                                                 __in
#define __in_ecount_nz(size)                                    __in_ecount(size)
#define __in_bcount_nz(size)                                    __in_bcount(size)
#define __out                                                   __ecount(1) __post __valid __refparam
#define __out_ecount(size)                                      __ecount(size) __post __valid __refparam
#define __out_bcount(size)                                      __bcount(size) __post __valid __refparam
#define __out_ecount_part(size,length)                          __out_ecount(size) __post __elem_readableTo(length)
#define __out_bcount_part(size,length)                          __out_bcount(size) __post __byte_readableTo(length)
#define __out_ecount_full(size)                                 __out_ecount_part(size,size)
#define __out_bcount_full(size)                                 __out_bcount_part(size,size)
#define __out_z                                                 __post __valid __refparam __post __nullterminated
#define __out_z_opt                                             __post __valid __refparam __post __nullterminated __exceptthat __maybenull
#define __out_ecount_z(size)                                    __ecount(size) __post __valid __refparam __post __nullterminated
#define __out_bcount_z(size)                                    __bcount(size) __post __valid __refparam __post __nullterminated
#define __out_ecount_part_z(size,length)                        __out_ecount_part(size,length) __post __nullterminated
#define __out_bcount_part_z(size,length)                        __out_bcount_part(size,length) __post __nullterminated
#define __out_ecount_full_z(size)                               __out_ecount_full(size) __post __nullterminated
#define __out_bcount_full_z(size)                               __out_bcount_full(size) __post __nullterminated
#define __out_nz                                                __post __valid __refparam __post
#define __out_nz_opt                                            __post __valid __refparam __post __exceptthat __maybenull
#define __out_ecount_nz(size)                                   __ecount(size) __post __valid __refparam
#define __out_bcount_nz(size)                                   __bcount(size) __post __valid __refparam
#define __inout                                                 __pre __valid __post __valid __refparam
#define __inout_ecount(size)                                    __out_ecount(size) __pre __valid
#define __inout_bcount(size)                                    __out_bcount(size) __pre __valid
#define __inout_ecount_part(size,length)                        __out_ecount_part(size,length) __pre __valid __pre __elem_readableTo(length)
#define __inout_bcount_part(size,length)                        __out_bcount_part(size,length) __pre __valid __pre __byte_readableTo(length)
#define __inout_ecount_full(size)                               __inout_ecount_part(size,size)
#define __inout_bcount_full(size)                               __inout_bcount_part(size,size)
#define __inout_z                                               __inout __pre __nullterminated __post __nullterminated
#define __inout_ecount_z(size)                                  __inout_ecount(size) __pre __nullterminated __post __nullterminated
#define __inout_bcount_z(size)                                  __inout_bcount(size) __pre __nullterminated __post __nullterminated
#define __inout_nz                                              __inout
#define __inout_ecount_nz(size)                                 __inout_ecount(size)
#define __inout_bcount_nz(size)                                 __inout_bcount(size)
#define __ecount_opt(size)                                      __ecount(size)                              __exceptthat __maybenull
#define __bcount_opt(size)                                      __bcount(size)                              __exceptthat __maybenull
#define __in_opt                                                __in                                        __exceptthat __maybenull
#define __in_ecount_opt(size)                                   __in_ecount(size)                           __exceptthat __maybenull
#define __in_bcount_opt(size)                                   __in_bcount(size)                           __exceptthat __maybenull
#define __in_z_opt                                              __in_opt __pre __nullterminated
#define __in_ecount_z_opt(size)                                 __in_ecount_opt(size) __pre __nullterminated
#define __in_bcount_z_opt(size)                                 __in_bcount_opt(size) __pre __nullterminated
#define __in_nz_opt                                             __in_opt
#define __in_ecount_nz_opt(size)                                __in_ecount_opt(size)
#define __in_bcount_nz_opt(size)                                __in_bcount_opt(size)
#define __out_opt                                               __out                                       __exceptthat __maybenull
#define __out_ecount_opt(size)                                  __out_ecount(size)                          __exceptthat __maybenull
#define __out_bcount_opt(size)                                  __out_bcount(size)                          __exceptthat __maybenull
#define __out_ecount_part_opt(size,length)                      __out_ecount_part(size,length)              __exceptthat __maybenull
#define __out_bcount_part_opt(size,length)                      __out_bcount_part(size,length)              __exceptthat __maybenull
#define __out_ecount_full_opt(size)                             __out_ecount_full(size)                     __exceptthat __maybenull
#define __out_bcount_full_opt(size)                             __out_bcount_full(size)                     __exceptthat __maybenull
#define __out_ecount_z_opt(size)                                __out_ecount_opt(size) __post __nullterminated
#define __out_bcount_z_opt(size)                                __out_bcount_opt(size) __post __nullterminated
#define __out_ecount_part_z_opt(size,length)                    __out_ecount_part_opt(size,length) __post __nullterminated
#define __out_bcount_part_z_opt(size,length)                    __out_bcount_part_opt(size,length) __post __nullterminated
#define __out_ecount_full_z_opt(size)                           __out_ecount_full_opt(size) __post __nullterminated
#define __out_bcount_full_z_opt(size)                           __out_bcount_full_opt(size) __post __nullterminated
#define __out_ecount_nz_opt(size)                               __out_ecount_opt(size) __post __nullterminated
#define __out_bcount_nz_opt(size)                               __out_bcount_opt(size) __post __nullterminated
#define __inout_opt                                             __inout                                     __exceptthat __maybenull
#define __inout_ecount_opt(size)                                __inout_ecount(size)                        __exceptthat __maybenull
#define __inout_bcount_opt(size)                                __inout_bcount(size)                        __exceptthat __maybenull
#define __inout_ecount_part_opt(size,length)                    __inout_ecount_part(size,length)            __exceptthat __maybenull
#define __inout_bcount_part_opt(size,length)                    __inout_bcount_part(size,length)            __exceptthat __maybenull
#define __inout_ecount_full_opt(size)                           __inout_ecount_full(size)                   __exceptthat __maybenull
#define __inout_bcount_full_opt(size)                           __inout_bcount_full(size)                   __exceptthat __maybenull
#define __inout_z_opt                                           __inout_opt __pre __nullterminated __post __nullterminated
#define __inout_ecount_z_opt(size)                              __inout_ecount_opt(size) __pre __nullterminated __post __nullterminated
#define __inout_ecount_z_opt(size)                              __inout_ecount_opt(size) __pre __nullterminated __post __nullterminated
#define __inout_bcount_z_opt(size)                              __inout_bcount_opt(size)
#define __inout_nz_opt                                          __inout_opt
#define __inout_ecount_nz_opt(size)                             __inout_ecount_opt(size)
#define __inout_bcount_nz_opt(size)                             __inout_bcount_opt(size)
#define __deref_ecount(size)                                    __ecount(1) __post __elem_readableTo(1) __post __deref __notnull __post __deref __elem_writableTo(size)
#define __deref_bcount(size)                                    __ecount(1) __post __elem_readableTo(1) __post __deref __notnull __post __deref __byte_writableTo(size)
#define __deref_out                                             __deref_ecount(1) __post __deref __valid __refparam
#define __deref_out_ecount(size)                                __deref_ecount(size) __post __deref __valid __refparam
#define __deref_out_bcount(size)                                __deref_bcount(size) __post __deref __valid __refparam
#define __deref_out_ecount_part(size,length)                    __deref_out_ecount(size) __post __deref __elem_readableTo(length)
#define __deref_out_bcount_part(size,length)                    __deref_out_bcount(size) __post __deref __byte_readableTo(length)
#define __deref_out_ecount_full(size)                           __deref_out_ecount_part(size,size)
#define __deref_out_bcount_full(size)                           __deref_out_bcount_part(size,size)
#define __deref_out_z                                           __post __deref __valid __refparam __post __deref __nullterminated
#define __deref_out_ecount_z(size)                              __deref_out_ecount(size) __post __deref __nullterminated
#define __deref_out_bcount_z(size)                              __deref_out_ecount(size) __post __deref __nullterminated
#define __deref_out_nz                                          __deref_out
#define __deref_out_ecount_nz(size)                             __deref_out_ecount(size)
#define __deref_out_bcount_nz(size)                             __deref_out_ecount(size)
#define __deref_inout                                           __notnull __elem_readableTo(1) __pre __deref __valid __post __deref __valid __refparam
#define __deref_inout_z                                         __deref_inout __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_inout_ecount(size)                              __deref_inout __pre __deref __elem_writableTo(size) __post __deref __elem_writableTo(size)
#define __deref_inout_bcount(size)                              __deref_inout __pre __deref __byte_writableTo(size) __post __deref __byte_writableTo(size)
#define __deref_inout_ecount_part(size,length)                  __deref_inout_ecount(size) __pre __deref __elem_readableTo(length) __post __deref __elem_readableTo(length)
#define __deref_inout_bcount_part(size,length)                  __deref_inout_bcount(size) __pre __deref __byte_readableTo(length) __post __deref __byte_readableTo(length)
#define __deref_inout_ecount_full(size)                         __deref_inout_ecount_part(size,size)
#define __deref_inout_bcount_full(size)                         __deref_inout_bcount_part(size,size)
#define __deref_inout_z                                         __deref_inout __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_inout_ecount_z(size)                            __deref_inout_ecount(size) __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_inout_bcount_z(size)                            __deref_inout_bcount(size) __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_inout_nz                                        __deref_inout
#define __deref_inout_ecount_nz(size)                           __deref_inout_ecount(size)
#define __deref_inout_bcount_nz(size)                           __deref_inout_ecount(size)
#define __deref_ecount_opt(size)                                __deref_ecount(size)                        __post __deref __exceptthat __maybenull
#define __deref_bcount_opt(size)                                __deref_bcount(size)                        __post __deref __exceptthat __maybenull
#define __deref_out_opt                                         __deref_out                                 __post __deref __exceptthat __maybenull
#define __deref_out_ecount_opt(size)                            __deref_out_ecount(size)                    __post __deref __exceptthat __maybenull
#define __deref_out_bcount_opt(size)                            __deref_out_bcount(size)                    __post __deref __exceptthat __maybenull
#define __deref_out_ecount_part_opt(size,length)                __deref_out_ecount_part(size,length)        __post __deref __exceptthat __maybenull
#define __deref_out_bcount_part_opt(size,length)                __deref_out_bcount_part(size,length)        __post __deref __exceptthat __maybenull
#define __deref_out_ecount_full_opt(size)                       __deref_out_ecount_full(size)               __post __deref __exceptthat __maybenull
#define __deref_out_bcount_full_opt(size)                       __deref_out_bcount_full(size)               __post __deref __exceptthat __maybenull
#define __deref_out_z_opt                                       __post __deref __valid __refparam __execeptthat __maybenull __post __deref __nullterminated
#define __deref_out_ecount_z_opt(size)                          __deref_out_ecount_opt(size) __post __deref __nullterminated
#define __deref_out_bcount_z_opt(size)                          __deref_out_bcount_opt(size) __post __deref __nullterminated
#define __deref_out_nz_opt                                      __deref_out_opt
#define __deref_out_ecount_nz_opt(size)                         __deref_out_ecount_opt(size)
#define __deref_out_bcount_nz_opt(size)                         __deref_out_bcount_opt(size)
#define __deref_inout_opt                                       __deref_inout                               __pre __deref __exceptthat __maybenull __post __deref __exceptthat __maybenull
#define __deref_inout_ecount_opt(size)                          __deref_inout_ecount(size)                  __pre __deref __exceptthat __maybenull __post __deref __exceptthat __maybenull
#define __deref_inout_bcount_opt(size)                          __deref_inout_bcount(size)                  __pre __deref __exceptthat __maybenull __post __deref __exceptthat __maybenull
#define __deref_inout_ecount_part_opt(size,length)              __deref_inout_ecount_part(size,length)      __pre __deref __exceptthat __maybenull __post __deref __exceptthat __maybenull
#define __deref_inout_bcount_part_opt(size,length)              __deref_inout_bcount_part(size,length)      __pre __deref __exceptthat __maybenull __post __deref __exceptthat __maybenull
#define __deref_inout_ecount_full_opt(size)                     __deref_inout_ecount_full(size)             __pre __deref __exceptthat __maybenull __post __deref __exceptthat __maybenull
#define __deref_inout_bcount_full_opt(size)                     __deref_inout_bcount_full(size)             __pre __deref __exceptthat __maybenull __post __deref __exceptthat __maybenull
#define __deref_inout_z_opt                                     __deref_inout_opt __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_inout_ecount_z_opt(size)                        __deref_inout_ecount_opt(size) __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_inout_bcount_z_opt(size)                        __deref_inout_bcount_opt(size) __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_inout_nz_opt                                    __deref_inout_opt
#define __deref_inout_ecount_nz_opt(size)                       __deref_inout_ecount_opt(size)
#define __deref_inout_bcount_nz_opt(size)                       __deref_inout_bcount_opt(size)
#define __deref_opt_ecount(size)                                __deref_ecount(size)                        __exceptthat __maybenull
#define __deref_opt_bcount(size)                                __deref_bcount(size)                        __exceptthat __maybenull
#define __deref_opt_out                                         __deref_out                                 __exceptthat __maybenull
#define __deref_opt_out_z                                       __deref_opt_out __post __deref __nullterminated
#define __deref_opt_out_ecount(size)                            __deref_out_ecount(size)                    __exceptthat __maybenull
#define __deref_opt_out_bcount(size)                            __deref_out_bcount(size)                    __exceptthat __maybenull
#define __deref_opt_out_ecount_part(size,length)                __deref_out_ecount_part(size,length)        __exceptthat __maybenull
#define __deref_opt_out_bcount_part(size,length)                __deref_out_bcount_part(size,length)        __exceptthat __maybenull
#define __deref_opt_out_ecount_full(size)                       __deref_out_ecount_full(size)               __exceptthat __maybenull
#define __deref_opt_out_bcount_full(size)                       __deref_out_bcount_full(size)               __exceptthat __maybenull
#define __deref_opt_inout                                       __deref_inout                               __exceptthat __maybenull
#define __deref_opt_inout_ecount(size)                          __deref_inout_ecount(size)                  __exceptthat __maybenull
#define __deref_opt_inout_bcount(size)                          __deref_inout_bcount(size)                  __exceptthat __maybenull
#define __deref_opt_inout_ecount_part(size,length)              __deref_inout_ecount_part(size,length)      __exceptthat __maybenull
#define __deref_opt_inout_bcount_part(size,length)              __deref_inout_bcount_part(size,length)      __exceptthat __maybenull
#define __deref_opt_inout_ecount_full(size)                     __deref_inout_ecount_full(size)             __exceptthat __maybenull
#define __deref_opt_inout_bcount_full(size)                     __deref_inout_bcount_full(size)             __exceptthat __maybenull
#define __deref_opt_inout_z                                     __deref_opt_inout __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_opt_inout_ecount_z(size)                        __deref_opt_inout_ecount(size) __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_opt_inout_bcount_z(size)                        __deref_opt_inout_bcount(size) __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_opt_inout_nz                                    __deref_opt_inout
#define __deref_opt_inout_ecount_nz(size)                       __deref_opt_inout_ecount(size)
#define __deref_opt_inout_bcount_nz(size)                       __deref_opt_inout_bcount(size)
#define __deref_opt_ecount_opt(size)                            __deref_ecount_opt(size)                    __exceptthat __maybenull
#define __deref_opt_bcount_opt(size)                            __deref_bcount_opt(size)                    __exceptthat __maybenull
#define __deref_opt_out_opt                                     __deref_out_opt                             __exceptthat __maybenull
#define __deref_opt_out_ecount_opt(size)                        __deref_out_ecount_opt(size)                __exceptthat __maybenull
#define __deref_opt_out_bcount_opt(size)                        __deref_out_bcount_opt(size)                __exceptthat __maybenull
#define __deref_opt_out_ecount_part_opt(size,length)            __deref_out_ecount_part_opt(size,length)    __exceptthat __maybenull
#define __deref_opt_out_bcount_part_opt(size,length)            __deref_out_bcount_part_opt(size,length)    __exceptthat __maybenull
#define __deref_opt_out_ecount_full_opt(size)                   __deref_out_ecount_full_opt(size)           __exceptthat __maybenull
#define __deref_opt_out_bcount_full_opt(size)                   __deref_out_bcount_full_opt(size)           __exceptthat __maybenull
#define __deref_opt_out_z_opt                                   __post __deref __valid __refparam __exceptthat __maybenull __pre __deref __exceptthat __maybenull __post __deref __exceptthat __maybenull __post __deref __nullterminated
#define __deref_opt_out_ecount_z_opt(size)                      __deref_opt_out_ecount_opt(size) __post __deref __nullterminated
#define __deref_opt_out_bcount_z_opt(size)                      __deref_opt_out_bcount_opt(size) __post __deref __nullterminated
#define __deref_opt_out_nz_opt                                  __deref_opt_out_opt
#define __deref_opt_out_ecount_nz_opt(size)                     __deref_opt_out_ecount_opt(size)
#define __deref_opt_out_bcount_nz_opt(size)                     __deref_opt_out_bcount_opt(size)
#define __deref_opt_inout_opt                                   __deref_inout_opt                           __exceptthat __maybenull
#define __deref_opt_inout_ecount_opt(size)                      __deref_inout_ecount_opt(size)              __exceptthat __maybenull
#define __deref_opt_inout_bcount_opt(size)                      __deref_inout_bcount_opt(size)              __exceptthat __maybenull
#define __deref_opt_inout_ecount_part_opt(size,length)          __deref_inout_ecount_part_opt(size,length)  __exceptthat __maybenull
#define __deref_opt_inout_bcount_part_opt(size,length)          __deref_inout_bcount_part_opt(size,length)  __exceptthat __maybenull
#define __deref_opt_inout_ecount_full_opt(size)                 __deref_inout_ecount_full_opt(size)         __exceptthat __maybenull
#define __deref_opt_inout_bcount_full_opt(size)                 __deref_inout_bcount_full_opt(size)         __exceptthat __maybenull
#define __deref_opt_inout_z_opt                                 __deref_opt_inout_opt  __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_opt_inout_ecount_z_opt(size)                    __deref_opt_inout_ecount_opt(size)  __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_opt_inout_bcount_z_opt(size)                    __deref_opt_inout_bcount_opt(size)  __pre __deref __nullterminated __post __deref __nullterminated
#define __deref_opt_inout_nz_opt                                __deref_opt_inout_opt
#define __deref_opt_inout_ecount_nz_opt(size)                   __deref_opt_inout_ecount_opt(size)
#define __deref_opt_inout_bcount_nz_opt(size)                   __deref_opt_inout_bcount_opt(size)
//xks

#endif

#else
// The following macros define the minimum required platform.  The minimum required platform
// is the earliest version of Windows, Internet Explorer etc. that has the necessary features to run
// your application.  The macros work by enabling all features available on platform versions up to and
// including the version specified.

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER                          // Specifies that the minimum required platform is Windows Vista.
#define WINVER 0x0600           // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows Vista.
#define _WIN32_WINNT 0x0600     // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINDOWS          // Specifies that the minimum required platform is Windows 98.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE                       // Specifies that the minimum required platform is Internet Explorer 7.0.
#define _WIN32_IE 0x0700        // Change this to the appropriate value to target other versions of IE.
#endif

/////////////////////
#endif

#endif
