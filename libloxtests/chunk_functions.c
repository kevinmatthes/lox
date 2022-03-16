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
 * \file        chunk_functions.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file contains all tests regarding the bytecode chunk's management
 * functions.
 */

/******************************************************************************/

/*
 * Includes.
 */

// This project.
#include "loxtests.h"



/**
 * \brief   A simple test for the initialisation of bytecode chunks.
 *
 * This test will check whether the chunk contains sane initial values after
 * being initialised.
 */

START_TEST (chunk_functions_init)
{
    chunk_t chunk;

    chunk_init (& chunk);

    ck_assert (chunk.capacity == 0x0);
    ck_assert (chunk.code     == NULL);
    ck_assert (chunk.count    == 0x0);

    chunk_write (& chunk, OP_RETURN);
    chunk_free (& chunk);

    return;
}
END_TEST



/**
 * \brief   A simple test for the writing of bytecode chunks.
 *
 * This test will check whether the chunk still contains its initial values
 * after appending an instruction to it.
 */

START_TEST (chunk_functions_write)
{
    chunk_t chunk;

    chunk_init (& chunk);
    chunk_write (& chunk, OP_RETURN);

    ck_assert (chunk.capacity != 0x0);
    ck_assert (chunk.code     != NULL);
    ck_assert (chunk.count    != 0x0);

    chunk_free (& chunk);

    return;
}
END_TEST



/**
 * \brief   The test case for chunk management.
 * \return  The configurated test case.
 *
 * This function will construct a new test case in order to run all tests
 * concerning the management of chunks of bytecode.
 */

TCase * chunk_functions (void)
{
    TCase * tcase = tcase_create ("Management Functions");

    tcase_add_test (tcase, chunk_functions_init);
    tcase_add_test (tcase, chunk_functions_write);

    return tcase;
}

/******************************************************************************/
