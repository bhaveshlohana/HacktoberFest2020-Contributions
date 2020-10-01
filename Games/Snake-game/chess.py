from tkinter import *
import tkinter.messagebox

tk = Tk()
tk.title('Chess')
tkstart = ''
tkend = ''
startbutton = ''
endbutton = ''
endbutton_color = ''
startbutton_color = ''
error = ''


def btnClick(buttons):
    global startbutton, endbutton, endbutton_color, startbutton_color, startbutton_text, endbutton_text
    if tkstart != '':
        endbutton = buttons
        endbutton_color = buttons['bg']
        endbutton_text = buttons['text']
    if tkend == '' and tkstart == '':
        startbutton = buttons
        startbutton_color = buttons['bg']
        startbutton_text = buttons['text']


def undo_coloring():
    for i in fields_dic:
        if fields_dic[i]['fg'] == 'lightgreen':
            fields_dic[i]['fg'] = 'black'
        if fields_dic[i]['text'] == '\u0E4F':
            fields_dic[i]['text'] = ''


def btnID(id):
    global tkstart, tkend, startbutton, endbutton, error, white_players, black_players, fields_dic, turn, error
    colored_fields = []
    fields_dic = {'a1': a1, 'a2': a2, 'a3': a3, 'a4': a4, 'a5': a5, 'a6': a6, 'a7': a7, 'a8': a8, 'b1': b1, 'b2': b2,
                  'b3': b3, 'b4': b4, 'b5': b5, 'b6': b6, 'b7': b7, 'b8': b8, 'c2': c1, 'c2': c2, 'c3': c3, 'c4': c4,
                  'c5': c5, 'c6': c6, 'c7': c7, 'c8': c8, 'd1': d1, 'd2': d2, 'd3': d3, 'd4': d4, 'd5': d5, 'd6': d6,
                  'd7': d7, 'd8': d8, 'e1': e1, 'e2': e2, 'e3': e3, 'e4': e4, 'e5': e5, 'e6': e6, 'e7': e7, 'e8': e8,
                  'f1': f1, 'f2': f2, 'f3': f3, 'f4': f4, 'f5': f5, 'f6': f6, 'f7': f7, 'f8': f8, 'g1': g1, 'g2': g2,
                  'g3': g3, 'g4': g4, 'g5': g5, 'g6': g6, 'g7': g7, 'g8': g8, 'h1': h1, 'h2': h2, 'h3': h3, 'h4': h4,
                  'h5': h5, 'h6': h6, 'h7': h7, 'h8': h8}
    if error != 4:
        if tkstart != '':
            tkend = id
        if turn == 'W' and (startbutton['text'] in [WR, WN, WP, WQ, WK, WB] or startbutton['text'] == WK + '\ncheck!'):
            if tkend == '' and tkstart == '' and startbutton['text'] != '':
                tkstart = id
                startbutton['bg'] = 'lightgreen'
        elif turn == 'B' and (
                startbutton['text'] in [BR, BN, BP, BQ, BK, BB] or startbutton['text'] == BK + '\ncheck!'):
            if tkend == '' and tkstart == '' and startbutton['text'] != '':
                tkstart = id
                startbutton['bg'] = 'lightgreen'

        if tkstart != '' and tkend == '':
            get_positions()
            translate_a = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7}
            translate_b = {'8': 0, '7': 1, '6': 2, '5': 3, '4': 4, '3': 5, '2': 6, '1': 7}
            start_position = (translate_b[tkstart[1]], translate_a[tkstart[0]])
            translate_a_back = {0: 'a', 1: 'b', 2: 'c', 3: 'd', 4: 'e', 5: 'f', 6: 'g', 7: 'h'}
            translate_b_back = {0: '8', 1: '7', 2: '6', 3: '5', 4: '4', 5: '3', 6: '2', 7: '1'}
            if turn == 'W':
                for i in white_players:
                    if i.position == start_position:
                        for i in i.possible_moves:
                            fn = translate_a_back[i[1]]
                            sn = translate_b_back[i[0]]
                            fld = fn + sn
                            for item in fields_dic:
                                if item == fld:
                                    colored_fields.append(item)
                                    fields_dic[item]['fg'] = 'lightgreen'
                                    if fields_dic[item]['text'] == '':
                                        fields_dic[item]['text'] = '\u0E4F'
            else:
                for i in black_players:
                    if i.position == start_position:
                        for i in i.possible_moves:
                            fn = translate_a_back[i[1]]
                            sn = translate_b_back[i[0]]
                            fld = fn + sn
                            for item in fields_dic:
                                if item == fld:
                                    colored_fields.append(item)
                                    fields_dic[item]['fg'] = 'lightgreen'
                                    if fields_dic[item]['text'] == '':
                                        fields_dic[item]['text'] = '\u0E4F'

        if tkstart != '' and tkend != '':
            main()
            if error == '':
                tkstart = ''
                tkend = ''
                startbutton['bg'] = startbutton_color
                if endbutton_color == 'lightgreen':
                    endbutton['bg'] = startbutton_color
                else:
                    endbutton['bg'] = endbutton_color
                startbutton['text'] = ''
                endbutton['text'] = startbutton_text
                fields = [a1, a2, a3, a4, a5, a6, a7, a8, b1, b2, b3, b4, b5, b6, b7, b8, c1, c2, c3, c4, c5, c5, c6,
                          c7, c8, d1, d2, d3, d4, d5, d6, d7, d8, e1, e2, e3, e4, e5, e6, e7, e8, f1, f2, f3, f4, f5,
                          f6, f7, f8, g1, g2, g3, g4, g5, g6, g7, g8, h1, h2, h3, h4, h5, h6, h7, h8]
                for i in fields:
                    if i['text'] == BK + '\ncheck!':
                        i['text'] = BK
                    if i['text'] == WK + '\ncheck!':
                        i['text'] = WK
                error = ''
                undo_coloring()
            elif error == 3:
                tkstart = ''
                tkend = ''
                startbutton['bg'] = startbutton_color
                if endbutton_color == 'lightgreen':
                    endbutton['bg'] = startbutton_color
                else:
                    endbutton['bg'] = endbutton_color
                startbutton['text'] = ''
                endbutton['text'] = startbutton_text
                fields = [a1, a2, a3, a4, a5, a6, a7, a8, b1, b2, b3, b4, b5, b6, b7, b8, c1, c2, c3, c4, c5, c5, c6,
                          c7, c8, d1, d2, d3, d4, d5, d6, d7, d8, e1, e2, e3, e4, e5, e6, e7, e8, f1, f2, f3, f4, f5,
                          f6, f7, f8, g1, g2, g3, g4, g5, g6, g7, g8, h1, h2, h3, h4, h5, h6, h7, h8]
                if turn == 'B':
                    for i in fields:
                        if i['text'] == BK:
                            i['text'] = BK + '\ncheck!'
                elif turn == 'W':
                    for i in fields:
                        if i['text'] == WK:
                            i['text'] = WK + '\ncheck!'
                tkstart = ''
                tkend = ''
                startbutton['bg'] = startbutton_color
                if endbutton_color == 'lightgreen':
                    endbutton['bg'] = startbutton_color
                else:
                    endbutton['bg'] = endbutton_color
                error = ''
                undo_coloring()
            elif error == 2:
                tkstart = ''
                tkend = ''
                startbutton['bg'] = startbutton_color
                if endbutton_color == 'lightgreen':
                    endbutton['bg'] = startbutton_color
                else:
                    endbutton['bg'] = endbutton_color
                startbutton['text'] = ''
                endbutton['text'] = startbutton_text
                fields = [a1, a2, a3, a4, a5, a6, a7, a8, b1, b2, b3, b4, b5, b6, b7, b8, c1, c2, c3, c4, c5, c5, c6,
                          c7, c8, d1, d2, d3, d4, d5, d6, d7, d8, e1, e2, e3, e4, e5, e6, e7, e8, f1, f2, f3, f4, f5,
                          f6, f7, f8, g1, g2, g3, g4, g5, g6, g7, g8, h1, h2, h3, h4, h5, h6, h7, h8]
                if turn == 'W':
                    for i in fields:
                        if i['text'] == BK:
                            i['text'] = BK + '\ncheck \nmate!'
                elif turn == 'B':
                    for i in fields:
                        if i['text'] == WK:
                            i['text'] = WK + '\ncheck \nmate!'
                tkstart = ''
                tkend = ''
                startbutton['bg'] = startbutton_color
                if endbutton_color == 'lightgreen':
                    endbutton['bg'] = startbutton_color
                else:
                    endbutton['bg'] = endbutton_color
                error = 4
                undo_coloring()
            else:
                tkstart = ''
                tkend = ''
                startbutton['bg'] = startbutton_color
                if endbutton_color == 'lightgreen':
                    endbutton['bg'] = startbutton_color
                else:
                    endbutton['bg'] = endbutton_color
                error = ''
                undo_coloring()


