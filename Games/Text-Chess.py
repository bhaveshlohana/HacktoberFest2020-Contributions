class Figure(object):

    def __init__(self, name, object_name, color, start_position, possible_moves):
        self.object_name = object_name
        self.name = name
        self.color = color
        self.position = start_position
        self.possible_moves = possible_moves

    def update_position(self, ps, pe, all_positions_enemy, all_positions_own_team, all_possible_moves_enemy, turn):
        self.position = pe  # new position
        self.check_if_move_legit(pe, (), all_positions_enemy, all_positions_own_team, all_possible_moves_enemy, turn)

    def return_position(self, ps, pe, all_positions_enemy, all_positions_own_team, all_possible_moves_enemy, turn):
        self.position = ps  # alternative position
        self.check_if_move_legit(ps, (), all_positions_enemy, all_positions_own_team, all_possible_moves_enemy, turn)

    def update_possible_moves(self, all_positions_enemy, all_positions_own_team, all_possible_moves_enemy, turn):
        self.check_if_move_legit(self.position, (), all_positions_enemy, all_positions_own_team,
                                 all_possible_moves_enemy, turn)

    def check_if_move_legit(self, ps, pe, all_positions_enemy, all_positions_own_team, all_possible_moves_enemy, turn):

        if self.name == 'WB' or self.name == 'BB':
            direction_1 = 1 if self.name == 'BB' else -1
            direction_2 = 2 if self.name == 'BB' else -2
            B_possible_moves = []
            if (self.name == 'BB' and ps in [(1, i) for i in range(8)]) or (
                    self.name == 'WB' and ps in [(6, i) for i in range(8)]):
                if ((ps[0] + direction_1, ps[1]) not in all_positions_enemy) and (
                        (ps[0] + direction_1, ps[1]) not in all_positions_own_team):
                    B_possible_moves.append((ps[0] + direction_1, ps[1]))
                if ((ps[0] + direction_2, ps[1]) not in all_positions_enemy) and (
                        (ps[0] + direction_2, ps[1]) not in all_positions_own_team):
                    B_possible_moves.append((ps[0] + direction_2, ps[1]))
                if (ps[0] + direction_1, ps[1] + 1) in all_positions_enemy:
                    B_possible_moves.append((ps[0] + direction_1, ps[1] + 1))
                if (ps[0] + direction_1, ps[1] - 1) in all_positions_enemy:
                    B_possible_moves.append((ps[0] + direction_1, ps[1] - 1))
                self.possible_moves = B_possible_moves
                if pe in B_possible_moves:
                    return True
                else:
                    return False
            else:
                if ((ps[0] + direction_1, ps[1]) not in all_positions_enemy) and (
                        (ps[0] + direction_1, ps[1]) not in all_positions_own_team):
                    B_possible_moves.append((ps[0] + direction_1, ps[1]))
                if (ps[0] + direction_1, ps[1] + 1) in all_positions_enemy:
                    B_possible_moves.append((ps[0] + direction_1, ps[1] + 1))
                if (ps[0] + direction_1, ps[1] - 1) in all_positions_enemy:
                    B_possible_moves.append((ps[0] + direction_1, ps[1] - 1))
                self.possible_moves = B_possible_moves
                if pe in B_possible_moves:
                    return True
                else:
                    return False

        if self.name == 'WT' or self.name == 'BT' or self.name == 'WD' or self.name == 'WK' or self.name == 'BD' or self.name == 'BK':
            T_possible_moves = []
            i = 1
            if ps[0] + i != 8 and ps[0] + i != 0:
                if (ps[0] + i, ps[1]) not in all_positions_own_team:
                    T_possible_moves.append((ps[0] + i, ps[1]))
                if self.name != 'WK' and self.name != 'BK':
                    while (ps[0] + i, ps[1]) not in all_positions_enemy and (
                    ps[0] + i, ps[1]) not in all_positions_own_team:
                        T_possible_moves.append((ps[0] + i, ps[1]))
                        i += 1
                        if (ps[0] + i, ps[1]) in all_positions_enemy:
                            T_possible_moves.append((ps[0] + i, ps[1]))
                            break
                        if ps[0] + i == 8:
                            break
            i = 1
            if ps[0] - i != -1 and ps[0] - i != -2:
                if (ps[0] - i, ps[1]) not in all_positions_own_team:
                    T_possible_moves.append((ps[0] - i, ps[1]))
                if self.name != 'WK' and self.name != 'BK':
                    while (ps[0] - i, ps[1]) not in all_positions_enemy and (
                    ps[0] - i, ps[1]) not in all_positions_own_team:
                        T_possible_moves.append((ps[0] - i, ps[1]))
                        i += 1
                        if (ps[0] - i, ps[1]) in all_positions_enemy:
                            T_possible_moves.append((ps[0] - i, ps[1]))
                            break
                        if ps[0] - i == -1:
                            break
            i = 1
            if ps[1] + i != 8 and ps[1] + 1 != 0:
                if (ps[0], ps[1] + i) not in all_positions_own_team:
                    T_possible_moves.append((ps[0], ps[1] + i))
                if self.name != 'WK' and self.name != 'BK':
                    while (ps[0], ps[1] + i) not in all_positions_enemy and (
                    ps[0], ps[1] + i) not in all_positions_own_team:
                        T_possible_moves.append((ps[0], ps[1] + i))
                        i += 1
                        if (ps[0], ps[1] + i) in all_positions_enemy:
                            T_possible_moves.append((ps[0], ps[1] + i))
                            break
                        if ps[1] + i == 8:
                            break
            i = 1
            if ps[1] - i != -1 and ps[1] - i != -2:
                if (ps[0], ps[1] - i) not in all_positions_own_team:
                    T_possible_moves.append((ps[0], ps[1] - i))
                if self.name != 'WK' and self.name != 'BK':
                    while (ps[0], ps[1] - i) not in all_positions_enemy and (
                    ps[0], ps[1] - i) not in all_positions_own_team:  # left
                        T_possible_moves.append((ps[0], ps[1] - i))
                        i += 1
                        if (ps[0], ps[1] - i) in all_positions_enemy:
                            T_possible_moves.append((ps[0], ps[1] - i))
                            break
                        if ps[1] - i == -1:
                            break
            self.possible_moves = []
            for i in T_possible_moves:
                self.possible_moves.append(i)
            if self.name == 'WK' or self.name == 'BK' or self.name == 'WD' or self.name == 'BD':
                pass
            elif pe in T_possible_moves:
                return True
            else:
                return False

        if self.name == 'WS' or self.name == 'BS':  # knight
            S_possible_moves = []
            if (ps[0] + 2, ps[1] + 1) not in all_positions_own_team and ps[0] + 2 in range(0, 8) and ps[1] + 1 in range(
                    0, 8):
                S_possible_moves.append((ps[0] + 2, ps[1] + 1))
            if (ps[0] + 2, ps[1] - 1) not in all_positions_own_team and ps[0] + 2 in range(0, 8) and ps[1] - 1 in range(
                    0, 8):
                S_possible_moves.append((ps[0] + 2, ps[1] - 1))
            if (ps[0] - 2, ps[1] + 1) not in all_positions_own_team and ps[0] - 2 in range(0, 8) and ps[1] + 1 in range(
                    0, 8):
                S_possible_moves.append((ps[0] - 2, ps[1] + 1))
            if (ps[0] - 2, ps[1] - 1) not in all_positions_own_team and ps[0] - 2 in range(0, 8) and ps[1] - 1 in range(
                    0, 8):
                S_possible_moves.append((ps[0] - 2, ps[1] - 1))
            if (ps[0] + 1, ps[1] + 2) not in all_positions_own_team and ps[0] + 1 in range(0, 8) and ps[1] + 2 in range(
                    0, 8):
                S_possible_moves.append((ps[0] + 1, ps[1] + 2))
            if (ps[0] + 1, ps[1] - 2) not in all_positions_own_team and ps[0] + 1 in range(0, 8) and ps[1] - 2 in range(
                    0, 8):
                S_possible_moves.append((ps[0] + 1, ps[1] - 2))
            if (ps[0] - 1, ps[1] + 2) not in all_positions_own_team and ps[0] - 1 in range(0, 8) and ps[1] + 2 in range(
                    0, 8):
                S_possible_moves.append((ps[0] - 1, ps[1] + 2))
            if (ps[0] - 1, ps[1] - 2) not in all_positions_own_team and ps[0] - 1 in range(0, 8) and ps[1] - 2 in range(
                    0, 8):
                S_possible_moves.append((ps[0] - 1, ps[1] - 2))

            self.possible_moves = S_possible_moves
            if pe in S_possible_moves:
                return True
            else:
                return False

        if self.name == 'WL' or self.name == 'BL' or self.name == 'WD' or self.name == 'WK' or self.name == 'BD' or self.name == 'BK':
            L_possible_moves = []
            i = 1
            j = 1
            if (ps[0] + i, ps[1] + j) not in all_positions_own_team and ps[0] + i in range(0, 8) and ps[1] + j in range(
                    0, 8):
                L_possible_moves.append((ps[0] + i, ps[1] + j))
            if self.name != 'BK' and self.name != 'WK':
                while (ps[0] + i, ps[1] + j) not in all_positions_own_team and (
                ps[0] + i, ps[1] + j) not in all_positions_enemy and ps[0] + i in range(0, 8) and ps[1] + j in range(0,
                                                                                                                     8):
                    L_possible_moves.append((ps[0] + i, ps[1] + j))
                    i += 1
                    j += 1
                    if (ps[0] + i, ps[1] + j) in all_positions_enemy:
                        L_possible_moves.append((ps[0] + i, ps[1] + j))
                        break
            i = 1
            j = 1
            if (ps[0] - i, ps[1] + j) not in all_positions_own_team and ps[0] - i in range(0, 8) and ps[1] + j in range(
                    0, 8):
                L_possible_moves.append((ps[0] - i, ps[1] + j))
            if self.name != 'BK' and self.name != 'WK':
                while (ps[0] - i, ps[1] + j) not in all_positions_own_team and (
                ps[0] - i, ps[1] + j) not in all_positions_enemy and ps[0] - i in range(0, 8) and ps[1] + j in range(0,
                                                                                                                     8):
                    L_possible_moves.append((ps[0] - i, ps[1] + j))
                    i += 1
                    j += 1
                    if (ps[0] - i, ps[1] + j) in all_positions_enemy:
                        L_possible_moves.append((ps[0] - i, ps[1] + j))
                        break
            i = 1
            j = 1
            if (ps[0] - i, ps[1] - j) not in all_positions_own_team and ps[0] - i in range(0, 8) and ps[1] - j in range(
                    0, 8):
                L_possible_moves.append((ps[0] - i, ps[1] - j))
            if self.name != 'BK' and self.name != 'WK':
                while (ps[0] - i, ps[1] - j) not in all_positions_own_team and (
                ps[0] - i, ps[1] - j) not in all_positions_enemy and ps[0] - i in range(0, 8) and ps[1] - j in range(0,
                                                                                                                     8):
                    L_possible_moves.append((ps[0] - i, ps[1] - j))
                    i += 1
                    j += 1
                    if (ps[0] - i, ps[1] - j) in all_positions_enemy:
                        L_possible_moves.append((ps[0] - i, ps[1] - j))
                        break
            i = 1
            j = 1
            if (ps[0] + i, ps[1] - j) not in all_positions_own_team and ps[0] + i in range(0, 8) and ps[1] - j in range(
                    0, 8):
                L_possible_moves.append((ps[0] + i, ps[1] - j))
            if self.name != 'BK' and self.name != 'WK':
                while (ps[0] + i, ps[1] - j) not in all_positions_own_team and (
                ps[0] + i, ps[1] - j) not in all_positions_enemy and ps[0] + i in range(0, 8) and ps[1] - j in range(0,
                                                                                                                     8):
                    L_possible_moves.append((ps[0] + i, ps[1] - j))
                    i += 1
                    j += 1
                    if (ps[0] + i, ps[1] - j) in all_positions_enemy:
                        L_possible_moves.append((ps[0] + i, ps[1] - j))
                        break
            if self.name != 'WK' and self.name != 'BK' and self.name != 'WD' and self.name != 'BD':
                self.possible_moves = []
            for i in L_possible_moves:
                self.possible_moves.append(i)
            self.possible_moves = list(
                set(self.possible_moves))
            self.possible_moves.sort()

            if self.name == 'WK' or self.name == 'BK':
                for i in all_possible_moves_enemy:
                    self.possible_moves = [j for j in self.possible_moves if j not in i]

            if pe in self.possible_moves:
                return True
            else:
                return False


