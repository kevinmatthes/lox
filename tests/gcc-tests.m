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
compiler.flags  = [compiler.flags ' -std=c99 '];
compiler.link   = ' -lcheck -lm -lpthread -lrt -lsubunit ';
compiler.link   = [compiler.link ' -L. -llox-tests '];
compiler.link   = [compiler.link ' -L../lib/ -llox '];
compiler.call   = [compiler.self compiler.flags];

octave.self = ' octave ';



% Files.
files.main  = 'main.o';
files.mklib = 'ar-create.m';
files.mkobj = 'gcc-objects.m';
files.out   = './lox-tests';
files.rmlib = 'clean-libraries.m';
files.rmobj = 'clean-objects.m';
files.self  = 'gcc-tests.m';



% Control flow.
banner      = ['[ ' files.self ' ] '];
failures    = 0;



% Call adjustment.
compiler.out   = [compiler.call files.main];
compiler.out   = [compiler.out compiler.link];
compiler.out   = [compiler.out ' -o '];
compiler.out   = [compiler.out files.out];



%%%%
%%
%% Build steps.
%%
%%%%

% Begin build instruction.
disp ([banner 'Begin build instruction.']);



% Preparations.
system ([octave.self files.rmlib]);
system ([octave.self files.mkobj]);
system ([octave.self files.mklib]);



% Call C compiler.
disp ([banner 'Compile test suites ...']);

disp (compiler.out);
system (compiler.out);

disp ([banner 'Done.']);



% Run tests.
disp ([banner 'Run tests ...']);

failures += system (files.out);

if ~ failures;
    disp ([banner 'No failures found.']);
else;
    disp ([banner 'Done.']);
end;



% Remove test applications.
system ([octave.self files.rmobj]);

fprintf ([banner 'Remove test suites ... ']);

if length (glob (files.out));
    delete (files.out);
end;

disp ('Done.');



% End build instruction.
disp ([banner 'End build instruction.']);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