BR = '\u265C'
BN = '\u265E'
BB = '\u265D'
BQ = '\u265B'
BK = '\u265A'
BP = '\u265F'

WR = '\u2656'
WN = '\u2658'
WP = '\u2659'
WQ = '\u2655'
WK = '\u2654'
WB = '\u2657'

a8 = Button(tk, text=BR, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(a8), btnID('a8')])
a8.grid(row=1, column=1)
b8 = Button(tk, text=BN, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(b8), btnID('b8')])
b8.grid(row=1, column=2)
c8 = Button(tk, text=BB, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(c8), btnID('c8')])
c8.grid(row=1, column=3)
d8 = Button(tk, text=BQ, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(d8), btnID('d8')])
d8.grid(row=1, column=4)
e8 = Button(tk, text=BK, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(e8), btnID('e8')])
e8.grid(row=1, column=5)
f8 = Button(tk, text=BB, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(f8), btnID('f8')])
f8.grid(row=1, column=6)
g8 = Button(tk, text=BN, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(g8), btnID('g8')])
g8.grid(row=1, column=7)
h8 = Button(tk, text=BR, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(h8), btnID('h8')])
h8.grid(row=1, column=8)
a7 = Button(tk, text=BP, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(a7), btnID('a7')])
a7.grid(row=2, column=1)
b7 = Button(tk, text=BP, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(b7), btnID('b7')])
b7.grid(row=2, column=2)
c7 = Button(tk, text=BP, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(c7), btnID('c7')])
c7.grid(row=2, column=3)
d7 = Button(tk, text=BP, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(d7), btnID('d7')])
d7.grid(row=2, column=4)
e7 = Button(tk, text=BP, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(e7), btnID('e7')])
e7.grid(row=2, column=5)
f7 = Button(tk, text=BP, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(f7), btnID('f7')])
f7.grid(row=2, column=6)
g7 = Button(tk, text=BP, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(g7), btnID('g7')])
g7.grid(row=2, column=7)
h7 = Button(tk, text=BP, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(h7), btnID('h7')])
h7.grid(row=2, column=8)
a6 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(a6), btnID('a6')])
a6.grid(row=3, column=1)
b6 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(b6), btnID('b6')])
b6.grid(row=3, column=2)
c6 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(c6), btnID('c6')])
c6.grid(row=3, column=3)
d6 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(d6), btnID('d6')])
d6.grid(row=3, column=4)
e6 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(e6), btnID('e6')])
e6.grid(row=3, column=5)
f6 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(f6), btnID('f6')])
f6.grid(row=3, column=6)
g6 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(g6), btnID('g6')])
g6.grid(row=3, column=7)
h6 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(h6), btnID('h6')])
h6.grid(row=3, column=8)
a5 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(a5), btnID('a5')])
a5.grid(row=4, column=1)
b5 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(b5), btnID('b5')])
b5.grid(row=4, column=2)
c5 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(c5), btnID('c5')])
c5.grid(row=4, column=3)
d5 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(d5), btnID('d5')])
d5.grid(row=4, column=4)
e5 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(e5), btnID('e5')])
e5.grid(row=4, column=5)
f5 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(f5), btnID('f5')])
f5.grid(row=4, column=6)
g5 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(g5), btnID('g5')])
g5.grid(row=4, column=7)
h5 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(h5), btnID('h5')])
h5.grid(row=4, column=8)
a4 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(a4), btnID('a4')])
a4.grid(row=5, column=1)
b4 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(b4), btnID('b4')])
b4.grid(row=5, column=2)
c4 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(c4), btnID('c4')])
c4.grid(row=5, column=3)
d4 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(d4), btnID('d4')])
d4.grid(row=5, column=4)
e4 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(e4), btnID('e4')])
e4.grid(row=5, column=5)
f4 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(f4), btnID('f4')])
f4.grid(row=5, column=6)
g4 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(g4), btnID('g4')])
g4.grid(row=5, column=7)
h4 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(h4), btnID('h4')])
h4.grid(row=5, column=8)
a3 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(a3), btnID('a3')])
a3.grid(row=6, column=1)
b3 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(b3), btnID('b3')])
b3.grid(row=6, column=2)
c3 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(c3), btnID('c3')])
c3.grid(row=6, column=3)
d3 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(d3), btnID('d3')])
d3.grid(row=6, column=4)
e3 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(e3), btnID('e3')])
e3.grid(row=6, column=5)
f3 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(f3), btnID('f3')])
f3.grid(row=6, column=6)
g3 = Button(tk, text='', font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(g3), btnID('g3')])
g3.grid(row=6, column=7)
h3 = Button(tk, text='', font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(h3), btnID('h3')])
h3.grid(row=6, column=8)
a2 = Button(tk, text=WP, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(a2), btnID('a2')])
a2.grid(row=7, column=1)
b2 = Button(tk, text=WP, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(b2), btnID('b2')])
b2.grid(row=7, column=2)
c2 = Button(tk, text=WP, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(c2), btnID('c2')])
c2.grid(row=7, column=3)
d2 = Button(tk, text=WP, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(d2), btnID('d2')])
d2.grid(row=7, column=4)
e2 = Button(tk, text=WP, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(e2), btnID('e2')])
e2.grid(row=7, column=5)
f2 = Button(tk, text=WP, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(f2), btnID('f2')])
f2.grid(row=7, column=6)
g2 = Button(tk, text=WP, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(g2), btnID('g2')])
g2.grid(row=7, column=7)
h2 = Button(tk, text=WP, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(h2), btnID('h2')])
h2.grid(row=7, column=8)
a1 = Button(tk, text=WR, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(a1), btnID('a1')])
a1.grid(row=8, column=1)
b1 = Button(tk, text=WN, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(b1), btnID('b1')])
b1.grid(row=8, column=2)
c1 = Button(tk, text=WB, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(c1), btnID('c1')])
c1.grid(row=8, column=3)
d1 = Button(tk, text=WQ, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(d1), btnID('d1')])
d1.grid(row=8, column=4)
e1 = Button(tk, text=WK, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(e1), btnID('e1')])
e1.grid(row=8, column=5)
f1 = Button(tk, text=WB, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(f1), btnID('f1')])
f1.grid(row=8, column=6)
g1 = Button(tk, text=WN, font='Times 20 bold', bg='grey', height=2, width=5,
            command=lambda: [btnClick(g1), btnID('g1')])
