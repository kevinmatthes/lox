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
 * \brief       The bytecode utilities.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        chunk.h
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file introduces the bytecode utilities.
 */

/******************************************************************************/

/*
 * Security settings.
 */

#pragma once
#ifndef __LOX__CHUNK_H__
#define __LOX__CHUNK_H__



/*
 * Includes.
 */

// This project.
#include "common.h"



/*
 * Macros.
 */

// .



/**
 * \brief   The bytecode instructions.
 *
 * This enum encodes the different bytecode instructions to a small basic
 * instruction set for the Lox compiler.
 */

typedef enum
{
    OP_RETURN               /*!< Leave a function.                            */
}
opcode_t;



/**
 * \brief   The data structure for the bytecode sequences.
 *
 * This data structure organises the sequences of bytecode which form the
 * compilation of the input Lox scripts.
 */

typedef struct
{
    int         capacity;   /*!< The maximal count of instructions to hold.   */
    int         count;      /*!< The amount of held instructions.             */
    uint8_t *   code;       /*!< The bytecode sequence to process.            */
}
chunk_t;



/*
 * Function declarations.
 */

extern  void    chunk_init  (chunk_t * chunk);



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
#endif  // ! __LOX__CHUNK_H__

/******************************************************************************/
