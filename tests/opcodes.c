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
 * \brief       Tests for the different opcodes.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        opcodes.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * These tests will check the different opcodes.
 */

/******************************************************************************/

/*
 * Includes.
 */

// The C standard library.
#include <stdio.h>

// This project.
#include "chunk.h"
#include "common.h"
#include "debug.h"



/**
 * \brief   The main function of the application.
 * \param   argc    The count of command line arguments.
 * \param   args    The command line arguments.
 * \return  The application status.
 *
 * This is the main function of the Lox compiler.
 *
 * The return codes have the following meanings:
 *
 * | Code   | Meaning                                                   |
 * |:------:|:----------------------------------------------------------|
 * | 0      | Anything alright, no problem occured.                     |
 * | 1      | The memory did not suffice for the required allocations.  |
 */

int main (const int argc, const char ** args)
{
    chunk_t chunk;

    chunk_init (& chunk);
    chunk_write (& chunk, OP_RETURN);
    chunk_disassemble (& chunk, "Test 0x1");
    chunk_free (& chunk);

    return 0x0;

    fprintf (stderr, "%d %s\n", argc, args[0x0]);
}

/******************************************************************************/
