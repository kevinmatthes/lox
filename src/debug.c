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

void chunk_disassemble (const chunk_t * const chunk, const char * const name)
{
    fprintf (stderr, "== %s ==\n", name);

    for ( int i = 0x0
        ; i < chunk -> count
        ; i = disassemble_instruction (chunk, i)
        );

    return;
}

/******************************************************************************/
