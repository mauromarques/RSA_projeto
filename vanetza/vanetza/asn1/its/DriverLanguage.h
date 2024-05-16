/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_DriverLanguage_H_
#define	_DriverLanguage_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeInteger.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DriverLanguage {
	DriverLanguage_english	= 0,
	DriverLanguage_german	= 1,
	DriverLanguage_french	= 2,
	DriverLanguage_italian	= 3,
	DriverLanguage_spanish	= 4
} e_DriverLanguage;

/* DriverLanguage */
typedef long	 DriverLanguage_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DriverLanguage;
asn_struct_free_f DriverLanguage_free;
asn_struct_print_f DriverLanguage_print;
asn_constr_check_f DriverLanguage_constraint;
ber_type_decoder_f DriverLanguage_decode_ber;
der_type_encoder_f DriverLanguage_encode_der;
xer_type_decoder_f DriverLanguage_decode_xer;
xer_type_encoder_f DriverLanguage_encode_xer;
oer_type_decoder_f DriverLanguage_decode_oer;
oer_type_encoder_f DriverLanguage_encode_oer;
per_type_decoder_f DriverLanguage_decode_uper;
per_type_encoder_f DriverLanguage_encode_uper;
per_type_decoder_f DriverLanguage_decode_aper;
per_type_encoder_f DriverLanguage_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _DriverLanguage_H_ */
#include "asn_internal.h"