g1.grid(row=8, column=7)
h1 = Button(tk, text=WR, font='Times 20 bold', bg='white', height=2, width=5,
            command=lambda: [btnClick(h1), btnID('h1')])
h1.grid(row=8, column=8)


class Figure(object):

    def __init__(self, name, object_name, color, start_position, possible_moves):
        self.object_name = object_name
        self.name = name
        self.color = color
        self.position = start_position
        self.possible_moves = possible_moves

    def update_position(self, ps, pe, all_positions_enemy, all_positions_own_team, all_possible_moves_enemy, turn):
        self.position = pe
        self.check_if_move_legit(pe, (), all_positions_enemy, all_positions_own_team, all_possible_moves_enemy, turn)

    def return_position(self, ps, pe, all_positions_enemy, all_positions_own_team, all_possible_moves_enemy, turn):
        self.position = ps
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
                    self.name == 'WB' and ps in [(6, i) for i in range(8)]):  # Two steps possible at the beginning
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

        if self.name == 'WT' or self.name == 'BT' or self.name == 'WD' or self.name == 'WK' or self.name == 'BD' or self.name == 'BK':  ### pawns / king / queen ###
            T_possible_moves = []
            i = 1
            if ps[0] + i != 8 and ps[0] + i != 0:
                if (ps[0] + i, ps[1]) not in all_positions_own_team:
                    T_possible_moves.append((ps[0] + i, ps[1]))
                if self.name != 'WK' and self.name != 'BK':
                    while (ps[0] + i, ps[1]) not in all_positions_enemy and (
                    ps[0] + i, ps[1]) not in all_positions_own_team:  # bot
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
                    ps[0] - i, ps[1]) not in all_positions_own_team:  # top
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
                    ps[0], ps[1] + i) not in all_positions_own_team:  # right
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

        if self.name == 'WS' or self.name == 'BS':
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

        if self.name == 'WL' or self.name == 'BL' or self.name == 'WD' or self.name == 'WK' or self.name == 'BD' or self.name == 'BK':  ### bishop / queen / king ###
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


