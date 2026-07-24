// ReSharper disable CppDFAUnreachableFunctionCall
// ReSharper disable CppRedundantParentheses
// ReSharper disable CppRedundantQualifier

#pragma once

#include <tuple>

#include <sourcepp/Math.h>

namespace vtfpp {

enum class ImageFormat : int32_t {
	// region Universal Formats
	RGBA8888 = 0,
	ABGR8888,
	RGB888,
	BGR888,
	RGB565,
	I8,
	IA88,
	P8,
	A8,
	RGB888_BLUESCREEN,
	BGR888_BLUESCREEN,
	ARGB8888,
	BGRA8888,
	DXT1,
	DXT3,
	DXT5,
	BGRX8888,
	BGR565,
	BGRX5551,
	BGRA4444,
	DXT1_ONE_BIT_ALPHA,
	BGRA5551,
	UV88,
	UVWQ8888,
	RGBA16161616F,
	RGBA16161616,
	UVLX8888,
	R32F,
	RGB323232F,
	RGBA32323232F,
	// endregion

	// region Alien Swarm & Beyond Formats
	RG1616F,
	RG3232F,
	RGBX8888,
	EMPTY,
	ATI2N,
	ATI1N,
	RGBA1010102,
	BGRA1010102,
	R16F,
	// endregion

	// region Console Formats
	CONSOLE_BGRX8888_LINEAR = 42,
	CONSOLE_RGBA8888_LINEAR,
	CONSOLE_ABGR8888_LINEAR,
	CONSOLE_ARGB8888_LINEAR,
	CONSOLE_BGRA8888_LINEAR,
	CONSOLE_RGB888_LINEAR,
	CONSOLE_BGR888_LINEAR,
	CONSOLE_BGRX5551_LINEAR,
	CONSOLE_I8_LINEAR,
	CONSOLE_RGBA16161616_LINEAR,
	CONSOLE_BGRX8888_LE,
	CONSOLE_BGRA8888_LE,
	// endregion

	// region Titanfall 1/2 Formats
	TITANFALL_BC6H = 66,
	TITANFALL_BC7,
	// endregion

	// region Strata Source Formats
	STRATA_R8 = 69,
	STRATA_BC7,
	STRATA_BC6H,
	// endregion

	// region SourcePP Virtual Formats
	SOURCEPP_BGRA8888_HDR = 10000,
	SOURCEPP_RGBA16161616_HDR,
	SOURCEPP_CONSOLE_RGBA16161616_HDR,

