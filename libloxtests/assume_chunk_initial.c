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
 * \brief       Assumption concerning the bytecode chunks.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        assume_chunk_initial.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file implements testing utilities concerning the bytecode chunk data
 * structure.
 */

/******************************************************************************/

/*
 * Includes.
 */

// This project.
#include "loxtests.h"



/**
 * \brief   Check whether a given chunk still has its initial state.
 * \param   chunk   The chunk to test
 *
 * The unit tests for the bytecode chunks frequently require to check whether a
 * certain chunk was already edited or not.  This function will abbreviate the
 * testing code.
 */

void assume_chunk_initial (const chunk_t * const chunk)
{
    ck_assert (chunk -> capacity == 0x0);
    ck_assert (chunk -> code     == NULL);
    ck_assert (chunk -> count    == 0x0);
    ck_assert (chunk -> lines    == NULL);

    return;
}

/******************************************************************************/
