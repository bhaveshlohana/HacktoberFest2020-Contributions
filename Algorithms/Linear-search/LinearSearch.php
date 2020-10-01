<?php
function search($arr, $x) {
    for($i = 0; $i < sizeof($arr); $i++) {
        if($arr[$i] == $x) return $i;
    }

    return -1;
}

$arr = array(4, 2, 5, 6, 14, 7, 15, 3);

echo search($arr, 14);

/* If element from the array that is searched exists in array, program will output index of the element. If not then, it returns -1. */
