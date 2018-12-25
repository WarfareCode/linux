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

#ifndef SRM_BASESRF3D_H_INCLUDED
#define SRM_BASESRF3D_H_INCLUDED

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

/** Changes a coordinate's values to this SRF.
    @note The destination coordinate must have been created using this SRF.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_coordinate in: this is the source coordinate
    @param target_coordinate out: this is the target coordinate
    @param region out: valid region for target coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate3DSRF
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Coordinate3D            *source_coordinate,
          SRM_Coordinate3D            *target_coordinate, /* OUT */
          SRM_Coordinate_Valid_Region *region             /* OUT */
);

/** Changes a coordinate's values to this SRF using tranformation object.
    @note The destination coordinate must have been created using this SRF.
    @note The value of omega_1, omega_2 and omega_3 for hst must be within the range ( -2_PI, 2_PI ).
    @note The value of delta_s for hst must be stricly greater than -1.0.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_coordinate in: the source coordinate in some other SRF
    @param h_st in: ORM 3D transformation
    @param target_coordinate out: the destination coordinate in this SRF
    @param region out: valid region for destination coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate3DSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate3D                     *source_coordinate,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Coordinate3D                     *target_coordinate, /* OUT */
          SRM_Coordinate_Valid_Region          *region             /* OUT */
);


/** Changes an array of coordinate values to this SRF using tranformation object.
    @note The destination coordinates must have been created using this SRF.
    @note The source and destination arrays must be of same size.
    @note All the coordinates in an array must be associated with the same SRF.
    @param this_object in: this SRF object
    @param source_srf in: this is the surface SRF
    @param source_coordinate_array in: the array of source coordinates in some other SRF
    @param target_coordinate out: the array of destination coordinate in this SRF
    @param index out: the number of elements in the arrays
    @param region_array out: the valid regions associated with the destination coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate3DArraySRF
(
          SRM_Object_Reference               this_object,
    const SRM_Object_Reference               source_srf,
    const SRM_Coordinate3D_Array            *source_coordinate_array,
          SRM_Coordinate3D_Array            *target_coordinate_array, /* OUT */
          SRM_Integer_Positive              *index,                   /* OUT */
          SRM_Coordinate_Valid_Region_Array *region_array             /* OUT */
);

/**  Changes an array of coordinate values to this SRF using tranformation object.
     @note The destination coordinates must have been created using this SRF.
     @note The source and destination arrays must be of same size.
     @note All the coordinates in an array must be associated with the same SRF.
     @param this_object in: this SRF object
     @param source_srf in: the array of source SRF
     @param h_st in: ORM 3D transformation
     @param target_coordinate_array out: the array of destination coordinate in this SRF
     @param index out: the number of elements in the arrays
     @param region_array out: the valid regions associated with the destination coordinate
     @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate3DArraySRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate3D_Array               *source_coordinate_array,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Coordinate3D_Array               *target_coordinate_array, /* OUT */
          SRM_Integer_Positive                 *index,                   /* OUT */
          SRM_Coordinate_Valid_Region_Array    *region_array             /* OUT */
);

/**  Changes a direction's values to this SRF.
     @note The destination direction must have been created using this SRF.
     @param this_object in: this SRF object
     @param source_srf in: this source SRF
     @param source_direction in: the source direction in some other SRF
     @param target_direction out: the destination direction in this SRF
     @param ref_coord_region out: reference coordinate region
     @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeDirectionSRF
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Direction               *source_direction,
          SRM_Direction               *target_direction, /* OUT */
          SRM_Coordinate_Valid_Region *ref_coord_region  /* OUT */
 );

/** Changes a direction's values to this SRF using tranformation object.
    @note The destination direction must have been created using this SRF.
    @note The value of omega_1, omega_2 and omega_3 for hst must be within the range ( -2_PI, 2_PI ).
    @note The value of delta_s for hst must be stricly greater than -1.0.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_direction in: the source direction in some other SRF
    @param h_st in: ORM 3D transformation
    @param target_direction out: the destination direction in this SRF
    @param ref_coord_region out: reference coordinate region
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeDirectionSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Direction                        *source_direction,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Direction                        *target_direction, /* OUT */
          SRM_Coordinate_Valid_Region          *ref_coord_region  /* OUT */
);

