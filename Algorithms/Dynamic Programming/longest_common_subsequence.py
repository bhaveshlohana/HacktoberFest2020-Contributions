def longest_common_subsequence(strOne, strTwo):
    strOne = "0" + strOne
    strTwo = "0" + strTwo
    subsequence = [[0 for _ in range(len(strOne))] for _ in range(len(strTwo))]
    direction = [["END" for _ in range(len(strOne))] for _ in range(len(strTwo))]

    # nested for loops takes O(nm)
    for i in range(1, len(strTwo)):
        for j in range(1, len(strOne)):
            if strTwo[i] == strOne[j]:
                subsequence[i][j] = subsequence[i - 1][j - 1] + 1
                direction[i][j] = "\\"
            elif subsequence[i][j - 1] > subsequence[i - 1][j]:
                subsequence[i][j] = subsequence[i][j - 1]
                direction[i][j] = "-"
            else:
                subsequence[i][j] = subsequence[i - 1][j]
                direction[i][j] = "|"

    # constructing subsequence takes O(n + m)
    i = len(strTwo) - 1
    j = len(strOne) - 1
    string = ""
    while (direction[i][j] != "END"):
        if direction[i][j] == "|":
            i -= 1
        elif direction[i][j] == "-":
            j -= 1
        else:
            string = strOne[j] + string
            i -= 1
            j -= 1

    print(string)

if __name__ == "__main__":
    longest_common_subsequence("AGACTGTC", "TAGTCACG")
    longest_common_subsequence("AGGTAB", "GXTXAYB")
