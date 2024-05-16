/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_AxlePlacardPressure_H_
#define	_AxlePlacardPressure_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum AxlePlacardPressure {
	AxlePlacardPressure_zero	= 0,
	AxlePlacardPressure_fiveKPa	= 1
} e_AxlePlacardPressure;

/* AxlePlacardPressure */
typedef long	 AxlePlacardPressure_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_AxlePlacardPressure_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_AxlePlacardPressure;
asn_struct_free_f AxlePlacardPressure_free;
asn_struct_print_f AxlePlacardPressure_print;
asn_constr_check_f AxlePlacardPressure_constraint;
ber_type_decoder_f AxlePlacardPressure_decode_ber;
der_type_encoder_f AxlePlacardPressure_encode_der;
xer_type_decoder_f AxlePlacardPressure_decode_xer;
xer_type_encoder_f AxlePlacardPressure_encode_xer;
oer_type_decoder_f AxlePlacardPressure_decode_oer;
oer_type_encoder_f AxlePlacardPressure_encode_oer;
per_type_decoder_f AxlePlacardPressure_decode_uper;
per_type_encoder_f AxlePlacardPressure_encode_uper;
per_type_decoder_f AxlePlacardPressure_decode_aper;
per_type_encoder_f AxlePlacardPressure_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _AxlePlacardPressure_H_ */
#include "asn_internal.h"