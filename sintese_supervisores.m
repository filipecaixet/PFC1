%sups_reduzidos

%SMALL_FACTORY_FRANK_2

% small factory. Franklin Meer

% Clear and close everything
clear all; close all; fclose all;

% Run setup.m
setup;


% Set working folder
init('sintese_supervisores');

% Supervisor design procedure
% Step 1


%***********************************************************************
% Creat plant (components)
%***********************************************************************

%---------------------- G1 ----------------------
Q = 2; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0 11 1;  % 11 È a1          % transition triples (exit state, event, enter state)
         1 12 0   % 12 È b1
         ];
create('G1', Q, delta, Qm); % create automaton

%---------------------- G2 ----------------------
Q = 3; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0 21 1;  % 21 È a2          transition triples (exit state, event, enter state)
         1 22 0;  % 22 È b2
         0 23 2;  % 23 È a3
         2 24 0   % 24 È b3
         ];
create('G2', Q, delta, Qm); % create automaton

%---------------------- G3 ----------------------
Q = 4; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0,31,1;  % 31 È a4       transition triples (exit state, event, enter state)
         1,32,0;  % 32 È b4
         0,33,2;  % 33 È a5
         2,34,0   % 34 È b5
         0,41,3
         3,42,0
         ];
create('G3', Q, delta, Qm); % create automaton


%---------------------- G5----------------------
Q = 1; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0,52,0;  % 52 È bv'
         0,54,0   % 54 È ba'          % transition triples (exit state, event, enter state)
         ];
create('G5', Q, delta, Qm); % create automaton

%---------------------- G6 ----------------------
Q = 1; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0,62,0;   % 62 È bp'
         0,64,0    % 64 È bg'           % transition triples (exit state, event, enter state)
         ];
create('G6', Q, delta, Qm); % create automaton

%***********************************************************************
% Creat especification (components)
%***********************************************************************

%---------------------- E1----------------------

Q = 2; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0 12 1;   % b1     transition triples (exit state, event, enter state)
         1 21 0;   % a2
         1 23 0    % a3
         ];
create('E1', Q, delta, Qm); % create automaton

figure(101)
displaydes('E1') % display automaton


%---------------------- E2----------------------

Q = 2; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0,22,1; % b2         transition triples (exit state, event, enter state)
         1,31,0  % a4
         1,33,0  % a5
         1,41,0
         ];
create('E2', Q, delta, Qm); % create automaton

figure(102)
displaydes('E2') % display automaton
%---------------------- E3 ----------------------
Q = 4; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0,52,1;  % bv'         % transition triples (exit state, event, enter state)
         0,62,0;
         0,64,0;
         1,52,1;
         2,64,2;
         2,62,2;
         3,62,3;
         3,64,3;
         3,52,3;
         1,64,2;  % bg'
         2,22,3;  % b2'
         3,41,0;  % a6
         1,62,0;  % bp'
         0,22,0;
         1,22,1;
         3,22,3
         2,52,2
         ];
create('E3', Q, delta, Qm); % create automaton

figure(103)
displaydes('E3') % display automaton

%---------------------- E4----------------------
Q = 4; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0,52,1;   % bv'             % transition triples (exit state, event, enter state)
         1,62,2    % bp'
         2,22,3    % b2'
         1,64,0    % bg'
         3,31,0    % a4
         0,62,0;   % bp'
         0,64,0;   % bg'
         0,22,0;   % b2'
         1,52,1
         1,22,1
         2,52,2
         2,62,2
         2,64,2
         3,22,3
         3,52,3
         3,62,3
         3,64,3
     ];
create('E4', Q, delta, Qm); % create automaton

figure(104)
displaydes('E4') % display automaton
%---------------------- E5----------------------

Q = 3; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0,64,0;  % bg'           % transition triples (exit state, event, enter state)
         0,54,1   % ba'
         1,54,1   % ba'
         1,64,2   % bg'
         1,62,0
         0,62,0
         2,62,2
         2,64,2   % bg'
         2,54,2   % ba'
         2,23,0   % a3
         ];
create('E5', Q, delta, Qm); % create automaton

figure(105)
displaydes('E5') % display automaton
%---------------------- E6----------------------

Q = 4; % number of states
       % the initial state q0 is always labeled "0"
Qm = [0]; % marker state set
delta = [0,54,1;   % ba'                  % transition triples (exit state, event, enter state)
         1,62,2    % bp'
         2,22,3    % b2'
         3,33,0    % a5
         1,64,0    % bg'         
         0,62,0    % bp'
         0,22,0
         0,64,0
         1,22,1
         1,54,1         
         2,54,2
         2,62,2
         2,64,2         
         3,22,3
         3,54,3
         3,62,3
         3,64,3
         ];
create('E6', Q, delta, Qm); % create automaton

figure(106)
displaydes('E6') % display automaton

%***********************************************************************
%                       OPERACOES (components)
%***********************************************************************

%---------------------- COMPOSICAO PARALELA PLANT_1----------------------
% composi√ß√£o paralela plantas
%sync('PLANT','M1','M2','M3');
sync('PLANT_1','G2','G3','G5', 'G6');
allevents('ALL', 'PLANT_1');

% ESPECIFICACAO DA PLANTA
sync('SPEC_4', 'E4','ALL');


