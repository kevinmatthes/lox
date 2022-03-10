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
%%      compile-library.m
%%
%%  BRIEF
%%      Create the main library of this repository.
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
octave.self = 'octave';



% Directories.
directories.lib = './lib/';



% Files.
files.mklib = 'ar-create.m';
files.mkobj = 'gcc-objects.m';
files.rmlib = 'clean-libraries.m';
files.rmobj = 'clean-objects.m';
files.self  = 'compile-library.m';



% Control flow.
banner  = ['[ ' files.self ' ] '];



%%%%
%%
%% Build steps.
%%
%%%%

% Begin build instruction.
disp ([banner 'Begin build instruction.']);



% Adjust working directory.
fprintf ([banner 'Set working directory to ' directories.lib ' ... ']);
cd (directories.lib);
disp ('Done.');



% Process build instructions.
system ([octave.self ' ' files.rmlib]);
system ([octave.self ' ' files.mkobj]);
system ([octave.self ' ' files.mklib]);
system ([octave.self ' ' files.rmobj]);



% End build instruction.
disp ([banner 'End build instruction.']);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
