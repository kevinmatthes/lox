/*
 * Copyright (C) 2022 Kevin Matthes
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * \author      Kevin Matthes
 * \brief       The constant utilities.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        value_array_write.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file implements the constant utilities.
 */

/******************************************************************************/

/*
 * Includes.
 */

// This project.
#include "value.h"



/**
 * \brief   Append a value to a certain value array.
 * \param   array   The array to append a value to.
 * \param   value   The value to append.
 *
 * This function will add a given value to a certain value array.
 */

void value_array_write (value_array_t * const array, const value_t value)
{
    if (array -> capacity < array -> count + 0x1)
    {
        const int old_capacity = array -> capacity;

        array -> capacity   = GROW_CAPACITY (old_capacity);
        array -> values     = GROW_ARRAY ( value_t
                                         , array -> values
                                         , old_capacity
                                         , array -> capacity
                                         );
    };

    array -> values[array -> count] = value;
    array -> count++;

    return;
}

/******************************************************************************/
