/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "BookingInfo.h"

/*
 * This type is implemented using UTF8String,
 * so here we adjust the DEF accordingly.
 */
static const ber_tlv_tag_t asn_DEF_BookingInfo_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (12 << 2))
};
asn_TYPE_descriptor_t asn_DEF_BookingInfo = {
	"BookingInfo",
	"BookingInfo",
	&asn_OP_UTF8String,
	asn_DEF_BookingInfo_tags_1,
	sizeof(asn_DEF_BookingInfo_tags_1)
		/sizeof(asn_DEF_BookingInfo_tags_1[0]), /* 1 */
	asn_DEF_BookingInfo_tags_1,	/* Same as above */
	sizeof(asn_DEF_BookingInfo_tags_1)
		/sizeof(asn_DEF_BookingInfo_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		UTF8String_constraint
	},
	0, 0,	/* No members */
	0	/* No specifics */
};

