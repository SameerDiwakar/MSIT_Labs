state(A, B)
% Fill Jug A (4L)
move(state(_, B), state(4, B)).

% Fill Jug B (3L)
move(state(A, _), state(A, 3)).

% Empty Jug A
move(state(_, B), state(0, B)).

% Empty Jug B
move(state(A, _), state(A, 0)).

% Pour A → B
move(state(A, B), state(A1, B1)) :-
    Transfer is min(A, 3 - B),
    A1 is A - Transfer,
    B1 is B + Transfer.

% Pour B → A
move(state(A, B), state(A1, B1)) :-
    Transfer is min(B, 4 - A),
    A1 is A + Transfer,
    B1 is B - Transfer.
goal(state(_, 2)).
path(State, State, _).

path(State, Goal, Visited) :-
    move(State, Next),
    \+ member(Next, Visited),
    path(Next, Goal, [Next | Visited]).