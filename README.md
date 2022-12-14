# DEKKERS-ALGORITHM-implementation-on-railway-station-problem
let us assume that there are two tracks and one cross. it is obvious that only one train must pass through the cross at a time since there are two tracks let us assume that driving a train from track one and two are threads one and two respectively...and hence cross is critical system which implies this is a critical section problem


#############################################################################################################################################
#   IMPLEMENTING DEKKERS ALGORITHM IN A RAILWAY STATION SCENARIO:
# Imagine that there are two railroads say A and B both meets at a cross and joins to a single railroad.Defenitely both trains cannot #
# access cross at same time. Clearly it is an critical section problem. let us solve using dekkers algo the first known algo for cs problem
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



so here critical section will be the crossing and bringing train through route1 be process one and the other route be process 2 implementation is self explainotary. Any doubts..please do a mail to 20pw26@psgtech.ac.in


                                                            ///HAPPY CODING///
                                                            #to run any file:-
                                                            //gcc <filename.c> -o <filename> -lpthread
                                                            