%---------------------- SUPERVISOR S1----------------------
%lenguaguem S
supcon('SUP_1', 'PLANT_1', 'SPEC_4')

%figure(1)
%displaydes('SUP') % display automaton

%condat
condat('SUP_DAT_1', 'PLANT_1', 'SUP_1')

%SUPERVISOR REDUCIDO
supreduce('SUP_RED_1','PLANT_1', 'SUP_1','SUP_DAT_1')
figure(1)
displaydes('SUP_RED_1') % display automaton

%---------------------- COMPOSICAO PARALELA PLANT_2----------------------

sync('PLANT_2','G2','G5','G6');
allevents('ALL', 'PLANT_2');

%ESPECIFICACAO DA PLANTA

sync('SPEC_5', 'E5','ALL');


%---------------------- SUPERVISOR S2----------------------
%lenguaguem S
supcon('SUP_2', 'PLANT_2', 'SPEC_5')
%figure(3)
%displaydes('SUP') % display automaton

%condat
condat('SUP_DAT_2', 'PLANT_2', 'SUP_2')

%SUPERVISOR REDUCIDO
supreduce('SUP_RED_2','PLANT_2', 'SUP_2','SUP_DAT_2')
figure(2)
displaydes('SUP_RED_2') % display automaton

%---------------------- COMPOSICAO PARALELA PLANT_3----------------------

sync('PLANT_3','G2','G3','G5','G6');
allevents('ALL', 'PLANT_3');


%ESPECIFICACAO DA PLANTA

sync('SPEC_3', 'E3','ALL');

%---------------------- SUPERVISOR S3----------------------
%lenguaguem S
supcon('SUP_3', 'PLANT_3', 'SPEC_3')
%figure(3)
%displaydes('SUP') % display automaton

%condat
condat('SUP_DAT_3', 'PLANT_3', 'SUP_3')

%SUPERVISOR REDUCIDO
supreduce('SUP_RED_3','PLANT_3', 'SUP_3','SUP_DAT_3')
figure(3)
displaydes('SUP_RED_3') % display automaton

%---------------------- COMPOSICAO PARALELA PLANT_4----------------------


sync('PLANT_4','G2','G3');
allevents('ALL', 'PLANT_4');

%ESPECIFICACAO DA PLANTA 

sync('SPEC_2', 'E2','ALL');

%---------------------- SUPERVISOR S4----------------------
%lenguaguem S
supcon('SUP_4', 'PLANT_4', 'SPEC_2')
%figure(3)
%displaydes('SUP') % display automaton

%condat
condat('SUP_DAT_4', 'PLANT_4', 'SUP_4')

%SUPERVISOR REDUCIDO
supreduce('SUP_RED_4','PLANT_4', 'SUP_4','SUP_DAT_4')
figure(4)
displaydes('SUP_RED_4') % display automaton

%---------------------- COMPOSICAO PARALELA PLANT_5----------------------

sync('PLANT_5','G2','G3','G5','G6');
allevents('ALL', 'PLANT_5');


%ESPECIFICACAO DA PLANTA 

sync('SPEC_6', 'E6','ALL');

%---------------------- SUPERVISOR S5----------------------
%lenguaguem S
supcon('SUP_5', 'PLANT_5', 'SPEC_6')
%figure(3)
%displaydes('SUP') % display automaton

%condat
condat('SUP_DAT_5', 'PLANT_5', 'SUP_5')

%SUPERVISOR REDUCIDO
supreduce('SUP_RED_5','PLANT_5', 'SUP_5','SUP_DAT_5')
figure(5)
displaydes('SUP_RED_5') % display automaton

%---------------------- COMPOSICAO PARALELA PLANT_6----------------------

sync('PLANT_6','G1','G2');
allevents('ALL', 'PLANT_6');

%ESPECIFICACAO DA PLANTA
sync('SPEC_1', 'E1','ALL');

%---------------------- SUPERVISOR S6----------------------
%lenguaguem S
supcon('SUP_6', 'PLANT_6', 'SPEC_1');
% sync('SUP_6');
% allevents('ALL','SUP_6');

%figure(6);
%displaydes('SUP_6'); % display automaton

%condat
condat('SUP_DAT_6', 'PLANT_6', 'SUP_6');

%SUPERVISOR REDUCIDO
supreduce('SUP_RED_6','PLANT_6', 'SUP_6','SUP_DAT_6');
figure(6)
displaydes('SUP_RED_6') % display automaton




%sync('SPEC_3', 'E3','ALL');
%figure(28)
%displaydes('SPEC_3') % display automaton


%figure(28)
%displaydes('SPEC_3') % display automaton













sync('SR_P','SUP_RED_6','PLANT_6');

figure(11)
displaydes('SR_P') % display automaton



sync('total','SUP_1','SUP_2','SUP_3','SUP_4','SUP_5','SUP_6');

figure(12)
displaydes('total') % display automaton


sync('PLANT_TOTAL','G1','G2','G3','G4','G5','G6');
allevents('ALL', 'PLANT_TOTAL');

%ESPECIFICACAO DA PLANTA
sync('SPEC_TOTAL', 'E1','E2','E3','E4','E5','E6','ALL');
 
supcon('SUP_TOTAL', 'PLANT_TOTAL', 'SPEC_TOTAL')
figure(13)
displaydes('SUP_TOTAL') % display automaton
 
