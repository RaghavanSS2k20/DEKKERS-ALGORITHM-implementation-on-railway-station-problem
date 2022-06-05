# DEKKERS-ALGORITHM-implementation-on-railway-station-problem
LET US ASSUME THAT THERE ARE TWO TRACKS AND ONE CROSS. IT IS OBIVIOUS THAT ONLY ONE TRAIN MUST PASS THROUGH THE CROSS AT A TIME SINCE THERE ARE TWO TRACKS LET US ASSUME THAT DRIVING A TRAIN FROM TRACK ONE AND TWO ARE THREADS ONE AND TWO RESPECTIVELY...AND HENCE CROSS IS CRITICAL SYSTEM WHICH IMPLIES THIS IS A CRITICAL SECTION PROBLEM


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



so here critical section will be the crossing and bringing train through route1 be process one and the other route be process 2 implementation is self explainotary. Any doubts..please do a mail to 20pw26@psgtech.ac.in


                                                            ///HAPPY CODING///
                                                            
