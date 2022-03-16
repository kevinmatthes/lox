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
 * \brief       The runners in order to invoke tests.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        runners.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file defines the test suite runners in order to execute the configurated
 * tests.
 */

/******************************************************************************/

/*
 * Includes.
 */

// This project.
#include "loxtests.h"



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

/******************************************************************************/
