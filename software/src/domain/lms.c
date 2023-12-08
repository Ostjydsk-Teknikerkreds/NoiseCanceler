/*******************************************************************************
 * @file lms.c
 * @date 2023-12-06
 * @author Markus Rytter (markus.r@live.dk)
 *
 * @copyright Copyright (c) 2023
 *
 ******************************************************************************/

/**
 * @addtogroup Domain
 * @{
 */

/*******************************************************************************
 *    Private Includes
 ******************************************************************************/

#include "lms.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

/*******************************************************************************
 *    Private Defines
 ******************************************************************************/

/*******************************************************************************
 *    Private Type defintions
 ******************************************************************************/

/*******************************************************************************
 *    Extern
 ******************************************************************************/

/*******************************************************************************
 *    Private Class/Functions
 ******************************************************************************/

static float lms_filter_get_input_normalizer(float *inputs, uint16_t size)
{
    float ret = 0;
    for(uint16_t i = 0; i < size; i++)
    {
        ret += inputs[i] * inputs[i];
    }
    return ret;
}

/*******************************************************************************/

static void lms_filter_error(lms_filter_t *filter, float *inputs, uint16_t size, float error)
{
    float normalizer = lms_filter_get_input_normalizer(inputs, size);
    for(int i = 0; i < size; i++)
    {
        filter->weights[i] += error * filter->step_size * inputs[i] / (normalizer + filter->regularization);
    }
}

/*******************************************************************************/

/*******************************************************************************
 *    Public Class/Functions
 ******************************************************************************/

void lms_filter_init(lms_filter_t *filter, uint16_t inputs, float step_size, float regularization)
{
    filter->weights = (float *) malloc(sizeof(float) * inputs);
    memset(filter->weights, 0, sizeof(float) * inputs);
    filter->step_size = step_size;
    filter->regularization = regularization;
}

/*******************************************************************************/

float lms_filter_evaluate(float * inputs, uint16_t size, float desired)
{
    float ret = 0;
    assert(size == filter->number_of_weights);
    for(int i = 0; i < size; i++)
    {
        ret += filter->weights[i] * inputs[i];
    }
    lms_filter_error(filter, inputs, size, desired - ret);
    return ret;
}

/*******************************************************************************/

/** @} addtogroup end */