/** Changes a direction's values to this SRF using tranformation object.
    @note The destination direction must have been created using this SRF.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_direction_array in: the array of source direction in some other SRF
    @param target_direction_array out: the array of destination direction in this SRF
    @param index out: the number of elements in the arrays
    @param ref_coord_region_array out: reference coordinate region array
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeDirectionArraySRF
(
          SRM_Object_Reference               this_object,
    const SRM_Object_Reference               source_srf,
    const SRM_Direction_Array               *source_direction_array,
          SRM_Direction_Array               *target_direction_array, /* OUT */
          SRM_Integer_Positive              *index,                  /* OUT */
          SRM_Coordinate_Valid_Region_Array *ref_coord_region_array  /* OUT */
);

/** Changes a direction's values to this SRF using tranformation object.
    @note The destination direction must have been created using this SRF.
    @note The value of omega_1, omega_2 and omega_3 for hst must be within the range ( -2_PI, 2_PI ).
    @note The value of delta_s for hst must be stricly greater than -1.0.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_direction_array in: the source direction in some other SRF
    @param h_st in: ORM 3D transformation
    @param target_direction out: the destination direction in this SRF
    @param index out: the number of elements in the arrays
    @param ref_coord_region out: reference coordinate region array
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeDirectionArraySRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Direction_Array                  *source_direction_array,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Direction_Array                  *target_direction_array, /* OUT */
          SRM_Integer_Positive                 *index,                  /* OUT */
          SRM_Coordinate_Valid_Region_Array    *ref_coord_region_array  /* OUT */
);

/** Creates a 3D coordinate object.
    @param this_object in: this SRF object
    @param first_coordinate_component in: creates the first of the three components
    @param second_coordinate_component in: creates the second of the three components
    @param third_coordinate_component in: creates the third of the three components
    @param new_coordinate out: new coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_CreateCoordinate3D
(
    SRM_Object_Reference  this_object,
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component,
    SRM_Long_Float        third_coordinate_component,
    SRM_Coordinate3D     *new_coordinate                 /* OUT */
);


/** Creates a Direction object.
    @param this_object in: this SRF object
    @param reference_coordinate in: this is the surface coordinate
    @param first_direction_component in: creates first direction component
    @param second_direction_component in: creates second direction component
    @param third_direction_component in: creates third direction component
    @param new_direction out: results the new direction
    @returns a status code
*/
typedef SRM_Status_Code SRM_CreateDirection
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *reference_coordinate,
          SRM_Long_Float        first_direction_component,
          SRM_Long_Float        second_direction_component,
          SRM_Long_Float        third_direction_component,
          SRM_Direction        *new_direction                /* OUT */
);

/** This method sets the values of the Orientation object representing the orientation
    of the source srf (at the source reference location) with respect to this (the
    target) srf (at the target reference location).  The Orientation is computed as
    the cosine matrix of the source local tangent frame (at the source referece
    location) with respect to the target local tangent frame (at the target
    reference location).
    @note The target reference location must have been created using this SRF.
    @note The source reference location must have been created using the source SRF.
    @note The output orientation (out_ori) points to the one of the concrete
    Orientation class previously created.
    @param this_object in : the target SRF
    @param source_srf in : the source SRF
    @param src_ref_point in : the source reference point
    @param tgt_ref_point in : the target reference point
    @param out_ori out : the orientation whose values are set by this method
    @returns a status code
*/
typedef SRM_Status_Code SRM_ComputeSRFOrientation
(
          SRM_Object_Reference  this_object,
    const SRM_Object_Reference  source_srf,
    const SRM_Coordinate3D     *src_ref_loc,
    const SRM_Coordinate3D     *tgt_ref_loc,
          SRM_Object_Reference  out_ori
);


/* forward declaration of SRM_LococentricEuclidean3D */
typedef struct _SRM_LococentricEuclidean3D SRM_LococentricEuclidean3D;