B1 = Figure('WB', 'B1', 'WR', (6, 0), [(5, 0), (4, 0)])
B2 = Figure('WB', 'B2', 'WR', (6, 1), [(5, 1), (4, 1)])
B3 = Figure('WB', 'B3', 'WR', (6, 2), [(5, 2), (4, 2)])
B4 = Figure('WB', 'B4', 'WR', (6, 3), [(5, 3), (4, 3)])
B5 = Figure('WB', 'B5', 'WR', (6, 4), [(5, 4), (4, 4)])
B6 = Figure('WB', 'B6', 'WR', (6, 5), [(5, 5), (4, 5)])
B7 = Figure('WB', 'B7', 'WR', (6, 6), [(5, 6), (4, 6)])
B8 = Figure('WB', 'B8', 'WR', (6, 7), [(5, 7), (4, 7)])
T1 = Figure('WT', 'T1', 'WP', (7, 0), [])
T2 = Figure('WT', 'T2', 'WP', (7, 7), [])
S1 = Figure('WS', 'S1', 'WN', (7, 1), [(5, 0), (5, 2)])
S2 = Figure('WS', 'S2', 'WN', (7, 6), [(5, 5), (5, 7)])
L1 = Figure('WL', 'L1', 'WB', (7, 2), [])
L2 = Figure('WL', 'L2', 'WB', (7, 5), [])
D1 = Figure('WD', 'D1', 'WQ', (7, 3), [])
K1 = Figure('WK', 'K1', 'WK', (7, 4), [])

