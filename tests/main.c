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

// This project.
#include "lox-tests.h"



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
