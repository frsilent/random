/*
Greed is a dice game played with five six-sided dice. Your mission, should you choose to accept it,
is to score a throw according to these rules. You will always be given an array with five six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point
A single die can only be counted once in each roll. For example, a "5" can only count as part of a triplet
(contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   50 + 2 * 100 = 250
 1 1 1 3 1   1000 + 100 = 1100
 2 4 4 5 4   400 + 50 = 450
 */

function score( dice ) {
    var score = 0,
    counter = {
        1:0, 2:0, 3:0, 4:0, 5:0, 6:0
    };

    for(i = 0; i < dice.length; i++) {
        counter[dice[i]] = counter[dice[i]] + 1;
    }
    if(counter['1'] >= 3) {
        score += 1000;
        counter['1'] -= 3;
    }
    for(i = 2; i <= 6; i++) {
        if(counter[i] >= 3) {
            score += i * 100;
            counter[i] -= 3;
        }
    }
    score += counter[1] * 100;
    score += counter[5] * 50;

    return score;
}

score([1,1,1,1,1]); // 1200
score([2, 3, 4, 6, 2]); // 0
score([4, 4, 4, 3, 3]); // 400
score([2, 4, 4, 5, 4]); // 450
