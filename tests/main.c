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
 * \brief       The main file in order to invoke all tests.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        main.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file will invoke all prepared tests.
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
#include "../lib/chunk.h"
#include "../lib/common.h"
#include "../lib/debug.h"



/**
 * \brief   A simple test for the chunk life cycle.
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
 * \brief   The test suite for chunks.
 * \return  The configurated test suite.
 *
 * This function will construct a new test suite in order to run all tests
 * concerning chunks of bytecode.
 */

Suite * chunks (void)
{
    Suite * suite       = suite_create ("Chunks of Bytecode");
    TCase * opreturn    = tcase_create ("Life Cycle");

    tcase_add_test (opreturn, chunk_lifecycle_0x1);

    suite_add_tcase (suite, opreturn);

    return suite;
}



/**
 * \brief   The main test runner.
 * \return  The test runner.
 *
 * This function constructs the main test runner which will invoke all test
 * suites.
 */

SRunner * sr_main (void)
{
    SRunner * runner = srunner_create (NULL);

    srunner_add_suite (runner, chunks ());

    return runner;
}



/**
 * \brief   The main function.
 * \return  The number of errors occured.
 *
 * This function will run all tests.
 */

int main (void)
{
    int         ret     = 0x0;
    SRunner *   runner  = sr_main ();

    srunner_run_all (runner, CK_NORMAL);
    ret += srunner_ntests_failed (runner);
    srunner_free (runner);

    return ret;
}

/******************************************************************************/
