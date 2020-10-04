Imports Microsoft.VisualBasic

Public Class Class1
    Dim Geser As Integer
    Function setGeser(ByVal jumlah As Integer)
        Geser = jumlah
        Return jumlah
    End Function
    Public Function EncCesar(ByVal txt As textbox) As String
        For Each c As Char In txt
            Dim i As Integer
            i = i + 1
            Select Case c
                Case "a"
                    getAbjad(1 + geser)
                Case "b"
                    getAbjad(2 + geser)
                Case "c"
                    getAbjad(3 + geser)
                Case "d"
                    getAbjad(4 + geser)
                Case "e"
                    getAbjad(5 + geser)
                Case "f"
                    getAbjad(6 + geser)
                Case "g"
                    getAbjad(7 + geser)
                Case "h"
                    getAbjad(8 + geser)
                Case "i"
                    getAbjad(9 + geser)
                Case "j"
                    getAbjad(10 + geser)
                Case "k"
                    getAbjad(11 + geser)
                Case "l"
                    getAbjad(12 + geser)
                Case "m"
                    getAbjad(13 + geser)
                Case "n"
                    getAbjad(14 + geser)
                Case "o"
                    getAbjad(15 + geser)
                Case "p"
                    getAbjad(16 + geser)
                Case "q"
                    getAbjad(17 + geser)
                Case "r"
                    getAbjad(18 + geser)
                Case "s"
                    getAbjad(19 + geser)
                Case "t"
                    getAbjad(20 + geser)
                Case "u"
                    getAbjad(21 + geser)
                Case "v"
                    getAbjad(22 + geser)
                Case "w"
                    getAbjad(23 + geser)
                Case "x"
                    getAbjad(24 + geser)
                Case "y"
                    getAbjad(25 + geser)
                Case "z"
                    getAbjad(26 + geser)
            End Select
        Next
    End Function
    Function getAbjad(ByVal i As Integer)
        Dim abjad(26) As String
        abjad(1) = "a"
        abjad(2) = "b"
        abjad(3) = "c"
        abjad(4) = "d"
        abjad(5) = "e"
        abjad(6) = "f"
        abjad(7) = "g"
        abjad(8) = "h"
        abjad(9) = "i"
        abjad(10) = "j"
        abjad(11) = "k"
        abjad(12) = "l"
        abjad(13) = "m"
        abjad(14) = "n"
        abjad(15) = "o"
        abjad(16) = "p"
        abjad(17) = "q"
        abjad(18) = "r"
        abjad(19) = "s"
        abjad(20) = "t"
        abjad(21) = "u"
        abjad(22) = "v"
        abjad(23) = "w"
        abjad(24) = "x"
        abjad(25) = "y"
        abjad(26) = "z"
        If i > 26 Then
            getAbjad = abjad(i - 26)
        ElseIf i < 26 Then
            getAbjad = abjad(i + 26)
        Else
            getAbjad = abjad(i)
        End If
    End Function
End Class
