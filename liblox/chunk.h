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
#include "memory.h"
#include "value.h"



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
    OP_CONSTANT,            /*!< Add a constant to the value array.           */
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
    /**
     * \brief   The maximum count of holdable instructions.
     *
     * This field represents the count of instructions which are at most
     * storable by this dynamic array.
     *
     * It is the count of allocated memory slots in sum.
     */

    int capacity;



    /**
     * \brief   The count of currently held instructions.
     *
     * This field represents the count of instructions actually held by this
     * dynamic array.
     *
     * It is the count of occupied memory slots from those which are allocated.
     */

    int count;



    /**
     * \brief   The bytecode sequence to process.
     *
     * This pointer points to the sequence of bytecode which shall be processed
     * by the interpreter.
     *
     * It is the memory region where the bytecode is saved.
     */

    uint8_t * code;



    /**
     * \brief   The line information.
     *
     * Each instruction appears on a certain line.  This array helps in case of
     * compilation errors to easily determine in which region the error occured.
     */

    int * lines;



    /**
     * \brief   The values introduced by this piece bytecode.
     *
     * This value array saves the constants which occur in the section of source
     * code causing this chunk of bytecode.
     */

    value_array_t constants;
}
chunk_t;



/*
 * Function declarations.
 */

extern  int     chunk_add_const (chunk_t * const chunk, const value_t value);
extern  void    chunk_free      (chunk_t * chunk);
extern  void    chunk_init      (chunk_t * const chunk);
extern  void    chunk_write     ( chunk_t * const   chunk
                                , const uint8_t     byte
                                , const int         line
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
#endif  // ! __LOX__CHUNK_H__

/******************************************************************************/
