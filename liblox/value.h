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
 * \file        value.h
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file introduces the constant utilities.
 */

/******************************************************************************/

/*
 * Security settings.
 */

#pragma once
#ifndef __LOX__VALUE_H__
#define __LOX__VALUE_H__



/*
 * Includes.
 */

// The C standard library.
#include <stdio.h>
#include <stdlib.h>

// This project.
#include "common.h"
#include "memory.h"



/*
 * Macros.
 */

// .



/**
 * \brief   The data structure for Lox values.
 *
 * This data structure will represent the possible values in Lox.
 */

typedef double value_t;



/**
 * \brief   The constant storage.
 *
 * This data structure stores the constant values which are introduced in a
 * certain chunk of bytecode.
 */

typedef struct
{
    /**
     * \brief   The maximum count of holdable values.
     *
     * This field represents the count of values which are at most storable by
     * this dynamic array.
     *
     * It is the count of allocated memory slots in sum.
     */

    int capacity;



    /**
     * \brief   The count of currently held values.
     *
     * This field represents the count of values actually held by this dynamic
     * array.
     *
     * It is the count of occupied memory slots from those which are allocated.
     */

    int count;



    /**
     * \brief   The constants to store.
     *
     * This pointer points to the set of constants contained in the current
     * chunk of bytecode.
     *
     * It is the memory region where the values are saved.
     */

    value_t * values;
}
value_array_t;



/*
 * Function declarations.
 */

extern  void    value_array_free    (value_array_t * array);
extern  void    value_array_init    (value_array_t * const array);
extern  void    value_array_write   ( value_array_t * const array
                                    , const value_t         value
                                    );
extern  void    value_print         (const value_t value, const FILE * stream);



/*
 * Constants.
 */

// .



/*
 * End of header.
 */

// Tidying up.
#ifndef __LOX_INTERNAL__
#endif  // ! __LOX_INTERNAL__

// Leaving the header.
#endif  // ! __LOX__VALUE_H__

/******************************************************************************/
