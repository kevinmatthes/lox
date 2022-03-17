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
 * \brief       The bytecode utilities.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        chunk.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file implements the bytecode utilities.
 */

/******************************************************************************/

/*
 * Includes.
 */

// This project.
#include "chunk.h"



/**
 * \brief   Append an instruction to a certain chunk of bytecode.
 * \param   chunk   The chunk to append a byte to.
 * \param   byte    The byte to append to the chunk.
 * \param   line    The line where this instruction occurs.
 *
 * This function will add a given instruction to a certain chunk of bytecode.
 */

void chunk_write (chunk_t * const chunk, const uint8_t byte, const int line)
{
    if (chunk -> capacity < chunk -> count + 0x1)
    {
        const int old_capacity = chunk -> capacity;

        chunk -> capacity   = GROW_CAPACITY (old_capacity);
        chunk -> code       = GROW_ARRAY ( uint8_t
                                         , chunk -> code
                                         , old_capacity
                                         , chunk -> capacity
                                         );
        chunk -> lines      = GROW_ARRAY ( int
                                         , chunk -> lines
                                         , old_capacity
                                         , chunk -> capacity
                                         );
    };

    chunk -> code[chunk -> count]   = byte;
    chunk -> lines[chunk -> count]  = line;

    chunk -> count++;

    return;
}

/******************************************************************************/
