/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "TIS-TPG-Transactions-Descriptions"
 * 	found in "asn1/TIS-TPG-Transactions-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "TisTpgTCM.h"

asn_TYPE_member_t asn_MBR_TisTpgTCM_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct TisTpgTCM, management),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TisTpgTCM_Management,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"management"
		},
	{ ATF_POINTER, 2, offsetof(struct TisTpgTCM, situation),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TisTpgTCM_Situation,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"situation"
		},
	{ ATF_POINTER, 1, offsetof(struct TisTpgTCM, location),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TisTpgTCM_Location,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"location"
		},
};
static const int asn_MAP_TisTpgTCM_oms_1[] = { 1, 2 };
static const ber_tlv_tag_t asn_DEF_TisTpgTCM_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_TisTpgTCM_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* management */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* situation */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* location */
};
asn_SEQUENCE_specifics_t asn_SPC_TisTpgTCM_specs_1 = {
	sizeof(struct TisTpgTCM),
	offsetof(struct TisTpgTCM, _asn_ctx),
	asn_MAP_TisTpgTCM_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_TisTpgTCM_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_TisTpgTCM = {
	"TisTpgTCM",
	"TisTpgTCM",
	&asn_OP_SEQUENCE,
	asn_DEF_TisTpgTCM_tags_1,
	sizeof(asn_DEF_TisTpgTCM_tags_1)
		/sizeof(asn_DEF_TisTpgTCM_tags_1[0]), /* 1 */
	asn_DEF_TisTpgTCM_tags_1,	/* Same as above */
	sizeof(asn_DEF_TisTpgTCM_tags_1)
		/sizeof(asn_DEF_TisTpgTCM_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_TisTpgTCM_1,
	3,	/* Elements count */
	&asn_SPC_TisTpgTCM_specs_1	/* Additional specs */
};

