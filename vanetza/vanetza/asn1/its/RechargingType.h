/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "/home/rrosmaninho/vanetza/asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R -D /home/rrosmaninho/vanetza/vanetza/asn1/its`
 */

#ifndef	_RechargingType_H_
#define	_RechargingType_H_


#include "asn_application.h"

/* Including external dependencies */
#include "RechargingMode.h"
#include "PowerSource.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* RechargingType */
typedef struct RechargingType {
	RechargingMode_t	 rechargingMode;
	PowerSource_t	 powerSource;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RechargingType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RechargingType;
extern asn_SEQUENCE_specifics_t asn_SPC_RechargingType_specs_1;
extern asn_TYPE_member_t asn_MBR_RechargingType_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _RechargingType_H_ */
#include "asn_internal.h"