class Board(object):

    def __init__(self):
        self.B1 = Figure('WB', 'B1', 'WR', (6, 0), [(5, 0), (4, 0)])
        self.B2 = Figure('WB', 'B2', 'WR', (6, 1), [(5, 1), (4, 1)])
        self.B3 = Figure('WB', 'B3', 'WR', (6, 2), [(5, 2), (4, 2)])
        self.B4 = Figure('WB', 'B4', 'WR', (6, 3), [(5, 3), (4, 3)])
        self.B5 = Figure('WB', 'B5', 'WR', (6, 4), [(5, 4), (4, 4)])
        self.B6 = Figure('WB', 'B6', 'WR', (6, 5), [(5, 5), (4, 5)])
        self.B7 = Figure('WB', 'B7', 'WR', (6, 6), [(5, 6), (4, 6)])
        self.B8 = Figure('WB', 'B8', 'WR', (6, 7), [(5, 7), (4, 7)])
        self.T1 = Figure('WT', 'T1', 'WP', (7, 0), [])
        self.T2 = Figure('WT', 'T2', 'WP', (7, 7), [])
        self.S1 = Figure('WS', 'S1', 'WN', (7, 1), [(5, 0), (5, 2)])
        self.S2 = Figure('WS', 'S2', 'WN', (7, 6), [(5, 5), (5, 7)])
        self.L1 = Figure('WL', 'L1', 'WB', (7, 2), [])
        self.L2 = Figure('WL', 'L2', 'WB', (7, 5), [])
        self.D1 = Figure('WD', 'D1', 'WQ', (7, 4), [])
        self.K1 = Figure('WK', 'K1', 'WK', (7, 3), [])

        self.B9 = Figure('BB', 'B9', 'BR', (1, 0), [(2, 0), (3, 0)])
        self.B10 = Figure('BB', 'B10', 'BR', (1, 1), [(2, 1), (3, 1)])
        self.B11 = Figure('BB', 'B11', 'BR', (1, 2), [(2, 2), (3, 2)])
        self.B12 = Figure('BB', 'B12', 'BR', (1, 3), [(2, 3), (3, 3)])
        self.B13 = Figure('BB', 'B13', 'BR', (1, 4), [(2, 4), (3, 4)])
        self.B14 = Figure('BB', 'B14', 'BR', (1, 5), [(2, 5), (3, 5)])
        self.B15 = Figure('BB', 'B15', 'BR', (1, 6), [(2, 6), (3, 6)])
        self.B16 = Figure('BB', 'B16', 'BR', (1, 7), [(2, 7), (3, 7)])
        self.T3 = Figure('BT', 'T3', 'BP', (0, 0), [])
        self.T4 = Figure('BT', 'T4', 'BP', (0, 7), [])
        self.S3 = Figure('BS', 'S3', 'BN', (0, 1), [(2, 0), (2, 2)])
        self.S4 = Figure('BS', 'S4', 'BN', (0, 6), [(2, 5), (2, 7)])
        self.L3 = Figure('BL', 'L3', 'BB', (0, 2), [])
        self.L4 = Figure('BL', 'L4', 'BB', (0, 5), [])
        self.D2 = Figure('BD', 'D2', 'BQ', (0, 4), [])
        self.K2 = Figure('BK', 'K2', 'BK', (0, 3), [])

        self.run = True
        self.turn = 'W'
        self.destroyed_unit = ''
        self.main()

    def main(self):
        print('You can move by typing something like "b2 b4"')
        while self.run == True:
            self.get_positions()
            self.print_board()
            self.destroyed_unit = ''
            start, end = self.checkinput()
            if (start, end) == (-1, -1):
                print('[0] invalid input')
                continue
            if (start, end) == (-2, -2):
                print('Game over.')
                break

    def checkinput(self):
        colors_turn = 'white' if self.turn == 'W' else 'black'
        print(f'\nIts {colors_turn} turn. Your move:')
        try:
            a, b, c, d, e = input()
            if a + b + c + d + e == 'exit!':
                self.run = False
                return (-2, -2)
            alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
            numbers = [1, 2, 3, 4, 5, 6, 7, 8]
            if str(a) in alphabet and int(b) in numbers and c == ' ' and str(d) in alphabet and int(e) in numbers:
                translate_a = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7}
                translate_b = {'8': 0, '7': 1, '6': 2, '5': 3, '4': 4, '3': 5, '2': 6, '1': 7}
                start_position = (translate_b[b], translate_a[a])
                end_position = (translate_b[e], translate_a[d])
                if self.check_chosen_move(start_position, end_position):
                    if self.turn == 'W':  # whites turn
                        # print('All possible Moves of White before: ' + str(self.possible_moves_white))
                        # print('All possible Moves of Black before: ' + str(self.possible_moves_black))
                        for i in self.white_players:
                            if i.position == start_position:
                                i.update_position(start_position, end_position, self.position_black_players,
                                                  self.position_white_players, self.possible_moves_black, self.turn)
                                for i in self.black_players:
                                    if i.position == end_position:
                                        self.destroyed_unit = i.object_name
                                        i.position = (-1, -1)
                        self.get_positions()
                        for i in self.black_players:  # Update all possible moves of the enemy team
                            i.update_possible_moves(self.position_white_players, self.position_black_players,
                                                    self.possible_moves_white, self.turn)
                        for i in self.white_players:  # Update all possible moves of the own team
                            i.update_possible_moves(self.position_black_players, self.position_white_players,
                                                    self.possible_moves_black, self.turn)
                        self.get_positions()
                        for i in self.possible_moves_black:
                            if self.position_king_white in i:  # If your King is checked
                                for i in self.white_players:
                                    if i.position == end_position:
                                        i.return_position(start_position, end_position, self.position_black_players,
                                                          self.position_white_players, self.possible_moves_black,
                                                          self.turn)
                                        for i in self.black_players:
                                            try:
                                                if i.object_name == self.destroyed_unit:
                                                    i.position = end_position
                                                    self.destroyed_unit = ''
                                            except:
                                                pass
                                print('Not allowed to move your King into check position')
                                return (0, 0)
                        # print('All possible Moves of White after: ' + str(self.possible_moves_white))
                        # print('All possible Moves of Black after: ' + str(self.possible_moves_black))
                        for i in self.possible_moves_white:
                            if self.position_king_black in i:
                                if self.K2.possible_moves != []:
                                    print('check!')
                                else:
                                    can_reach_king = []
                                    can_reach_king_position = []
                                    helpfull_positions = []
                                    who_can_help = {}
                                    for i in self.white_players:
                                        if self.position_king_black in i.possible_moves or self.possible_moves_black in i.possible_moves or self.possible_moves_black in i.position:  # Can the enemy jump in between?
                                            possible_positions_to_cover = []
                                            for m in self.possible_moves_black:
                                                for u in m:
                                                    if u in i.possible_moves or u in i.position:
                                                        possible_positions_to_cover.append(u)
                                            for k in possible_positions_to_cover:
                                                for n in self.black_players:
                                                    if k in n.possible_moves:
                                                        who_can_help[(n.object_name, k)] = 0
                                                        current_object = n.object_name
                                                        current_position = n.position
                                                        n.update_position(n.position, k, self.position_black_players,
                                                                          self.position_white_players,
                                                                          self.possible_moves_black, self.turn)
                                                        for q in self.white_players:
                                                            if q.position == k:
                                                                self.destroyed_unit = q.object_name
                                                                q.position = (-1, -1)
                                                        self.get_positions()
                                                        for x in self.white_players:
                                                            x.update_possible_moves(self.position_black_players,
                                                                                    self.position_white_players,
                                                                                    self.possible_moves_black,
                                                                                    self.turn)
                                                        for y in self.black_players:
                                                            y.update_possible_moves(self.position_white_players,
                                                                                    self.position_black_players,
                                                                                    self.possible_moves_white,
                                                                                    self.turn)
                                                        self.get_positions()
                                                        for p in self.possible_moves_white:
                                                            if self.position_king_black in p:
                                                                who_can_help[(n.object_name, k)] = 1
                                                        n.return_position(current_position, k,
                                                                          self.position_black_players,
                                                                          self.position_white_players,
                                                                          self.possible_moves_black, self.turn)
                                                        for h in self.white_players:
                                                            try:
                                                                if h.object_name == self.destroyed_unit:
                                                                    h.position = k
                                                                    self.destroyed_unit = ''
                                                            except:
                                                                pass
                                                        self.get_positions()
                                                        for z in self.white_players:
                                                            z.update_possible_moves(self.position_black_players,
                                                                                    self.position_white_players,
                                                                                    self.possible_moves_black,
                                                                                    self.turn)
                                                        for w in self.black_players:
                                                            w.update_possible_moves(self.position_white_players,
                                                                                    self.position_black_players,
                                                                                    self.possible_moves_white,
                                                                                    self.turn)
                                                        self.get_positions()
                                    for key, item in who_can_help.items():
                                        if item == 0:
                                            helpfull_positions.append(key[1])
                                    if helpfull_positions != []:
                                        print('check!')
                                        pass
                                    else:
                                        for i in self.white_players:
                                            if i.position == start_position:
                                                i.update_position(start_position, end_position,
                                                                  self.position_black_players,
                                                                  self.position_white_players,
                                                                  self.possible_moves_black, self.turn)
                                                for i in self.black_players:
                                                    if i.position == end_position:
                                                        self.destroyed_unit = i.object_name
                                                        i.position = (-1, -1)
                                        self.get_positions()
                                        self.print_board()
                                        print('checkmate!')
                                        return (-2, -2)
                        self.turn = 'B'
                    else:  # blacks turn
                        # print('All possible Moves of White before: ' + str(self.possible_moves_white))
                        # print('All possible Moves of Black before: ' + str(self.possible_moves_black))
                        for i in self.black_players:
                            if i.position == start_position:
                                i.update_position(start_position, end_position, self.position_white_players,
                                                  self.position_black_players, self.possible_moves_white, self.turn)
                                for i in self.white_players:
                                    if i.position == end_position:
                                        self.destroyed_unit = i.object_name
                                        i.position = (-1, -1)
                        self.get_positions()
                        for i in self.black_players:
                            i.update_possible_moves(self.position_white_players, self.position_black_players,
                                                    self.possible_moves_white, self.turn)
                        for i in self.white_players:
                            i.update_possible_moves(self.position_black_players, self.position_white_players,
                                                    self.possible_moves_black, self.turn)
                        self.get_positions()
                        for i in self.possible_moves_white:
                            if self.position_king_black in i:
                                for i in self.black_players:
                                    if i.position == end_position:
                                        i.return_position(start_position, end_position, self.position_white_players,
                                                          self.position_black_players, self.possible_moves_white,
                                                          self.turn)
                                        for i in self.white_players:
                                            try:
                                                if i.object_name == self.destroyed_unit:
                                                    i.position = end_position
                                                    self.destroyed_unit = ''
                                            except:
                                                pass
                                print('Not allowed to move your King into check position')
                                return (0, 0)
                        # print('All possible Moves of White after: ' + str(self.possible_moves_white))
                        # print('All possible Moves of Black after: ' + str(self.possible_moves_black))
                        for i in self.possible_moves_black:
                            if self.position_king_white in i:
                                if self.K1.possible_moves != []:
                                    print('check!')
                                else:
                                    can_reach_king = []
                                    can_reach_king_position = []
                                    helpfull_positions = []
                                    who_can_help = {}
                                    for i in self.black_players:
                                        if self.position_king_white in i.possible_moves or self.possible_moves_white in i.possible_moves or self.possible_moves_white in i.position:  # Can the enemy jump in between?
                                            possible_positions_to_cover = []
                                            for m in self.possible_moves_white:
                                                for u in m:
                                                    if u in i.possible_moves or u in i.position:
                                                        possible_positions_to_cover.append(u)
                                            for k in possible_positions_to_cover:
                                                for n in self.white_players:
                                                    if k in n.possible_moves:
                                                        who_can_help[(n.object_name, k)] = 0
                                                        current_object = n.object_name
                                                        current_position = n.position
                                                        n.update_position(n.position, k, self.position_white_players,
                                                                          self.position_black_players,
                                                                          self.possible_moves_white, self.turn)
                                                        for q in self.black_players:
                                                            if q.position == k:
                                                                self.destroyed_unit = q.object_name
                                                                q.position = (-1, -1)
                                                        self.get_positions()
                                                        for x in self.white_players:
                                                            x.update_possible_moves(self.position_black_players,
                                                                                    self.position_white_players,
                                                                                    self.possible_moves_black,
                                                                                    self.turn)
                                                        for y in self.black_players:
                                                            y.update_possible_moves(self.position_white_players,
                                                                                    self.position_black_players,
                                                                                    self.possible_moves_white,
                                                                                    self.turn)
                                                        self.get_positions()

                                                        for p in self.possible_moves_black:
                                                            if self.position_king_white in p:
                                                                who_can_help[(n.object_name, k)] = 1
                                                        n.return_position(current_position, k,
                                                                          self.position_white_players,
                                                                          self.position_black_players,
                                                                          self.possible_moves_white, self.turn)
                                                        for h in self.black_players:
                                                            try:
                                                                if h.object_name == self.destroyed_unit:
                                                                    h.position = k
                                                                    self.destroyed_unit = ''
                                                            except:
                                                                pass
                                                        self.get_positions()
                                                        for z in self.white_players:
                                                            z.update_possible_moves(self.position_black_players,
                                                                                    self.position_white_players,
                                                                                    self.possible_moves_black,
                                                                                    self.turn)
                                                        for w in self.black_players:
                                                            w.update_possible_moves(self.position_white_players,
                                                                                    self.position_black_players,
                                                                                    self.possible_moves_white,
                                                                                    self.turn)
                                                        self.get_positions()
                                    for key, item in who_can_help.items():
                                        if item == 0:
                                            helpfull_positions.append(key[1])
                                    if helpfull_positions != []:
                                        print('check!')
                                        pass
                                    else:
                                        for i in self.black_players:
                                            if i.position == start_position:
                                                i.update_position(start_position, end_position,
                                                                  self.position_white_players,
                                                                  self.position_black_players,
                                                                  self.possible_moves_white, self.turn)
                                                for i in self.white_players:
                                                    if i.position == end_position:
                                                        self.destroyed_unit = i.object_name
                                                        i.position = (-1, -1)
                                        self.get_positions()
                                        self.print_board()
                                        print('check mate!')
                                        return (-2, -2)
                        self.turn = 'W'
                    return (0, 0)
                else:
                    return (0, 0)
            else:
                return (-1, -1)
        except:
            return (-1, -1)

    def check_chosen_move(self, ps, pe):
        if self.turn == 'W' and ps in self.position_white_players:
            try:
                for i in self.white_players:
                    if i.position == ps:
                        if i.check_if_move_legit(ps, pe, self.position_black_players, self.position_white_players,
                                                 self.possible_moves_black, self.turn):
                            return True
                        else:
                            print('move not legit')
                            return False
            except:
                print('Choose a legit player')
                return False
        elif self.turn == 'B' and ps in self.position_black_players:
            try:
                for i in self.black_players:
                    if i.position == ps:
                        if i.check_if_move_legit(ps, pe, self.position_white_players, self.position_black_players,
                                                 self.possible_moves_white, self.turn):
                            return True
                        else:
                            print('move not legit')
                            return False
            except:
                print('Choose a legit player')
                return False
        else:
            print(f'Its {self.turn} turn, pick a valid figure!')
            return False

    def print_board(self):
        board_side = [' 8 \u2502', ' 7 \u2502', ' 6 \u2502', ' 5 \u2502', ' 4 \u2502', ' 3 \u2502', ' 2 \u2502',
                      ' 1 \u2502']
        print(
            '\n\n        a   b   c   d   e   f   g   h' + '\n    \u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\n   \u2502                                    \u2502')
        k = 8
        for i in range(8):
            print(board_side[i], end='   ')
            for j in range(8):
                if (i, j) in self.position_white_players or (i, j) in self.position_black_players:
                    for x in self.white_players:
                        if x.position == (i, j):
                            print(x.color, end='  ')
                    for x in self.black_players:
                        if x.position == (i, j):
                            print(x.color, end='  ')
                else:
                    print(' \u2022 ', end=' ')
            print(' \u2502 ' + str(k) + '\n   \u2502                                    \u2502')
            k -= 1
        print(
            '    \u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\n        a   b   c   d   e   f   g   h' + '\n')

    def get_positions(self):
        self.white_players = white_players = [self.B1, self.B2, self.B3, self.B4, self.B5, self.B6, self.B7, self.B8,
                                              self.T1, self.T2, self.S1, self.S2, self.L1, self.L2, self.D1, self.K1]
        self.position_white_players = [i.position for i in white_players]
        self.possible_moves_white = [i.possible_moves for i in white_players]
        self.position_king_white = self.K1.position
        self.black_players = black_players = [self.B9, self.B10, self.B11, self.B12, self.B13, self.B14, self.B15,
                                              self.B16, self.T3, self.T4, self.S3, self.S4, self.L3, self.L4, self.D2,
                                              self.K2]
        self.position_black_players = [i.position for i in black_players]
        self.possible_moves_black = [i.possible_moves for i in black_players]
        self.position_king_black = self.K2.position
        return True


Board()