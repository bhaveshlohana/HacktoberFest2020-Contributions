Public Class Form1

    Dim enkrip As New Engine
    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        hs.Minimum = -26
        hs.Maximum = 26
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        enkrip.setGeser(hs.Value)
        enkrip.EncCesar(TextBox1, TextBox2)
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        enkrip.setGeser(hs.Value)
        StrReverse(enkrip.DecCesar(TextBox2, TextBox1))
    End Sub

    Private Sub hs_Scroll(ByVal sender As System.Object, ByVal e As System.Windows.Forms.ScrollEventArgs) Handles hs.Scroll
        Me.Text = hs.Value
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        FileCopy("D:\Decenzo Lab\STEG\g1.jpg", "D:\Decenzo Lab\STEG\asdd.jpg")
    End Sub
End Class
