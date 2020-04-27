/**
  ******************************************************************************
  * @file    network_cnn.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sat Apr 25 21:23:15 2020
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network_cnn.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"

#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network_cnn
 
#undef AI_NETWORK_CNN_MODEL_SIGNATURE
#define AI_NETWORK_CNN_MODEL_SIGNATURE     "04df9f4d688b97fad5d31b055831dd59"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.0.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sat Apr 25 21:23:15 2020"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_CNN_N_BATCHES
#define AI_NETWORK_CNN_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #0 */
AI_STATIC ai_array conv2d_8_scratch0_array;   /* Array #1 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #2 */
AI_STATIC ai_array dense_6_bias_array;   /* Array #3 */
AI_STATIC ai_array dense_6_weights_array;   /* Array #4 */
AI_STATIC ai_array dense_5_bias_array;   /* Array #5 */
AI_STATIC ai_array dense_5_weights_array;   /* Array #6 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #7 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #8 */
AI_STATIC ai_array conv2d_8_bias_array;   /* Array #9 */
AI_STATIC ai_array conv2d_8_weights_array;   /* Array #10 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #11 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #12 */
AI_STATIC ai_array input_0_output_array;   /* Array #13 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #14 */
AI_STATIC ai_array conv2d_8_output_array;   /* Array #15 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #16 */
AI_STATIC ai_array dense_5_output_array;   /* Array #17 */
AI_STATIC ai_array dense_5_nl_output_array;   /* Array #18 */
AI_STATIC ai_array dense_6_output_array;   /* Array #19 */
AI_STATIC ai_array dense_6_nl_output_array;   /* Array #20 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_8_scratch0;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #2 */
AI_STATIC ai_tensor dense_6_bias;   /* Tensor #3 */
AI_STATIC ai_tensor dense_6_weights;   /* Tensor #4 */
AI_STATIC ai_tensor dense_5_bias;   /* Tensor #5 */
AI_STATIC ai_tensor dense_5_weights;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_8_bias;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_8_weights;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #12 */
AI_STATIC ai_tensor input_0_output;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_8_output;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_9_output0;   /* Tensor #17 */
AI_STATIC ai_tensor dense_5_output;   /* Tensor #18 */
AI_STATIC ai_tensor dense_5_nl_output;   /* Tensor #19 */
AI_STATIC ai_tensor dense_6_output;   /* Tensor #20 */
AI_STATIC ai_tensor dense_6_nl_output;   /* Tensor #21 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_8_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain dense_5_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain dense_5_nl_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain dense_6_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain dense_6_nl_chain;   /* Chain #6 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d_nl_pool conv2d_7_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_8_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_9_layer; /* Layer #2 */
AI_STATIC ai_layer_dense dense_5_layer; /* Layer #3 */
AI_STATIC ai_layer_nl dense_5_nl_layer; /* Layer #4 */
AI_STATIC ai_layer_dense dense_6_layer; /* Layer #5 */
AI_STATIC ai_layer_nl dense_6_nl_layer; /* Layer #6 */


/**  Array declarations section  **********************************************/
AI_ARRAY_OBJ_DECLARE(
    conv2d_9_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 1024,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_8_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 1024,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_7_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 1024,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_6_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 3,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_6_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 384,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 128,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_5_weights_array, AI_ARRAY_FORMAT_LUT4_FLOAT,
    NULL, NULL, 131072,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_9_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 64,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_9_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 18432,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_8_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 32,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_8_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 4608,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 16,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 432,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
    NULL, NULL, 3072,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_7_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 4096,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_8_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 2048,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    conv2d_9_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 1024,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_5_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 128,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_5_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 128,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_6_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 3,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_6_nl_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
    NULL, NULL, 3,
     AI_STATIC)




/**  Tensor declarations section  *********************************************/
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 64, 8, 2), AI_STRIDE_INIT(4, 4, 4, 256, 2048),
  1, &conv2d_9_scratch0_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 32, 16, 2), AI_STRIDE_INIT(4, 4, 4, 128, 2048),
  1, &conv2d_8_scratch0_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 16, 32, 2), AI_STRIDE_INIT(4, 4, 4, 64, 2048),
  1, &conv2d_7_scratch0_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_6_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_6_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_6_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 128, 3, 1, 1), AI_STRIDE_INIT(4, 4, 512, 1536, 1536),
  1, &dense_6_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_5_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_5_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_5_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1024, 128, 1, 1), AI_STRIDE_INIT(4, 1, 512, 65536, 65536),
  1, &dense_5_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_9_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 32, 3, 3, 64), AI_STRIDE_INIT(4, 4, 128, 384, 1152),
  1, &conv2d_9_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_8_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 16, 3, 3, 32), AI_STRIDE_INIT(4, 4, 64, 192, 576),
  1, &conv2d_8_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_7_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 4, 12, 36, 108),
  1, &conv2d_7_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 32, 32), AI_STRIDE_INIT(4, 4, 4, 12, 384),
  1, &input_0_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &conv2d_7_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 4, 4, 128, 1024),
  1, &conv2d_8_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 4, 4, 256, 1024),
  1, &conv2d_9_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output0, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4096, 4096),
  1, &conv2d_9_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_5_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_5_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_5_nl_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_5_nl_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_6_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_6_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_6_nl_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_6_nl_output_array, NULL)


