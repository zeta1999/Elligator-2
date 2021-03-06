#include <stdbool.h>

#include "tests.h"

const struct least_square_root_test least_square_root_tests[LEAST_SQUARE_ROOT_TESTS_COUNT] = {
	// Pair of residues not requiring multiplication by square_root(-1). One of them needs negation

	{
		.number = {
			0xd6, 0x2c, 0xb0, 0xa2, 0x33, 0x69, 0x5a, 0xe7, 0xca, 0x6d, 0x90, 0x37, 0x9f, 0xe0, 0x55, 0xce,
			0x3a, 0x99, 0x63, 0xc6, 0xf5, 0x2a, 0xea, 0xc5, 0x07, 0x90, 0x25, 0x53, 0x81, 0x8d, 0xfb, 0x70
		},

		.result = true,

		.root = {
			0x63, 0xa8, 0xb6, 0x7f, 0x72, 0x44, 0xf7, 0xb8, 0x2e, 0x3c, 0xdd, 0x35, 0x14, 0x02, 0x8a, 0xf8,
			0x88, 0x96, 0xd1, 0x3e, 0x3f, 0xb5, 0x27, 0x4b, 0xd1, 0x5f, 0xd1, 0xe1, 0x0c, 0x9c, 0xa1, 0x00
		}
	},

	{
		.number = {
			0x24, 0xee, 0x3e, 0xef, 0x8e, 0xf2, 0xc4, 0x82, 0x15, 0xcd, 0x66, 0x97, 0xb0, 0x50, 0x58, 0xda,
			0x5c, 0x82, 0xef, 0xe2, 0x01, 0x50, 0xd8, 0xf9, 0x70, 0xa4, 0x8c, 0x35, 0xf6, 0x9f, 0x3a, 0x30
		},

		.result = true,

		.root = {
			0x55, 0x46, 0x8a, 0xd8, 0xac, 0xa2, 0xb5, 0x12, 0x4d, 0x11, 0x88, 0xa3, 0xcf, 0x2c, 0xa8, 0xf5,
			0xe0, 0x91, 0x16, 0x71, 0x7f, 0xfb, 0xce, 0x33, 0xc9, 0x50, 0x46, 0x8d, 0xc4, 0x41, 0x2a, 0x17
		}
	},

	// Pair of residues requiring the multiplication. One of them needs negation

	{
		.number = {
			0x93, 0xdc, 0xf9, 0x23, 0xf4, 0xde, 0x76, 0x0f, 0x68, 0xfa, 0x7a, 0x67, 0x2a, 0xc6, 0xc8, 0x93,
			0x78, 0xa5, 0x34, 0xcb, 0xf4, 0xba, 0x73, 0x41, 0xb7, 0xdd, 0x94, 0x0d, 0x37, 0x02, 0x2b, 0x77
		},

		.result = true,

		.root = {
			0xae, 0x04, 0x8b, 0x63, 0x38, 0xde, 0x11, 0xb5, 0xe3, 0x37, 0x78, 0xba, 0xd9, 0x3d, 0x2c, 0x1a,
			0xa2, 0x0b, 0xe3, 0xd6, 0x09, 0x08, 0x61, 0xf2, 0x7c, 0xf1, 0x24, 0x80, 0xba, 0x4b, 0x5c, 0x14
		}
	},

	{
		.number = {
			0x3b, 0x05, 0xf4, 0x92, 0x05, 0x62, 0xb1, 0xbd, 0x1c, 0x6a, 0xfe, 0x72, 0x1f, 0x2e, 0x99, 0xb3,
			0x4b, 0x18, 0x22, 0x33, 0x58, 0xf6, 0x2c, 0xa5, 0x8f, 0x7d, 0x2e, 0xd6, 0x6b, 0x5f, 0xbb, 0x19
		},

		.result = true,

		.root = {
			0x03, 0x87, 0x16, 0x4c, 0x0d, 0x4d, 0xf5, 0x72, 0xe4, 0x23, 0xf7, 0x40, 0xe0, 0xdd, 0xd4, 0xed,
			0xb8, 0xa7, 0xc6, 0x66, 0xdd, 0x5e, 0x94, 0xfe, 0x33, 0x76, 0xb5, 0xe3, 0x54, 0x9d, 0x69, 0x3b
		}
	},

	// A non-residue

	{
		.number = {
			0x20, 0xe6, 0xdf, 0xa6, 0x1d, 0x10, 0xef, 0xb1, 0x3d, 0xfb, 0x8d, 0xe7, 0x04, 0x3b, 0xfa, 0x19,
			0x0e, 0x01, 0x31, 0x88, 0xa8, 0x07, 0x3f, 0xf0, 0xe3, 0x12, 0x79, 0x25, 0x69, 0xf8, 0xe4, 0x21
		},

		.result = false
	},

	// 0

	{
		.number = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		},

		.result = true,

		.root = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		}
	}
};

