/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "GDD"
 * 	found in "build.asn1/iso/ISO14823.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#include "GddStructure.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_nature_constraint_18(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1L && value <= 9L)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_serialNumber_constraint_18(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0L && value <= 99L)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_countryCode_constraint_2(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size == 2UL)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_trafficSignPictogram_constr_5 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_trafficSignPictogram_constr_5 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_publicFacilitiesPictogram_constr_10 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_publicFacilitiesPictogram_constr_10 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  0,  0,  0,  0 }	/* (0..0,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_ambientOrRoadConditionPictogram_constr_13 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_ambientOrRoadConditionPictogram_constr_13 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_type_serviceCategoryCode_constr_4 CC_NOTUSED = {
	{ 0, 0 },
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_serviceCategoryCode_constr_4 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_memb_nature_constr_19 CC_NOTUSED = {
	{ 1, 1 }	/* (1..9) */,
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_nature_constr_19 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  1,  9 }	/* (1..9) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_memb_serialNumber_constr_20 CC_NOTUSED = {
	{ 1, 1 }	/* (0..99) */,
	-1};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_serialNumber_constr_20 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 7,  7,  0,  99 }	/* (0..99) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
#if !defined(ASN_DISABLE_OER_SUPPORT)
static asn_oer_constraints_t asn_OER_memb_countryCode_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	2	/* (SIZE(2..2)) */};
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_countryCode_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  2,  2 }	/* (SIZE(2..2)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static const asn_INTEGER_enum_map_t asn_MAP_trafficSignPictogram_value2enum_5[] = {
	{ 0,	13,	"dangerWarning" },
	{ 1,	10,	"regulatory" },
	{ 2,	11,	"informative" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_trafficSignPictogram_enum2value_5[] = {
	0,	/* dangerWarning(0) */
	2,	/* informative(2) */
	1	/* regulatory(1) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_trafficSignPictogram_specs_5 = {
	asn_MAP_trafficSignPictogram_value2enum_5,	/* "tag" => N; sorted by tag */
	asn_MAP_trafficSignPictogram_enum2value_5,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_trafficSignPictogram_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_trafficSignPictogram_5 = {
	"trafficSignPictogram",
	"trafficSignPictogram",
	&asn_OP_NativeEnumerated,
	asn_DEF_trafficSignPictogram_tags_5,
	sizeof(asn_DEF_trafficSignPictogram_tags_5)
		/sizeof(asn_DEF_trafficSignPictogram_tags_5[0]) - 1, /* 1 */
	asn_DEF_trafficSignPictogram_tags_5,	/* Same as above */
	sizeof(asn_DEF_trafficSignPictogram_tags_5)
		/sizeof(asn_DEF_trafficSignPictogram_tags_5[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_trafficSignPictogram_constr_5,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_trafficSignPictogram_constr_5,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_trafficSignPictogram_specs_5	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_publicFacilitiesPictogram_value2enum_10[] = {
	{ 0,	16,	"publicFacilities" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_publicFacilitiesPictogram_enum2value_10[] = {
	0	/* publicFacilities(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_publicFacilitiesPictogram_specs_10 = {
	asn_MAP_publicFacilitiesPictogram_value2enum_10,	/* "tag" => N; sorted by tag */
	asn_MAP_publicFacilitiesPictogram_enum2value_10,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	2,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_publicFacilitiesPictogram_tags_10[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_publicFacilitiesPictogram_10 = {
	"publicFacilitiesPictogram",
	"publicFacilitiesPictogram",
	&asn_OP_NativeEnumerated,
	asn_DEF_publicFacilitiesPictogram_tags_10,
	sizeof(asn_DEF_publicFacilitiesPictogram_tags_10)
		/sizeof(asn_DEF_publicFacilitiesPictogram_tags_10[0]) - 1, /* 1 */
	asn_DEF_publicFacilitiesPictogram_tags_10,	/* Same as above */
	sizeof(asn_DEF_publicFacilitiesPictogram_tags_10)
		/sizeof(asn_DEF_publicFacilitiesPictogram_tags_10[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_publicFacilitiesPictogram_constr_10,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_publicFacilitiesPictogram_constr_10,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_publicFacilitiesPictogram_specs_10	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_ambientOrRoadConditionPictogram_value2enum_13[] = {
	{ 0,	16,	"ambientCondition" },
	{ 1,	13,	"roadCondition" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_ambientOrRoadConditionPictogram_enum2value_13[] = {
	0,	/* ambientCondition(0) */
	1	/* roadCondition(1) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_ambientOrRoadConditionPictogram_specs_13 = {
	asn_MAP_ambientOrRoadConditionPictogram_value2enum_13,	/* "tag" => N; sorted by tag */
	asn_MAP_ambientOrRoadConditionPictogram_enum2value_13,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_ambientOrRoadConditionPictogram_tags_13[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ambientOrRoadConditionPictogram_13 = {
	"ambientOrRoadConditionPictogram",
	"ambientOrRoadConditionPictogram",
	&asn_OP_NativeEnumerated,
	asn_DEF_ambientOrRoadConditionPictogram_tags_13,
	sizeof(asn_DEF_ambientOrRoadConditionPictogram_tags_13)
		/sizeof(asn_DEF_ambientOrRoadConditionPictogram_tags_13[0]) - 1, /* 1 */
	asn_DEF_ambientOrRoadConditionPictogram_tags_13,	/* Same as above */
	sizeof(asn_DEF_ambientOrRoadConditionPictogram_tags_13)
		/sizeof(asn_DEF_ambientOrRoadConditionPictogram_tags_13[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_ambientOrRoadConditionPictogram_constr_13,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_ambientOrRoadConditionPictogram_constr_13,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeEnumerated_constraint
	},
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ambientOrRoadConditionPictogram_specs_13	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_serviceCategoryCode_4[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GddStructure__pictogramCode__serviceCategoryCode, choice.trafficSignPictogram),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_trafficSignPictogram_5,
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
		"trafficSignPictogram"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GddStructure__pictogramCode__serviceCategoryCode, choice.publicFacilitiesPictogram),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_publicFacilitiesPictogram_10,
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
		"publicFacilitiesPictogram"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GddStructure__pictogramCode__serviceCategoryCode, choice.ambientOrRoadConditionPictogram),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ambientOrRoadConditionPictogram_13,
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
		"ambientOrRoadConditionPictogram"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_serviceCategoryCode_tag2el_4[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* trafficSignPictogram */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* publicFacilitiesPictogram */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* ambientOrRoadConditionPictogram */
};
static asn_CHOICE_specifics_t asn_SPC_serviceCategoryCode_specs_4 = {
	sizeof(struct GddStructure__pictogramCode__serviceCategoryCode),
	offsetof(struct GddStructure__pictogramCode__serviceCategoryCode, _asn_ctx),
	offsetof(struct GddStructure__pictogramCode__serviceCategoryCode, present),
	sizeof(((struct GddStructure__pictogramCode__serviceCategoryCode *)0)->present),
	asn_MAP_serviceCategoryCode_tag2el_4,
	3,	/* Count of tags in the map */
	0, 0,
	3	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_serviceCategoryCode_4 = {
	"serviceCategoryCode",
	"serviceCategoryCode",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		&asn_OER_type_serviceCategoryCode_constr_4,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_serviceCategoryCode_constr_4,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		CHOICE_constraint
	},
	asn_MBR_serviceCategoryCode_4,
	3,	/* Elements count */
	&asn_SPC_serviceCategoryCode_specs_4	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_pictogramCategoryCode_18[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GddStructure__pictogramCode__pictogramCategoryCode, nature),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			&asn_OER_memb_nature_constr_19,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_nature_constr_19,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_nature_constraint_18
		},
		0, 0, /* No default value */
		"nature"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GddStructure__pictogramCode__pictogramCategoryCode, serialNumber),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			&asn_OER_memb_serialNumber_constr_20,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_serialNumber_constr_20,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_serialNumber_constraint_18
		},
		0, 0, /* No default value */
		"serialNumber"
		},
};
static const ber_tlv_tag_t asn_DEF_pictogramCategoryCode_tags_18[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_pictogramCategoryCode_tag2el_18[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* nature */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* serialNumber */
};
static asn_SEQUENCE_specifics_t asn_SPC_pictogramCategoryCode_specs_18 = {
	sizeof(struct GddStructure__pictogramCode__pictogramCategoryCode),
	offsetof(struct GddStructure__pictogramCode__pictogramCategoryCode, _asn_ctx),
	asn_MAP_pictogramCategoryCode_tag2el_18,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_pictogramCategoryCode_18 = {
	"pictogramCategoryCode",
	"pictogramCategoryCode",
	&asn_OP_SEQUENCE,
	asn_DEF_pictogramCategoryCode_tags_18,
	sizeof(asn_DEF_pictogramCategoryCode_tags_18)
		/sizeof(asn_DEF_pictogramCategoryCode_tags_18[0]) - 1, /* 1 */
	asn_DEF_pictogramCategoryCode_tags_18,	/* Same as above */
	sizeof(asn_DEF_pictogramCategoryCode_tags_18)
		/sizeof(asn_DEF_pictogramCategoryCode_tags_18[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_pictogramCategoryCode_18,
	2,	/* Elements count */
	&asn_SPC_pictogramCategoryCode_specs_18	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_pictogramCode_2[] = {
	{ ATF_POINTER, 1, offsetof(struct GddStructure__pictogramCode, countryCode),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			&asn_OER_memb_countryCode_constr_3,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_countryCode_constr_3,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_countryCode_constraint_2
		},
		0, 0, /* No default value */
		"countryCode"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GddStructure__pictogramCode, serviceCategoryCode),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_serviceCategoryCode_4,
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
		"serviceCategoryCode"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GddStructure__pictogramCode, pictogramCategoryCode),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		0,
		&asn_DEF_pictogramCategoryCode_18,
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
		"pictogramCategoryCode"
		},
};
static const int asn_MAP_pictogramCode_oms_2[] = { 0 };
static const ber_tlv_tag_t asn_DEF_pictogramCode_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_pictogramCode_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* countryCode */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* serviceCategoryCode */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* pictogramCategoryCode */
};
static asn_SEQUENCE_specifics_t asn_SPC_pictogramCode_specs_2 = {
	sizeof(struct GddStructure__pictogramCode),
	offsetof(struct GddStructure__pictogramCode, _asn_ctx),
	asn_MAP_pictogramCode_tag2el_2,
	3,	/* Count of tags in the map */
	asn_MAP_pictogramCode_oms_2,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_pictogramCode_2 = {
	"pictogramCode",
	"pictogramCode",
	&asn_OP_SEQUENCE,
	asn_DEF_pictogramCode_tags_2,
	sizeof(asn_DEF_pictogramCode_tags_2)
		/sizeof(asn_DEF_pictogramCode_tags_2[0]) - 1, /* 1 */
	asn_DEF_pictogramCode_tags_2,	/* Same as above */
	sizeof(asn_DEF_pictogramCode_tags_2)
		/sizeof(asn_DEF_pictogramCode_tags_2[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_pictogramCode_2,
	3,	/* Elements count */
	&asn_SPC_pictogramCode_specs_2	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_GddStructure_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GddStructure, pictogramCode),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_pictogramCode_2,
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
		"pictogramCode"
		},
	{ ATF_POINTER, 1, offsetof(struct GddStructure, attributes),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GddAttributes,
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
		"attributes"
		},
};
static const int asn_MAP_GddStructure_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_GddStructure_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_GddStructure_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pictogramCode */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* attributes */
};
asn_SEQUENCE_specifics_t asn_SPC_GddStructure_specs_1 = {
	sizeof(struct GddStructure),
	offsetof(struct GddStructure, _asn_ctx),
	asn_MAP_GddStructure_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_GddStructure_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_GddStructure = {
	"GddStructure",
	"GddStructure",
	&asn_OP_SEQUENCE,
	asn_DEF_GddStructure_tags_1,
	sizeof(asn_DEF_GddStructure_tags_1)
		/sizeof(asn_DEF_GddStructure_tags_1[0]), /* 1 */
	asn_DEF_GddStructure_tags_1,	/* Same as above */
	sizeof(asn_DEF_GddStructure_tags_1)
		/sizeof(asn_DEF_GddStructure_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_GddStructure_1,
	2,	/* Elements count */
	&asn_SPC_GddStructure_specs_1	/* Additional specs */
};