/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&input_0_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_7_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_ENTRY(&conv2d_7_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 0,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &AI_NET_OBJ_INSTANCE, &conv2d_8_layer, AI_STATIC,
  .tensors = &conv2d_7_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&conv2d_7_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_8_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_ENTRY(&conv2d_8_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 3,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC,
  .tensors = &conv2d_8_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&conv2d_8_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_9_output),
  AI_TENSOR_LIST_ENTRY(&conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_ENTRY(&conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 6,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &AI_NET_OBJ_INSTANCE, &dense_5_layer, AI_STATIC,
  .tensors = &conv2d_9_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&conv2d_9_output0),
  AI_TENSOR_LIST_ENTRY(&dense_5_output),
  AI_TENSOR_LIST_ENTRY(&dense_5_weights, &dense_5_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_5_layer, 11,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_5_nl_layer, AI_STATIC,
  .tensors = &dense_5_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_5_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&dense_5_output),
  AI_TENSOR_LIST_ENTRY(&dense_5_nl_output),
  AI_TENSOR_LIST_EMPTY,
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_5_nl_layer, 11,
  NL_TYPE,
  nl, forward_relu,
  &AI_NET_OBJ_INSTANCE, &dense_6_layer, AI_STATIC,
  .tensors = &dense_5_nl_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&dense_5_nl_output),
  AI_TENSOR_LIST_ENTRY(&dense_6_output),
  AI_TENSOR_LIST_ENTRY(&dense_6_weights, &dense_6_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_6_layer, 12,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_6_nl_layer, AI_STATIC,
  .tensors = &dense_6_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_6_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&dense_6_output),
  AI_TENSOR_LIST_ENTRY(&dense_6_nl_output),
  AI_TENSOR_LIST_EMPTY,
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_6_nl_layer, 12,
  NL_TYPE,
  nl, forward_sm,
  &AI_NET_OBJ_INSTANCE, &dense_6_nl_layer, AI_STATIC,
  .tensors = &dense_6_nl_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 161996, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 22784, 1,
                     NULL),
  AI_TENSOR_LIST_IO_ENTRY(AI_FLAG_NONE, AI_NETWORK_CNN_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_ENTRY(AI_FLAG_NONE, AI_NETWORK_CNN_OUT_NUM, &dense_6_nl_output),
  &conv2d_7_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_cnn_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    conv2d_9_scratch0_array.data = AI_PTR(activations + 18688);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 18688);
    conv2d_8_scratch0_array.data = AI_PTR(activations + 18688);
    conv2d_8_scratch0_array.data_start = AI_PTR(activations + 18688);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 18688);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 18688);
    input_0_output_array.data = AI_PTR(NULL);
    input_0_output_array.data_start = AI_PTR(NULL);
    conv2d_7_output_array.data = AI_PTR(activations + 2304);
    conv2d_7_output_array.data_start = AI_PTR(activations + 2304);
    conv2d_8_output_array.data = AI_PTR(activations + 0);
    conv2d_8_output_array.data_start = AI_PTR(activations + 0);
    conv2d_9_output_array.data = AI_PTR(activations + 14592);
    conv2d_9_output_array.data_start = AI_PTR(activations + 14592);
    dense_5_output_array.data = AI_PTR(activations + 14080);
    dense_5_output_array.data_start = AI_PTR(activations + 14080);
    dense_5_nl_output_array.data = AI_PTR(activations + 14080);
    dense_5_nl_output_array.data_start = AI_PTR(activations + 14080);
    dense_6_output_array.data = AI_PTR(activations + 14068);
    dense_6_output_array.data_start = AI_PTR(activations + 14068);
    dense_6_nl_output_array.data = AI_PTR(NULL);
    dense_6_nl_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool network_cnn_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_6_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_6_bias_array.data = AI_PTR(weights + 161984);
    dense_6_bias_array.data_start = AI_PTR(weights + 161984);
    dense_6_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_6_weights_array.data = AI_PTR(weights + 160448);
    dense_6_weights_array.data_start = AI_PTR(weights + 160448);
    dense_5_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_5_bias_array.data = AI_PTR(weights + 159936);
    dense_5_bias_array.data_start = AI_PTR(weights + 159936);
    dense_5_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_5_weights_array.data = AI_PTR(weights + 94400);
    dense_5_weights_array.data_start = AI_PTR(weights + 94336);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 94080);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 94080);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 20352);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 20352);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(weights + 20224);
    conv2d_8_bias_array.data_start = AI_PTR(weights + 20224);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(weights + 1792);
    conv2d_8_weights_array.data_start = AI_PTR(weights + 1792);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 1728);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 1728);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 0);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_network_cnn_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_CNN_MODEL_NAME,
      .model_signature   = AI_NETWORK_CNN_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 2990749,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_network_cnn_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_cnn_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_cnn_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_cnn_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= network_cnn_configure_weights(net_ctx, &params->params);
  ok &= network_cnn_configure_activations(net_ctx, &params->activations);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_cnn_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_cnn_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}

#undef AI_NETWORK_CNN_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

