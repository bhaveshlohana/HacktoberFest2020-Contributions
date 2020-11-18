Public Class Engine
    Dim Geser As Integer
    Function setGeser(ByVal jumlah As Integer)
        Geser = jumlah
        Return jumlah
    End Function
    Public Function EncCesar(ByVal txt As TextBox, ByVal hasil As TextBox) As String
        For Each c As Char In txt.Text
            Dim i As Integer
            i = i + 1
            Select Case LCase(c)
                Case "a"
                    hasil.AppendText(getAbjad(1 + Geser))
                Case "b"
                    hasil.AppendText(getAbjad(2 + Geser))
                Case "c"
                    hasil.AppendText(getAbjad(3 + Geser))
                Case "d"
                    hasil.AppendText(getAbjad(4 + Geser))
                Case "e"
                    hasil.AppendText(getAbjad(5 + Geser))
                Case "f"
                    hasil.AppendText(getAbjad(6 + Geser))
                Case "g"
                    hasil.AppendText(getAbjad(7 + Geser))
                Case "h"
                    hasil.AppendText(getAbjad(8 + Geser))
                Case "i"
                    hasil.AppendText(getAbjad(9 + Geser))
                Case "j"
                    hasil.AppendText(getAbjad(10 + Geser))
                Case "k"
                    hasil.AppendText(getAbjad(11 + Geser))
                Case "l"
                    hasil.AppendText(getAbjad(12 + Geser))
                Case "m"
                    hasil.AppendText(getAbjad(13 + Geser))
                Case "n"
                    hasil.AppendText(getAbjad(14 + Geser))
                Case "o"
                    hasil.AppendText(getAbjad(15 + Geser))
                Case "p"
                    hasil.AppendText(getAbjad(16 + Geser))
                Case "q"
                    hasil.AppendText(getAbjad(17 + Geser))
                Case "r"
                    hasil.AppendText(getAbjad(18 + Geser))
                Case "s"
                    hasil.AppendText(getAbjad(19 + Geser))
                Case "t"
                    hasil.AppendText(getAbjad(20 + Geser))
                Case "u"
                    hasil.AppendText(getAbjad(21 + Geser))
                Case "v"
                    hasil.AppendText(getAbjad(22 + Geser))
                Case "w"
                    hasil.AppendText(getAbjad(23 + Geser))
                Case "x"
                    hasil.AppendText(getAbjad(24 + Geser))
                Case "y"
                    hasil.AppendText(getAbjad(25 + Geser))
                Case "z"
                    hasil.AppendText(getAbjad(26 + Geser))
                Case " "
                    hasil.AppendText(" ")
            End Select
        Next
    End Function

    Public Function DecCesar(ByVal txt As TextBox, ByVal hasil As TextBox) As String
        For Each c As Char In txt.Text
            Dim i As Integer
            i = i + 1
            Select Case LCase(c)
                Case "a"
                    hasil.AppendText(getAbjad(1 - Geser))
                Case "b"
                    hasil.AppendText(getAbjad(2 - Geser))
                Case "c"
                    hasil.AppendText(getAbjad(3 - Geser))
                Case "d"
                    hasil.AppendText(getAbjad(4 - Geser))
                Case "e"
                    hasil.AppendText(getAbjad(5 - Geser))
                Case "f"
                    hasil.AppendText(getAbjad(6 - Geser))
                Case "g"
                    hasil.AppendText(getAbjad(7 - Geser))
                Case "h"
                    hasil.AppendText(getAbjad(8 - Geser))
                Case "i"
                    hasil.AppendText(getAbjad(9 - Geser))
                Case "j"
                    hasil.AppendText(getAbjad(10 - Geser))
                Case "k"
                    hasil.AppendText(getAbjad(11 - Geser))
                Case "l"
                    hasil.AppendText(getAbjad(12 - Geser))
                Case "m"
                    hasil.AppendText(getAbjad(13 - Geser))
                Case "n"
                    hasil.AppendText(getAbjad(14 - Geser))
                Case "o"
                    hasil.AppendText(getAbjad(15 - Geser))
                Case "p"
                    hasil.AppendText(getAbjad(16 - Geser))
                Case "q"
                    hasil.AppendText(getAbjad(17 - Geser))
                Case "r"
                    hasil.AppendText(getAbjad(18 - Geser))
                Case "s"
                    hasil.AppendText(getAbjad(19 - Geser))
                Case "t"
                    hasil.AppendText(getAbjad(20 - Geser))
                Case "u"
                    hasil.AppendText(getAbjad(21 - Geser))
                Case "v"
                    hasil.AppendText(getAbjad(22 - Geser))
                Case "w"
                    hasil.AppendText(getAbjad(23 - Geser))
                Case "x"
                    hasil.AppendText(getAbjad(24 - Geser))
                Case "y"
                    hasil.AppendText(getAbjad(25 - Geser))
                Case "z"
                    hasil.AppendText(getAbjad(26 - Geser))
                Case " "
                    hasil.AppendText(" ")
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
        ElseIf i < 0 Then
            getAbjad = abjad(i + 26)
        Else
            getAbjad = abjad(i)
        End If
    End Function

    Function SimpleSteg(ByVal path As String, ByVal file1 As String, ByVal file2 As String, ByVal hasil As String)

    End Function

End Class
