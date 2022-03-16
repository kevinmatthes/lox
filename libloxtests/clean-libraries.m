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
%%      clean-libraries.m
%%
%%  BRIEF
%%      Remove compiled libraries.
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

% Files.
files.self  = 'clean-libraries.m';

files.types.a   = '*.a';
files.types.dll = '*.dll';
files.types.lib = '*.lib';
files.types.so  = '*.so';



% Control flow.
banner  = ['[ ' files.self ' ] '];



%%%%
%%
%% Build steps.
%%
%%%%

% Begin build instruction.
disp ([banner 'Begin build instruction.']);



% Check for and remove libraries.
fprintf ([banner 'Check for libraries ... ']);

count.a     = length (glob (files.types.a));
count.dll   = length (glob (files.types.dll));
count.lib   = length (glob (files.types.lib));
count.so    = length (glob (files.types.so));

count.sum   = count.a + count.dll + count.lib + count.so;

if count.sum;
    fprintf ('%d found.\n', count.sum);
    fprintf ([banner 'Remove those ... ']);

    if count.a;     delete (files.types.a);     end;
    if count.dll;   delete (files.types.dll);   end;
    if count.lib;   delete (files.types.lib);   end;
    if count.so;    delete (files.types.so);    end;

    disp ('Done.');
else;
    disp ('There are no libraries.');
end;



% End build instruction.
disp ([banner 'End build instruction.']);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
