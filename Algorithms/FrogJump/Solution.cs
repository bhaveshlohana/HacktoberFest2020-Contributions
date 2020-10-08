using System;

namespace FrogJump
{
    public class Solution
    {
        public int solution(int X, int Y, int D) {
        var distance = Y - X;
        var mod = distance % D;
        var result = distance / D;
        return mod > 0
            ? result + 1
            : result;
    }
    }
}
