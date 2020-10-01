"""Code by Lucas Trogo in contribution to HacktoberFest 2020
   Pylint Rate: 9.55/10"""


import pytest


def palind(list_palind):
    """Function to se if the word or sequence of numbers is a palindrome or not"""
    pos = 0
    vet = 0
    size_palind = len(list_palind) - 1
    while pos <= size_palind:
        for _ in range(size_palind):
            if list_palind[vet] == list_palind[size_palind]:
                vet += 1
                size_palind -= 1
                return "Is an palindrome"
            else:
                return "Isn´t an palindrome"
        pos += 1
    return list_palind


LIST_PALIND = ["a", "n", "a"]


def main():
    """Main function"""
    palind(LIST_PALIND)

PALIND_PARAMS = [[["a", "n", "a"],"Is an palindrome"], [["o", "s", "s", "o"],"Is an palindrome"] ,
                [[1, 2, 3, 2, 1], "Is an palindrome"], [["c", "a", "r"], "Isn´t an palindrome"]]


@pytest.mark.parametrize("list_palind, ans", PALIND_PARAMS)
def test_palind(list_palind, ans):
    """Function to test if the main funcion works correctly"""
    assert palind(list_palind) == ans


if __name__ == "__main__":
    main()