/** creates a Loccentric Euclidean 3D SRF whose origin in at the input
    lococentre and the primary and secodary axes are aligned with the
    input direction axes.
    @param this_object in : the invoking SRF
    @param lococentre in : the lococentre of the SRF
    @param primary_axis in : the direction of the primary axis
    @param secondary_axis in : the direction of the secondary axis
    @param new_lce3d_srf out : an instance of Lococentric Euclidean 3D SRF.
    @returns a status code
*/
typedef SRM_Status_Code SRM_CreateLococentricEuclidean3DSRF
(
          SRM_Object_Reference        this_object,
    const SRM_Coordinate3D           *lococentre,
    const SRM_Direction              *primary_axis,
    const SRM_Direction              *secondary_axis,
          SRM_LococentricEuclidean3D *new_lce3d_srf
);

/** Given an orientation with respect to a local tangent frame (LTF_S)
    associated with a reference location in the source SRF, this method
    computes the orientation with respect to the local tangent frame (LTF_T)
    associated with the specified reference location in the target SRF. The
    output orientation is computed by composing the orientation of LTF_S
    with respect to LTF_T with the input source orientation.
    The SRF invoking this method is the target SRF.
    @note The target reference location must have been created using this SRF.
    @note The source reference location must have been created using the source SRF.
    @note The output orientation (out_ori) points to the one of the concrete
    Orientation class previously created.
    @param this_object in : the target SRF
    @param source_srf in : the source SRF
    @param src_ref_loc in : the source reference location (a coordinate in the source
    SRF) where the origin of the source local tangent frame
    (LTF_S) is located
    @param src_ori in : the source orientation of some linear reference frame with
    respect to LTF_S
    @param tgt_ref_loc in : the target reference location (a coordinate in this SRF,
    the target SRF) where the origin of the target local tangent
    frame (LTF_T) is located
    @param tgt_ori out : the target orientation with respect to LTF_T
    @returns a status code
*/
typedef SRM_Status_Code SRM_TransformOrientation
(
          SRM_Object_Reference  this_object,
    const SRM_Object_Reference  source_srf,
    const SRM_Coordinate3D     *src_ref_loc,
    const SRM_Object_Reference  src_ori,
    const SRM_Coordinate3D     *tgt_ref_loc,
          SRM_Object_Reference  tgt_ori
);


/** Given an orientation with respect to a local tangent frame (LTF_S)
    associated with a reference location in the source SRF, this method
    computes the orientation with respect to the local tangent frame (LTF_T)
    associated with the specified reference location in the target SRF.
     LTF_S and LTF_T have a common origin. The output orientation is computed
    by composing the orientation of LTF_S with respect to LTF_T with the
    input source orientation.  The SRF invoking this method is the target
    SRF.
    @note The target reference location must have been created using this SRF.
    @note The source reference location must have been created using the source SRF.
    @note The output orientation (out_ori) points to the one of the concrete
    Orientation class previously created.
    @note The ref_coord_region output parameter could be set to NULL if no region information
    is needed.
    @param this_object in : the target SRF
    @param source_srf in : the source SRF
    @param src_ref_loc in : the source reference location (a coordinate in the source
    SRF) where the origin of the source local tangent frame
    (LTF_S) is located
    @param src_ori in : the source orientation of some linear reference frame with
    respect to LTF_S
    @param tgt_ref_loc out : the coordinate of the common reference location in the
    target SRF
    @param tgt_ori out : the target orientation with respect to LTF_T
    @param ref_coord_region out : the valid region category for the target reference location
    @returns a status code
*/
typedef SRM_Status_Code SRM_TransformOrientationCommonOrigin
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Coordinate3D            *src_ref_loc,
    const SRM_Object_Reference         src_ori,
          SRM_Coordinate3D            *tgt_ref_loc,
          SRM_Object_Reference         tgt_ori,
          SRM_Coordinate_Valid_Region *ref_coord_region
);


