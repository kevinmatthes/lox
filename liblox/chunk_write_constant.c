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
 * \file        chunk_write_const.c
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
 * \brief   Append the instruction for an `OP_CONSTANT_32` value.
 * \param   chunk   The chunk to append a value to.
 * \param   value   The value to append to the chunk.
 * \param   line    The line where this instruction occurs.
 *
 * This function will add a given value to a certain chunk of bytecode.
 */

void chunk_write_const ( chunk_t * const chunk
                       , const value_t   value
                       , const int       line
                       )
{
    return;
}

/******************************************************************************/
