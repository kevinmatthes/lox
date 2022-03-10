%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% Copyright (C) 2022 Kevin Matthes
%%
%% This program is free software; you can redistribute it and/or modify
%% it under the terms of the GNU General Public License as published by
%% the Free Software Foundation; either version 2 of the License, or
%% (at your option) any later version.
%%
%% This program is distributed in the hope that it will be useful,
%% but WITHOUT ANY WARRANTY; without even the implied warranty of
%% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%% GNU General Public License for more details.
%%
%% You should have received a copy of the GNU General Public License along
%% with this program; if not, write to the Free Software Foundation, Inc.,
%% 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
%%
%%%%
%%
%%  FILE
%%      gcc-tests.m
%%
%%  BRIEF
%%      Test the provided Fortran source code using `gcc`.
%%
%%  AUTHOR
%%      Kevin Matthes
%%
%%  COPYRIGHT
%%      (C) 2022 Kevin Matthes.
%%      This file is licensed GPL 2 as of June 1991.
%%
%%  DATE
%%      2022
%%
%%  NOTE
%%      See `LICENSE' for full license.
%%      See `README.md' for project details.
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%
%%
%% Variables.
%%
%%%%

% Software.
compiler.self   = ' gcc ';
compiler.flags  = ' -Wall -Werror -Wextra -Wpedantic ';
compiler.flags  = [compiler.flags ' -std=f95 '];
compiler.flags  = [compiler.flags ' -fall-intrinsics '];
compiler.link   = '';
compiler.call   = [compiler.self compiler.flags];



% Files.
files.app1.out  = '';
files.app1.self = '';

files.self  = 'gcc-tests.m';



% Control flow.
banner      = ['[ ' files.self ' ] '];
failures    = 0;



% Call adjustment.
compiler.app1   = [compiler.call files.app1.self];
compiler.app1   = [compiler.app1 compiler.link];
compiler.app1   = [compiler.app1 ' -o '];
compiler.app1   = [compiler.app1 files.app1.out];



%%%%
%%
%% Build steps.
%%
%%%%

% Begin build instruction.
disp ([banner 'Begin build instruction.']);



% Call Fortran compiler.
disp ([banner 'Compile test suites ...']);

disp (compiler.app1);
system (compiler.app1);

disp ([banner 'Done.']);



% Run tests.
disp ([banner 'Run tests ...']);

failures += system (files.app1.out);

if ~ failures;
    disp ([banner 'No failures found.']);
else;
    disp ([banner 'Done.']);
end;



% Remove test applications.
fprintf ([banner 'Remove test suites ... ']);

if length (glob (files.app1.out));
    delete (files.app1.out);
end;

disp ('Done.');



% End build instruction.
disp ([banner 'End build instruction.']);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