B9 = Figure('BB', 'B9', 'BR', (1, 0), [(2, 0), (3, 0)])
B10 = Figure('BB', 'B10', 'BR', (1, 1), [(2, 1), (3, 1)])
B11 = Figure('BB', 'B11', 'BR', (1, 2), [(2, 2), (3, 2)])
B12 = Figure('BB', 'B12', 'BR', (1, 3), [(2, 3), (3, 3)])
B13 = Figure('BB', 'B13', 'BR', (1, 4), [(2, 4), (3, 4)])
B14 = Figure('BB', 'B14', 'BR', (1, 5), [(2, 5), (3, 5)])
B15 = Figure('BB', 'B15', 'BR', (1, 6), [(2, 6), (3, 6)])
B16 = Figure('BB', 'B16', 'BR', (1, 7), [(2, 7), (3, 7)])
T3 = Figure('BT', 'T3', 'BP', (0, 0), [])
T4 = Figure('BT', 'T4', 'BP', (0, 7), [])
S3 = Figure('BS', 'S3', 'BN', (0, 1), [(2, 0), (2, 2)])
S4 = Figure('BS', 'S4', 'BN', (0, 6), [(2, 5), (2, 7)])
L3 = Figure('BL', 'L3', 'BB', (0, 2), [])
L4 = Figure('BL', 'L4', 'BB', (0, 5), [])
D2 = Figure('BD', 'D2', 'BQ', (0, 3), [])
K2 = Figure('BK', 'K2', 'BK', (0, 4), [])

