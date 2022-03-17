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
 * \brief       Tests for the bytecode life cycle.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        chunk_lifecycle.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file contains all tests regarding the bytecode chunk's life cycle.
 */

/******************************************************************************/

/*
 * Includes.
 */

// This project.
#include "loxtests.h"



/**
 * \brief   A simple test for the chunk life cycle.
 * \return  Nothing.
 *
 * This test will check the simple chunk life cycle.
 */

START_TEST (chunk_lifecycle_0x1)
{
    chunk_t chunk;

    chunk_init (& chunk);
    chunk_write (& chunk, OP_RETURN);
    chunk_disassemble (& chunk, "Test 0x1");
    chunk_free (& chunk);

    return;
}
END_TEST



/**
 * \brief   The test case for chunk life cycles.
 * \return  The configurated test case.
 *
 * This function will construct a new test case in order to run all tests
 * concerning the life cycle of chunks of bytecode.
 */

TCase * chunk_lifecycle (void)
{
    TCase * tcase = tcase_create ("Life Cycle");

    tcase_add_test (tcase, chunk_lifecycle_0x1);

    return tcase;
}

/******************************************************************************/
