
from django import forms

class ArtistForm(forms.Form):
    Artist_guess = forms.CharField(label='Artist', max_length=100)