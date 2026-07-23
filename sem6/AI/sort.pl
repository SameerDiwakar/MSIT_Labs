% Entry point: sort a sentence
sort_sentence(Sentence, SortedWords) :-
    split_string(Sentence, " ", "", WordList),  % Step 1: split sentence into words
    sort(WordList, SortedWords).               % Step 2: sort alphabetically
