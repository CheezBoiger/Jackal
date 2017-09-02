// Copyright (c) 2017 Jackal Engine, MIT License.
#pragma once


namespace jackal {


typedef enum {
  DATA_DYNAMIC,
  DATA_STATIC
} DataT;


enum TextureT {
  TEXTURE_1D,
  TEXTURE_2D,
  TEXTURE_3D,
  TEXTURE_CUBE
};


typedef enum {
  TOPOLOGY_POINT_LIST,
  TOPOLOGY_LINE_LIST,
  TOPOLOGY_LINE_STRIP,
  TOPOLOGY_TRIANGLE_LIST,
  TOPOLOGY_TRIANGLE_STRIP,
  TOPOLOGY_TRIANGLE_FAN,
  TOPOLOGY_LINE_LIST_WITH_ADJACENCY,
  TOPOLOGY_LINE_STRIP_WITH_ADJACENCY,
  TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY,
  TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY,
} TopologyT;


// Enum types based on Vulkan Blend Factors.
// OpenGL Will need to be a bit picky about few of these.
typedef enum {
  BLEND_ZERO,
  BLEND_ONE,
  BLEND_SRC_COLOR,
  BLEND_ONE_MINUS_SRC_COLOR,
  BLEND_DST_COLOR,
  BLEND_ONE_MINUS_DST_COLOR,
  BLEND_SRC_ALPHA,
  BLEND_ONE_MINUS_SRC_ALPHA,
  BLEND_DST_ALPHA,
  BLEND_ONE_MINUS_DST_ALPHA,
  BLEND_CONSTANT_COLOR,
  BLEND_ONE_MINUS_CONSTANT_COLOR,
  BLEND_CONSTANT_ALPHA,
  BLEND_ONE_MINUS_CONSTANT_ALPHA,
  BLEND_SRC_ALPHA_SATURATE,
  BLEND_SRC1_COLOR,
  BLEND_ONE_MINUS_SRC1_COLOR,
  BLEND_SRC1_ALPHA,
  BLEND_ONE_MINUS_SRC1_ALPHA
} BlendT;


// Blending operation types.
typedef enum {
  BLEND_OPERATION_ADD,
  BLEND_OPERATION_SUBTRACT,
  BLEND_OPERATION_REVERSE_SUBTRACT,
  BLEND_OPERATION_MIN,
  BLEND_OPERATION_MAX
} BlendOperationT;


// Culling mode type. Used to determine which side to cull on a mesh object.
typedef enum {
  CULL_MODE_FRONT,
  CULL_MODE_BACK,
  CULL_MODE_FRONT_AND_BACK
} CullModeT;


// Front face culling mode types. These are used to determine the
// front face order of an object to show, while culling the opposite 
// side.
typedef enum {
  FRONT_FACE_COUNTER_CLOCKWISE,
  FRONT_FACE_CLOCKWISE
} FrontFaceT;


// Compare operations. Used for Depth testing functionality.
typedef enum {
  COMPARE_NEVER,
  COMPARE_LESS,
  COMPARE_EQUAL,
  COMPARE_LESS_OR_EQUAL,
  COMPARE_GREATER,
  COMPARE_NOT_EQUAL,
  COMPARE_GREATER_OR_EQUAL,
  COMPARE_ALWAYS
} CompareT;


// Wrap Mode for texture samplers.
typedef enum {
  WRAP_MODE_REPEAT,
  WRAP_MODE_MIRRORED_REPEAT,
  WRAP_MODE_CLAMP_TO_EDGE,
  WRAP_MODE_CLAMP_TO_BORDER
} WrapModeT;

// FilterMode for texture samplers.
typedef enum {
  FILTER_MODE_NEAREST,
  FILTER_MODE_LINEAR
} FilterModeT;


// Texel Filtering modes for mipmaps.
typedef enum {
  SAMPLER_MIPMAP_MODE_NONE,
  SAMPLER_MIPMAP_MODE_NEAREST,
  SAMPLER_MIPMAP_MODE_LINEAR
} SamplerMipMapMode;


// RenderDevice error types.
typedef enum {
  RENDER_ERROR_NONE,
  RENDER_ERROR_RENDER_DEVICE_UNINITIALIZED,
  RENDER_ERROR_BAD_MEMORY_STRUCTURE_ALLOC,
  RENDER_ERROR_BAD_TEXTURE_ALLOC,
  RENDER_ERROR_BAD_RENDER_TARGET_ALLOC,
  RENDER_ERROR_BAD_RENDER_PASS_ALLOC,
  RENDER_ERROR_BAD_FRAMEBUFFER_ALLOC,
  RENDER_ERROR_BAD_UNIFORM_BUFFER_ALLOC,
  RENDER_ERROR_BAD_GRAPHICS_PIPELINE_STATE_ALLOC,
  RENDER_ERROR_BAD_COMPUTE_PIPELINE_STATE_ALLOC,
  RENDER_ERROR_BAD_SHADER_ALLOC,
  RENDER_ERROR_BAD_VERTEX_BUFFER_ALLOC,
  RENDER_ERROR_BAD_COMMAND_BUFFER_ALLOC,
  RENDER_ERROR_PIPELINE_NULL_VERTEX_SHADER,
  RENDER_ERROR_PIPELINE_NULL_PIXEL_SHADER,
  RENDER_ERROR_NULL_VERTEX_BUFFER,
  RENDER_ERROR_NULL_COMMAND_BUFFER_LIST,
  RENDER_ERROR_NULL_GRAPHICS_PIPELINE_STATE,
  RENDER_ERROR_NULL_COMPUTE_PIPELINE_STATE,
  RENDER_ERROR_PIPELINE_BAD_INFORMATION_SET,
  RENDER_ERROR_PIPELINE_SHADER_LINK_ERROR,
  RENDER_ERROR_PIPELINE_UNCOMPILED_SHADER,
  RENDER_ERROR_PIPELINE_FAIL
} RenderErrorT;


// NOTE(): Not all of these formats are supported.
// OpenGL Definitely does not support most of these.
typedef enum {
  FORMAT_UNDEFINED = 0,
  FORMAT_R4G4_UNORM_PACK8 = 1,
  FORMAT_R4G4B4A4_UNORM_PACK16 = 2,
  FORMAT_B4G4R4A4_UNORM_PACK16 = 3,
  FORMAT_R5G6B5_UNORM_PACK16 = 4,
  FORMAT_B5G6R5_UNORM_PACK16 = 5,
  FORMAT_R5G5B5A1_UNORM_PACK16 = 6,
  FORMAT_B5G5R5A1_UNORM_PACK16 = 7,
  FORMAT_A1R5G5B5_UNORM_PACK16 = 8,
  FORMAT_R8_UNORM = 9,
  FORMAT_R8_SNORM = 10,
  FORMAT_R8_USCALED = 11,
  FORMAT_R8_SSCALED = 12,
  FORMAT_R8_UINT = 13,
  FORMAT_R8_SINT = 14,
  FORMAT_R8_SRGB = 15,
  FORMAT_R8G8_UNORM = 16,
  FORMAT_R8G8_SNORM = 17,
  FORMAT_R8G8_USCALED = 18,
  FORMAT_R8G8_SSCALED = 19,
  FORMAT_R8G8_UINT = 20,
  FORMAT_R8G8_SINT = 21,
  FORMAT_R8G8_SRGB = 22,
  FORMAT_R8G8B8_UNORM = 23,
  FORMAT_R8G8B8_SNORM = 24,
  FORMAT_R8G8B8_USCALED = 25,
  FORMAT_R8G8B8_SSCALED = 26,
  FORMAT_R8G8B8_UINT = 27,
  FORMAT_R8G8B8_SINT = 28,
  FORMAT_R8G8B8_SRGB = 29,
  FORMAT_B8G8R8_UNORM = 30,
  FORMAT_B8G8R8_SNORM = 31,
  FORMAT_B8G8R8_USCALED = 32,
  FORMAT_B8G8R8_SSCALED = 33,
  FORMAT_B8G8R8_UINT = 34,
  FORMAT_B8G8R8_SINT = 35,
  FORMAT_B8G8R8_SRGB = 36,
  FORMAT_R8G8B8A8_UNORM = 37,
  FORMAT_R8G8B8A8_SNORM = 38,
  FORMAT_R8G8B8A8_USCALED = 39,
  FORMAT_R8G8B8A8_SSCALED = 40,
  FORMAT_R8G8B8A8_UINT = 41,
  FORMAT_R8G8B8A8_SINT = 42,
  FORMAT_R8G8B8A8_SRGB = 43,
  FORMAT_B8G8R8A8_UNORM = 44,
  FORMAT_B8G8R8A8_SNORM = 45,
  FORMAT_B8G8R8A8_USCALED = 46,
  FORMAT_B8G8R8A8_SSCALED = 47,
  FORMAT_B8G8R8A8_UINT = 48,
  FORMAT_B8G8R8A8_SINT = 49,
  FORMAT_B8G8R8A8_SRGB = 50,
  FORMAT_A8B8G8R8_UNORM_PACK32 = 51,
  FORMAT_A8B8G8R8_SNORM_PACK32 = 52,
  FORMAT_A8B8G8R8_USCALED_PACK32 = 53,
  FORMAT_A8B8G8R8_SSCALED_PACK32 = 54,
  FORMAT_A8B8G8R8_UINT_PACK32 = 55,
  FORMAT_A8B8G8R8_SINT_PACK32 = 56,
  FORMAT_A8B8G8R8_SRGB_PACK32 = 57,
  FORMAT_A2R10G10B10_UNORM_PACK32 = 58,
  FORMAT_A2R10G10B10_SNORM_PACK32 = 59,
  FORMAT_A2R10G10B10_USCALED_PACK32 = 60,
  FORMAT_A2R10G10B10_SSCALED_PACK32 = 61,
  FORMAT_A2R10G10B10_UINT_PACK32 = 62,
  FORMAT_A2R10G10B10_SINT_PACK32 = 63,
  FORMAT_A2B10G10R10_UNORM_PACK32 = 64,
  FORMAT_A2B10G10R10_SNORM_PACK32 = 65,
  FORMAT_A2B10G10R10_USCALED_PACK32 = 66,
  FORMAT_A2B10G10R10_SSCALED_PACK32 = 67,
  FORMAT_A2B10G10R10_UINT_PACK32 = 68,
  FORMAT_A2B10G10R10_SINT_PACK32 = 69,
  FORMAT_R16_UNORM = 70,
  FORMAT_R16_SNORM = 71,
  FORMAT_R16_USCALED = 72,
  FORMAT_R16_SSCALED = 73,
  FORMAT_R16_UINT = 74,
  FORMAT_R16_SINT = 75,
  FORMAT_R16_SFLOAT = 76,
  FORMAT_R16G16_UNORM = 77,
  FORMAT_R16G16_SNORM = 78,
  FORMAT_R16G16_USCALED = 79,
  FORMAT_R16G16_SSCALED = 80,
  FORMAT_R16G16_UINT = 81,
  FORMAT_R16G16_SINT = 82,
  FORMAT_R16G16_SFLOAT = 83,
  FORMAT_R16G16B16_UNORM = 84,
  FORMAT_R16G16B16_SNORM = 85,
  FORMAT_R16G16B16_USCALED = 86,
  FORMAT_R16G16B16_SSCALED = 87,
  FORMAT_R16G16B16_UINT = 88,
  FORMAT_R16G16B16_SINT = 89,
  FORMAT_R16G16B16_SFLOAT = 90,
  FORMAT_R16G16B16A16_UNORM = 91,
  FORMAT_R16G16B16A16_SNORM = 92,
  FORMAT_R16G16B16A16_USCALED = 93,
  FORMAT_R16G16B16A16_SSCALED = 94,
  FORMAT_R16G16B16A16_UINT = 95,
  FORMAT_R16G16B16A16_SINT = 96,
  FORMAT_R16G16B16A16_SFLOAT = 97,
  FORMAT_R32_UINT = 98,
  FORMAT_R32_SINT = 99,
  FORMAT_R32_SFLOAT = 100,
  FORMAT_R32G32_UINT = 101,
  FORMAT_R32G32_SINT = 102,
  FORMAT_R32G32_SFLOAT = 103,
  FORMAT_R32G32B32_UINT = 104,
  FORMAT_R32G32B32_SINT = 105,
  FORMAT_R32G32B32_SFLOAT = 106,
  FORMAT_R32G32B32A32_UINT = 107,
  FORMAT_R32G32B32A32_SINT = 108,
  FORMAT_R32G32B32A32_SFLOAT = 109,
  FORMAT_R64_UINT = 110,
  FORMAT_R64_SINT = 111,
  FORMAT_R64_SFLOAT = 112,
  FORMAT_R64G64_UINT = 113,
  FORMAT_R64G64_SINT = 114,
  FORMAT_R64G64_SFLOAT = 115,
  FORMAT_R64G64B64_UINT = 116,
  FORMAT_R64G64B64_SINT = 117,
  FORMAT_R64G64B64_SFLOAT = 118,
  FORMAT_R64G64B64A64_UINT = 119,
  FORMAT_R64G64B64A64_SINT = 120,
  FORMAT_R64G64B64A64_SFLOAT = 121,
  FORMAT_B10G11R11_UFLOAT_PACK32 = 122,
  FORMAT_E5B9G9R9_UFLOAT_PACK32 = 123,
  FORMAT_D16_UNORM = 124,
  FORMAT_X8_D24_UNORM_PACK32 = 125,
  FORMAT_D32_SFLOAT = 126,
  FORMAT_S8_UINT = 127,
  FORMAT_D16_UNORM_S8_UINT = 128,
  FORMAT_D24_UNORM_S8_UINT = 129,
  FORMAT_D32_SFLOAT_S8_UINT = 130,
  FORMAT_BC1_RGB_UNORM_BLOCK = 131,
  FORMAT_BC1_RGB_SRGB_BLOCK = 132,
  FORMAT_BC1_RGBA_UNORM_BLOCK = 133,
  FORMAT_BC1_RGBA_SRGB_BLOCK = 134,
  FORMAT_BC2_UNORM_BLOCK = 135,
  FORMAT_BC2_SRGB_BLOCK = 136,
  FORMAT_BC3_UNORM_BLOCK = 137,
  FORMAT_BC3_SRGB_BLOCK = 138,
  FORMAT_BC4_UNORM_BLOCK = 139,
  FORMAT_BC4_SNORM_BLOCK = 140,
  FORMAT_BC5_UNORM_BLOCK = 141,
  FORMAT_BC5_SNORM_BLOCK = 142,
  FORMAT_BC6H_UFLOAT_BLOCK = 143,
  FORMAT_BC6H_SFLOAT_BLOCK = 144,
  FORMAT_BC7_UNORM_BLOCK = 145,
  FORMAT_BC7_SRGB_BLOCK = 146,
  FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 147,
  FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 148,
  FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 149,
  FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 150,
  FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 151,
  FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 152,
  FORMAT_EAC_R11_UNORM_BLOCK = 153,
  FORMAT_EAC_R11_SNORM_BLOCK = 154,
  FORMAT_EAC_R11G11_UNORM_BLOCK = 155,
  FORMAT_EAC_R11G11_SNORM_BLOCK = 156,
  FORMAT_ASTC_4x4_UNORM_BLOCK = 157,
  FORMAT_ASTC_4x4_SRGB_BLOCK = 158,
  FORMAT_ASTC_5x4_UNORM_BLOCK = 159,
  FORMAT_ASTC_5x4_SRGB_BLOCK = 160,
  FORMAT_ASTC_5x5_UNORM_BLOCK = 161,
  FORMAT_ASTC_5x5_SRGB_BLOCK = 162,
  FORMAT_ASTC_6x5_UNORM_BLOCK = 163,
  FORMAT_ASTC_6x5_SRGB_BLOCK = 164,
  FORMAT_ASTC_6x6_UNORM_BLOCK = 165,
  FORMAT_ASTC_6x6_SRGB_BLOCK = 166,
  FORMAT_ASTC_8x5_UNORM_BLOCK = 167,
  FORMAT_ASTC_8x5_SRGB_BLOCK = 168,
  FORMAT_ASTC_8x6_UNORM_BLOCK = 169,
  FORMAT_ASTC_8x6_SRGB_BLOCK = 170,
  FORMAT_ASTC_8x8_UNORM_BLOCK = 171,
  FORMAT_ASTC_8x8_SRGB_BLOCK = 172,
  FORMAT_ASTC_10x5_UNORM_BLOCK = 173,
  FORMAT_ASTC_10x5_SRGB_BLOCK = 174,
  FORMAT_ASTC_10x6_UNORM_BLOCK = 175,
  FORMAT_ASTC_10x6_SRGB_BLOCK = 176,
  FORMAT_ASTC_10x8_UNORM_BLOCK = 177,
  FORMAT_ASTC_10x8_SRGB_BLOCK = 178,
  FORMAT_ASTC_10x10_UNORM_BLOCK = 179,
  FORMAT_ASTC_10x10_SRGB_BLOCK = 180,
  FORMAT_ASTC_12x10_UNORM_BLOCK = 181,
  FORMAT_ASTC_12x10_SRGB_BLOCK = 182,
  FORMAT_ASTC_12x12_UNORM_BLOCK = 183,
  FORMAT_ASTC_12x12_SRGB_BLOCK = 184,
} FormatT;


enum PipelineBindPoint {
  BIND_POINT_GRAPHICS,
  BIND_POINT_COMPUTE
};


enum AttachmentLoadOp {
  ATTACHMENT_LOAD_OP_LOAD,
  ATTACHMENT_LOAD_OP_CLEAR,
  ATTACHMENT_LOAD_OP_DONT_CARE
};


enum AttachmentStoreOp {
  ATTACHMENT_STORE_OP_STORE,
  ATTACHMENT_STORE_OP_DONT_CARE
};


enum ImageLayout {
  IMAGE_LAYOUT_UNDEFINED,
  IMAGE_LAYOUT_GENERAL,
  IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
  IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL,
  IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL,
  IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
  IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
  IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
  IMAGE_LAYOUT_PREINITIALIZED,
  IMAGE_LAYOUT_PRESENT_SRC_KHR
};


enum SampleCount : uint8 {
  SAMPLE_COUNT_1_BIT  = (1 << 0),
  SAMPLE_COUNT_2_BIT  = (1 << 1),
  SAMPLE_COUNT_4_BIT  = (1 << 2),
  SAMPLE_COUNT_8_BIT  = (1 << 3),
  SAMPLE_COUNT_16_BIT = (1 << 4),
  SAMPLE_COUNT_32_BIT = (1 << 5),
  SAMPLE_COUNT_64_BIT = (1 << 6)
};


enum VertexInputRate {
  VERTEX_INPUT_RATE_VERTEX,
  VERTEX_INPUT_RATE_INSTANCE
};


struct TextureInfoT {
  uint32        Mipmaps;
  FormatT       Format;
  bool8         Mipmapped;
  bool8         Multisampled;
  SampleCount   Samples;
};


enum BufferType {
  BUFFER_TYPE_VERTEX_BUFFER,
  BUFFER_TYPE_INDEX_BUFFER,
  BUFFER_TYPE_STORAGE_BUFFER,
  BUFFER_TYPE_UNIFORM_BUFFER
};
} // jackal