/** Given a vector in a body frame (or in general any linear reference frame)
    whose orientation with respect to the local tangent frame (LTF_S) that is
    associated with a reference location in the source SRF, this method
    computes the vector in the local tangent frame (LTF_T) associated with
    the specified reference location in the target SRF.  The output vector is
    computed by applying the composed orientation, from the orientation of
    LTF_S with respect to LTF_T with the source orientation, to the source
    vector. This method is equivalent to applying the orientation result from
    the transformOrientation method to the source vector. The SRF invoking
    this method is the target SRF.
    @note The target reference location must have been created using this SRF.
    @note The source reference location must have been created using the source SRF.
    @param this_object in : the target SRF
    @param source_srf in : the source SRF
    @param src_ref_loc in : the source reference location (a coordinate in the source
    SRF) where the origin of the source local tangent frame
    (LTF_S) is located
    @param src_ori in : the source orientation of some linear reference frame L with
    respect to LTF_S
    @param input_vec in : the input vector in L
    @param tgt_ref_loc in : the target reference location (a coordinate in this
    SRF, the target SRF) where the origin of the target local tangent frame
    (LTF_T) is located
    @param tgt_vec out : the target vector in LTF_T
    @returns a status code
*/
typedef SRM_Status_Code SRM_TransformVectorInBodyFrame
(
          SRM_Object_Reference  this_object,
    const SRM_Object_Reference  source_srf,
    const SRM_Coordinate3D     *src_ref_loc,
    const SRM_Object_Reference  src_ori,
    const SRM_Vector_3D        *vec,
    const SRM_Coordinate3D     *tgt_ref_loc,
          SRM_Vector_3D        *tgt_vec
);


/** Given a vector in a body frame (or in general any linear reference frame)
    whose orientation with respect to the local tangent frame (LTF_S) that is
    associated with a reference location in the source SRF, this method
    computes the vector in the local tangent frame (LTF_T) associated with
    the specified reference location in the target SRF. LTF_S and LTF_T have
    a common origin. The output vector is computed by applying the composed
    orientation, from the orientation of LTF_S with respect to LTF_T with the
    source orientation, to the source vector. This method is equivalent to
    applying the orientation result from the transformOrientation method to
    the source vector.  The SRF invoking this method is the target SRF.
    @note The target reference location must have been created using this SRF.
    @note The source reference location must have been created using the source SRF.
    @param this_object in : the target SRF
    @param source_srf in : the source SRF
    @param src_ref_loc in : the source reference location (a coordinate in the source
    SRF) where the origin of the source local tangent frame
    (LTF_S) is located
    @param src_ori in : the source orientation of some linear reference frame L with
    respect to LTF_S
    @param input_vec in : the input vector in L
    @param tgt_ref_loc out : the coordinate of the common reference location in the
    target SRF
    @param tgt_vec out : the target vector in LTF_T
    @param ref_coord_region out : the valid region category for the target reference location
    @returns a status code
*/
typedef SRM_Status_Code SRM_TransformVectorInBodyFrameCommonOrigin
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Coordinate3D            *src_ref_loc,
    const SRM_Object_Reference         src_ori,
    const SRM_Vector_3D               *vec,
          SRM_Coordinate3D            *tgt_ref_loc,
          SRM_Vector_3D               *tgt_vec,
          SRM_Coordinate_Valid_Region *ref_coord_region
);


/** Given a vector in the local tangent frame (LTF_S) associated with a reference
    location in the source SRF, this method computes the vector in the local tangent
    frame (LTF_T) associated with the specified reference location in the target SRF.
    The output vector is computed by applying the orientation of LTF_S with respect to
    LTF_T to the source vector. The SRF invoking this method is the target SRF.
    @note The target reference location must have been created using this SRF.
    @note The source reference location must have been created using the source SRF.
    @param this_object in : the target SRF
    @param source_srf in : the source SRF
    @param src_ref_loc in : the source reference location (a coordinate in the source
    SRF) where the origin of the source local tangent frame
    (LTF_S) is located
    @param src_vec in : the source vector in LTF_S
    @param tgt_ref_loc in : the target reference location (a coordinate in this SRF,
    the target SRF) where the origin of the target local tangent
    frame (LTF_T) is located
    @param tgt_vec out : the target vector in LTF_T
    @returns a status code
*/
typedef SRM_Status_Code SRM_TransformVector
(
          SRM_Object_Reference  this_object,
    const SRM_Object_Reference  source_srf,
    const SRM_Coordinate3D     *src_ref_loc,
    const SRM_Vector_3D        *src_vec,
    const SRM_Coordinate3D     *tgt_ref_loc,
          SRM_Vector_3D        *tgt_vec
);

