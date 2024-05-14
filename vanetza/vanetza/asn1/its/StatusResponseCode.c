/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EV-RechargingSpotReservation-PDU-Descriptions"
 * 	found in "/home/rrosmaninho/vanetza/asn1/EV-RSR-PDU-Descriptions.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R -D /home/rrosmaninho/vanetza/vanetza/asn1/its`
 */

#include "StatusResponseCode.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_StatusResponseCode_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_StatusResponseCode_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  6 }	/* (0..6) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_StatusResponseCode_value2enum_1[] = {
	{ 0,	22,	"charging-Spot-Occupied" },
	{ 1,	24,	"charging-Spot-Unoccupied" },
	{ 2,	16,	"charging-Ongoing" },
	{ 3,	26,	"reservation-Limit-Exceeded" },
	{ 4,	21,	"reservation-Cancelled" },
	{ 5,	22,	"unknown-Reservation-ID" },
	{ 6,	22,	"expired-Reservation-ID" }
};
static const unsigned int asn_MAP_StatusResponseCode_enum2value_1[] = {
	2,	/* charging-Ongoing(2) */
	0,	/* charging-Spot-Occupied(0) */
	1,	/* charging-Spot-Unoccupied(1) */
	6,	/* expired-Reservation-ID(6) */
	4,	/* reservation-Cancelled(4) */
	3,	/* reservation-Limit-Exceeded(3) */
	5	/* unknown-Reservation-ID(5) */
};
static const asn_INTEGER_specifics_t asn_SPC_StatusResponseCode_specs_1 = {
	asn_MAP_StatusResponseCode_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_StatusResponseCode_enum2value_1,	/* N => "tag"; sorted by N */
	7,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_StatusResponseCode_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_StatusResponseCode = {
	"StatusResponseCode",
	"StatusResponseCode",
	&asn_OP_NativeEnumerated,
	asn_DEF_StatusResponseCode_tags_1,
	sizeof(asn_DEF_StatusResponseCode_tags_1)
		/sizeof(asn_DEF_StatusResponseCode_tags_1[0]), /* 1 */
	asn_DEF_StatusResponseCode_tags_1,	/* Same as above */
	sizeof(asn_DEF_StatusResponseCode_tags_1)
		/sizeof(asn_DEF_StatusResponseCode_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_StatusResponseCode_constr_1,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_StatusResponseCode_constr_1,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_StatusResponseCode_specs_1	/* Additional specs */
};

