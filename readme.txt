#############################################################################################################################################
#   IMPLEMENTING DEKKERS ALGORITHM IN A RAILWAY STATION SCENARIO:
# Imagine that there are two railroads say A and B both meets at a cross and joins to a single railroad.Defenitely both trains cannot #
# access cross at same time. Clearly it is an critical section problem. let us solve using dekkers algo the first known algo
# THE ALGORITHM:-
var flag: array [0..1] of boolean;
turn: 0..1;
repeat

        flag[i] := true;
        while flag[j] do
                if turn = j then
                begin
                        flag[i] := false;
                        while turn = j do no-op;
                        flag[i] := true;
                end;

                critical section

        turn := j;
        flag[i] := false;

                remainder section

until false;



so here critical section will be the crossing and bringing train through route1 be process one and the other route be process 2
implementation is self explainotary. Any doubts..please do a mail to 20pw26@psgtech.ac.in


                                                            ///HAPPY CODING///

coming to the failure of dekkers,
dekkers algorithm can be said failed when mutual exclusion is not satisfied so we trigger the drawback of it, the busy waiting and lets see
what happens...!
note :- it is not representation of railway station problem it is just making dekkers algo fail..!
//gcc dekkers_fail.c -o dekkers_fail -lpthread


By the way feel free to copy bcos learning at last moment is bit hectic! :)