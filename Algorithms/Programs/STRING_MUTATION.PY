t = int(input())
for x in range(1, t + 1):
    p = input()
    y = "".join({"S": "E", "E": "S"}[c] for c in p)
    print("Case #{}: {}".format(x, y))