/** Given a vector in the local tangent frame (LTF_S) associated with a reference
    location in the source SRF, this method computes the vector in the local tangent
    frame (LTF_T) associated with the specified reference location in the target SRF.
    LTF_S and LTF_T have a common origin.  The output vector is computed by applying
    the orientation of LTF_S with respect to LTF_T to the source vector. The SRF
    invoking this method is the target SRF.
    @note The target reference location must have been created using this SRF.
    @note The source reference location must have been created using the source SRF.
    @param this_object in : the target SRF
    @param source_srf in : the source SRF
    @param src_ref_loc in : the source reference location (a coordinate in the source
    SRF) where the origin of the source local tangent frame
    (LTF_S) is located
    @param src_vec in : the source vector in LTF_S
    @param tgt_ref_loc out : coordinate of the common reference location in the
    target SRF
    @param tgt_vec out : the target vector in LTF_T
    @param ref_coord_region out : the valid region category for the target reference location
    @returns a status code
*/
typedef SRM_Status_Code SRM_TransformVectorCommonOrigin
(
          SRM_Object_Reference  this_object,
    const SRM_Object_Reference  source_srf,
    const SRM_Coordinate3D      *src_ref_loc,
    const SRM_Vector_3D         *src_vec,
          SRM_Coordinate3D      *tgt_ref_loc,
          SRM_Vector_3D         *tgt_vec,
          SRM_Coordinate_Valid_Region  *ref_coord_region   /* OUT */
);


/** Destroys the 3D Coordinate
    @param this_object in: this SRF object
    @param coordinate in: the 3D coordinate to be destroyed
*/
typedef SRM_Status_Code SRM_DestroyCoordinate3D
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference coordinate
);


/** Destroys direction
    @param this_object in: this SRF object
    @param direction in: the direction to be destroyed
*/
typedef SRM_Status_Code SRM_DestroyDirection
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference direction
);


/** Euclidean Distance 3D
    @param this_object in: this SRF object
    @param point1_coordinate in: this is the surface coordinate
    @param point2_coordinate in: this is the target coordinate
    @param distance out:  distance between the two coordinates
    @returns a status code
*/
typedef SRM_Status_Code SRM_EuclideanDistance3D
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *point1_coordinate,
    const SRM_Coordinate3D     *point2_coordinate,
          SRM_Long_Float       *distance           /* OUT */
);

/** Retrieves the 3D coordinate component values.
    @param this_object in: this SRF object
    @param coordinate in: gets the 3D coordinate
    @param first_coordinate_component out: gets the first 3D coordinate
    @param second_coordinate_component out: gets the second 3D coordinate
    @param third_coordinate_component out:  gets the third 3D coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetCoordinate3DValues
(
       SRM_Object_Reference  this_object,
 const SRM_Coordinate3D     *coordinate,
       SRM_Long_Float       *first_coordinate_component,  /* OUT */
       SRM_Long_Float       *second_coordinate_component, /* OUT */
       SRM_Long_Float       *third_coordinate_component   /* OUT */
);


/** Retrieves the direction component values.
    @param this_object in: this SRF object
    @param direction in: gets direction
    @param reference_coordinate out: results the reference coordinate
    @param first_direction_component out: first direction component
    @param second_direction_component out: second direction component
    @param third_direction_component out: third direction component
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetDirectionValues
(
          SRM_Object_Reference  this_object,
    const SRM_Direction        *direction,
          SRM_Coordinate3D     *reference_coordinate,        /* OUT */
          SRM_Long_Float       *first_direction_component,   /* OUT */
          SRM_Long_Float       *second_direction_component,  /* OUT */
          SRM_Long_Float       *third_direction_component    /* OUT */
);


/**  Get the Extended Valid Region for this SRF.
     @note Given a coordinate component, the last invocation of this
     method or the setValidRegion method determines
     the valid and extended valid intervals of the coordinate
     component values.
     @param this_object in: this SRF object
     @param component_identifier in: identifies the component
     @param interval_type out: the type of interval
     @param extended_lower_bound out: the extended lower value of the interval
     @param lower_bound out: the lower value of the interval
     @param upper_bound out: the upper value of the interval
     @param extended_upper_bound out: the extended_upper value of the interval
     @returns a status code
*/
typedef SRM_Status_Code SRM_GetExtendedValidRegion
(
    SRM_Object_Reference   this_object,
    SRM_Integer            component_identifier,
    SRM_Interval_Type     *interval_type,        /* OUT */
    SRM_Long_Float        *extended_lower_bound, /* OUT */
    SRM_Long_Float        *lower_bound,          /* OUT */
    SRM_Long_Float        *upper_bound,          /* OUT */
    SRM_Long_Float        *extended_upper_bound  /* OUT */
 );


