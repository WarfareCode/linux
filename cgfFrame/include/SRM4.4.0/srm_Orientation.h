/* SRM API
 *
 * SRM SDK Release 4.4.0 - January 21, 2010
 *
 * - SRM spec. 4.4
 *
 *
 *                             NOTICE
 * 
 * This software is provided openly and freely for use in representing and
 * interchanging environmental data & databases.
 * 
 * This software was developed for use by the United States Government with
 * unlimited rights.  The software was developed under contract
 * DASG60-02-D-0006 TO-193 by Science Applications International Corporation.
 * The software is unclassified and is deemed as Distribution A, approved
 * for Public Release.
 * 
 * Use by others is permitted only upon the ACCEPTANCE OF THE TERMS AND
 * CONDITIONS, AS STIPULATED UNDER THE FOLLOWING PROVISIONS:
 * 
 *    1. Recipient may make unlimited copies of this software and give
 *       copies to other persons or entities as long as the copies contain
 *       this NOTICE, and as long as the same copyright notices that
 *       appear on, or in, this software remain.
 * 
 *    2. Trademarks. All trademarks belong to their respective trademark
 *       holders.  Third-Party applications/software/information are
 *       copyrighted by their respective owners.
 * 
 *    3. Recipient agrees to forfeit all intellectual property and
 *       ownership rights for any version created from the modification
 *       or adaptation of this software, including versions created from
 *       the translation and/or reverse engineering of the software design.
 * 
 *    4. Transfer.  Recipient may not sell, rent, lease, or sublicense
 *       this software.  Recipient may, however enable another person
 *       or entity the rights to use this software, provided that this
 *       AGREEMENT and NOTICE is furnished along with the software and
 *       /or software system utilizing this software.
 * 
 *       All revisions, modifications, created by the Recipient, to this
 *       software and/or related technical data shall be forwarded by the
 *       Recipient to the Government at the following address:
 * 
 *         SMDC
 *         Attention SEDRIS (TO193) TPOC
 *         P.O. Box 1500
 *         Huntsville, AL  35807-3801
 * 
 *         or via electronic mail to:  se-mgmt@sedris.org
 * 
 *    5. No Warranty. This software is being delivered to you AS IS
 *       and there is no warranty, EXPRESS or IMPLIED, as to its use
 *       or performance.
 * 
 *       The RECIPIENT ASSUMES ALL RISKS, KNOWN AND UNKNOWN, OF USING
 *       THIS SOFTWARE.  The DEVELOPER EXPRESSLY DISCLAIMS, and the
 *       RECIPIENT WAIVES, ANY and ALL PERFORMANCE OR RESULTS YOU MAY
 *       OBTAIN BY USING THIS SOFTWARE OR DOCUMENTATION.  THERE IS
 *       NO WARRANTY, EXPRESS OR, IMPLIED, AS TO NON-INFRINGEMENT OF
 *       THIRD PARTY RIGHTS, MERCHANTABILITY, OR FITNESS FOR ANY
 *       PARTICULAR PURPOSE.  IN NO EVENT WILL THE DEVELOPER, THE
 *       UNITED STATES GOVERNMENT OR ANYONE ELSE ASSOCIATED WITH THE
 *       DEVELOPMENT OF THIS SOFTWARE BE HELD LIABLE FOR ANY CONSEQUENTIAL,
 *       INCIDENTAL OR SPECIAL DAMAGES, INCLUDING ANY LOST PROFITS
 *       OR LOST SAVINGS WHATSOEVER.
 *
 *
 * SRM_OTHERS_GOES_HERE
 *
 *
 * COPYRIGHT 2010, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 * 
 *
 */
#ifndef SRM_ORIENTATION_H_INCLUDED
#define SRM_ORIENTATION_H_INCLUDED

#if !defined(_WIN32)
#define EXPORT_DLL
#elif !defined(EXPORT_DLL)
#if defined(_LIB)
#define EXPORT_DLL
#elif defined(_USRDLL)
#define EXPORT_DLL __declspec(dllexport)
#else
#define EXPORT_DLL __declspec(dllimport)
#endif
#endif /* _WIN32 && EXPORT_DLL */

#include "srm.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

