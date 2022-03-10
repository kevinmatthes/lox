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
 * \file        debug.h
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file introduces useful debugging utilities.
 */

/******************************************************************************/

/*
 * Security settings.
 */

#pragma once
#ifndef __LOX__DEBUG_H__
#define __LOX__DEBUG_H__



/*
 * Includes.
 */

// The C standard library.
#include <stdio.h>

// This project.
#include "chunk.h"



/*
 * Macros.
 */

// .



/*
 * Function declarations.
 */

extern  void    chunk_disassemble       ( const chunk_t * const chunk
                                        , const char * const    name
                                        );
extern  int     disassemble_instruction ( const chunk_t * const chunk
                                        , const int             offset
                                        );
extern  int     simple_instruction      ( const char * const    name
                                        , const int             offset
                                        );



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
#endif  // ! __LOX__DEBUG_H__

/******************************************************************************/
