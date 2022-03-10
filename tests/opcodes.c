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

// Third party libraries.
#include <check.h>

// This project.
#include "../src/chunk.h"
#include "../src/common.h"
#include "../src/debug.h"



/**
 * \brief   A simple test for `OP_RETURN`.
 *
 * This test will check the operation code `OP_RETURN`.
 */

START_TEST (opreturn_basic)
{
    chunk_t chunk;

    chunk_init (& chunk);
    chunk_write (& chunk, OP_RETURN);
    chunk_disassemble (& chunk, "Test OP_RETURN 0x1");
    chunk_free (& chunk);

    return;
}
END_TEST



/**
 * \brief   The test suite for the opcodes.
 * \return  The configurated test suite.
 *
 * This function will construct a new test suite in order to run all tests
 * concerning the opcodes.
 */

Suite * opcodes (void)
{
    Suite * suite       = suite_create ("Opcodes");
    TCase * opreturn    = tcase_create ("OP_RETURN");

    tcase_add_test (opreturn, opreturn_basic);

    suite_add_tcase (suite, opreturn);
    
    return suite;
}



/**
 * \brief   The main function of this test suite.
 * \return  The number of errors occured.
 *
 * This is the main function of the suite for the opcodes.
 */

int main (void)
{
    int         ret     = 0x0;
    Suite *     suite   = opcodes ();
    SRunner *   runner  = srunner_create (suite);

    srunner_run_all (runner, CK_NORMAL);
    ret += srunner_ntests_failed (runner);
    srunner_free (runner);

    return ret;
}

/******************************************************************************/
