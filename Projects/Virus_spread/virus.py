import os


def infect_apple(apple, n):
    # coordinates of 'V' in the 2D array
    v_positions = []
    row_v = 0
    col_v = 0
    for i in range(n):
        for row in apple:
            if "V" in row:
                for col in row:
                    if col == "V":
                        if [row_v, col_v] in v_positions:
                            break
                        else:
                            v_positions.append([row_v, col_v])
                    col_v = col_v + 1
            row_v = row_v + 1
            col_v = 0
        row_v = 0

        # generate koordinates of spreadings
        for j in range(len(v_positions)):
            x = v_positions[j][0]
            y = v_positions[j][1]
            if x > 0 and x <= (len(apple[0])):
                x1 = x - 1
                v_positions.append([x1, y])
                x1 = x
            if x < (len(apple) - 1):
                x1 = x + 1
                v_positions.append([x1, y])
                x1 = x
            if y > 0 and y <= len(apple):
                y1 = y - 1
                v_positions.append([x, y1])
                y1 = y
            if y < (len(apple[0])) - 1:
                y1 = y + 1
                v_positions.append([x, y1])
                y1 = y
        # update 2D array with "V"
        for k1, k2 in v_positions:
            apple[k1][k2] = "V"
            os.system("cls" if os.name == "nt" else "clear")
            for row in apple:
                print(row)


apple = [
    [" ", " ", " ", " ", " "],
    [" ", " ", " ", " ", " "],
    [" ", " ", "V", " ", " "],
    [" ", " ", " ", " ", " "],
    [" ", " ", " ", " ", " "],
    [" ", " ", " ", " ", " "],
]

infect_apple(apple, 3)
