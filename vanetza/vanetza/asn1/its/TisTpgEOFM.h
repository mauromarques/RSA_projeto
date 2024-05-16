/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TisTpgEOFM_H_
#define	_TisTpgEOFM_H_


#include "asn_application.h"

/* Including external dependencies */
#include "TisTpgEOFM-Management.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TisTpgEOFM */
typedef struct TisTpgEOFM {
	TisTpgEOFM_Management_t	 management;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TisTpgEOFM_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TisTpgEOFM;
extern asn_SEQUENCE_specifics_t asn_SPC_TisTpgEOFM_specs_1;
extern asn_TYPE_member_t asn_MBR_TisTpgEOFM_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _TisTpgEOFM_H_ */
#include "asn_internal.h"