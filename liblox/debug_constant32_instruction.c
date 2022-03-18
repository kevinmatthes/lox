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
 * \brief       The debugging utilities.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        debug_constant32_instruction.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file implements useful debugging utilities.
 */

/******************************************************************************/

/*
 * Includes.
 */

// This project.
#include "debug.h"



/**
 * \brief   Determine the offset for a constant instruction.
 * \param   name    The instruction's identifier.
 * \param   chunk   The chunk to disassemble.
 * \param   offset  The index of the given instruction.
 * \return  The index of the succeeding instruction.
 *
 * A constant instruction contains the opcode as well as the corresponding value
 * to store.
 */

int debug_constant32_instruction ( const char * const       name
                                 , const chunk_t * const    chunk
                                 , const int                offset
                                 )
{
    const uint8_t   byte1       = chunk -> code[offset + 0x1];
    const uint8_t   byte2       = chunk -> code[offset + 0x2];
    const uint8_t   byte3       = chunk -> code[offset + 0x3];
    const uint8_t   byte4       = chunk -> code[offset + 0x4];

    const uint32_t  constant    = (byte1 << 0x18)
                                | (byte2 << 0x10)
                                | (byte3 << 0x8)
                                | byte4;

    fprintf (stderr, "%-16s %16x '", name, constant);
    value_print (chunk -> constants.values[constant], stderr);
    fprintf (stderr, "'\n");

    return offset + 0x5;
}

/******************************************************************************/
