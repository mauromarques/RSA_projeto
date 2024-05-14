/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IMZM-PDU-Descriptions"
 * 	found in "asn1/IMZM-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_IMZM_H_
#define	_IMZM_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ItsPduHeader.h"
#include "InterferenceManagementZoneMessage.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* IMZM */
typedef struct IMZM {
	ItsPduHeader_t	 header;
	InterferenceManagementZoneMessage_t	 imzm;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IMZM_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IMZM;

#ifdef __cplusplus
}
#endif

#endif	/* _IMZM_H_ */
#include "asn_internal.h"