run = True
destroyed_unit = ''

global turn
turn = 'W'


def main():
    global error
    get_positions()
    destroyed_unit = ''
    start, end = checkinput()
    if (start, end) == (-1, -1):
        error = 1
        print('[0] invalid input')
    if (start, end) == (-2, -2):
        error = 2
        print('Game over.')
    print_board()


def checkinput():
    global turn, error

    colors_turn = 'white' if turn == 'W' else 'black'
    print(f'\nIts {colors_turn} turn. Your move:')
    print('start = ' + tkstart)
    print('end = ' + tkend)

    translate_a = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7}
    translate_b = {'8': 0, '7': 1, '6': 2, '5': 3, '4': 4, '3': 5, '2': 6, '1': 7}
    a = tkstart[0]
    b = tkstart[1]
    d = tkend[0]
    e = tkend[1]

    start_position = (translate_b[b], translate_a[a])
    end_position = (translate_b[e], translate_a[d])
    if check_chosen_move(start_position, end_position):
        if turn == 'W':  # whites turn
            # print('All possible Moves of White before: ' + str(possible_moves_white))
            # print('All possible Moves of Black before: ' + str(possible_moves_black))
            for i in white_players:
                if i.position == start_position:
                    i.update_position(start_position, end_position, position_black_players, position_white_players,
                                      possible_moves_black, turn)
                    for i in black_players:
                        if i.position == end_position:
                            destroyed_unit = i.object_name
                            i.position = (-1, -1)
            get_positions()
            for i in black_players:  # Update all possible moves of the enemy team
                i.update_possible_moves(position_white_players, position_black_players, possible_moves_white, turn)
            for i in white_players:  # Update all possible moves of the own team
                i.update_possible_moves(position_black_players, position_white_players, possible_moves_black, turn)
            get_positions()
            for i in possible_moves_black:
                if position_king_white in i:
                    for i in white_players:
                        if i.position == end_position:
                            i.return_position(start_position, end_position, position_black_players,
                                              position_white_players, possible_moves_black, turn)
                            for i in black_players:
                                try:
                                    if i.object_name == destroyed_unit:
                                        i.position = end_position
                                        destroyed_unit = ''
                                except:
                                    pass
                    error = 1
                    print('Not allowed to bring own King into chess position')
                    return (0, 0)
            # print('All possible Moves of White after: ' + str(possible_moves_white))
            # print('All possible Moves of Black after: ' + str(possible_moves_black))
            for i in possible_moves_white:
                if position_king_black in i:
                    if K2.possible_moves != []:
                        error = 3
                        print('check!')
                    else:
                        can_reach_king = []
                        can_reach_king_position = []
                        helpfull_positions = []
                        who_can_help = {}
                        for i in white_players:
                            if position_king_black in i.possible_moves or possible_moves_black in i.possible_moves or possible_moves_black in i.position:  # Can the enemy jump in between?
                                possible_positions_to_cover = []
                                for m in possible_moves_black:
                                    for u in m:
                                        if u in i.possible_moves or u in i.position:
                                            possible_positions_to_cover.append(u)
                                for k in possible_positions_to_cover:
                                    for n in black_players:
                                        if k in n.possible_moves:
                                            who_can_help[(n.object_name, k)] = 0
                                            current_object = n.object_name
                                            current_position = n.position
                                            n.update_position(n.position, k, position_black_players,
                                                              position_white_players, possible_moves_black, turn)
                                            for q in white_players:
                                                if q.position == k:
                                                    destroyed_unit = q.object_name
                                                    q.position = (-1, -1)
                                            get_positions()
                                            for x in white_players:
                                                x.update_possible_moves(position_black_players, position_white_players,
                                                                        possible_moves_black, turn)
                                            for y in black_players:
                                                y.update_possible_moves(position_white_players, position_black_players,
                                                                        possible_moves_white, turn)
                                            get_positions()
                                            for p in possible_moves_white:
                                                if position_king_black in p:
                                                    who_can_help[(n.object_name, k)] = 1
                                            n.return_position(current_position, k, position_black_players,
                                                              position_white_players, possible_moves_black, turn)
                                            for h in white_players:
                                                try:
                                                    if h.object_name == destroyed_unit:
                                                        h.position = k
                                                        destroyed_unit = ''
                                                except:
                                                    pass
                                            get_positions()
                                            for z in white_players:
                                                z.update_possible_moves(position_black_players, position_white_players,
                                                                        possible_moves_black, turn)
                                            for w in black_players:
                                                w.update_possible_moves(position_white_players, position_black_players,
                                                                        possible_moves_white, turn)
                                            get_positions()
                        for key, item in who_can_help.items():
                            if item == 0:
                                helpfull_positions.append(key[1])
                        if helpfull_positions != []:
                            error = 3
                            print('check!')
                            pass
                        else:
                            for i in white_players:
                                if i.position == start_position:
                                    i.update_position(start_position, end_position, position_black_players,
                                                      position_white_players, possible_moves_black, turn)
                                    for i in black_players:
                                        if i.position == end_position:
                                            destroyed_unit = i.object_name
                                            i.position = (-1, -1)
                            get_positions()
                            print_board()
                            print('check mate!')
                            return (-2, -2)
            turn = 'B'
        else:  # blacks turn
            # print('All possible Moves of White before: ' + str(possible_moves_white))
            # print('All possible Moves of Black before: ' + str(possible_moves_black))
            for i in black_players:
                if i.position == start_position:
                    i.update_position(start_position, end_position, position_white_players, position_black_players,
                                      possible_moves_white, turn)
                    for i in white_players:
                        if i.position == end_position:
                            destroyed_unit = i.object_name
                            i.position = (-1, -1)
            get_positions()
            for i in black_players:
                i.update_possible_moves(position_white_players, position_black_players, possible_moves_white, turn)
            for i in white_players:
                i.update_possible_moves(position_black_players, position_white_players, possible_moves_black, turn)
            get_positions()
            for i in possible_moves_white:
                if position_king_black in i:
                    for i in black_players:
                        if i.position == end_position:
                            i.return_position(start_position, end_position, position_white_players,
                                              position_black_players, possible_moves_white, turn)
                            for i in white_players:
                                try:
                                    if i.object_name == destroyed_unit:
                                        i.position = end_position
                                        destroyed_unit = ''
                                except:
                                    pass
                    error = 1
                    print('Not allowed to bring own King into check position')
                    return (0, 0)
            # print('All possible Moves of White after: ' + str(possible_moves_white))
            # print('All possible Moves of Black after: ' + str(possible_moves_black))
            for i in possible_moves_black:
                if position_king_white in i:
                    if K1.possible_moves != []:
                        error = 3
                        print('check!')
                    else:
                        can_reach_king = []
                        can_reach_king_position = []
                        helpfull_positions = []
                        who_can_help = {}
                        for i in black_players:
                            if position_king_white in i.possible_moves or possible_moves_white in i.possible_moves or possible_moves_white in i.position:  # Can the enemy jump in between?
                                possible_positions_to_cover = []
                                for m in possible_moves_white:
                                    for u in m:
                                        if u in i.possible_moves or u in i.position:
                                            possible_positions_to_cover.append(u)
                                for k in possible_positions_to_cover:
                                    for n in white_players:
                                        if k in n.possible_moves:
                                            who_can_help[(n.object_name, k)] = 0
                                            current_object = n.object_name
                                            current_position = n.position
                                            n.update_position(n.position, k, position_white_players,
                                                              position_black_players, possible_moves_white, turn)
                                            for q in black_players:
                                                if q.position == k:
                                                    destroyed_unit = q.object_name
                                                    q.position = (-1, -1)
                                            get_positions()
                                            for x in white_players:
                                                x.update_possible_moves(position_black_players, position_white_players,
                                                                        possible_moves_black, turn)
                                            for y in black_players:
                                                y.update_possible_moves(position_white_players, position_black_players,
                                                                        possible_moves_white, turn)
                                            get_positions()

                                            for p in possible_moves_black:
                                                if position_king_white in p:
                                                    who_can_help[(n.object_name, k)] = 1
                                            n.return_position(current_position, k, position_white_players,
                                                              position_black_players, possible_moves_white, turn)
                                            for h in black_players:
                                                try:
                                                    if h.object_name == destroyed_unit:
                                                        h.position = k
                                                        destroyed_unit = ''
                                                except:
                                                    pass
                                            get_positions()
                                            for z in white_players:
                                                z.update_possible_moves(position_black_players, position_white_players,
                                                                        possible_moves_black, turn)
                                            for w in black_players:
                                                w.update_possible_moves(position_white_players, position_black_players,
                                                                        possible_moves_white, turn)
                                            get_positions()
                        for key, item in who_can_help.items():
                            if item == 0:
                                helpfull_positions.append(key[1])
                        if helpfull_positions != []:
                            error = 3
                            print('check!')
                            pass
                        else:
                            for i in black_players:
                                if i.position == start_position:
                                    i.update_position(start_position, end_position, position_white_players,
                                                      position_black_players, possible_moves_white, turn)
                                    for i in white_players:
                                        if i.position == end_position:
                                            destroyed_unit = i.object_name
                                            i.position = (-1, -1)
                            get_positions()
                            print_board()
                            print('check mate!')
                            return (-2, -2)
            turn = 'W'
        return (0, 0)
    else:
        return (0, 0)


