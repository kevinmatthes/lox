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
%%      clean-documentation.m
%%
%%  BRIEF
%%      Remove the automatically compiled documentation.
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

% Doxygen settings.
doxygen.outdir  = './';

doxygen.html.search = [doxygen.outdir 'html/search/'];
doxygen.html.self   = [doxygen.outdir 'html/'];
doxygen.latex.self  = [doxygen.outdir 'latex/'];



% Files.
files.self  = 'clean-documentation.m';



% Control flow.
banner  = ['[ ' files.self ' ] '];



%%%%
%%
%% Build steps.
%%
%%%%

% Begin build instruction.
disp ([banner 'Begin build instruction.']);



% Remove common Doxygen directories.
fprintf ([banner 'Check for and remove Doxygen directories ... ']);

if length (glob (doxygen.html.search));
    if length (glob ([doxygen.html.search '*']));
        delete ([doxygen.html.search '*']);
    end;

    rmdir (doxygen.html.search);
end;

if length (glob (doxygen.html.self));
    if length (glob ([doxygen.html.self '*']));
        delete ([doxygen.html.self '*']);
    end;

    rmdir (doxygen.html.self);
end;

if length (glob (doxygen.latex.self));
    if length (glob ([doxygen.latex.self '*']));
        delete ([doxygen.latex.self '*']);
    end;

    rmdir (doxygen.latex.self);
end;

disp ('Done.');



% End build instruction.
disp ([banner 'End build instruction.']);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
