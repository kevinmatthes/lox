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
 * \brief       The main header of the test library for Lox.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        loxtests.h
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This header introduces all test cases, test suites and suite runners which
 * are created in order to ensure the correctness of this Lox implementation.
 */

/******************************************************************************/

/*
 * Security settings.
 */

#pragma once
#ifndef __LOX__TESTS_H__
#define __LOX__TESTS_H__



/*
 * Includes.
 */

// Third party libraries.
#include <check.h>

// This project.
#include "../liblox/chunk.h"
#include "../liblox/common.h"
#include "../liblox/debug.h"
#include "../liblox/memory.h"
#include "../liblox/value.h"



/*
 * Macros.
 */

// .



/*
 * Function declarations.
 */

// Assumptions.
extern  bool    assume_chunk_initial    (const chunk_t * const chunk);
extern  bool    assume_va_initial       (const value_array_t * const va);

// Suite runners.
extern  SRunner *   sr_main (void);

// Test suites.
extern  Suite * chunks  (void);

// Test cases.
extern  TCase * chunk_functions (void);
extern  TCase * chunk_lifecycle (void);



/*
 * Constants.
 */

// .



/*
 * End of header.
 */

// Tidying up.
#ifndef __LOX_INTERNAL__
#endif  // ! __LOX_INTERNAL__

// Leaving the header.
#endif  // ! __LOX__TESTS_H__

/******************************************************************************/
