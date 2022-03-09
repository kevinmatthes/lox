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
 * \brief       The memory management utilities.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        memory.h
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file introduces useful memory management utilities.
 */

/******************************************************************************/

/*
 * Security settings.
 */

#pragma once
#ifndef __LOX__MEMORY_H__
#define __LOX__MEMORY_H__



/*
 * Includes.
 */

// The C standard library.
#include <stdlib.h>

// This project.
#include "common.h"



/**
 * \brief   Increase the capacity of the given dynamic array.
 * \param   t   The type of the array to increase the capacity of.
 * \param   p   The pointer to the array to increase the capacity of.
 * \param   o   The old capacity.
 * \param   n   The new capacity.
 * \return  The pointer to the memory region with the requested higher capacity.
 *
 * This macro abbreviates the process of memory reallocation in order to enlarge
 * the provided storage capacity for elements of the given type.
 *
 * This macro will be tidied up at the end of the header.
 */

#define GROW_ARRAY(t, p, o, n) \
    (t *) reallocate ((p), sizeof (t) * (o), sizeof (t) * (n))



/**
 * \brief   An abbreviation to increase the capacity of a dynamic array.
 * \param   c   The old capacity to increase.
 * \return  The new higher capacity.
 *
 * This macro abbreviates the determination of the new capacity for a dynamic
 * array.
 *
 * Beginning with an initial size, each call will double the current capacity.
 *
 * This macro will be tidied up at the end of the header.
 */

#define GROW_CAPACITY(c) \
    ((c) < 0x8 ? 0x8 : (c) << 0x2)



/*
 * Function declarations.
 */

extern  void *  reallocate  ( void * pointer
                            , const size_t old_size
                            , const size_t new_size
                            );



/*
 * Constants.
 */

// .



/*
 * End of header.
 */

// Tidying up.
#ifndef __LOX_INTERNAL__
#undef  GROW_ARRAY
#undef  GROW_CAPACITY
#endif  // ! __LOX_INTERNAL__

// Leaving the header.
#endif  // ! __LOX__MEMORY_H__

/******************************************************************************/