	// ASTC formats (stored as values 41-88 in VTF files on PC platform)
	SOURCEPP_ASTC4x4,              // 10003, file value 41
	SOURCEPP_ASTC4x4_HDR,          // 10004, file value 42
	// 2D ASTC LDR
	SOURCEPP_ASTC5x4,              // 10005, file value 43
	SOURCEPP_ASTC5x5,
	SOURCEPP_ASTC6x5,
	SOURCEPP_ASTC6x6,
	SOURCEPP_ASTC8x5,
	SOURCEPP_ASTC8x6,
	SOURCEPP_ASTC8x8,
	SOURCEPP_ASTC10x5,
	SOURCEPP_ASTC10x6,
	SOURCEPP_ASTC10x8,
	SOURCEPP_ASTC10x10,
	SOURCEPP_ASTC12x10,
	SOURCEPP_ASTC12x12,            // 10017, file value 55
	// 3D ASTC LDR
	SOURCEPP_ASTC3x3x3,            // 10018, file value 56
	SOURCEPP_ASTC4x3x3,
	SOURCEPP_ASTC4x4x3,
	SOURCEPP_ASTC4x4x4,
	SOURCEPP_ASTC5x4x4,
	SOURCEPP_ASTC5x5x4,
	SOURCEPP_ASTC5x5x5,
	SOURCEPP_ASTC6x5x5,
	SOURCEPP_ASTC6x6x5,
	SOURCEPP_ASTC6x6x6,            // 10027, file value 65
	// 2D ASTC HDR
	SOURCEPP_ASTC5x4_HDR,          // 10028, file value 66
	SOURCEPP_ASTC5x5_HDR,
	SOURCEPP_ASTC6x5_HDR,
	SOURCEPP_ASTC6x6_HDR,
	SOURCEPP_ASTC8x5_HDR,
	SOURCEPP_ASTC8x6_HDR,
	SOURCEPP_ASTC8x8_HDR,
	SOURCEPP_ASTC10x5_HDR,
	SOURCEPP_ASTC10x6_HDR,
	SOURCEPP_ASTC10x8_HDR,
	SOURCEPP_ASTC10x10_HDR,
	SOURCEPP_ASTC12x10_HDR,
	SOURCEPP_ASTC12x12_HDR,        // 10040, file value 78
	// 3D ASTC HDR
	SOURCEPP_ASTC3x3x3_HDR,        // 10041, file value 79
	SOURCEPP_ASTC4x3x3_HDR,
	SOURCEPP_ASTC4x4x3_HDR,
	SOURCEPP_ASTC4x4x4_HDR,
	SOURCEPP_ASTC5x4x4_HDR,
	SOURCEPP_ASTC5x5x4_HDR,
	SOURCEPP_ASTC5x5x5_HDR,
	SOURCEPP_ASTC6x5x5_HDR,
	SOURCEPP_ASTC6x6x5_HDR,
	SOURCEPP_ASTC6x6x6_HDR,        // 10050, file value 88
	// endregion
};

namespace ImageFormatDetails {

/**
 * Check if the given format is an ASTC format.
 * @param format The format to check.
 * @return True if the given format is ASTC.
 */
[[nodiscard]] constexpr bool isASTC(ImageFormat format) {
	return static_cast<int32_t>(format) >= static_cast<int32_t>(ImageFormat::SOURCEPP_ASTC4x4) &&
	       static_cast<int32_t>(format) <= static_cast<int32_t>(ImageFormat::SOURCEPP_ASTC6x6x6_HDR);
}

/**
 * Check if the given ASTC format is an HDR format.
 * @param format The format to check. Must be an ASTC format.
 * @return True if the given ASTC format is HDR.
 */
[[nodiscard]] constexpr bool astcHDR(ImageFormat format) {
	return (static_cast<int32_t>(format) >= static_cast<int32_t>(ImageFormat::SOURCEPP_ASTC4x4_HDR) &&
	        static_cast<int32_t>(format) <= static_cast<int32_t>(ImageFormat::SOURCEPP_ASTC4x4_HDR)) ||
	       (static_cast<int32_t>(format) >= static_cast<int32_t>(ImageFormat::SOURCEPP_ASTC5x4_HDR) &&
	        static_cast<int32_t>(format) <= static_cast<int32_t>(ImageFormat::SOURCEPP_ASTC6x6x6_HDR));
}

/**
 * Get the ASTC block dimensions for the given format.
 * @param format The ASTC format to get block dimensions for.
 * @return A tuple of (blockX, blockY, blockZ). Returns (0, 0, 0) if not an ASTC format.
 */
[[nodiscard]] constexpr std::tuple<uint8_t, uint8_t, uint8_t> astcBlockDimensions(ImageFormat format) {
	switch (format) {
		using enum ImageFormat;
		case SOURCEPP_ASTC4x4:
		case SOURCEPP_ASTC4x4_HDR:
			return {4, 4, 1};
		case SOURCEPP_ASTC5x4:
		case SOURCEPP_ASTC5x4_HDR:
			return {5, 4, 1};
		case SOURCEPP_ASTC5x5:
		case SOURCEPP_ASTC5x5_HDR:
			return {5, 5, 1};
		case SOURCEPP_ASTC6x5:
		case SOURCEPP_ASTC6x5_HDR:
			return {6, 5, 1};
		case SOURCEPP_ASTC6x6:
		case SOURCEPP_ASTC6x6_HDR:
			return {6, 6, 1};
		case SOURCEPP_ASTC8x5:
		case SOURCEPP_ASTC8x5_HDR:
			return {8, 5, 1};
		case SOURCEPP_ASTC8x6:
		case SOURCEPP_ASTC8x6_HDR:
			return {8, 6, 1};
		case SOURCEPP_ASTC8x8:
		case SOURCEPP_ASTC8x8_HDR:
			return {8, 8, 1};
		case SOURCEPP_ASTC10x5:
		case SOURCEPP_ASTC10x5_HDR:
			return {10, 5, 1};
		case SOURCEPP_ASTC10x6:
		case SOURCEPP_ASTC10x6_HDR:
			return {10, 6, 1};
		case SOURCEPP_ASTC10x8:
		case SOURCEPP_ASTC10x8_HDR:
			return {10, 8, 1};
		case SOURCEPP_ASTC10x10:
		case SOURCEPP_ASTC10x10_HDR:
			return {10, 10, 1};
		case SOURCEPP_ASTC12x10:
		case SOURCEPP_ASTC12x10_HDR:
			return {12, 10, 1};
		case SOURCEPP_ASTC12x12:
		case SOURCEPP_ASTC12x12_HDR:
			return {12, 12, 1};
		case SOURCEPP_ASTC3x3x3:
		case SOURCEPP_ASTC3x3x3_HDR:
			return {3, 3, 3};
		case SOURCEPP_ASTC4x3x3:
		case SOURCEPP_ASTC4x3x3_HDR:
			return {4, 3, 3};
		case SOURCEPP_ASTC4x4x3:
		case SOURCEPP_ASTC4x4x3_HDR:
			return {4, 4, 3};
		case SOURCEPP_ASTC4x4x4:
		case SOURCEPP_ASTC4x4x4_HDR:
			return {4, 4, 4};
		case SOURCEPP_ASTC5x4x4:
		case SOURCEPP_ASTC5x4x4_HDR:
			return {5, 4, 4};
		case SOURCEPP_ASTC5x5x4:
		case SOURCEPP_ASTC5x5x4_HDR:
			return {5, 5, 4};
		case SOURCEPP_ASTC5x5x5:
		case SOURCEPP_ASTC5x5x5_HDR:
			return {5, 5, 5};
		case SOURCEPP_ASTC6x5x5:
		case SOURCEPP_ASTC6x5x5_HDR:
			return {6, 5, 5};
		case SOURCEPP_ASTC6x6x5:
		case SOURCEPP_ASTC6x6x5_HDR:
			return {6, 6, 5};
		case SOURCEPP_ASTC6x6x6:
		case SOURCEPP_ASTC6x6x6_HDR:
			return {6, 6, 6};
		default:
			return {0, 0, 0};
	}
}

/**
 * Convert a VTF file format value (41-88) to the internal SOURCEPP_ASTC* format.
 * @param fileFormat The raw format value from the VTF file.
 * @return The internal ASTC format, or the input unchanged if not in ASTC range.
 */
[[nodiscard]] constexpr ImageFormat astcFromFileFormat(int32_t fileFormat) {
	if (fileFormat >= 41 && fileFormat <= 88) {
		return static_cast<ImageFormat>(fileFormat - 41 + static_cast<int32_t>(ImageFormat::SOURCEPP_ASTC4x4));
	}
	return static_cast<ImageFormat>(fileFormat);
}

/**
 * Convert an internal SOURCEPP_ASTC* format to the VTF file format value (41-88).
 * @param format The internal ASTC format.
 * @return The file format value, or the input's integer value unchanged if not ASTC.
 */
[[nodiscard]] constexpr int32_t astcToFileFormat(ImageFormat format) {
	if (isASTC(format)) {
		return static_cast<int32_t>(format) - static_cast<int32_t>(ImageFormat::SOURCEPP_ASTC4x4) + 41;
	}
	return static_cast<int32_t>(format);
}

/**
 * Get the number of bits of precision of the red channel in the given format.
 * @param format The format to get the number of bits of precision in this channel from.
 * @return The number of bits of precision the red channel has in the given format. -1
 * is returned if the given format is compressed.
 */
[[nodiscard]] constexpr int8_t red(ImageFormat format) {
	if (isASTC(format)) {
		return -1;
	}
	switch (format) {
		using enum ImageFormat;
		case R32F:
		case RG3232F:
		case RGB323232F:
		case RGBA32323232F:
			return 32;
		case R16F:
		case RG1616F:
		case RGBA16161616F:
		case RGBA16161616:
		case CONSOLE_RGBA16161616_LINEAR:
			return 16;
		case RGBA1010102:
		case BGRA1010102:
			return 10;
		case RGBA8888:
		case CONSOLE_RGBA8888_LINEAR:
		case ABGR8888:
		case CONSOLE_ABGR8888_LINEAR:
		case RGB888:
		case CONSOLE_RGB888_LINEAR:
		case BGR888:
		case CONSOLE_BGR888_LINEAR:
		case I8:
		case CONSOLE_I8_LINEAR:
		case IA88:
		case P8:
		case RGB888_BLUESCREEN:
		case BGR888_BLUESCREEN:
		case ARGB8888:
		case CONSOLE_ARGB8888_LINEAR:
		case BGRA8888:
		case CONSOLE_BGRA8888_LINEAR:
		case CONSOLE_BGRA8888_LE:
		case BGRX8888:
		case CONSOLE_BGRX8888_LINEAR:
		case CONSOLE_BGRX8888_LE:
		case UV88:
		case UVWQ8888:
		case UVLX8888:
		case RGBX8888:
		case STRATA_R8:
			return 8;
		case RGB565:
		case BGR565:
		case BGRX5551:
		case CONSOLE_BGRX5551_LINEAR:
		case BGRA5551:
			return 5;
		case BGRA4444:
			return 4;
		case A8:
		case EMPTY:
			return 0;
		case DXT1:
		case DXT3:
		case DXT5:
		case DXT1_ONE_BIT_ALPHA:
		case ATI2N:
		case ATI1N:
		case TITANFALL_BC6H:
		case TITANFALL_BC7:
		case STRATA_BC7:
		case STRATA_BC6H:
		case SOURCEPP_BGRA8888_HDR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return -1;
	}
	return 0;
}

/**
 * Get the number of bits of precision of the red channel in the given format regardless of compression.
 * @param format The format to get the number of bits of precision in this channel from.
 * @return The number of bits of precision the red channel has in the given format.
 */
[[nodiscard]] constexpr int8_t decompressedRed(ImageFormat format) {
	// This is merely for convenience, the true size may be different depending on the data
	switch (format) {
		using enum ImageFormat;
		case DXT1:
		case DXT1_ONE_BIT_ALPHA:
		case DXT3:
		case DXT5:
		case ATI2N:
		case ATI1N:
		case TITANFALL_BC7:
		case STRATA_BC7:
			return 8;
		case TITANFALL_BC6H:
		case STRATA_BC6H:
		case SOURCEPP_BGRA8888_HDR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return 16;
		default:
			break;
	}
	return red(format);
}

/**
 * Get the number of bits of precision of the green channel in the given format.
 * @param format The format to get the number of bits of precision in this channel from.
 * @return The number of bits of precision the green channel has in the given format. -1
 * is returned if the given format is compressed.
 */
[[nodiscard]] constexpr int8_t green(ImageFormat format) {
	if (isASTC(format)) {
		return -1;
	}
	switch (format) {
		using enum ImageFormat;
		case RG3232F:
		case RGB323232F:
		case RGBA32323232F:
			return 32;
		case RG1616F:
		case RGBA16161616F:
		case RGBA16161616:
		case CONSOLE_RGBA16161616_LINEAR:
			return 16;
		case RGBA1010102:
		case BGRA1010102:
			return 10;
		case RGBA8888:
		case CONSOLE_RGBA8888_LINEAR:
		case ABGR8888:
		case CONSOLE_ABGR8888_LINEAR:
		case RGB888:
		case CONSOLE_RGB888_LINEAR:
		case BGR888:
		case CONSOLE_BGR888_LINEAR:
		case RGB888_BLUESCREEN:
		case BGR888_BLUESCREEN:
		case ARGB8888:
		case CONSOLE_ARGB8888_LINEAR:
		case BGRA8888:
		case CONSOLE_BGRA8888_LINEAR:
		case CONSOLE_BGRA8888_LE:
		case BGRX8888:
		case CONSOLE_BGRX8888_LINEAR:
		case CONSOLE_BGRX8888_LE:
		case UV88:
		case UVWQ8888:
		case UVLX8888:
		case RGBX8888:
			return 8;
		case RGB565:
		case BGR565:
			return 6;
		case BGRX5551:
		case CONSOLE_BGRX5551_LINEAR:
		case BGRA5551:
			return 5;
		case BGRA4444:
			return 4;
		case I8:
		case CONSOLE_I8_LINEAR:
		case IA88:
		case P8:
		case R32F:
		case A8:
		case EMPTY:
		case R16F:
		case STRATA_R8:
			return 0;
		case DXT1:
		case DXT3:
		case DXT5:
		case DXT1_ONE_BIT_ALPHA:
		case ATI2N:
		case ATI1N:
		case TITANFALL_BC6H:
		case TITANFALL_BC7:
		case STRATA_BC7:
		case STRATA_BC6H:
		case SOURCEPP_BGRA8888_HDR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return -1;
	}
	return 0;
}

/**
 * Get the number of bits of precision of the green channel in the given format regardless of compression.
 * @param format The format to get the number of bits of precision in this channel from.
 * @return The number of bits of precision the green channel has in the given format.
 */
[[nodiscard]] constexpr int8_t decompressedGreen(ImageFormat format) {
	// This is merely for convenience, the true size may be different depending on the data
	switch (format) {
		using enum ImageFormat;
		case DXT1:
		case DXT1_ONE_BIT_ALPHA:
		case DXT3:
		case DXT5:
		case ATI2N:
		case ATI1N:
		case TITANFALL_BC7:
		case STRATA_BC7:
			return 8;
		case TITANFALL_BC6H:
		case STRATA_BC6H:
		case SOURCEPP_BGRA8888_HDR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return 16;
		default:
			break;
	}
	return green(format);
}

/**
 * Get the number of bits of precision of the blue channel in the given format.
 * @param format The format to get the number of bits of precision in this channel from.
 * @return The number of bits of precision the blue channel has in the given format. -1
 * is returned if the given format is compressed.
 */
[[nodiscard]] constexpr int8_t blue(ImageFormat format) {
	if (isASTC(format)) {
		return -1;
	}
	switch (format) {
		using enum ImageFormat;
		case RGB323232F:
		case RGBA32323232F:
			return 32;
		case RGBA16161616F:
		case RGBA16161616:
		case CONSOLE_RGBA16161616_LINEAR:
			return 16;
		case RGBA1010102:
		case BGRA1010102:
			return 10;
		case RGBA8888:
		case CONSOLE_RGBA8888_LINEAR:
		case ABGR8888:
		case CONSOLE_ABGR8888_LINEAR:
		case RGB888:
		case CONSOLE_RGB888_LINEAR:
		case BGR888:
		case CONSOLE_BGR888_LINEAR:
		case RGB888_BLUESCREEN:
		case BGR888_BLUESCREEN:
		case ARGB8888:
		case CONSOLE_ARGB8888_LINEAR:
		case BGRA8888:
		case CONSOLE_BGRA8888_LINEAR:
		case CONSOLE_BGRA8888_LE:
		case BGRX8888:
		case CONSOLE_BGRX8888_LINEAR:
		case CONSOLE_BGRX8888_LE:
		case UVWQ8888:
		case UVLX8888:
		case RGBX8888:
			return 8;
		case RGB565:
		case BGR565:
		case BGRX5551:
		case CONSOLE_BGRX5551_LINEAR:
		case BGRA5551:
			return 5;
		case BGRA4444:
			return 4;
		case I8:
		case CONSOLE_I8_LINEAR:
		case IA88:
		case P8:
		case UV88:
		case R32F:
		case A8:
		case EMPTY:
		case RG3232F:
		case RG1616F:
		case R16F:
		case STRATA_R8:
			return 0;
		case DXT1:
		case DXT3:
		case DXT5:
		case DXT1_ONE_BIT_ALPHA:
		case ATI2N:
		case ATI1N:
		case TITANFALL_BC6H:
		case TITANFALL_BC7:
		case STRATA_BC7:
		case STRATA_BC6H:
		case SOURCEPP_BGRA8888_HDR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return -1;
	}
	return 0;
}

/**
 * Get the number of bits of precision of the blue channel in the given format regardless of compression.
 * @param format The format to get the number of bits of precision in this channel from.
 * @return The number of bits of precision the blue channel has in the given format.
 */
[[nodiscard]] constexpr int8_t decompressedBlue(ImageFormat format) {
	// This is merely for convenience, the true size may be different depending on the data
	switch (format) {
		using enum ImageFormat;
		case DXT1:
		case DXT1_ONE_BIT_ALPHA:
		case DXT3:
		case DXT5:
		case ATI2N:
		case ATI1N:
		case TITANFALL_BC7:
		case STRATA_BC7:
			return 8;
		case TITANFALL_BC6H:
		case STRATA_BC6H:
		case SOURCEPP_BGRA8888_HDR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return 16;
		default:
			break;
	}
	return blue(format);
}

/**
 * Get the number of bits of precision of the alpha channel in the given format.
 * @param format The format to get the number of bits of precision in this channel from.
 * @return The number of bits of precision the alpha channel has in the given format. -1
 * is returned if the given format is compressed.
 */
[[nodiscard]] constexpr int8_t alpha(ImageFormat format) {
	if (isASTC(format)) {
		return -1;
	}
	switch (format) {
		using enum ImageFormat;
		case RGBA32323232F:
			return 32;
		case RGBA16161616F:
		case RGBA16161616:
		case CONSOLE_RGBA16161616_LINEAR:
			return 16;
		case RGBA8888:
		case CONSOLE_RGBA8888_LINEAR:
		case ABGR8888:
		case CONSOLE_ABGR8888_LINEAR:
		case IA88:
		case A8:
		case ARGB8888:
		case CONSOLE_ARGB8888_LINEAR:
		case BGRA8888:
		case CONSOLE_BGRA8888_LINEAR:
		case CONSOLE_BGRA8888_LE:
		case BGRX8888:
		case CONSOLE_BGRX8888_LINEAR:
		case CONSOLE_BGRX8888_LE:
		case UVWQ8888:
		case UVLX8888:
		case RGBX8888:
			return 8;
		case BGRA4444:
			return 4;
		case RGBA1010102:
		case BGRA1010102:
			return 2;
		case BGRX5551:
		case CONSOLE_BGRX5551_LINEAR:
		case BGRA5551:
			return 1;
		case RGB888:
		case CONSOLE_RGB888_LINEAR:
		case BGR888:
		case CONSOLE_BGR888_LINEAR:
		case P8:
		case I8:
		case CONSOLE_I8_LINEAR:
		case RGB888_BLUESCREEN:
		case BGR888_BLUESCREEN:
		case UV88:
		case RGB565:
		case BGR565:
		case R32F:
		case RGB323232F:
		case EMPTY:
		case RG3232F:
		case RG1616F:
		case R16F:
		case STRATA_R8:
			return 0;
		case DXT1:
		case DXT3:
		case DXT5:
		case DXT1_ONE_BIT_ALPHA:
		case ATI2N:
		case ATI1N:
		case TITANFALL_BC6H:
		case TITANFALL_BC7:
		case STRATA_BC7:
		case STRATA_BC6H:
		case SOURCEPP_BGRA8888_HDR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return -1;
	}
	return 0;
}

/**
 * Get the number of bits of precision of the alpha channel in the given format regardless of compression.
 * @param format The format to get the number of bits of precision in this channel from.
 * @return The number of bits of precision the alpha channel has in the given format.
 */
[[nodiscard]] constexpr int8_t decompressedAlpha(ImageFormat format) {
	// This is merely for convenience, the true size may be different depending on the data
	switch (format) {
		using enum ImageFormat;
		case DXT5:
		case TITANFALL_BC7:
		case STRATA_BC7:
			return 8;
		case DXT3:
			return 4;
		case DXT1_ONE_BIT_ALPHA:
			return 1;
		case DXT1:
		case ATI2N:
		case ATI1N:
		case TITANFALL_BC6H:
		case STRATA_BC6H:
		case SOURCEPP_BGRA8888_HDR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return 0;
		default:
			break;
	}
	return alpha(format);
}

/**
 * Find the bits per pixel of the given format. Note this is <em>bits</em> per pixel, not <em>bytes</em>
 * per pixel. The DXT1 format is 0.5 bytes per pixel, which cannot be stored in a <code>uint8_t</code>.
 * @param format The format to find the bits per pixel of.
 * @return The bits per pixel of the given format.
 */
[[nodiscard]] constexpr uint8_t bpp(ImageFormat format) {
	switch (format) {
		using enum ImageFormat;
		case RGBA32323232F:
			return 128;
		case RGB323232F:
			return 96;
		case RGBA16161616F:
		case RGBA16161616:
		case CONSOLE_RGBA16161616_LINEAR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
		case RG3232F:
			return 64;
		case RGBA8888:
		case CONSOLE_RGBA8888_LINEAR:
		case ABGR8888:
		case CONSOLE_ABGR8888_LINEAR:
		case ARGB8888:
		case CONSOLE_ARGB8888_LINEAR:
		case BGRA8888:
		case CONSOLE_BGRA8888_LINEAR:
		case CONSOLE_BGRA8888_LE:
		case SOURCEPP_BGRA8888_HDR:
		case BGRX8888:
		case CONSOLE_BGRX8888_LINEAR:
		case CONSOLE_BGRX8888_LE:
		case UVLX8888:
		case R32F:
		case UVWQ8888:
		case RGBX8888:
		case RGBA1010102:
		case BGRA1010102:
		case RG1616F:
			return 32;
		case RGB888:
		case CONSOLE_RGB888_LINEAR:
		case BGR888:
		case CONSOLE_BGR888_LINEAR:
		case RGB888_BLUESCREEN:
		case BGR888_BLUESCREEN:
			return 24;
		case RGB565:
		case BGR565:
		case IA88:
		case BGRX5551:
		case CONSOLE_BGRX5551_LINEAR:
		case BGRA4444:
		case BGRA5551:
		case UV88:
		case R16F:
			return 16;
		case I8:
		case CONSOLE_I8_LINEAR:
		case P8:
		case A8:
		case DXT3:
		case DXT5:
		case ATI2N:
		case TITANFALL_BC6H:
		case TITANFALL_BC7:
		case STRATA_BC7:
		case STRATA_BC6H:
		case STRATA_R8:
			return 8;
		case ATI1N:
		case DXT1:
		case DXT1_ONE_BIT_ALPHA:
			return 4;
		case EMPTY:
			return 0;
	}
	return 0;
}

/**
 * Find a container format for the given format, a format that is more commonly understood
 * within this library and can represent the input texture without losing data.
 * @param format The format to find the container format of.
 * @return The container format of the given format. If the given format is representable with
 * RGBA8888, that is used. RGBA16161616 is used if the given format is representable with that.
 * RGBA32323232F is used for formats that are too large for both the previous two.
 */
[[nodiscard]] constexpr ImageFormat containerFormat(ImageFormat format) {
	if (isASTC(format)) {
		return astcHDR(format) ? ImageFormat::RGBA32323232F : ImageFormat::RGBA8888;
	}
	switch (format) {
		using enum ImageFormat;
		case R32F:
		case RG3232F:
		case RGB323232F:
		case R16F:
		case RG1616F:
		case RGBA16161616F:
		case RGBA32323232F:
		case TITANFALL_BC6H:
		case STRATA_BC6H:
		case SOURCEPP_BGRA8888_HDR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return RGBA32323232F;
		case RGBA16161616:
		case CONSOLE_RGBA16161616_LINEAR:
		case RGBA1010102:
		case BGRA1010102:
			return RGBA16161616;
		case RGBA8888:
		case CONSOLE_RGBA8888_LINEAR:
		case ABGR8888:
		case CONSOLE_ABGR8888_LINEAR:
		case RGB888:
		case CONSOLE_RGB888_LINEAR:
		case BGR888:
		case CONSOLE_BGR888_LINEAR:
		case RGB888_BLUESCREEN:
		case BGR888_BLUESCREEN:
		case ARGB8888:
		case CONSOLE_ARGB8888_LINEAR:
		case BGRA8888:
		case CONSOLE_BGRA8888_LINEAR:
		case CONSOLE_BGRA8888_LE:
		case BGRX8888:
		case CONSOLE_BGRX8888_LINEAR:
		case CONSOLE_BGRX8888_LE:
		case UVWQ8888:
		case UVLX8888:
		case RGB565:
		case BGR565:
		case BGRX5551:
		case CONSOLE_BGRX5551_LINEAR:
		case BGRA5551:
		case BGRA4444:
		case I8:
		case CONSOLE_I8_LINEAR:
		case IA88:
		case P8:
		case UV88:
		case A8:
		case DXT1:
		case DXT3:
		case DXT5:
		case DXT1_ONE_BIT_ALPHA:
		case ATI2N:
		case ATI1N:
		case RGBX8888:
		case TITANFALL_BC7:
		case STRATA_R8:
		case STRATA_BC7:
			return RGBA8888;
		case EMPTY:
			break;
	}
	return ImageFormat::EMPTY;
}

/**
 * Check if the given format is representable by RGBA8888 without losing data.
 * @param format The format to check.
 * @return True if the given format cannot be represented by RGBA8888 without losing data.
 */
[[nodiscard]] constexpr bool large(ImageFormat format) {
	return containerFormat(format) != ImageFormat::RGBA8888 && containerFormat(format) != ImageFormat::EMPTY;
}

/**
 * Checks if the given format stores floating points in its channels.
 * @param format The format to check.
 * @return True if the given format stores floating points.
 */
[[nodiscard]] constexpr bool decimal(ImageFormat format) {
	return containerFormat(format) == ImageFormat::RGBA32323232F;
}

/**
 * Check if the given format is a compressed format (DXT1, DXT3, DXT5, ATI1N, ATI2N, BC7, BC6H, BGRA8888 HDR, RGBA16161616 HDR).
 * @param format The format to check.
 * @return True if the given format is compressed.
 */
[[nodiscard]] constexpr bool compressed(ImageFormat format) {
	return red(format) == -1;
}

/**
 * Check if the given format is a compressed HDR format (not counting BC6H).
 * @param format The format to check.
 * @return True if the format is a compressed HDR format..
 */
[[nodiscard]] constexpr bool compressedHDR(ImageFormat format) {
	switch (format) {
		using enum ImageFormat;
		case SOURCEPP_BGRA8888_HDR:
		case SOURCEPP_RGBA16161616_HDR:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return true;
		default:
			break;
	}
	return false;
}

/**
 * Check if the given format can store transparency.
 * @param format The format to check.
 * @return True if the format can store transparency.
 */
[[nodiscard]] constexpr bool transparent(ImageFormat format) {
	if (isASTC(format)) {
		return true; // ASTC always encodes RGBA
	}
	const auto a = alpha(format);
	if (a < 0) {
		switch (format) {
			using enum ImageFormat;
			case DXT3:
			case DXT5:
			case DXT1_ONE_BIT_ALPHA:
			case ATI2N:
			case ATI1N:
			case TITANFALL_BC6H:
			case TITANFALL_BC7:
			case STRATA_BC7:
			case STRATA_BC6H:
				return true;
			default:
				break;
		}
		return false;
	}
	switch (format) {
		using enum ImageFormat;
		case RGB888_BLUESCREEN:
		case BGR888_BLUESCREEN:
			return true;
		case BGRX8888:
		case CONSOLE_BGRX8888_LINEAR:
		case CONSOLE_BGRX8888_LE:
		case BGRX5551:
		case CONSOLE_BGRX5551_LINEAR:
		case UVLX8888:
		case RGBX8888:
			return false;
		default:
			break;
	}
	return a != 0;
}

/**
 * Check if the given format cannot store transparency.
 * @param format The format to check.
 * @return True if the format cannot store transparency.
 */
[[nodiscard]] constexpr bool opaque(ImageFormat format) {
	return !transparent(format);
}

/**
 * Check if the given format is exclusively used on console platforms.
 * @param format The format to check.
 * @return True if the format is exclusively used on console platforms.
 */
[[nodiscard]] constexpr bool console(ImageFormat format) {
	switch (format) {
		using enum ImageFormat;
		case CONSOLE_BGRX8888_LINEAR:
		case CONSOLE_RGBA8888_LINEAR:
		case CONSOLE_ABGR8888_LINEAR:
		case CONSOLE_ARGB8888_LINEAR:
		case CONSOLE_BGRA8888_LINEAR:
		case CONSOLE_RGB888_LINEAR:
		case CONSOLE_BGR888_LINEAR:
		case CONSOLE_BGRX5551_LINEAR:
		case CONSOLE_I8_LINEAR:
		case CONSOLE_RGBA16161616_LINEAR:
		case CONSOLE_BGRX8888_LE:
		case CONSOLE_BGRA8888_LE:
		case SOURCEPP_CONSOLE_RGBA16161616_HDR:
			return true;
		default:
			break;
	}
	return false;
}

/**
 * Check if the given format is exclusively used by Titanfall 1/2.
 * @param format The format to check.
 * @return True if the format is exclusively used by Titanfall 1/2.
 */
[[nodiscard]] constexpr bool titanfall(ImageFormat format) {
	switch (format) {
		using enum ImageFormat;
		case TITANFALL_BC6H:
		case TITANFALL_BC7:
			return true;
		default:
			break;
	}
	return false;
}

/**
 * Check if the given format is exclusively used by Strata Source.
 * @param format The format to check.
 * @return True if the format is exclusively used by Strata Source.
 */
[[nodiscard]] constexpr bool strata(ImageFormat format) {
	switch (format) {
		using enum ImageFormat;
		case STRATA_R8:
		case STRATA_BC7:
		case STRATA_BC6H:
			return true;
		default:
			break;
	}
	return false;
}

} // namespace ImageFormatDetails

namespace ImageDimensions {

/**
 * Get the dimension at a given mip level. Does not include padding added by compressed formats by default.
 * @param mip The mip level.
 * This should not be enabled if the input dimension is depth, as compressed formats are compressed on 2D slices.
 * Otherwise, it should be enabled if <code>ImageFormatDetails::compressed(format)</code> is true.
 * @param dim The dimension of the largest mip in the texture. Can be width, height, or depth.
 * @param addCompressedFormatPadding Aligns the output dimension to 4 pixels.
 * @return The dimension at the given mip level.
 */
[[nodiscard]] constexpr uint16_t getMipDim(uint8_t mip,  uint16_t dim, bool addCompressedFormatPadding = false) {
	if (!dim) {
		return 0;
	}
	for (int i = 0; i < mip && dim > 1; i++) {
		dim >>= 1;
	}
	if (addCompressedFormatPadding) {
		dim += sourcepp::math::paddingForAlignment(4, dim);
	}
	return dim;
}

/**
 * Get the width and height at a given mip level. Does not include padding added by compressed formats by default.
 * @param mip The mip level.
 * @param width The width of the largest mip in the texture.
 * @param height The height of the largest mip in the texture.
 * @param addCompressedFormatPadding Aligns the output width and height to 4 pixels.
 * @return The width and height at the given mip level.
 */
[[nodiscard]] constexpr std::pair<uint16_t, uint16_t> getMipDims(uint8_t mip, uint16_t width, uint16_t height, bool addCompressedFormatPadding = false) {
	const auto originalWidth = width, originalHeight = height;
	for (int i = 0; i < mip && (width > 1 || height > 1); i++) {
		if ((width  >>= 1) < 1) width  = 1;
		if ((height >>= 1) < 1) height = 1;
	}
	if (addCompressedFormatPadding) {
		width  += sourcepp::math::paddingForAlignment(4, width);
		height += sourcepp::math::paddingForAlignment(4, height);
	}
	return {!originalWidth ? 0 : width, !originalHeight ? 0 : height};
}

/**
 * Get the width, height, and depth at a given mip level. Does not include padding added by compressed formats by default.
 * @param mip The mip level.
 * @param width The width of the largest mip in the texture.
 * @param height The height of the largest mip in the texture.
 * @param depth The depth of the largest mip in the texture.
 * @param addCompressedFormatPadding Aligns the output width and height to 4 pixels.
 * @return The width, height, and depth at the given mip level.
 */
[[nodiscard]] constexpr std::tuple<uint16_t, uint16_t, uint16_t> getMipDims(uint8_t mip, uint16_t width, uint16_t height, uint16_t depth, bool addCompressedFormatPadding = false) {
	const auto originalWidth = width, originalHeight = height, originalDepth = depth;
	for (int i = 0; i < mip && (width > 1 || height > 1 || depth > 1); i++) {
		if ((width  >>= 1) < 1) width  = 1;
		if ((height >>= 1) < 1) height = 1;
		if ((depth  >>= 1) < 1) depth  = 1;
	}
	if (addCompressedFormatPadding) {
		width  += sourcepp::math::paddingForAlignment(4, width);
		height += sourcepp::math::paddingForAlignment(4, height);
	}
	return {!originalWidth ? 0 : width, !originalHeight ? 0 : height, !originalDepth ? 0 : depth};
}

/**
 * Calculate the largest mip count a texture with the given width, height, and depth
 * can contain. On console platforms, since there is no mip count field in the header,
 * this determines the actual mip count if the texture contains mips.
 * @param width The width of the largest mip in the texture.
 * @param height The height of the largest mip in the texture.
 * @param depth The depth of the largest mip in the texture.
 * @return The largest mip count possible for the texture to contain.
 */
[[nodiscard]] constexpr uint8_t getMaximumMipCount(uint16_t width, uint16_t height, uint16_t depth = 1) {
	uint8_t numMipLevels = 1;
	if (width && height && depth) {
		while (width > 1 || height > 1 || depth > 1) {
			if ((width  >>= 1) < 1) width  = 1;
			if ((height >>= 1) < 1) height = 1;
			if ((depth  >>= 1) < 1) depth  = 1;
			numMipLevels++;
		}
	}
	return numMipLevels;
}

} // namespace ImageDimensions

namespace ImageFormatDetails {

/**
 * Calculate the amount of data required to store a texture with the given format and dimensions.
 * @param format The format of the texture.
 * @param width The width of the texture.
 * @param height The height of the texture.
 * @param depth The depth of the texture.
 * @return The length in bytes of a texture containing the given format, width, height, and depth.
 */
[[nodiscard]] constexpr uint32_t getDataLength(ImageFormat format, uint16_t width, uint16_t height, uint16_t depth = 1) {
	if (isASTC(format)) {
		const auto [bx, by, bz] = astcBlockDimensions(format);
		return ((width + bx - 1) / bx) * ((height + by - 1) / by) * ((depth + bz - 1) / bz) * 16;
	}
	if (ImageFormatDetails::compressed(format) && !ImageFormatDetails::compressedHDR(format)) {
		return ((width + 3) / 4) * ((height + 3) / 4) * depth * bpp(format) * 2;
	}
	return width * height * depth * (bpp(format) / 8);
}

/**
 * Calculate the amount of data required to store a texture with the given format, mip/frame/face count, and dimensions.
 * @param format The format of the texture.
 * @param mipCount The mip count of the texture.
 * @param frameCount The frame count of the texture.
 * @param faceCount The face count of the texture.
 * @param width The width of the texture.
 * @param height The height of the texture.
 * @param depth The depth of the texture.
 * @return The length in bytes of a texture containing the given format, mip count, frame count,
 * face count, width, height, and depth.
 */
[[nodiscard]] constexpr uint32_t getDataLength(ImageFormat format, uint8_t mipCount, uint16_t frameCount, uint8_t faceCount, uint16_t width, uint16_t height, uint16_t depth = 1) {
	uint32_t length = 0;
	for (int i = mipCount - 1; i >= 0; i--) {
		const auto [mipWidth, mipHeight, mipDepth] = ImageDimensions::getMipDims(i, width, height, depth);
		length += ImageFormatDetails::getDataLength(format, mipWidth, mipHeight, mipDepth) * frameCount * faceCount;
	}
	return length;
}

/**
 * Calculate the amount of data required to store an XBOX platform texture with the given format, mip/frame/face count,
 * and dimensions. XBOX platform textures have padding between frames to attempt to align each one to 512 bytes (this
 * explanation is simplified from the actual padding algorithm but is mostly correct).
 * @param padded Whether to add padding after some frames. Some parts of an XBOX platform texture
 * expect this padding and some do not.
 * @param format The format of the texture.
 * @param mipCount The mip count of the texture.
 * @param frameCount The frame count of the texture.
 * @param faceCount The face count of the texture.
 * @param width The width of the texture.
 * @param height The height of the texture.
 * @param depth The depth of the texture.
 * @return The length in bytes of an XBOX platform texture containing the given format, mip count,
 * frame count, face count, width, height, and depth; possibly with padding after some frames.
 */
[[nodiscard]] constexpr uint32_t getDataLengthXBOX(bool padded, ImageFormat format, uint8_t mipCount, uint16_t frameCount, uint8_t faceCount, uint16_t width, uint16_t height, uint16_t depth = 1) {
	uint32_t length = 0;
	for (int j = 0; j < frameCount; j++) {
		for (int i = 0; i < mipCount; i++) {
			const auto [mipWidth, mipHeight, mipDepth] = ImageDimensions::getMipDims(i, width, height, depth);
			length += ImageFormatDetails::getDataLength(format, mipWidth, mipHeight, mipDepth) * faceCount;
		}
		if (padded && j + 1 != frameCount && length > 512) {
			length += sourcepp::math::paddingForAlignment(512, length);
		}
	}
	return length;
}

/**
 * Find the position of a specific mip, frame, face, and slice within a texture.
 * @param offset Set to the offset of the section of the texture being searched for.
 * @param length Set to the length of the section of the texture being searched for.
 * @param format The format of the texture.
 * @param mip The mip level to search for within the texture.
 * @param mipCount The mip count of the texture.
 * @param frame The frame to search for within the texture.
 * @param frameCount The frame count of the texture.
 * @param face The face to search for within the texture.
 * @param faceCount The face count of the texture.
 * @param width The width of the texture.
 * @param height The height of the texture.
 * @param slice The slice to search for within the texture.
 * @param depth The depth of the texture.
 * @return True if the section of the texture was successfully found.
 */
[[nodiscard]] constexpr bool getDataPosition(uint32_t& offset, uint32_t& length, ImageFormat format, uint8_t mip, uint8_t mipCount, uint16_t frame, uint16_t frameCount, uint8_t face, uint8_t faceCount, uint16_t width, uint16_t height, uint16_t slice = 0, uint16_t depth = 1) {
	offset = 0;
	length = 0;
	for (int i = mipCount - 1; i >= 0; i--) {
		const auto [mipWidth, mipHeight, mipDepth] = ImageDimensions::getMipDims(i, width, height, depth);
		for (int j = 0; j < frameCount; j++) {
			for (int k = 0; k < faceCount; k++) {
				for (int l = 0; l < mipDepth; l++) {
					const auto imageSize = ImageFormatDetails::getDataLength(format, mipWidth, mipHeight);
					if (i == mip && j == frame && k == face && l == slice) {
						length = imageSize;
						return true;
					}
					offset += imageSize;
				}
			}
		}
	}
	return false;
}

/**
 * Find the position of a specific mip, frame, face, and slice within an XBOX platform texture.
 * XBOX platform textures are laid out in the inverse of a regular texture in DDS mip layout and
 * have padding between some frames.
 * @param offset Set to the offset of the section of the texture being searched for.
 * @param length Set to the length of the section of the texture being searched for.
 * @param padded Whether to add padding after some frames. Some parts of an XBOX platform texture
 * expect this padding and some do not.
 * @param format The format of the texture.
 * @param mip The mip level to search for within the texture.
 * @param mipCount The mip count of the texture.
 * @param frame The frame to search for within the texture.
 * @param frameCount The frame count of the texture.
 * @param face The face to search for within the texture.
 * @param faceCount The face count of the texture.
 * @param width The width of the texture.
 * @param height The height of the texture.
 * @param slice The slice to search for within the texture.
 * @param depth The depth of the texture.
 * @return True if the section of the texture was successfully found.
 */
[[nodiscard]] constexpr bool getDataPositionXBOX(uint32_t& offset, uint32_t& length, bool padded, ImageFormat format, uint8_t mip, uint8_t mipCount, uint16_t frame, uint16_t frameCount, uint8_t face, uint8_t faceCount, uint16_t width, uint16_t height, uint16_t slice = 0, uint16_t depth = 1) {
	offset = 0;
	length = 0;
	for (int j = 0; j < frameCount; j++) {
		for (int k = 0; k < faceCount; k++) {
			for (int i = 0; i < mipCount; i++) {
				const auto [mipWidth, mipHeight, mipDepth] = ImageDimensions::getMipDims(i, width, height, depth);
				for (int l = 0; l < mipDepth; l++) {
					const auto imageSize = ImageFormatDetails::getDataLength(format, mipWidth, mipHeight);
					if (i == mip && j == frame && k == face && l == slice) {
						length = imageSize;
						return true;
					}
					offset += imageSize;
				}
			}
		}
		if (padded && j + 1 != frameCount && offset > 512) {
			offset += sourcepp::math::paddingForAlignment(512, offset);
		}
	}
	return false;
}

} // namespace ImageFormatDetails

} // namespace vtfpp