const struct encoding_test encoding_tests[ENCODING_TESTS_COUNT] = {
	// A not encodable point with both "high_y" values

	{
		.point = {
			0xe6, 0xf6, 0x6f, 0xdf, 0x6e, 0x23, 0x0c, 0x60, 0x3c, 0x5e, 0x6e, 0x59, 0xa2, 0x54, 0xea, 0x14,
			0x76, 0xa1, 0x3e, 0xb9, 0x51, 0x1b, 0x95, 0x49, 0x84, 0x67, 0x81, 0xe1, 0x2e, 0x52, 0x23, 0x0a
		},

		.high_y = false,

		.result = false
	},

	{
		.point = {
			0xe6, 0xf6, 0x6f, 0xdf, 0x6e, 0x23, 0x0c, 0x60, 0x3c, 0x5e, 0x6e, 0x59, 0xa2, 0x54, 0xea, 0x14,
			0x76, 0xa1, 0x3e, 0xb9, 0x51, 0x1b, 0x95, 0x49, 0x84, 0x67, 0x81, 0xe1, 0x2e, 0x52, 0x23, 0x0a
		},

		.high_y = true,

		.result = false
	},

	// An encodable point with both "high_y" values

	{
		.point = {
			0x33, 0x95, 0x19, 0x64, 0x00, 0x3c, 0x94, 0x08, 0x78, 0x06, 0x3c, 0xcf, 0xd0, 0x34, 0x8a, 0xf4,
			0x21, 0x50, 0xca, 0x16, 0xd2, 0x64, 0x6f, 0x2c, 0x58, 0x56, 0xe8, 0x33, 0x83, 0x77, 0xd8, 0x80
		},

		.high_y = false,

		.result = true,

		.representative = {
			0x28, 0x20, 0xb6, 0xb2, 0x41, 0xe0, 0xf6, 0x8a, 0x6c, 0x4a, 0x7f, 0xee, 0x3d, 0x97, 0x82, 0x28,
			0xef, 0x3a, 0xe4, 0x55, 0x33, 0xcd, 0x41, 0x0a, 0xa9, 0x1a, 0x41, 0x53, 0x31, 0xd8, 0x61, 0x2d
		}
	},

	{
		.point = {
			0x33, 0x95, 0x19, 0x64, 0x00, 0x3c, 0x94, 0x08, 0x78, 0x06, 0x3c, 0xcf, 0xd0, 0x34, 0x8a, 0xf4,
			0x21, 0x50, 0xca, 0x16, 0xd2, 0x64, 0x6f, 0x2c, 0x58, 0x56, 0xe8, 0x33, 0x83, 0x77, 0xd8, 0x80
		},

		.high_y = true,

		.result = true,

		.representative = {
			0x3c, 0xfb, 0x87, 0xc4, 0x6c, 0x0b, 0x45, 0x75, 0xca, 0x81, 0x75, 0xe0, 0xed, 0x1c, 0x0a, 0xe9,
			0xda, 0xe7, 0x9d, 0xb7, 0x8d, 0xf8, 0x69, 0x97, 0xc4, 0x84, 0x7b, 0x9f, 0x20, 0xb2, 0x77, 0x18
		}
	},

	// 0 with both "high_y" values

	{
		.point = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		},

		.high_y = false,

		.result = true,

		.representative = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		}
	},

	{
		.point = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		},

		.high_y = true,

		.result = true,

		.representative = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		}
	}
};

