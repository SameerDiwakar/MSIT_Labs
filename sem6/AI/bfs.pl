% -------- Graph Definition --------
% Define edges using edge(Start, End).

edge(a, b).
edge(a, c).
edge(b, d).
edge(b, e).
edge(c, f).
edge(e, g).

% -------- BFS Implementation --------

% bfs(Start, Goal, Path).
bfs(Start, Goal, Path) :-
    bfs_queue([[Start]], Goal, RevPath),
    reverse(RevPath, Path).

% If the first path in queue reaches Goal, succeed.
bfs_queue([[Goal|Rest]|_], Goal, [Goal|Rest]).

% Otherwise expand first path and continue.
bfs_queue([[Current|RestPath]|OtherPaths], Goal, Path) :-
    findall([Next,Current|RestPath],
            (edge(Current, Next),
             \+ member(Next, [Current|RestPath])),
            NewPaths),
    append(OtherPaths, NewPaths, UpdatedQueue),
    bfs_queue(UpdatedQueue, Goal, Path).
















