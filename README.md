<!------------------------------------------------------------------------------
--
-- Copyright (C) 2022 Kevin Matthes
--
-- This program is free software; you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 2 of the License, or
-- (at your option) any later version.
--
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License along
-- with this program; if not, write to the Free Software Foundation, Inc.,
-- 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
--
----
--
--  FILE
--      README.md
--
--  BRIEF
--      Important information regarding this project.
--
--  AUTHOR
--      Kevin Matthes
--
--  COPYRIGHT
--      (C) 2022 Kevin Matthes.
--      This file is licensed GPL 2 as of June 1991.
--
--  DATE
--      2022
--
--  NOTE
--      See `LICENSE' for full license.
--
------------------------------------------------------------------------------->

# lox

## Summary

My implementation of the Lox coding language.

## License

This project's license is **GPL 2** (as of June 1991).  The whole license text
can be found in `LICENSE` in the main directory of this repository.  The brief
version is as follows:

> Copyright (C) 2022 Kevin Matthes
>
> This program is free software; you can redistribute it and/or modify
> it under the terms of the GNU General Public License as published by
> the Free Software Foundation; either version 2 of the License, or
> (at your option) any later version.
>
> This program is distributed in the hope that it will be useful,
> but WITHOUT ANY WARRANTY; without even the implied warranty of
> MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
> GNU General Public License for more details.
>
> You should have received a copy of the GNU General Public License along
> with this program; if not, write to the Free Software Foundation, Inc.,
> 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

When compiling a printable version of this documentation using Pandoc, the full
license will be attached automatically to the resulting document.  This can be
invoked by calling `repository-manual.m`.

## Software Requirements

| Requirement       | Type          | Role                                  |
|:------------------|:-------------:|:--------------------------------------|
| `ar`              | application   | create and update static libraries    |
| Check             | library       | C unit tests                          |
| `docs-snippets`   | repository    | documentation constants               |
| Doxygen           | application   | creation of source code documentation |
| GCC               | application   | C compiler                            |
| GNU Octave        | application   | execution of the provided scripts     |
| `make`            | application   | finalisation of Doxygen documentation |
| Pandoc            | application   | compilation of repository manual      |
| `texlive-full`    | package       | compilation of repository manual      |

The compilation of such an **optional** repository manual can be invoked by just
calling one of the following lines in a terminal.

```
octave repository-manual.m
octave-cli repository-manual.m
```

Both will redirect to the same application, GNU Octave, which will then create
the manual for this repository and attach the entire license to it.  The
resulting file, `repository.pdf`, will be saved in the main directory of this
repository.

## Description

This implementation follows the **bytecode interpreter** approach but differs
from the suggested one regarding various details.  *Hence, this is no standard
Lox* but extending it.

### Differences to the Standard Implementation

#### Hexadecimal Numbers

This implementation uses the hexadecimal representation of integer numbers
whenever possible and useful in both implementation and printed output.  One
exception to this rule is the line output in the bytecode disassembler which
will be made using the decimal representation in order to avoid confusion.

Although this compiler is built around hexadecimal numbers, it does not support
them, yet.

#### `OP_CONSTANT_32` -- `OP_CONSTANT_LONG` with 32 Bits

This compiler provides the extended storage range for constants, introduced in
challenge 14.2 by the further opcode instruction `OP_CONSTANT_LONG`.  But in
contrast to the original suggestion, it uses 32 instead of just 24 bits for this
instruction.

One reason for this decision was the better portability since `uint32_t` is a
native type declared by `stdint.h` such that the solution of this challenge can
be realised with a standard primitive instead of artificial types.

Furthermore, 4294967296 instead of 16777216 constants are possible, now.  This
was the second reason to decide against the suggested 24 bits for this
representation and to use more instead.

Since the language definition itself suggests a further constant like at least
`OP_CONSTANT_16` after the introduction of challenge 14.2, the chosen
implementation of it is named accordingly in order to reflect the provided count
of bits directly by its name.

### Solved Challanges

This implementation solved the following challenges suggested in the language
definition:

* Challenge 14.2 (`OP_CONSTANT_LONG`)

<!----------------------------------------------------------------------------->