const struct decoding_test decoding_tests[DECODING_TESTS_COUNT] = {
	// A small representative with false "high_y" property

	{
		.representative = {
			0xe7, 0x35, 0x07, 0xd3, 0x8b, 0xae, 0x63, 0x99, 0x2b, 0x3f, 0x57, 0xaa, 0xc4, 0x8c, 0x0a, 0xbc,
			0x14, 0x50, 0x95, 0x89, 0x28, 0x84, 0x57, 0x99, 0x5a, 0x2b, 0x4c, 0xa3, 0x49, 0x0a, 0xa2, 0x07
		},

		.result = true,

		.point = {
			0x1e, 0x8a, 0xff, 0xfe, 0xd6, 0xbf, 0x53, 0xfe, 0x27, 0x1a, 0xd5, 0x72, 0x47, 0x32, 0x62, 0xde,
			0xd8, 0xfa, 0xec, 0x68, 0xe5, 0xe6, 0x7e, 0xf4, 0x5e, 0xbb, 0x82, 0xee, 0xba, 0x52, 0x60, 0x4f
		},

		.high_y = false
	},

	// A small representative with true "high_y" property

	{
		.representative = {
			0x95, 0xa1, 0x60, 0x19, 0x04, 0x1d, 0xbe, 0xfe, 0xd9, 0x83, 0x20, 0x48, 0xed, 0xe1, 0x19, 0x28,
			0xd9, 0x03, 0x65, 0xf2, 0x4a, 0x38, 0xaa, 0x7a, 0xef, 0x1b, 0x97, 0xe2, 0x39, 0x54, 0x10, 0x1b
		},

		.result = true,

		.point = {
			0x79, 0x4f, 0x05, 0xba, 0x3e, 0x3a, 0x72, 0x95, 0x80, 0x22, 0x46, 0x8c, 0x88, 0x98, 0x1e, 0x0b,
			0xe5, 0x78, 0x2b, 0xe1, 0xe1, 0x14, 0x5c, 0xe2, 0xc3, 0xc6, 0xfd, 0xe1, 0x6d, 0xed, 0x53, 0x63
		},

		.high_y = true
	},

	// The last representative returning true: (p - 1) / 2

	{
		.representative = {
			0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f
		},

		.result = true,

		.point = {
			0x9c, 0xdb, 0x52, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
			0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55
		},

		.high_y = false
	},

	// The first representative returning false: (p + 1) / 2

	{
		.representative = {
			0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f
		},

		.result = false,

		.point = {
			0x9c, 0xdb, 0x52, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
			0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55
		},

		.high_y = false
	},

	// A large representative with false "high_y" property

	{
		.representative = {
			0x17, 0x9f, 0x24, 0x73, 0x0d, 0xed, 0x2c, 0xe3, 0x17, 0x39, 0x08, 0xec, 0x61, 0x96, 0x46, 0x53,
			0xb8, 0x02, 0x7e, 0x38, 0x3f, 0x40, 0x34, 0x6c, 0x1c, 0x9b, 0x4d, 0x2b, 0xdb, 0x1d, 0xb7, 0x6c
		},

		.result = false,

		.point = {
			0x10, 0x74, 0x54, 0x97, 0xd3, 0x5c, 0x6e, 0xde, 0x6e, 0xa6, 0xb3, 0x30, 0x54, 0x6a, 0x6f, 0xcb,
			0xf1, 0x5c, 0x90, 0x3a, 0x7b, 0xe2, 0x8a, 0xe6, 0x9b, 0x1c, 0xa1, 0x4e, 0x0b, 0xf0, 0x9b, 0x60
		},

		.high_y = false
	},

	// A large representative with true "high_y" property

	{
		.representative = {
			0x8a, 0x2f, 0x28, 0x61, 0x80, 0xc3, 0xd8, 0x63, 0x0b, 0x5f, 0x5a, 0x3c, 0x7c, 0xc0, 0x27, 0xa5,
			0x5e, 0x0d, 0x3f, 0xfb, 0x3b, 0x1b, 0x99, 0x0c, 0x5c, 0x7b, 0xb4, 0xc3, 0xd1, 0xf9, 0x1b, 0x6f
		},

		.result = false,

		.point = {
			0x6d, 0x31, 0x87, 0x19, 0x2a, 0xfc, 0x3b, 0xcc, 0x05, 0xa4, 0x97, 0x92, 0x88, 0x16, 0xe3, 0xe2,
			0x33, 0x6d, 0xc5, 0x39, 0xaa, 0x7f, 0xc2, 0x96, 0xa9, 0xee, 0x01, 0x3f, 0x56, 0x0d, 0xb8, 0x43
		},

		.high_y = true
	},

	// 0

	{
		.representative = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		},

		.result = true,

		.point = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		},

		.high_y = false
	}
};

const struct conversion_test conversion_tests[CONVERSION_TESTS_COUNT] = {
	// (0; 1)

	{
		.source = {
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		},

		.result = true,

		.point = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		}
	},

	// (0; -1)

	{
		.source = {
			0xec, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f
		},

		.result = true,

		.point = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
		}
	},

	// An invalid point with y < p

	{
		.source = {
			0x12, 0x82, 0x5a, 0x8f, 0x7d, 0x75, 0x81, 0x7c, 0x91, 0xc2, 0x75, 0xaf, 0x8d, 0x9a, 0x82, 0x2d,
			0x65, 0x7f, 0x57, 0x75, 0x40, 0x5f, 0x3f, 0xcd, 0xab, 0x52, 0x91, 0x8b, 0x08, 0x58, 0x77, 0x1c
		},

		.result = false
	},

	// A point with y = p

	{
		.source = {
			0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f
		},

		.result = false
	},

	// A point with y > p

	{
		.source = {
			0xee, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
			0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f
		},

		.result = false
	},

	// A point with x = 0, but non-zero parity flag

	{
		.source = {
			0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80
		},

		.result = false
	},

	// A valid point

	{
		.source = {
			0x15, 0x98, 0xf8, 0x52, 0x09, 0xf4, 0x47, 0x72, 0x87, 0xf0, 0x81, 0x70, 0x16, 0xe9, 0xf3, 0x48,
			0x4a, 0x8c, 0x68, 0x0d, 0xb8, 0x4d, 0x6a, 0x10, 0x3e, 0x18, 0x53, 0xdf, 0xa0, 0xf5, 0x1f, 0x4d
		},

		.result = true,

		.point = {
			0xb5, 0xe9, 0x56, 0xd0, 0xc3, 0xf1, 0x71, 0xac, 0xf9, 0x44, 0xfe, 0x0c, 0x0f, 0x67, 0x17, 0x0a,
			0xa7, 0x3c, 0x65, 0xaa, 0x67, 0xdf, 0x54, 0xa2, 0x06, 0x4b, 0x98, 0x6e, 0x5b, 0xed, 0xc0, 0x0e
		}
	}
};
