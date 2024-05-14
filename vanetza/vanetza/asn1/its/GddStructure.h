/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "GDD"
 * 	found in "build.asn1/iso/ISO14823.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_GddStructure_H_
#define	_GddStructure_H_


#include "asn_application.h"

/* Including external dependencies */
#include "OCTET_STRING.h"
#include "NativeEnumerated.h"
#include "constr_CHOICE.h"
#include "NativeInteger.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum GddStructure__pictogramCode__serviceCategoryCode_PR {
	GddStructure__pictogramCode__serviceCategoryCode_PR_NOTHING,	/* No components present */
	GddStructure__pictogramCode__serviceCategoryCode_PR_trafficSignPictogram,
	GddStructure__pictogramCode__serviceCategoryCode_PR_publicFacilitiesPictogram,
	GddStructure__pictogramCode__serviceCategoryCode_PR_ambientOrRoadConditionPictogram
	/* Extensions may appear below */
	
} GddStructure__pictogramCode__serviceCategoryCode_PR;
typedef enum GddStructure__pictogramCode__serviceCategoryCode__trafficSignPictogram {
	GddStructure__pictogramCode__serviceCategoryCode__trafficSignPictogram_dangerWarning	= 0,
	GddStructure__pictogramCode__serviceCategoryCode__trafficSignPictogram_regulatory	= 1,
	GddStructure__pictogramCode__serviceCategoryCode__trafficSignPictogram_informative	= 2
	/*
	 * Enumeration is extensible
	 */
} e_GddStructure__pictogramCode__serviceCategoryCode__trafficSignPictogram;
typedef enum GddStructure__pictogramCode__serviceCategoryCode__publicFacilitiesPictogram {
	GddStructure__pictogramCode__serviceCategoryCode__publicFacilitiesPictogram_publicFacilities	= 0
	/*
	 * Enumeration is extensible
	 */
} e_GddStructure__pictogramCode__serviceCategoryCode__publicFacilitiesPictogram;
typedef enum GddStructure__pictogramCode__serviceCategoryCode__ambientOrRoadConditionPictogram {
	GddStructure__pictogramCode__serviceCategoryCode__ambientOrRoadConditionPictogram_ambientCondition	= 0,
	GddStructure__pictogramCode__serviceCategoryCode__ambientOrRoadConditionPictogram_roadCondition	= 1
	/*
	 * Enumeration is extensible
	 */
} e_GddStructure__pictogramCode__serviceCategoryCode__ambientOrRoadConditionPictogram;

/* Forward declarations */
struct GddAttributes;

/* GddStructure */
typedef struct GddStructure {
	struct GddStructure__pictogramCode {
		OCTET_STRING_t	*countryCode;	/* OPTIONAL */
		struct GddStructure__pictogramCode__serviceCategoryCode {
			GddStructure__pictogramCode__serviceCategoryCode_PR present;
			union GddStructure__pictogramCode__serviceCategoryCode_u {
				long	 trafficSignPictogram;
				long	 publicFacilitiesPictogram;
				long	 ambientOrRoadConditionPictogram;
				/*
				 * This type is extensible,
				 * possible extensions are below.
				 */
			} choice;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} serviceCategoryCode;
		struct GddStructure__pictogramCode__pictogramCategoryCode {
			long	 nature;
			long	 serialNumber;
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} pictogramCategoryCode;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} pictogramCode;
	struct GddAttributes	*attributes;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GddStructure_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_trafficSignPictogram_5;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_publicFacilitiesPictogram_10;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_ambientOrRoadConditionPictogram_13;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_GddStructure;
extern asn_SEQUENCE_specifics_t asn_SPC_GddStructure_specs_1;
extern asn_TYPE_member_t asn_MBR_GddStructure_1[2];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "GddAttributes.h"

#endif	/* _GddStructure_H_ */
#include "asn_internal.h"
