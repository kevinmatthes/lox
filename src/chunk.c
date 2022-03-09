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
#include "memory.h"



/**
 * \brief   Free a chunk of bytecode.
 * \param   chunk   The chunk to free.
 *
 * Since the given chunk required the allocation of memory, this allocation
 * should be revoked appropriately as soon as the chunk is not required anymore.
 *
 * After the freeing is complete, the chunk will be reinitialised.
 */

void chunk_free (chunk_t * chunk)
{
    FREE_ARRAY (uint8_t, chunk -> code, chunk -> capacity);
    chunk_init (chunk);

    return;
}



/**
 * \brief   Construct a new chunk of bytecode.
 * \param   chunk   The chunk to initialise.
 *
 * This function will prepare the given chunk of bytecode with sane initial
 * values.
 */

void chunk_init (chunk_t * chunk)
{
    chunk -> capacity   = 0x0;
    chunk -> count      = 0x0;
    chunk -> code       = NULL;

    return;
}



/**
 * \brief   Append an instruction to a certain chunk of bytecode.
 * \param   chunk   The chunk to append a byte to.
 * \param   byte    The byte to append to the chunk.
 *
 * This function will add a given instruction to a certain chunk of bytecode.
 */

void chunk_write (chunk_t * chunk, const uint8_t byte)
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
    };

    chunk -> code[chunk -> count] = byte;
    chunk -> count++;

    return;
}

/******************************************************************************/