/** Get the Valid Region for this SRF.
    @note Given a coordinate component, the last invocation of this
    method or the setExtendedValidRegion method determines
    the valid and extended valid intervals of the coordinate
    component values.
    @param this_object in: this SRF object
    @param component_identifier in: identifies the component
    @param interval_type out: the type of interval
    @param lower_bound out: the lower value of the interval
    @param upper_bound out: the upper value of the interval
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetValidRegion
(
    SRM_Object_Reference  this_object,
    SRM_Integer           component_identifier,
    SRM_Interval_Type    *interval_type,        /* OUT */
    SRM_Long_Float       *lower_bound,          /* OUT */
    SRM_Long_Float       *upper_bound           /* OUT */
 );

/** Get the Natural Set Member Code
    @param this_object in: this SRF object
    @param source_coordinate in: this is the source coordinate
    @param orm_code in: orm code
    @param rt_code in: rt code
    @param target_srfs in:  this outputs the correct target srfs
    @param srfs_code_info out: results in set member
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetNaturalSRFSMemberCode
(
          SRM_Object_Reference   this_object,
    const SRM_Coordinate3D      *source_coordinate,
          SRM_ORM_Code           orm_code,
          SRM_RT_Code            rt_code,
          SRM_SRFS_Code          target_srfs,
          SRM_SRFS_Code_Info    *srfs_code_info    /* OUT */
);

/** Sets the 3D coordinate component values.
    @param this_object in: this SRF object
    @param coordinate in out: sets the 3D coordinate
    @param first_coordinate_component in: sets the first 3D coordinate
    @param second_coordinate_component in: sets the second 3D coordinate
    @param third_coordinate_component in:  sets the third 3D coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetCoordinate3DValues
(
    SRM_Object_Reference  this_object,
    SRM_Coordinate3D     *coordinate, /* IN / OUT */
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component,
    SRM_Long_Float        third_coordinate_component
);


/** Set the Extended Valid Region for this SRF.
    @note Given a coordinate component, the last invocation of this
    method or the setValidRegion method determines
    the valid and extended valid intervals of the coordinate
    component values.
    @note Upper or Lower value is ignored if the interval is a
    semi-interval or unbounded.
    @note The Lower value must be strictly less than the Upper value.
    @note The Extended_Lower value must be strictly greater than the Lower value
    and the Extended_Upper value must be strictly smaller than the Lower value.
    @param this_object in: this SRF object
    @param component_identifier in: identifies the component
    @param interval_type out: the type of interval
    @param extended_lower_bound out: the extended lower value of the interval
    @param lower_bound out: the lower value of the interval
    @param upper_bound out: the upper value of the interval
    @param extended_upper_bound out: the extended_upper value of the interval
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetExtendedValidRegion
(
    SRM_Object_Reference  this_object,
    SRM_Integer           component_identifier,
    SRM_Interval_Type     interval_type,
    SRM_Long_Float        extended_lower_bound,
    SRM_Long_Float        lower_bound,
    SRM_Long_Float        upper_bound,
    SRM_Long_Float        extended_upper_bound
 );


/**Set the Valid Region for this SRF.
   @note Given a coordinate component, the last invocation of this
   method or the setExtendedValidRegion method determines
   the valid and extended valid intervals of the coordinate
   component values.
   @note Upper or Lower value is ignored if the interval is a
   semi-interval or unbounded.
   @note The Lower value must be strictly less than the Upper value.
   @param this_object in: this SRF object
   @param component_identifier in: identifies the component
   @param interval_type out: the type of interval
   @param lower_bound out: the lower value of the interval
   @param upper_bound out: the upper value of the interval
   @returns a status code
*/
typedef SRM_Status_Code SRM_SetValidRegion
(
    SRM_Object_Reference this_object,
    SRM_Integer          component_identifier,
    SRM_Interval_Type    interval_type,
    SRM_Long_Float       lower_bound,
    SRM_Long_Float       upper_bound
);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef/define/endif for SRM_BASESRF3D_H_INCLUDED */
