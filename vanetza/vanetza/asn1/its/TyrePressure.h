/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_TyrePressure_H_
#define	_TyrePressure_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TyrePressure {
	TyrePressure_invalid	= 0,
	TyrePressure_lessThanOneBar	= 1,
	TyrePressure_oneBar	= 2,
	TyrePressure_oneBarPlusTwoAndHalfKPa	= 3,
	TyrePressure_inflation	= 254,
	TyrePressure_overflow	= 255
} e_TyrePressure;

/* TyrePressure */
typedef long	 TyrePressure_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_TyrePressure_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_TyrePressure;
asn_struct_free_f TyrePressure_free;
asn_struct_print_f TyrePressure_print;
asn_constr_check_f TyrePressure_constraint;
ber_type_decoder_f TyrePressure_decode_ber;
der_type_encoder_f TyrePressure_encode_der;
xer_type_decoder_f TyrePressure_decode_xer;
xer_type_encoder_f TyrePressure_encode_xer;
oer_type_decoder_f TyrePressure_decode_oer;
oer_type_encoder_f TyrePressure_encode_oer;
per_type_decoder_f TyrePressure_decode_uper;
per_type_encoder_f TyrePressure_encode_uper;
per_type_decoder_f TyrePressure_decode_aper;
per_type_encoder_f TyrePressure_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _TyrePressure_H_ */
#include "asn_internal.h"