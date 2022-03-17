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
 * \file        debug.c
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
 * \brief   Show the function of a given piece of bytecode.
 * \param   chunk   The sequence of bytecode to analyse.
 * \param   name    The bytecode chunk's identifier and / or purpose.
 *
 * This function will prompt the content of a bytecode sequence to the user.
 */

void debug_disassemble_chunk ( const chunk_t * const    chunk
                             , const char * const       name
                             )
{
    fprintf (stderr, "== %s ==\n", name);

    for ( int i = 0x0
        ; i < chunk -> count
        ; i = debug_disassemble_instruction (chunk, i)
        );

    return;
}



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

int debug_constant_instruction ( const char * const       name
                               , const chunk_t * const    chunk
                               , const int                offset
                               )
{
    const uint8_t constant = chunk -> code[offset + 0x1];

    fprintf (stderr, "%-16s %4x '", name, constant);
    value_print (chunk -> constants.values[constant], stderr);
    fprintf (stderr, "'\n");

    return offset + 0x2;
}



/**
 * \brief   Explain the purpose of a certain instruction.
 * \param   chunk   The chunk to analyse the instructions of.
 * \param   offset  The index of the intruction to examine.
 * \return  The index of the next instruction.
 *
 * This function will prompt the purpose of the instructions a certain sequence
 * of bytecode contains to the user.
 */

int debug_disassemble_instruction ( const chunk_t * const   chunk
                                  , const int               offset
                                  )
{
    const uint8_t   instruction = chunk -> code[offset];
    int             ret         = 0x0;

    fprintf (stderr, "%04x ", offset);

    if (offset && chunk -> lines[offset] == chunk -> lines[offset - 0x1])
        fprintf (stderr, "   | ");
    else
        fprintf (stderr, "%4d ", chunk -> lines[offset]);

    switch (instruction)
    {
        default:
            fprintf (stderr, "Unknown opcode %d.\n", instruction);
            ret = 0x1;
            break;

        case OP_CONSTANT:
            ret = debug_constant_instruction ("OP_CONSTANT", chunk, offset);
            break;

        case OP_RETURN:
            ret = debug_simple_instruction ("OP_RETURN", offset);
            break;
    };

    return ret;
}



/**
 * \brief   Determine the offset for a simple instruction.
 * \param   name    The instruction's identifier.
 * \param   offset  The index of the given instruction.
 * \return  The index of the succeeding instruction.
 *
 * A simple instruction is an operation on its own which does not accept any
 * operands.  Hence, the offset to its successing operation is always 1.
 */

inline int debug_simple_instruction (const char * const name, const int offset)
{
    fprintf (stderr, "%s\n", name);
    return offset + 0x1;
}

/******************************************************************************/