/** Gets the orientation parameters in matrix 3x3 representation .
    @param this_object in: this orientation object
    @param ori_matrix_3x3 out: the orientation parameters in matrix 3x3 representation
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetMatrix3x3
(
    SRM_Object_Reference  this_object,
    SRM_Matrix_3x3       *ori_matrix_3x3 /* OUT ori params */
);

/** Gets the orientation parameters in axis-angle representation .
    @param this_object in: this orientation object
    @param ori_axis_angle_params out: the orientation parameters in axis-angle representation
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetAxisAngleParams
(
    SRM_Object_Reference   this_object,
    SRM_Axis_Angle_Params *ori_axis_angle_params   /* OUT ori params */
);

/** Gets the orientation parameters in Euler angles ZXZ representation .
    @param this_object in: this orientation object
    @param ori_euler_angles_zxz_params out: the orientation parameters in Euler angles ZXZ representation
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetEulerAnglesZXZParams
(
    SRM_Object_Reference         this_object,
    SRM_Euler_Angles_ZXZ_Params *ori_auler_angles_zxz_params   /* OUT ori params */
);

/** Gets the orientation parameters in Tait-Bryan angles representation .
    @param this_object in: this orientation object
    @param ori_tiat_bryan_angles_params out: the orientation parameters in Tait-Bryan angles representation
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetTaitBryanAnglesParams
(
    SRM_Object_Reference          this_object,
    SRM_Tait_Bryan_Angles_Params *ori_tait_bryan_angles_params   /* OUT ori params */
);

/** Gets the orientation parameters in quaternion representation .
    @param this_object in: this orientation object
    @param ori_quaternion_params out: the orientation parameters in quaternion representation
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetQuaternionParams
(
    SRM_Object_Reference   this_object,
    SRM_Quaternion_Params *ori_quaternion_params   /* OUT ori params */
);

/** Sets the orientation parameters in matrix 3x3 representation .
    @param this_object in: this orientation object
    @param ori_matrix_3x3 in: the orientation parameters in matrix 3x3 representation
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetMatrix3x3
(
    SRM_Object_Reference  this_object,
    SRM_Matrix_3x3       *ori_matrix_3x3 /* IN ori params */
);

/** Sets the orientation parameters in axis-angle representation .
    @param this_object in: this orientation object
    @param ori_axis_angle_params in: the orientation parameters in axis-angle representation
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetAxisAngleParams
(
    SRM_Object_Reference   this_object,
    SRM_Axis_Angle_Params *ori_axis_angle_params   /* IN ori params */
);

/** Sets the orientation parameters in Euler angles ZXZ representation .
    @param this_object in: this orientation object
    @param ori_euler_angles_zxz_params in: the orientation parameters in Euler angles ZXZ representation
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetEulerAnglesZXZParams
(
    SRM_Object_Reference         this_object,
    SRM_Euler_Angles_ZXZ_Params *ori_auler_angles_zxz_params   /* IN ori params */
);

/** Sets the orientation parameters in Tait-Bryan angles representation .
    @param this_object in: this orientation object
    @param ori_tait_bryan_angles_params in: the orientation parameters in Tait-Bryan angles representation
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetTaitBryanAnglesParams
(
    SRM_Object_Reference          this_object,
    SRM_Tait_Bryan_Angles_Params *ori_tait_bryan_angles_params   /* IN ori params */
);

/** Sets the orientation parameters in quaternion representation .
    @param this_object in: this orientation object
    @param ori_quaternion_params in: the orientation parameters in quaternion representation
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetQuaternionParams
(
    SRM_Object_Reference   this_object,
    SRM_Quaternion_Params *ori_quaternion_params   /* IN ori params */
);

typedef SRM_Status_Code SRM_TransformVectorOri
(
    SRM_Object_Reference  this_object,
    SRM_Vector_3D        *in_vec,
    SRM_Vector_3D        *out_vec
);

typedef SRM_Status_Code SRM_Compose
(
    SRM_Object_Reference left_ori_in,
    SRM_Object_Reference right_ori_in,
    SRM_Object_Reference out_ori
);

typedef SRM_Status_Code SRM_GetOriType
(
    SRM_Object_Reference  this_object,
    SRM_Ori_Rep_Type     *ori_type
);

typedef SRM_Status_Code SRM_Ori_Destroy
(
    SRM_Object_Reference object /* orientation to destroy*/
);

