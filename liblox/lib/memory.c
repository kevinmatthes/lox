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
 * \file        memory.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file implements useful memory management utilities.
 */

/******************************************************************************/

/*
 * Includes.
 */

// This project.
#include "memory.h"



/**
 * \brief   Adjust the memory allocation of the given dynamic array.
 * \param   pointer     The pointer to the allocated region.
 * \param   old_size    The current size of the given memory region.
 * \param   new_size    The intended new size of the given memory region.
 * \return  The pointer to the new memory region.
 *
 * This function manages all memory demands of the contained data structures.
 */

void * reallocate ( void * const    pointer
                  , const size_t    old_size
                  , const size_t    new_size
                  )
{
    void * ret = NULL;

    if (! new_size)
        free (pointer);
    else
    {
        ret = realloc (pointer, new_size);

        if (ret == NULL)
            exit (0x1);
    };

    return ret;

    size_t temp = old_size;
    temp = temp;
}

/******************************************************************************/