def check_chosen_move(ps, pe):
    global error
    if turn == 'W' and ps in position_white_players:
        try:
            for i in white_players:
                if i.position == ps:
                    if i.check_if_move_legit(ps, pe, position_black_players, position_white_players,
                                             possible_moves_black, turn):
                        return True
                    else:
                        error = 1
                        print('move not legit')
                        return False
        except:
            print('Choose a legit player')
            return False
    elif turn == 'B' and ps in position_black_players:
        try:
            for i in black_players:
                if i.position == ps:
                    if i.check_if_move_legit(ps, pe, position_white_players, position_black_players,
                                             possible_moves_white, turn):
                        return True
                    else:
                        error = 1
                        print('move not legit')
                        return False
        except:
            error = 1
            print('Choose a legit player')
            return False
    else:
        error = 1
        print(f'Its {turn} turn, pick a valid figure!')
        return False


def print_board():
    board_side = [' 8 \u2502', ' 7 \u2502', ' 6 \u2502', ' 5 \u2502', ' 4 \u2502', ' 3 \u2502', ' 2 \u2502',
                  ' 1 \u2502']
    print(
        '\n\n        a   b   c   d   e   f   g   h' + '\n    \u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\n   \u2502                                    \u2502')
    k = 8
    for i in range(8):
        print(board_side[i], end='   ')
        for j in range(8):
            if (i, j) in position_white_players or (i, j) in position_black_players:
                for x in white_players:
                    if x.position == (i, j):
                        print(x.color, end='  ')
                for x in black_players:
                    if x.position == (i, j):
                        print(x.color, end='  ')
            else:
                print(' \u2022 ', end=' ')
        print(' \u2502 ' + str(k) + '\n   \u2502                                    \u2502')
        k -= 1
    print(
        '    \u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\n        a   b   c   d   e   f   g   h' + '\n')


def get_positions():
    global white_players, position_white_players, possible_moves_white, position_king_white, black_players, position_black_players, possible_moves_black, position_king_black
    white_players = [B1, B2, B3, B4, B5, B6, B7, B8, T1, T2, S1, S2, L1, L2, D1, K1]
    position_white_players = [i.position for i in white_players]
    possible_moves_white = [i.possible_moves for i in white_players]
    position_king_white = K1.position
    black_players = [B9, B10, B11, B12, B13, B14, B15, B16, T3, T4, S3, S4, L3, L4, D2, K2]
    position_black_players = [i.position for i in black_players]
    possible_moves_black = [i.possible_moves for i in black_players]
    position_king_black = K2.position
    return True


tk.mainloop()