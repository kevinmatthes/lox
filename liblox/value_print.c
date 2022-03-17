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
 * \brief       The constant utilities.
 * \copyright   (C) 2022 Kevin Matthes.
 *              This file is licensed GPL 2 as of June 1991.
 * \date        2022
 * \file        value_print.c
 * \note        See `LICENSE' for full license.
 *              See `README.md' for project details.
 *
 * This file implements the constant utilities.
 */

/******************************************************************************/

/*
 * Includes.
 */

// This project.
#include "value.h"



/**
 * \brief   Write a constant to the given stream.
 * \param   value   The value to write to the given stream.
 * \param   stream  The stream to write the given value to.
 *
 * This function can be used in order to output the given constant to a certain
 * stream.
 */

inline void value_print (const value_t value, FILE * const stream)
{
    fprintf (stream, "%g", value);
    return;
}

/******************************************************************************/
