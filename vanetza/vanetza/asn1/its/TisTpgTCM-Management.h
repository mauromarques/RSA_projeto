/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TisTpgTCM_Management_H_
#define	_TisTpgTCM_Management_H_


#include "asn_application.h"

/* Including external dependencies */
#include "TimestampIts.h"
#include "StationID.h"
#include "ReservationStatus.h"
#include "NativeInteger.h"
#include "CustomerContract.h"
#include "ReservationID.h"
#include "TpgAutomation.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TisTpgTCM-Management */
typedef struct TisTpgTCM_Management {
	TimestampIts_t	 generationTime;
	StationID_t	 tpgStationID;
	ReservationStatus_t	 reservationStatus;
	long	*reservedTpg;	/* OPTIONAL */
	CustomerContract_t	*costumercontract;	/* OPTIONAL */
	ReservationID_t	*reservationID;	/* OPTIONAL */
	TpgAutomation_t	*tpgAutomationLevel;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} TisTpgTCM_Management_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_TisTpgTCM_Management;
extern asn_SEQUENCE_specifics_t asn_SPC_TisTpgTCM_Management_specs_1;
extern asn_TYPE_member_t asn_MBR_TisTpgTCM_Management_1[7];

#ifdef __cplusplus
}
#endif

#endif	/* _TisTpgTCM_Management_H_ */
#include "asn_internal.h"