/** Orientation matrix 3x3 method list
*/
typedef struct
{
    SRM_Ori_Destroy              *Destroy;
    SRM_GetMatrix3x3             *GetMatrix3x3;
    SRM_GetAxisAngleParams       *GetAxisAngleParams;
    SRM_GetEulerAnglesZXZParams  *GetEulerAnglesZXZParams;
    SRM_GetTaitBryanAnglesParams *GetTaitBryanAnglesParams;
    SRM_GetQuaternionParams      *GetQuaternionParams;
    SRM_SetMatrix3x3             *SetParams;
    SRM_TransformVectorOri       *TransformVector;
    SRM_Compose                  *Compose;
    SRM_GetOriType               *GetOriType;
} SRM_Orientation_M_Method_List;

/** SRM_Orientation struct
    @param state in: this state
    @param methods in: methods for matrix 3x3 orientation
*/
typedef struct
{
    void                          *state;
    SRM_Orientation_M_Method_List *methods;
} SRM_Orientation_Matrix;

/** Orientation axis-angle method list
*/
typedef struct
{
    SRM_Ori_Destroy              *Destroy;
    SRM_GetMatrix3x3             *GetMatrix3x3;
    SRM_GetAxisAngleParams       *GetAxisAngleParams;
    SRM_GetEulerAnglesZXZParams  *GetEulerAnglesZXZParams;
    SRM_GetTaitBryanAnglesParams *GetTaitBryanAnglesParams;
    SRM_GetQuaternionParams      *GetQuaternionParams;
    SRM_SetAxisAngleParams       *SetParams;
    SRM_TransformVectorOri       *TransformVector;
    SRM_Compose                  *Compose;
    SRM_GetOriType               *GetOriType;
} SRM_Orientation_AA_Method_List;

/** SRM_Orientation struct
    @param state in: this state
    @param methods in: methods for angle-axis orientation
*/
typedef struct
{
    void                           *state;
    SRM_Orientation_AA_Method_List *methods;
} SRM_Orientation_Axis_Angle;

/** Orientation Euler Angles ZXZ method list
*/
typedef struct
{
    SRM_Ori_Destroy              *Destroy;
    SRM_GetMatrix3x3             *GetMatrix3x3;
    SRM_GetAxisAngleParams       *GetAxisAngleParams;
    SRM_GetEulerAnglesZXZParams  *GetEulerAnglesZXZParams;
    SRM_GetTaitBryanAnglesParams *GetTaitBryanAnglesParams;
    SRM_GetQuaternionParams      *GetQuaternionParams;
    SRM_SetEulerAnglesZXZParams  *SetParams;
    SRM_TransformVectorOri       *TransformVector;
    SRM_Compose                  *Compose;
    SRM_GetOriType               *GetOriType;
} SRM_Orientation_EA_Method_List;

/** SRM_Orientation struct
    @param state in: this state
    @param methods in: methods for Euler Angles ZXZ orientation
*/
typedef struct
{
    void                           *state;
    SRM_Orientation_EA_Method_List *methods;
} SRM_Orientation_Euler_Angles_ZXZ;

/** Orientation Tait-Bryan Angles method list
*/
typedef struct
{
    SRM_Ori_Destroy              *Destroy;
    SRM_GetMatrix3x3             *GetMatrix3x3;
    SRM_GetAxisAngleParams       *GetAxisAngleParams;
    SRM_GetEulerAnglesZXZParams  *GetEulerAnglesZXZParams;
    SRM_GetTaitBryanAnglesParams *GetTaitBryanAnglesParams;
    SRM_GetQuaternionParams      *GetQuaternionParams;
    SRM_SetTaitBryanAnglesParams *SetParams;
    SRM_TransformVectorOri       *TransformVector;
    SRM_Compose                  *Compose;
    SRM_GetOriType               *GetOriType;
} SRM_Orientation_TB_Method_List;

/** SRM_Orientation struct
    @param state in: this state
    @param methods in: methods for Tait-Bryan Angles orientation
*/
typedef struct
{
    void                           *state;
    SRM_Orientation_TB_Method_List *methods;
} SRM_Orientation_Tait_Bryan_Angles;

