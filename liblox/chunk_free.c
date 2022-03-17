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
 * \file        chunk_free.c
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
    FREE_ARRAY (int, chunk -> lines, chunk -> capacity);
    value_array_free (& chunk -> constants);
    chunk_init (chunk);

    return;
}

/******************************************************************************/
