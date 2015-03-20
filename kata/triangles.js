/*
In this kata, you should calculate type of triangle with three given sides a, b and c.

If all angles are less than 90°, this triangle is acute and function should return 1.

If one angle is strictly 90°, this triangle is right and function should return 2.

If one angle more than 90°, this triangle is obtuse and function should return 3.

If three sides cannot form triangle, or one angle is 180° (which turns triangle into segment) - function should return 0.

Input parameters are sides of given triangle. All input values are non-negative floating point or integer numbers (or both).
*/

function toRadians (angle) {
  return angle * (Math.PI / 180);
}

function toDegrees (angle) {
  return angle * (180 / Math.PI);
}

function isAcute(element, index, array) {
    return element < 90;
}

function isObtuse(element, index, array) {
    return element > 90;
}

function triangleType(a, b, c){
    //Triangle inequality theorem
    if(a + b > c && a + c > b && b + c > a) {
        //Use law of cosines    cos A = ( b2 + c2 - a2 ) / 2bc
        var A = Math.round(toDegrees(Math.acos((b*b + c*c - a*a) / (2*b*c))));
        var B = Math.round(toDegrees(Math.acos((c*c + a*a - b*b) / (2*c*a))));
        var C = 180 - A - B;
        var angles = new Array(A,B,C);

        if(angles.some(isObtuse)) {
            return 3;
        }
        if(angles.indexOf(90) > -1) {
            return 2;
        }
        if(angles.every(isAcute)) {
            return 1;
        }
    }

    return 0;
}

debug(triangleType(2, 4, 6)); // return 0 (Not triangle)
debug(triangleType(8, 5, 7)); // return 1 (Acute, angles are approx. 82°, 38° and 60°)    1.43116999,  0.663225116,  1.04719755
debug(triangleType(3, 4, 5)); // return 2 (Right, angles are approx. 37°, 53° and exactly 90°)
debug(triangleType(7, 12, 8)); // return 3 (Obtuse, angles are approx. 34°, 106° and 40°)