/** Orientation quaternion method list
*/
typedef struct
{
    SRM_Ori_Destroy              *Destroy;
    SRM_GetMatrix3x3             *GetMatrix3x3;
    SRM_GetAxisAngleParams       *GetAxisAngleParams;
    SRM_GetEulerAnglesZXZParams  *GetEulerAnglesZXZParams;
    SRM_GetTaitBryanAnglesParams *GetTaitBryanAnglesParams;
    SRM_GetQuaternionParams      *GetQuaternionParams;
    SRM_SetQuaternionParams      *SetParams;
    SRM_TransformVectorOri       *TransformVector;
    SRM_Compose                  *Compose;
    SRM_GetOriType               *GetOriType;
} SRM_Orientation_QT_Method_List;

/** SRM_Orientation struct
    @param state in: this state
    @param methods in: methods for quaternion orientation
*/
typedef struct
{
    void                           *state;
    SRM_Orientation_QT_Method_List *methods;
} SRM_Orientation_Quaternion;


/** Creates a Matrix 3x3 orientation object.
     @note The returned SRF should be freed by calling its Destroy()
           method.
     @note the INV(mat)=TRANSPOSE(mat), consequently, mat*TRANSPOSE(mat)=I
     @param params in: the matrix 3x3 parameter.
     @param new_ori out: result is a new SRM_Orientation_Matrix3x3
     @returns a status code
*/
EXPORT_DLL extern SRM_Status_Code
SRM_CreateOrientationMatrix
(
    SRM_Matrix_3x3         *params,
    SRM_Orientation_Matrix *new_ori /* OUT */
);

/** Creates an axis-angle orientation object.
    @note The returned SRF should be freed by calling its Destroy()
          method.
    @note the input axis is a unit vector
    @note the input angle is in radians in the range of [-2PI, 2PI]
    @param params in: the axis-angle parameter.
    @param new_ori out: results is a new SRM_Orientation_Axis_Angle
    @returns a status code
*/
EXPORT_DLL extern SRM_Status_Code
SRM_CreateOrientationAxisAngle
(
    SRM_Axis_Angle_Params      *params,
    SRM_Orientation_Axis_Angle *new_ori /* OUT */
);

/** Creates a Euler angle ZXZ orientation object.
    @note The returned SRF should be freed by calling its Destroy()
          method.
    @note the spin angle is in radians in the range of [-2PI, 2PI]
    @note the nutation angle is in radians in the range of [-PI/2, PI/2]
    @note the precession angle is in radians in the range of [-PI/2, PI/2]
    @param params in: the Euler angles ZXZ parameter.
    @param new_ori out: results is a new SRM_Orientation_Euler_Angles_ZXZ
    @returns a status code
*/
EXPORT_DLL extern SRM_Status_Code
SRM_CreateOrientationEulerAnglesZXZ
(
    SRM_Euler_Angles_ZXZ_Params      *params,
    SRM_Orientation_Euler_Angles_ZXZ *new_ori /* OUT */
);

/** Creates a Tait_Bryan angles orientation object.
    @note The returned SRF should be freed by calling its Destroy()
          method.
    @note the roll angle is in radians in the range of [-2PI, 2PI]
    @note the pitch angle is in radians in the range of [-2PI, 2PI]
    @note the yaw angle is in radians in the range of [-2PI, 2PI]
    @param params in: the Tait-Bryan angles parameter.
    @param new_ori out: results is a new SRM_Orientation_Tait_Bryan_Angles
    @returns a status code
*/
EXPORT_DLL extern SRM_Status_Code
SRM_CreateOrientationTaitBryanAngles
(
    SRM_Tait_Bryan_Angles_Params      *params,
    SRM_Orientation_Tait_Bryan_Angles *new_ori /* OUT */
);

/** Creates a quaternion orientation object.
    @note The returned SRF should be freed by calling its Destroy()
          method.
    @note q = e0 + e1*i + e2*j + e3*k
    @note e0^2 + e1^2 + e2^2 + e3^2 = 1
    @param params in: the quaternion parameter.
    @param new_ori out: results in a new SRM_Orientation_Quaternion
    @returns a status code
*/
EXPORT_DLL extern SRM_Status_Code
SRM_CreateOrientationQuaternion
(
    SRM_Quaternion_Params      *params,
    SRM_Orientation_Quaternion *new_ori /* OUT */
);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef/define/endif for SRM_ORIENTATION_H_INCLUDED */
